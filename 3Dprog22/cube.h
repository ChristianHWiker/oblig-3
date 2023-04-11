#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"

class Cube : public VisualObject
{
public:
    Cube();
    ~Cube() override;
    void init(GLint matrixUniform) override;
    void draw() override;

    void move(float x, float y, float z);


    void moveNotBad(float dt);
private:
    float mx, my, mz; // posisjon
};

#endif // CUBE_H
