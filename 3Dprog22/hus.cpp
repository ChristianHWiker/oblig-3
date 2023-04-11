#include "hus.h"

hus::hus()
{
    //forand vegg
      Vertex v0{0.0f, 0.0f,1.0f, 1,0,0};    mVertices.push_back(v0);
      Vertex v1{0.3f, 0.0f, 1.0f, 1,0,0};    mVertices.push_back(v1);
      Vertex v2{0.3f, 1.0f,1.0f, 1,0,0};    mVertices.push_back(v2);

      Vertex v3{0.0f,0.0f,1.0f, 1,0,0};    mVertices.push_back(v3);
      Vertex v4{0.0f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v4);
      Vertex v5{0.3f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v5);

      Vertex v6{0.3f,0.8f,1.0f, 1,0,0};    mVertices.push_back(v6);
      Vertex v7{0.7f,0.8f,1.0f, 1,0,0};    mVertices.push_back(v7);
      Vertex v8{0.7f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v8);

      Vertex v9{0.3f,0.8f,1.0f,  1,0,0};    mVertices.push_back(v9);
      Vertex v10{0.3f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v10);
      Vertex v11{0.7f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v11);

      Vertex v12{0.7f,0.0f,1.0f, 1,0,0};    mVertices.push_back(v12);
      Vertex v13{0.7f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v13);
      Vertex v14{1.0f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v14);

      Vertex v15{0.7f,0.0f,1.0f, 1,0,0};    mVertices.push_back(v15);
      Vertex v16{1.0f,0.0f,1.0f, 1,0,0};    mVertices.push_back(v16);
      Vertex v17{1.0f,1.0f,1.0f, 1,0,0};    mVertices.push_back(v17);

      //side vegg
      Vertex v18{0.0f,0.0f,1.0f, 0,1,0};    mVertices.push_back(v18);
      Vertex v19{0.0f,0.0f,0.0f, 0,1,0};    mVertices.push_back(v19);
      Vertex v20{0.0f,1.0f,0.0f, 0,1,0};    mVertices.push_back(v20);

      Vertex v21{0.0f,0.0f,1.0f, 0,1,0};    mVertices.push_back(v21);
      Vertex v22{0.0f,1.0f,1.0f, 0,1,0};    mVertices.push_back(v22);
      Vertex v23{0.0f,1.0f,0.0f, 0,1,0};    mVertices.push_back(v23);

      Vertex v24{1.0f,0.0f,1.0f, 1,1,1};    mVertices.push_back(v24);
      Vertex v25{1.0f,0.0f,0.0f, 1,1,1};    mVertices.push_back(v25);
      Vertex v26{1.0f,1.0f,0.0f, 1,1,1};    mVertices.push_back(v26);

      Vertex v27{1.0f,0.0f,1.0f, 1,1,1};    mVertices.push_back(v27);
      Vertex v28{1.0f,1.0f,1.0f, 1,1,1};    mVertices.push_back(v28);
      Vertex v29{1.0f,1.0f,0.0f, 1,1,1};    mVertices.push_back(v29);

      Vertex v30{0.0f,0.0f,0.0f, 0,0,0};    mVertices.push_back(v30);
      Vertex v31{1.0f,0.0f,0.0f, 0,0,0};    mVertices.push_back(v31);
      Vertex v32{1.0f,1.0f,0.0f, 0,0,0};    mVertices.push_back(v32);

      Vertex v33{0.0f,0.0f,0.0f, 0,0,0};    mVertices.push_back(v33);
      Vertex v34{0.0f,1.0f,0.0f, 0,0,0};    mVertices.push_back(v34);
      Vertex v35{1.0f,1.0f,0.0f, 0,0,0};    mVertices.push_back(v35);

      //tak
      Vertex v36{0.0f,1.0f,1.0f, 0,0,1};    mVertices.push_back(v36);
      Vertex v37{0.0f,1.0f,0.0f, 0,0,1};    mVertices.push_back(v37);
      Vertex v38{0.5f,1.5f,0.5f, 0,0,1};    mVertices.push_back(v38);

      Vertex v39{0.0f,1.0f,1.0f, 0,1,1};    mVertices.push_back(v39);
      Vertex v40{1.0f,1.0f,1.0f, 0,1,1};    mVertices.push_back(v40);
      Vertex v41{0.5f,1.5f,0.5f, 0,1,1};    mVertices.push_back(v41);

      Vertex v42{1.0f,1.0f,1.0f, 1,1,0};    mVertices.push_back(v42);
      Vertex v43{1.0f,1.0f,0.0f, 1,1,0};    mVertices.push_back(v43);
      Vertex v44{0.5f,1.5f,0.5f, 1,1,0};    mVertices.push_back(v44);

      Vertex v45{0.0f,1.0f,0.0f, 1,0,1};    mVertices.push_back(v45);
      Vertex v46{1.0f,1.0f,0.0f, 1,0,1};    mVertices.push_back(v46);
      Vertex v47{0.5f,1.5f,0.5f, 1,0,1};    mVertices.push_back(v47);

      //gulv
      Vertex v48{0.0f,0.0f,1.0f, 1,0,1};    mVertices.push_back(v48);
      Vertex v49{1.0f,0.0f,1.0f, 1,0,1};    mVertices.push_back(v49);
      Vertex v50{1.0f,0.0f,0.0f, 1,0,1};    mVertices.push_back(v50);

      Vertex v51{0.0f,0.0f,1.0f, 1,0,1};    mVertices.push_back(v51);
      Vertex v52{0.0f,0.0f,0.0f, 1,0,1};    mVertices.push_back(v52);
      Vertex v53{1.0f,0.0f,0.0f, 1,0,1};    mVertices.push_back(v53);



      mMatrix.setToIdentity();
}

hus::~hus()
{

}



void hus::init(GLint matrixUniform){
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

void hus::draw(){
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
