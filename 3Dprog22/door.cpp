#include "door.h"
#include "visualobject.h"

door::door()
{

    //døren
    Vertex v0{0.3f, 0.0f,1.0f, 0.5,0.5,0};    mVertices.push_back(v0);
    Vertex v1{0.7f, 0.0f,1.0f, 0.5,0.5,0};    mVertices.push_back(v1);
    Vertex v2{0.7f, 0.8f,1.0f, 0.5,0.5,0};    mVertices.push_back(v2);

    Vertex v3{0.3f, 0.0f,1.0f, 0.5,0.5,0};    mVertices.push_back(v3);
    Vertex v4{0.3f, 0.8f,1.0f, 0.5,0.5,0};    mVertices.push_back(v4);
    Vertex v5{0.7f, 0.8f,1.0f, 0.5,0.5,0};    mVertices.push_back(v5);


    //håndtak
    Vertex v6{0.35f, 0.5f,1.01f, 0,0,0};    mVertices.push_back(v6);
    Vertex v7{0.4f, 0.4f,1.01f, 0,0,0};    mVertices.push_back(v7);
    Vertex v8{0.45f, 0.5f,1.01f, 0,0,0};    mVertices.push_back(v8);

    Vertex v9{0.35f, 0.5f,1.01f, 0,0,0};    mVertices.push_back(v9);
    Vertex v10{0.4f, 0.6f,1.01f, 0,0,0};    mVertices.push_back(v10);
    Vertex v11{0.45f, 0.5f,1.01f, 0,0,0};    mVertices.push_back(v11);

    mMatrix.setToIdentity();

}

door::~door()
{

}



void door::init(GLint matrixUniform){
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

void door::draw(){
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
