//#include <GL/glew.h>
#include "texture.h"
#include "renderwindow.h"
#include <QTimer>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLDebugLogger>
#include <QKeyEvent>
#include <QStatusBar>
#include <QDebug>

#include <stdio.h>
#include <cmath>
#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>


#include <QTimer>
#include <QTime>
#include <QElapsedTimer>

#include <string>


#include "shader.h"
#include "mainwindow.h"
#include "logger.h"
#include "trianglesurface.h"
#include "xyz.h"
#include "hus.h"
#include "door.h"
#include "lamp.h"
#include "point.h"
#include "cube.h"
#include "trophy.h"


QElapsedTimer timer;
bool function1 = true;
int oldTime{};
int abc = 1;
float someValue = 0.0f;


RenderWindow::RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow)
    : mContext(nullptr), mInitialized(false), mMainWindow(mainWindow)

{
    timer.start();



    //This is sent to QWindow:
    setSurfaceType(QWindow::OpenGLSurface);
    setFormat(format);
    //Make the OpenGL context
    mContext = new QOpenGLContext(this);
    //Give the context the wanted OpenGL format (v4.1 Core)
    mContext->setFormat(requestedFormat());
    if (!mContext->create()) {
        delete mContext;
        mContext = nullptr;
        qDebug() << "Context could not be made - quitting this application";
    }

    //This is the matrix used to transform (rotate) the triangle
    //You could do without, but then you have to simplify the shader and shader setup
    mMVPmatrix = new QMatrix4x4{};
    mMVPmatrix->setToIdentity();    //1, 1, 1, 1 in the diagonal of the matrix

    mPmatrix = new QMatrix4x4{};
    mPmatrix->setToIdentity();

    mVmatrix = new QMatrix4x4{};
    mVmatrix->setToIdentity();


//    void setupTextureShader(int shaderIndex);
//    GLint mMatrixUniform{-1};
//    GLint vMatrixUniform{-1};
//    GLint pMatrixUniform{-1};
//    GLint mTextureUniform{-1};

//    Texture *mTexture[4]{nullptr};
//    Shader *mShaderProgram[4]{nullptr};


    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);


//    mObjects.push_back(new Curve());
//    mObjects.push_back(new XYZ());
//    mObjects.push_back(new Curve());
//    mObjects.push_back(new XYZ());
//    mObjects.push_back(new Curve());
//    mObjects.push_back(new XYZ());

    mObjects.push_back(new Cube());
 mObjects.push_back(new TriangleSurface());
 mObjects.push_back(new Curve());

//    mObjects.push_back(new XYZ());

  trophies.push_back(new Trophy(0.5f, 0.0f, -0.5f, 0.2));
  trophies.push_back(new Trophy(4.5f, 0.0f, 2.3f, 0.2));
  trophies.push_back(new Trophy(-2.5f, 0.0f, 1.0f, 0.2));
  trophies.push_back(new Trophy(3.2f, 0.0f, -2.5f, 0.2));
  trophies.push_back(new Trophy(-2.0f, 0.0f, 2.0f, 0.2));
  trophies.push_back(new Trophy(1.5f, 0.0f, 3.5f, 0.2));
  trophies.push_back(new Trophy(-3.0f, 0.0f, -2.3f, 0.2));
  trophies.push_back(new Trophy(-7.0f, 0.0f, -8.0f, 0.2));

  for (int i = 0; i < trophies.size(); i++) {
      mObjects.push_back(trophies[i]);
      trophies[i]->setRenderStyle(0);
  }


     mObjects.push_back(new lamp());


       mia = new InteractiveObject;
       mObjects.push_back(mia);

     mObjects.push_back(new hus());
     //if (open == false)
     mObjects.push_back(new door());


}

RenderWindow::~RenderWindow()
{
    //cleans up the GPU memory
    glDeleteVertexArrays( 1, &mVAO );
    glDeleteBuffers( 1, &mVBO );
}

//Simple global for vertices of a triangle - should belong to a class !
//static GLfloat vertices[] =
//{
    // Positions         // Colors
 //  -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
//   0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
//   0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top
//};

// Sets up the general OpenGL stuff and the buffers needed to render a triangle
void RenderWindow::init()
{
    //Get the instance of the utility Output logger
    //Have to do this, else program will crash (or you have to put in nullptr tests...)
    mLogger = Logger::getInstance();

    //Connect the gameloop timer to the render function:
    //This makes our render loop
    connect(mRenderTimer, SIGNAL(timeout()), this, SLOT(render()));
    //********************** General OpenGL stuff **********************

    //The OpenGL context has to be set.
    //The context belongs to the instanse of this class!
    if (!mContext->makeCurrent(this)) {
        mLogger->logText("makeCurrent() failed", LogType::REALERROR);
        return;
    }



    //just to make sure we don't init several times
    //used in exposeEvent()
    if (!mInitialized)
        mInitialized = true;

    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    //Print render version info (what GPU is used):
    //Nice to see if you use the Intel GPU or the dedicated GPU on your laptop
    // - can be deleted
    mLogger->logText("The active GPU and API:", LogType::HIGHLIGHT);
    std::string tempString;
    tempString += std::string("  Vendor: ") + std::string((char*)glGetString(GL_VENDOR)) + "\n" +
            std::string("  Renderer: ") + std::string((char*)glGetString(GL_RENDERER)) + "\n" +
            std::string("  Version: ") + std::string((char*)glGetString(GL_VERSION));
    mLogger->logText(tempString);


    mShaderProgram[0] = new Shader("../3Dprog22/plainvertex.vert","../3Dprog22/plainshader.frag");
    //QDebug() << "Plain shader program id: " << mShaderProgram[0]->getProgram();
    mShaderProgram[1] = new Shader("../3Dprog22/texturevertex.vert", "../3Dprog22/texturefragment.frag ");
    //QDebug()<<"Rexture shader program id: " << mShaderProgram[1]->getProgram();

    setupPlainShader(0);
    setupTextureShader(1);

    //******texture stuff: ****************

    wallTexture = new Texture((char*)("../Texture/wall"));
    wallTexture->loadTexture();
   //mTexture[1] = new Texture("../Texture/wall");

//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D), mTexture[0]->id();
//    glActiveTexture(GL_TEXTURE1);
//    glBindTexture(GL_TEXTURE_2D, mTexture[1]->id());

    //****** making the object to be drawn *******



    //Start the Qt OpenGL debugger
    //Really helpfull when doing OpenGL
    //Supported on most Windows machines - at least with NVidia GPUs
    //reverts to plain glGetError() on Mac and other unsupported PCs
    // - can be deleted
    startOpenGLDebugger();

    //general OpenGL stuff:
    glEnable(GL_DEPTH_TEST);            //enables depth sorting - must then use GL_DEPTH_BUFFER_BIT in glClear
    //    glEnable(GL_CULL_FACE);       //draws only front side of models - usually what you want - test it out!
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);    //gray color used in glClear GL_COLOR_BUFFER_BIT

    //Compile shaders:
    //NB: hardcoded path to files! You have to change this if you change directories for the project.
    //Qt makes a build-folder besides the project folder. That is why we go down one directory
    // (out of the build-folder) and then up into the project folder.

    //mShaderProgram = new Shader("../3Dprog22/plainshader.vert", "../3Dprog22/plainshader.frag");

    // Get the matrixUniform location from the shader
    // This has to match the "matrix" variable name in the vertex shader
    // The uniform is used in the render() function to send the model matrix to the shader
    // Flere matriser her! Skal legges inn i kameraklasse


//       mMatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "matrix" );
//       mPMatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "pmatrix" );
//       mVMatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "vmatrix" );


    for (auto it=mObjects.begin(); it!= mObjects.end(); it++)
        (*it)->init(mMatrixUniform);

   graph.init(mMatrixUniform);
   plane.init(mMatrixUniform);
   cube.init(mMatrixUniform);

   graph.writeFile("../3Dprog22/filnavn.txt");
   //graph.readFile("../3Dprog22/filnavn.txt");


    glBindVertexArray(0);       //unbinds any VertexArray - good practice
}




Point* MoveObject(float xValue)
{
    if (function1)
    {
    Point* pos = new Point(xValue, (-0.27 * pow(xValue, 3) - 2.33 * pow(xValue, 2) + 4 * xValue + 0), 0);
    return pos;
    }
    else
    {
     Point* pos = new Point(xValue, (-0.09 * pow(xValue, 2) + 0.76 * xValue + 1.65), 0);
     return pos;
    }

}

void RenderWindow::setupPlainShader(int shaderIndex){
    mMatrixUniform0= glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(),"mMatrix");
    vMatrixUniform0= glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(),"vMatrix");
    pMatrixUniform0= glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(),"pMatrix");
}

void RenderWindow::setupTextureShader(int shaderIndex){
    mMatrixUniform1 = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "mMatrix");
    vMatrixUniform1 = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "vMatrix");
    pMatrixUniform1 = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "pMatrix");
    mTextureUniform = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "textureSampler");
}

// Called each frame - doing the rendering!!!
void RenderWindow::render()
{

    timer.elapsed();
        int dt = timer.elapsed() - oldTime;
         oldTime = timer.elapsed();
         qDebug() << "The slow operation took" << dt << "milliseconds";

         int deltaTime = dt * abc;
         float deltaTime2 = deltaTime * 0.01f;

         someValue += deltaTime2;
         if (someValue >= 10)
         {
           abc = -abc;
         }
         else if (someValue <= -10)
         {
           abc = -abc;
         }

         Point *somePoint = MoveObject(someValue);

        mObjects[0]->mMatrix = QMatrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
        mObjects[0]->move(somePoint->xx, somePoint->yy, somePoint->zz);


    initializeOpenGLFunctions();    //must call this every frame it seems...

    //kamera
    mPmatrix->setToIdentity();
    mVmatrix->setToIdentity();
    mPmatrix->perspective(60, 4.0/3.0, 0.1, 10.0);

//    glUniformMatrix4fv( mPMatrixUniform, 1, GL_FALSE, mPmatrix->constData());
//    glUniformMatrix4fv( mVMatrixUniform, 1, GL_FALSE, mVmatrix->constData());


    //draws object
    {
        glUseProgram(mShaderProgram[0]->getProgram());

        glUniformMatrix4fv(vMatrixUniform0,1,GL_TRUE, mCurrentCamera->mVmatrix.constData());
        glUniformMatrix4fv(pMatrixUniform0,1,GL_TRUE, mCurrentCamera->mPmatrix.constData());
        glUniformMatrix4fv(mMatrixUniform0,1,GL_TRUE, mVisualObjects[0]->mMatrix.constData());

        mVisualObjects[0]->draw();

        glUseProgram(mShaderProgram[1]->getProgram());
        glUniformMatrix4fv(vMatrixUniform0,1,GL_TRUE, mCurrentCamera->mVmatrix.constData());
        glUniformMatrix4fv(pMatrixUniform0,1,GL_TRUE, mCurrentCamera->mPmatrix.constData());
        glUniformMatrix4fv(mMatrixUniform0,1,GL_TRUE, mVisualObjects[0]->mMatrix.constData());
        glUniform1i(mTextureUniform,1);
        mVisualObjects[1]->draw();
        mVisualObjects[1]->mMatrix.translate(.001f, .001f, -.001f);

    }


    //to open the door
    if(open == true){
        mObjects.pop_back();
        open = false;
    }

    qDebug() << *mPmatrix;
        // Flytter kamera
    if(camera == false)
       mVmatrix->translate(0, -2, -8);

    else if (camera == true)
        mVmatrix->translate(-0.5, -0.5, -1.0);

       // Flere matriser her! Skal legges i kameraklasse
       glUniformMatrix4fv( mPMatrixUniform, 1, GL_FALSE, mPmatrix->constData());
       glUniformMatrix4fv( mVMatrixUniform, 1, GL_FALSE, mVmatrix->constData());


    //mMVPmatrix->setToIdentity();

    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this); //must be called every frame (every time mContext->swapBuffers is called)



    //clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //what shader to use
    //glUseProgram(mShaderProgram[shaderIndex]->getProgram());

    int i{};

    for (auto it=mObjects.begin(); it!= mObjects.end(); it++)
    {
//        (*it)->setTransformation(posArray[i], posArray[i+1], posArray[i+2] );
//        i++;
        (*it)->draw();
    }

    //cube.draw();
    //graph.draw();
    //plane.draw();

    //Calculate framerate before
    // checkForGLerrors() because that call takes a long time
    // and before swapBuffers(), else it will show the vsync time
    calculateFramerate();

    //using our expanded OpenGL debugger to check if everything is OK.
    checkForGLerrors();

    //Qt require us to call this swapBuffers() -function.
    // swapInterval is 1 by default which means that swapBuffers() will (hopefully) block
    // and wait for vsync.
    mContext->swapBuffers(this);

    //just to make the triangle rotate - tweak this:
    //                   degree, x,   y,   z -axis
        if(mRotate)
           mMVPmatrix->rotate(2.f, 0.f, 1.0, 0.f);
//    if(mRotate)
//         InteractiveObject.rotate(90);

        for (int i = 0; i < trophies.size(); i++)
                {
                    float distance = trophies[i]->getPosition().distanceToPoint(mia->getPosition());
                    //float distance = mia->getPosition().distanceToPoint(trophies[i]->getPosition());
                    mLogger->logText("Object " + std::to_string(i) + ": " + std::to_string(distance));

                    if (distance < mia->getRadius() + trophies[i]->getRadius())
                    {
                        mLogger->logText("Collisions!!!");
                        trophies[i]->setRenderStyle(1);
                    }
                }


}




//This function is called from Qt when window is exposed (shown)
// and when it is resized
//exposeEvent is a overridden function from QWindow that we inherit from
void RenderWindow::exposeEvent(QExposeEvent *)
{
    //if not already initialized - run init() function - happens on program start up
    if (!mInitialized)
        init();

    //This is just to support modern screens with "double" pixels (Macs and some 4k Windows laptops)
    const qreal retinaScale = devicePixelRatio();

    //Set viewport width and height to the size of the QWindow we have set up for OpenGL
    glViewport(0, 0, static_cast<GLint>(width() * retinaScale), static_cast<GLint>(height() * retinaScale));

    //If the window actually is exposed to the screen we start the main loop
    //isExposed() is a function in QWindow
    if (isExposed())
    {
        //This timer runs the actual MainLoop
        //16 means 16ms = 60 Frames pr second (should be 16.6666666 to be exact...)
        mRenderTimer->start(16);
        mTimeStart.start();
    }
}

//The way this function is set up is that we start the clock before doing the draw call,
// and check the time right after it is finished (done in the render function)
//This will approximate what framerate we COULD have.
//The actual frame rate on your monitor is limited by the vsync and is probably 60Hz
void RenderWindow::calculateFramerate()
{
    long nsecElapsed = mTimeStart.nsecsElapsed();
    static int frameCount{0};                       //counting actual frames for a quick "timer" for the statusbar

    if (mMainWindow)            //if no mainWindow, something is really wrong...
    {
        ++frameCount;
        if (frameCount > 30)    //once pr 30 frames = update the message == twice pr second (on a 60Hz monitor)
        {
            //showing some statistics in status bar
            mMainWindow->statusBar()->showMessage(" Time pr FrameDraw: " +
                                                  QString::number(nsecElapsed/1000000.f, 'g', 4) + " ms  |  " +
                                                  "FPS (approximated): " + QString::number(1E9 / nsecElapsed, 'g', 7));
            frameCount = 0;     //reset to show a new message in 30 frames
        }
    }
}

//Uses QOpenGLDebugLogger if this is present
//Reverts to glGetError() if not
void RenderWindow::checkForGLerrors()
{
    if(mOpenGLDebugLogger)  //if our machine got this class to work
    {
        const QList<QOpenGLDebugMessage> messages = mOpenGLDebugLogger->loggedMessages();
        for (const QOpenGLDebugMessage &message : messages)
        {
            if (!(message.type() == message.OtherType)) // get rid of uninteresting "object ...
                                                        // will use VIDEO memory as the source for
                                                        // buffer object operations"
                // valid error message:
                mLogger->logText(message.message().toStdString(), LogType::REALERROR);
        }
    }
    else
    {
        GLenum err = GL_NO_ERROR;
        while((err = glGetError()) != GL_NO_ERROR)
        {
            mLogger->logText("glGetError returns " + std::to_string(err), LogType::REALERROR);
            switch (err) {
            case 1280:
                mLogger->logText("GL_INVALID_ENUM - Given when an enumeration parameter is not a "
                                "legal enumeration for that function.");
                break;
            case 1281:
                mLogger->logText("GL_INVALID_VALUE - Given when a value parameter is not a legal "
                                "value for that function.");
                break;
            case 1282:
                mLogger->logText("GL_INVALID_OPERATION - Given when the set of state for a command "
                                "is not legal for the parameters given to that command. "
                                "It is also given for commands where combinations of parameters "
                                "define what the legal parameters are.");
                break;
            }
        }
    }
}

//Tries to start the extended OpenGL debugger that comes with Qt
//Usually works on Windows machines, but not on Mac...
void RenderWindow::startOpenGLDebugger()
{
    QOpenGLContext * temp = this->context();
    if (temp)
    {
        QSurfaceFormat format = temp->format();
        if (! format.testOption(QSurfaceFormat::DebugContext))
            mLogger->logText("This system can not use QOpenGLDebugLogger, so we revert to glGetError()",
                             LogType::HIGHLIGHT);

        if(temp->hasExtension(QByteArrayLiteral("GL_KHR_debug")))
        {
            mLogger->logText("This system can log extended OpenGL errors", LogType::HIGHLIGHT);
            mOpenGLDebugLogger = new QOpenGLDebugLogger(this);
            if (mOpenGLDebugLogger->initialize()) // initializes in the current context
                mLogger->logText("Started Qt OpenGL debug logger");
        }
    }
}

//Event sent from Qt when program receives a keyPress
// NB - see renderwindow.h for signatures on keyRelease and mouse input
void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        mMainWindow->close();       //Shuts down the whole program
    }

    //You get the keyboard input like this
        if(event->key() == Qt::Key_A)
        {
            mia->move(-0.5f,0.0f,0.0f);

        }

        if(event->key() == Qt::Key_S)
        {
            mia->move(0.0f,0.0f,0.5f);

        }

        if(event->key() == Qt::Key_D)
        {
            mia->move(0.5f,0.0f,0.0f);

        }

        if(event->key() == Qt::Key_W)
        {
            mia->move(0.0f,0.0f,-0.5f);

        }
           // if (event->key() == Qt::Key_A) controller.left = true;
//            if (event->key() == Qt::Key_D) controller.right = true;
//            if (event->key() == Qt::Key_W) controller.up = true;
//            if (event->key() == Qt::Key_S) controller.down = true;

    if (event->key() == Qt::Key_T){
        camera = true;
    }

    if(event ->key()== Qt::Key_O){
        open = true;
    }

    if (event->key() == Qt::Key_E)
        {
            function1 = !function1;
        }

}

void RenderWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A) controller.left = false;
    if (event->key() == Qt::Key_D) controller.right = false;
    if (event->key() == Qt::Key_W) controller.up = false;
    if (event->key() == Qt::Key_S) controller.down = false;
}
