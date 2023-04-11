#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QElapsedTimer>
#include <vector>
#include "vertex.h"
#include "trianglesurface.h"
#include "curve.h"
#include "visualobject.h"
#include "xyz.h"
#include "interactiveobject.h"
#include "camera.h"

class QOpenGLContext;
class Shader;
class Texture;
class MainWindow;

/// This inherits from QWindow to get access to the Qt functionality and
// OpenGL surface.
// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
// This is the same as using "glad" and "glw" from general OpenGL tutorials
class RenderWindow : public QWindow, protected QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow);
    ~RenderWindow() override;

    QOpenGLContext *context() { return mContext; }

    void exposeEvent(QExposeEvent *) override;  //gets called when app is shown and resized

    bool mRotate{true};     //Check if triangle should rotate

private slots:
    void render();          //the actual render - function

private:
    //QVertex m_v;
    std::vector<TriangleSurface*> TriangleObjects;
    std::vector<Curve*> CurveObjects;
    std::vector<XYZ*> XYZObjects;
    std::vector<InteractiveObject*> IntObjects;


    bool camera = false;
    bool open = false;

    bool keyPressed = false;

                         //

    QMatrix4x4 *mMVPmatrix{nullptr};      //  Erstatter denne med
    QMatrix4x4 *mPmatrix{nullptr};         // denne,
    QMatrix4x4 *mVmatrix{nullptr};         // og denne

    struct Controller
    {
        bool up{false};
        bool down{false};
        bool left{false};
        bool right{false};
    };


    Controller controller;

    float posArray[30] = {0.0f,  0.0f,  0.0f,
                    0.9f,  0.3f, 0.0f,
                    -0.5f, 0.2f, 0.0f,
                    -0.8f, 0.0f, 0.0f,
                    0.4f, -0.4f, 0.0f,
                    -0.7f, 0.0f, 0.0f,
                    0.3f, 0.2f, 0.0f,
                    0.5f,  0.3f, 0.0f,
                    0.5f,  0.2f, 0.0f,
                    -0.3f,  0.9f, 0.0f};

    InteractiveObject cube;
    TriangleSurface plane;
    Curve graph;

    struct Object
    {
        int type;
        std::vector<Vertex> vertex;
    };


    void init();            //initialize things we need before rendering

    VisualObject* mia;

    QOpenGLContext *mContext{nullptr};  //Our OpenGL context
    bool mInitialized{false};

    //Shader *mShaderProgram{nullptr};    //holds pointer the GLSL shader program
    GLint  mMatrixUniform;
    GLint  mPMatrixUniform;
    GLint  mVMatrixUniform;
                                //OpenGL reference to the Uniform in the shader program
    //GLint  mPmatrixUniform;
    //GLint  mVmatrixUniform;
    GLint  mMmdatrixUniform;
                         //
          // og denne

    GLuint mVAO;                        //OpenGL reference to our VAO
    GLuint mVBO;                        //OpenGL reference to our VBO

    //QMatrix4x4 *mMVPmatrix{nullptr};         //The matrix with the transform for the object we draw


    //Camera *mCurrentCamera{nullptr};

    void setupPlainShader(int shaderIndex);
    GLint mMatrixUniform0{-1};
    GLint vMatrixUniform0{-1};
    GLint pMatrixUniform0{-1};

    void setupTextureShader(int shaderIndex);
    GLint mMatrixUniform1{-1};
    GLint vMatrixUniform1{-1};
    GLint pMatrixUniform1{-1};
    GLint mTextureUniform{-1};

    Texture *mTexture[4]{nullptr};
    Texture *wallTexture;
    Shader  *mShaderProgram[4]{nullptr};

    Camera *mCurrentCamera{nullptr};

    std::vector<VisualObject*> mVisualObjects;

    std::vector<VisualObject*> mObjects;

    std::vector<VisualObject*> trophies;

    QTimer *mRenderTimer{nullptr};           //timer that drives the gameloop
    QElapsedTimer mTimeStart;               //time variable that reads the calculated FPS

    MainWindow *mMainWindow{nullptr};        //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger *mOpenGLDebugLogger{nullptr};  //helper class to get some clean debug info from OpenGL
    class Logger *mLogger{nullptr};         //logger - Output Log in the application

    ///Helper function that uses QOpenGLDebugLogger or plain glGetError()
    void checkForGLerrors();

    void calculateFramerate();          //as name says

    ///Starts QOpenGLDebugLogger if possible
    void startOpenGLDebugger();


protected:
    //The QWindow that we inherit from have these functions to capture
    // - mouse and keyboard.
    // Uncomment to use (you also have to make the definitions of
    // these functions in the cpp-file to use them of course!)
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    //    void mouseMoveEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent *event) override;              //the only one we use now
    //    void keyReleaseEvent(QKeyEvent *event) override{}
    //    void wheelEvent(QWheelEvent *event) override{}

    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // RENDERWINDOW_H
