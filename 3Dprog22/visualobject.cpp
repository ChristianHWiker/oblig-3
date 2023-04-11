// VisualObject.cpp
#include "visualobject.h"


VisualObject::VisualObject() {  }
VisualObject::~VisualObject() {
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}

void VisualObject::setTransformation(float x, float y, float z)
{
    mMatrix.setToIdentity();
    mMatrix.translate(x,y,z);
}

void VisualObject::setRenderStyle(int input)
{
    renderValue = input;
}



void VisualObject::setPosition3D(QVector3D inPos)
{
    auto V4D = mMatrix.column(3);
    V4D.setX(inPos.x());
    V4D.setY(inPos.y());
    V4D.setZ(inPos.z());
    mMatrix.setColumn(3, V4D);
}
