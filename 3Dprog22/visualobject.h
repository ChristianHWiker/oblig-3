#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H


#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"


class VisualObject : public QOpenGLFunctions_4_1_Core {
public:
   VisualObject();
   ~VisualObject();
   virtual void init(GLint matrixUniform)=0;
   virtual void draw()=0;
   // move for interaktive objekter
   virtual void move(float x, float y, float z) {  }
   // move for simulering (for eksempel NPC)
   virtual void move(float dt) { }

   void setTransformation(float x, float y, float z);



   virtual float getRadius() {}
   virtual QVector3D getPosition() {}
   void setRenderStyle(int input);
    void setPosition3D(QVector3D inPos);

   bool mRotate;

   QMatrix4x4 mMatrix;

protected:

       int renderValue;

   std::vector<Vertex> mVertices;
   std::vector<GLuint> mIndices;
   GLuint mVAO{0};
   GLuint mVBO{0};
   GLuint mEAB{0};
   GLint mMatrixUniform{0};

   // Velger å lagre posisjon, rotasjon og translasjon
   // i hver sin 4x4 matrise
   QMatrix4x4 mPosition;
   QMatrix4x4 mRotation;
   QMatrix4x4 mScale;
   // Legger til rette for simulering
   QVector3D mVelocity;
};
#endif // VISUALOBJECT_H
// VisualObject.cpp
//#include "visualobject.h"


//VisualObject::VisualObject() {  }
//VisualObject::~VisualObject() {
//   glDeleteVertexArrays( 1, &mVAO );
//   glDeleteBuffers( 1, &mVBO );
//}

//void VisualObject::setTransformation(float x, float y, float z)
//{
//    mMatrix.setToIdentity();
//    mMatrix.translate(x,y,z);
//}
