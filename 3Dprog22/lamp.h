#ifndef LAMP_H
#define LAMP_H
#include "visualobject.h"

class lamp : public VisualObject
{
public:
    lamp();
    ~lamp() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // LAMP_H
