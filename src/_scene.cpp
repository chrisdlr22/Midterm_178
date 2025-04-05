#include "_scene.h"
#include "_parallax.h"
#include "_button.h"
#include "_inputs.h"
#include "_collisionckeck.h"

_parallax* bg = new _parallax();
_button* butt = new _button();
_inputs* inputs = new _inputs();
_collisionCkeck* collision = new _collisionCkeck();

double mouseX, mouseY;

_scene::_scene()
{
    //ctor
}

_scene::~_scene()
{
    //dtor
}

GLint _scene::initGL()
{
   glClearColor(1.0,1.0,1.0,1.0);
   glClearDepth(1.0);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);

   glEnable(GL_BLEND); // take off the transparent background
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

  // glEnable(GL_COLOR_MATERIAL);
  // myLight->setLight(GL_LIGHT0);

   dim.x = GetSystemMetrics(SM_CXSCREEN);
   dim.y = GetSystemMetrics(SM_CYSCREEN);

   bg->initPrlx("images/jungle.png");
   butt->initButton("images/playbutton.png");
   butt->placeButton(0.0,0.0,-0.5,0.5);
   return true;
}

void _scene::reSize(GLint width, GLint height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
    // keep track of the resize window
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);  // perspective projection settings
    glLoadIdentity();             // identity matrix
    gluPerspective(45,aspectRatio,0.1,100.0); // projection settings
    glMatrixMode(GL_MODELVIEW);   // camera and model settings
    glLoadIdentity();             // identity matrix

    dim.x = GetSystemMetrics(SM_CXSCREEN);
    dim.y = GetSystemMetrics(SM_CYSCREEN);
}

void _scene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // bg->drawBackground(dim.x,dim.y);
    butt->drawButton(200,400);
    butt->buttonAction();

    if(collision->isPlaneColButton(butt, mouseX, mouseY, dim.x, dim.y))
    {
        butt->actionTrigger = butt->HOVER;
    }
    else
        butt->actionTrigger = butt->NOHOVER;


    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);

    glPushMatrix();
    glPointSize(10.0);
    glBegin(GL_POINTS);
        glColor3f(1,0,0); // red dot
        glVertex3f((mouseX / dim.x) * 2 - 1, 1 - (mouseY / dim.y) * 2, -2);
    glEnd();
glPopMatrix();

    glEnable(GL_BLEND);

}


int _scene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_KEYDOWN:

        inputs->wParam = wParam;
        inputs->keyPressed(butt);

        break;

    case WM_KEYUP: break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:

        break;
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:

        break;
    case WM_MOUSEMOVE:
        mouseX = LOWORD(lParam);
        mouseY = HIWORD(lParam);
        //cout << "\nMOUSE X: " << mouseX << " MOUSE Y: " << mouseY;
        //cout << "\nBUTTONPOSX: " << butt->pos.x << " BUTTONPOSY: " << butt->pos.y;
        //cout << "\nOFFSET X: " << mouseX - butt->pos.x << " OFFSET Y: " << mouseY - butt->pos.y;
        break;
    case WM_MOUSEWHEEL:

        break;
    }
}

