#define STB_IMAGE_IMPLEMENTATION
#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <string.h>



int main(int argc, char *argv[])
{


//    Texture texture1Melon; // create an instance/object of the Texture class
//    GLfloat deltaTime = 0.0f; // you can use this method to slow down the frames
//    // it is shown how to use it in while loop
//    GLfloat lastTime = 0.0f;
//    // Vertex Shader
//    static const char* vShader = "Shaders/shader.vert";
//    // Fragment Shader
//    static const char* fShader = "Shaders/shader.frag";
//    void CreateObjects()
//    {
//    // cube indices // if you have triangle or other shapes this may be differ
//    GLuint indices[] = {
//    0, 1, 2, 2, 3, 0, // Front face
//    4, 5, 6, 6, 7, 4, // Back face
//    8, 9, 10, 10, 11, 8, // Left face
//    12, 13, 14, 14, 15, 12, // Right face
//    16, 17, 18, 18, 19, 16, // Top face
//    20, 21, 22, 22, 23, 20 // Bottom face
//    };
//    // example of trangle or pyramid vertices
//    GLfloat vertices[] = {
//    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//    0.0f, -1.0f, 1.0f, 0.5f, 0.0f,
//    1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
//    0.0f, 1.0f, 0.0f, 0.5f, 1.0f
//    };
//    // Define cube vertices and texture coordinates
//    // U & V are texture coordinates
//    GLfloat Cubevertices[] = {
//    // Front face //U //V
//    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // Bottom-left
//    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // Bottom-right
//    0.5f, 0.5f, 0.5f, 1.0f, 1.0f, // Top-right
//    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, // Top-left
//    // Back face
//    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // Bottom-left
//    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // Bottom-right
//    0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // Top-right
//    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, // Top-left
//    // Left face
//    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // Top-right
//    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // Top-left
//    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // Bottom-left
//    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // Bottom-right
//    // Right face
//    0.5f, 0.5f, 0.5f, 0.0f, 0.0f, // Top-left
//    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, // Top-right
//    0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // Bottom-right
//    0.5f, -0.5f, 0.5f, 0.0f, 1.0f, // Bottom-left
//    // Top face
//    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, // Bottom-left
//    0.5f, 0.5f, 0.5f, 1.0f, 1.0f, // Bottom-right
//    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, // Top-right
//    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, // Top-left
//    // Bottom face
//    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // Top-left
//    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // Top-right
//    0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // Bottom-right
//    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f // Bottom-left
//    };





    //Forces the usage of desktop OpenGL - Qt uses OpenGL ES as default
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes a Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    return a.exec();
}
