#ifndef HIGHTMAP_H
#define HIGHTMAP_H

#include "visualobject.h"

class Hightmap : public VisualObject
{
public:
    Hightmap();
       ~Hightmap() override;
       void init(GLint matrixUniform) override;
       void draw() override;
    QVector3D Bary(const QVector2D playerpos, const QVector2D P, const QVector2D Q, const QVector2D R);


};

#endif // HIGHTMAP_H
