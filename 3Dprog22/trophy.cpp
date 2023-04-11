#include "trophy.h"



Trophy::Trophy()
{

}

Trophy::Trophy(float dx, float dy, float dz, float dr) : mx{0.0f}, my{0.0f}, mz{0.0f}
{
    Vertex v0{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v0);
    Vertex v1{-0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v1);
    Vertex v2{ 0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v2);
    Vertex v3{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v3);
    Vertex v4{-0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v4);
    Vertex v5{ 0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};      mVertices.push_back(v5);
    Vertex v6{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v6);
    Vertex v7{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v7);
    Vertex v8{ 0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v8);
    Vertex v9{ 0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v9);
    Vertex v10{ 0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v10);
    Vertex v11{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v11);
    Vertex v12{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v12);
    Vertex v13{-0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v13);
    Vertex v14{-0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v14);
    Vertex v15{ 0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v15);
    Vertex v16{-0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v16);
    Vertex v17{-0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v17);
    Vertex v18{-0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v18);
    Vertex v19{-0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v19);
    Vertex v20{ 0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v20);
    Vertex v21{ 0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v21);
    Vertex v22{ 0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v22);
    Vertex v23{ 0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v23);
    Vertex v24{ 0.2f, 0.0f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v24);
    Vertex v25{ 0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v25);
    Vertex v26{ 0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v26);
    Vertex v27{ 0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v27);
    Vertex v28{ 0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v28);
    Vertex v29{-0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v29);
    Vertex v30{ 0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v30);
    Vertex v31{-0.2f, 0.4f,-0.2f, 1.0f, 0.0f, 0.0f};   mVertices.push_back(v31);
    Vertex v32{-0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v32);
    Vertex v33{ 0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v33);
    Vertex v34{-0.2f, 0.4f, 0.2f, 1.0f, 0.0f, 0.0f};    mVertices.push_back(v34);
    Vertex v35{ 0.2f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f};     mVertices.push_back(v35);

    mMatrix.setToIdentity();
    place(dx, dy, dz, dr);
}

Trophy::~Trophy()
{

}

void Trophy::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;
    initializeOpenGLFunctions();

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER,
                 mVertices.size() * sizeof(Vertex),
                 mVertices.data(),
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          reinterpret_cast<GLvoid*>(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          reinterpret_cast<GLvoid*>(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Trophy::draw()
{
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());

    switch (renderValue)
    {
    case 0:
        // Visible
        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
        break;
    case 1:
        // Invisible
        glDrawArrays(GL_POINTS, 0, mVertices.size());
        break;
    default:
        break;
    }


}

void Trophy::place(float dx, float dy, float dz, float dr)
{
    mx += dx;
    my += dy;
    mz += dz;
    mr += dr;

//    qDebug() << "move";
    mMatrix.translate(dx, dy, dz);
}

float Trophy::getRadius()
{
    return mr;
}

QVector3D Trophy::getPosition()
{
    return mMatrix.column(3).toVector3D();
}
