#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H
#include "visualobject.h"

class InteractiveObject : public VisualObject {
public:
   InteractiveObject();
   ~InteractiveObject() override;
   void init(GLint matrixUniform) override;
   void draw() override;

   void move(float x, float y, float z);

   float getRadius() override;
      QVector3D getPosition() override;

private:

    QVector3D position();
   float mx, my, mz,mr; // posisjon


//       float mx, my, mz, mr;
};

#endif // INTERACTIVEOBJECT_H
