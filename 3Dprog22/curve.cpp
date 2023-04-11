#include "curve.h"

  Curve::Curve()
    {
        float xmin = -30.0f, xmax = 30.0f, h = 0.10f;
        float y{};
        float z{};
        for (auto x = xmin; x < xmax; x += h)
        {
            float y = (-0.27 * pow(x, 3) - 2.33 * pow(x, 2) + 4 * x + 0);
            mVertices.push_back(Vertex{x,y,z,x,y,z});

        }

        for (auto x = xmin; x < xmax; x += h)
        {
            float y = (-0.09 * pow(x, 2) + 0.76 * x + 1.65);
            mVertices.push_back(Vertex{x,y,z,x,y,z});

        }
    }


Curve::~Curve(){ }

Curve::Curve(std::string filnavn) : VisualObject()
{
   readFile(filnavn);
   std::cout << "test";
   mMatrix.setToIdentity();
}

void Curve::readFile(std::string filnavn) {
   std::ifstream inn;
   inn.open(filnavn.c_str());


   if (inn.is_open()) {
       int n;
       Vertex vertex;
       inn >> n;
       mVertices.reserve(n);
       for (int i=0; i<n; i++) {
            inn >> vertex;
            mVertices.push_back(vertex);
       }
       inn.close();
   }
}

void Curve::writeFile(std::string filnavn)
{
    std::ofstream ut;
    ut.open(filnavn.c_str());

    if (ut.is_open())
    {

        auto n = mVertices.size();
        Vertex vertex;
        ut << n << std::endl;
        for (auto it=mVertices.begin(); it != mVertices.end(); it++)
        {
            //vertex = *it;
            ut << *it << std::endl;
        }
        ut.close();
    }
}

void Curve::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;
    initializeOpenGLFunctions();

    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray ( mVAO );

    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO);

    glBufferData( GL_ARRAY_BUFFER,
                  mVertices.size()*sizeof( Vertex ),
                  mVertices.data(),
                  GL_STATIC_DRAW
                  );

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(
                0,
                3,
                GL_FLOAT,
                GL_FALSE,
                sizeof(Vertex),
                reinterpret_cast<GLvoid*>(0)
                );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Curve::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());
}


//        float y = (2 * x);
//        mVertices.push_back(Vertex{x,y,z,x,y,z});
//        y = (2 * (x + h));
//        mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//        y = (2 * x);
//        mVertices.push_back(Vertex{x,y,z,x,y,z});
