#ifndef POINT_H
#define POINT_H

#include "visualobject.h"

class Point : public VisualObject
{
public:
    Point(float x, float y, float z);
      ~Point() override;
    void init(GLint matrixUniform);
    void draw();

float xx, yy, zz;

};

#endif // POINT_H
