//#ifndef TEXTURE_H
#define TEXTURE_H

#include "stb_image.h"
#include <qopenglfunctions_4_1_core.h>

class Texture : protected QOpenGLFunctions_4_1_Core
{
public:
Texture();
Texture(char* fileLoc); // getting the address and name of the file in constructor

void loadTexture();
void useTexture();
void clearTexture();
~Texture();

private:
GLuint textureID; // each texture needs to have an ID
int width, height, bitDepth; //size of the texture and pixels (texel)
char* fileLocation;
};
