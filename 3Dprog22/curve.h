#ifndef CURVE_H
#define CURVE_H

#include "visualobject.h"
#include "fstream"
#include "ostream"
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>


class Curve : public VisualObject
{
public:
   Curve();
   Curve(std::string filnavn);
   ~Curve() override;
   void graph();
   void readFile(std::string filnavn);
   void writeFile(std::string filnavn);
   void init(GLint shader) override;
   void draw() override;
};

#endif // CURVE_H
