#ifndef TROPHY_H
#define TROPHY_H


#include "visualobject.h"

class Trophy : public VisualObject
{
public:
    Trophy();
    Trophy(float dx, float dy, float dz, float dr);
    ~Trophy() override;

    void init(GLint matrixUniform) override;
    void draw() override;
    void place(float dx, float dy, float dz, float dr);
    QVector3D getPosition() override;
    float getRadius() override;

private:
    /*
    struct {
        float mx, my, mz;
    } position;
    */
    QVector3D position;
    float mx, my, mz, mr;  //posisjon
};

#endif // TROPHY_H
