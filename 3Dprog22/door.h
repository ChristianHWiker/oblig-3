#ifndef DOOR_H
#define DOOR_H
#include "visualobject.h"

class door :public VisualObject
{
public:
    door();
    ~door() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // DOOR_H
