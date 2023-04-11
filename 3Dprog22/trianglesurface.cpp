#include "trianglesurface.h"

TriangleSurface::TriangleSurface()
{

    Vertex v0(-15, 0, 15, 0, 0, 1);     mVertices.push_back(v0);
        Vertex v1(-15, 0, -15, 0, 0, 1);    mVertices.push_back(v1);
        Vertex v2(15, 0, 15, 0, 0, 1);      mVertices.push_back(v2);
        mVertices.push_back(v0);
        mVertices.push_back(v1);
        Vertex v3(15, 0, -15, 0, 0, 1);     mVertices.push_back(v3);

        mMatrix.setToIdentity();




//    float xmin = -1.0f, xmax = 1.0f, ymin = -1.0f, ymax = 1.0f, h = 0.25f;
//    float y{};
//    float z{};
//    for (auto x = xmin; x < xmax; x += h)
//    for (auto y = ymin; y < ymax; y +=h)
//    {
//    float z = (2 * x) * pow(y, 2);
//    mVertices.push_back(Vertex{x,y,z,x,y,z});
//    z = (2 * (x + h)) * pow(y, 2);
//    mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//    z = (2 * x) * pow((y+h), 2);
//    mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//    mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//    z = (2 * (x+h)) * pow(y, 2);
//    mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//    z = (2 * (x+h)) * pow((y+h), 2);
//    mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});

//       float y = (2 * x);
//       mVertices.push_back(Vertex{x,y,z,x,y,z});
//       y = (2 * (x + h));
//       mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//       y = (2 * x);
//       mVertices.push_back(Vertex{x,y,z,x,y,z});

    //}
}

TriangleSurface::~TriangleSurface(){ }

TriangleSurface::TriangleSurface(std::string filnavn) : VisualObject()
{
   readFile(filnavn);
   std::cout << "test";
   mMatrix.setToIdentity();
}

void TriangleSurface::readFile(std::string filnavn) {
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

void TriangleSurface::writeFile(std::string filnavn)
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

void TriangleSurface::init(GLint matrixUniform)
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

void TriangleSurface::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
