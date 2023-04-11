#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H


#include "visualobject.h"
#include "fstream"
#include "ostream"
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>


class TriangleSurface : public VisualObject
{
public:
   TriangleSurface();
   TriangleSurface(std::string filnavn);
   ~TriangleSurface() override;
   void graph();
   void readFile(std::string filnavn);
   void writeFile(std::string filnavn);
   void init(GLint shader) override;
   void draw() override;
};

#endif // TRIANGLESURFACE_H
