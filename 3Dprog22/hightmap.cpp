#include "hightmap.h"
#include <cmath>
#include <math.h>
#include <stdlib.h>

Hightmap::Hightmap()
{

}

Hightmap::~Hightmap()
{

}

//QVector3D Hightmap:: Bary(const QVector2D playerpos, const QVector2D P, const QVector2D Q, const QVector2D R){
//    QVector2D PQ = Q -P;
//    QVector2D PR = R-P;

//    QVector3D PQR = crossProduct2D(PQ,PR);
//    float normalPQR = PQR.length();

//    QVector3D Bary = QVector3D();

//    QVector2D XP = P - playerpos;
//    QVector2D XQ = Q - playerpos;

//    Bary.SetX(crossProduct2D(XP,XQ).z()/normalPQR);

//    QVector2D XR = R - playerpos;

//    Bary.SetY(crossProduct2D(XQ,XR).z() / normalPQR);

//    Bary.SetZ(crossProduct2D(XR,XP).z()/normawlPQR);

//    return Bary;
//}

void Hightmap::init(GLint matrixUniform)
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

void Hightmap::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_LINES, 0, mVertices.size());
}
