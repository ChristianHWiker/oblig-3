#ifndef HUS_H
#define HUS_H
#include "visualobject.h"

class hus: public VisualObject
{
public:
    hus();
    ~hus() override;
    void init(GLint matrixUniform) override;
    void draw() override;

};

#endif // HUS_H
