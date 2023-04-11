#include "interactiveobject.h"

InteractiveObject::InteractiveObject() : mx{0.0f}, my{0.0f}, mz{0.0f}
{

    float xmin = -1.0f, xmax = 1.0f, ymin = -1.0f, ymax = 1.0f, h = 0.25f;
        float y{};
        float z{};
//        for (auto x = xmin; x < xmax; x += h)
//        for (auto y = ymin; y < ymax; y +=h)
//        {
//        float z = (2 * x) * pow(y, 2);
//        mVertices.push_back(Vertex{x,y,z,x,y,z});
//        z = (2 * (x + h)) * pow(y, 2);
//        mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//        z = (2 * x) * pow((y+h), 2);
//        mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//        mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//        z = (2 * (x+h)) * pow(y, 2);
//        mVertices.push_back(Vertex{x+h,y,z,x,y,z});
//        z = (2 * (x+h)) * pow((y+h), 2);
//        mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});
//        }

//    float xmin = -1.0f, xmax = 1.0f, ymin = -1.0f, ymax = 1.0f,  h = 0.25f;
//    float y{};
//    float z{};
    float r = 1;

//    for (auto x = xmin; x < xmax; x += h)
//    {
//        for (auto y = ymin; y < ymax; ++y) {


//        //r = pow(x,2) + pow(y,2) + pow(z,2);
//           // mVertices.push_back(Vertex{x,y,z,x,y,z});

////            z = pow(x+h,2);
////            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
////            z = pow(y+h,2);
////            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
////            //z = pow(z,2);
////            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//            float z = pow(x,2) + x;
//            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
//          }

//    }

    Vertex v0{0.1f, 0.0f, 3.0f, 0,1,0};    mVertices.push_back(v0);
    Vertex v1{0.3f, 0.0f, 3.1f, 0,1,0};    mVertices.push_back(v1);
    Vertex v2{0.2f, 0.8f,3.0f, 0,1,0};     mVertices.push_back(v2);

    Vertex v3{0.1f, 0.0f, 3.0f, 0,0.9,0};    mVertices.push_back(v3);
    Vertex v4{0.3f, 0.0f, 3.1f, 0,0.9,0};    mVertices.push_back(v4);
    Vertex v5{0.2f, 0.8f,3.0f, 0,0.9,0};     mVertices.push_back(v5);




//    Vertex v0{ 0.0f, 0.0f, 0.0f, 1,0,0};   mVertices.push_back(v0);
//     Vertex v1{ 0.0f, 1.0f, 0.0f, 0,0,1};   mVertices.push_back(v1);
//     Vertex v2{ 0.5f, 0.0f, 0.0f, 1,0,0};   mVertices.push_back(v2);
//     mVertices.push_back(v0);
//     mVertices.push_back(v1);
//     Vertex v3{-0.5f, 0.0f, 0.0f, 1,0,0};   mVertices.push_back(v3);
//     mVertices.push_back(v0);
//     mVertices.push_back(v1);
//     Vertex v4{ 0.0f, 0.0f, 0.5f, 1,0,0};   mVertices.push_back(v4);
//     mVertices.push_back(v0);
//     mVertices.push_back(v1);
//     Vertex v5{ 0.0f, 0.0f,-0.5f, 1,0,0};   mVertices.push_back(v5);


      mMatrix.setToIdentity();

}

InteractiveObject::~InteractiveObject()
{

}


void InteractiveObject::init(GLint matrixUniform){
    //Vertex Array Object - VAO

    mMatrixUniform = matrixUniform;

     initializeOpenGLFunctions();

    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3*sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

}

void InteractiveObject::draw(){
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

float InteractiveObject::getRadius()
{
    return mr;
}

QVector3D InteractiveObject::getPosition()
{
    return mMatrix.column(3).toVector3D();
}

void InteractiveObject::move(float dx, float dy, float dz){
    mx += dx;
    my += dy;
    mz += dz;

    mMatrix.translate(mx,my,mz);
}




//            Vertex v0{-1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v0);
//            Vertex v1{-1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v1);
//            Vertex v2{1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v2);
//            Vertex v3{-1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v3);
//            Vertex v4{-1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v4);
//            Vertex v5{1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v5);
//            Vertex v6{ -1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v6);
//            Vertex v7{ -1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v7);
//            Vertex v8{ 1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v8);
//            Vertex v9{ 1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v9);
//            Vertex v10{ 1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v10);
//            Vertex v11{ -1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v11);
//            Vertex v12{ -1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v12);
//            Vertex v13{ -1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v13);
//            Vertex v14{ -1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v14);
//            Vertex v15{ 1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v15);
//            Vertex v16{ -1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v16);
//            Vertex v17{ -1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v17);
//            Vertex v18{ -1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v18);
//            Vertex v19{ -1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v19);
//            Vertex v20{ 1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v20);
//            Vertex v21{  1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v21);
//            Vertex v22{ 1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v22);
//            Vertex v23{ 1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v23);
//            Vertex v24{ 1.0f,-1.0f,-1.0f, 1,0,0};    mVertices.push_back(v24);
//            Vertex v25{  1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v25);
//            Vertex v26{ 1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v26);
//            Vertex v27{ 1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v27);
//            Vertex v28{ 1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v28);
//            Vertex v29{ -1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v29);
//            Vertex v30{ 1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v30);
//            Vertex v31{ -1.0f, 1.0f,-1.0f, 1,0,0};    mVertices.push_back(v31);
//            Vertex v32{ -1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v32);
//            Vertex v33{ 1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v33);
//            Vertex v34{ -1.0f, 1.0f, 1.0f, 1,0,0};    mVertices.push_back(v34);
//            Vertex v35{  1.0f,-1.0f, 1.0f, 1,0,0};    mVertices.push_back(v35);
