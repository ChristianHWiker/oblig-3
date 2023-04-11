#ifndef PHONG_H
#define PHONG_H

#include "shader.h"
#include "visualobject.h"

class Phong : public VisualObject
{
public:
    Phong();

    virtual void init(GLint matrixUniform) override;
        virtual void draw() override;



    GLfloat ambientStrength{ 0.3f };
    QVector3D ambientColour{ 0.3f, 0.3f, 0.3f };

    GLfloat lightStrength{ 0.7f };
    QVector3D lightColour{ 1.0f, 0.0f, 0.0f };

    GLfloat specularStrength{ 0.9f };
    GLint specularExponent{ 4 };
private:
    float mx, my, mz, mr;
};

#endif // PHONG_H
