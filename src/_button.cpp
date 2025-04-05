#include "_button.h"

_button::_button()
{
    xMax = 1.0;
    xMin = 0.0;
    yMax = 1.0;
    yMin = 0.0;
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = -3.0;
    scale.x = -1.0;
    scale.y = 1.0;
    actionTrigger = 1;
}

_button::~_button()
{
    //dtor
}

void _button::initButton(char* filename)
{
    texture->loadTexture(filename);
}

void _button::drawButton(int width, int height)
{
    glColor3f(1.0,1.0,1.0);
    texture->textureBinder();

    glPushMatrix();
        glTranslatef(pos.x,pos.y,-2);

         glScalef(scale.x,scale.y,1.0);

         glBegin(GL_POLYGON);

          glTexCoord2f(xMin,yMin);
          glVertex3f(1.0,1.0,0);

          glTexCoord2f(xMax,yMin);
          glVertex3f(-1.0,1.0,0);

          glTexCoord2f(xMax,yMax);
          glVertex3f(-1.0,-1.0,0);

          glTexCoord2f(xMin,yMax);
          glVertex3f(1.0,-1.0,0);

    glEnd();
    glPopMatrix();
}

void _button::buttonAction()
{
    switch(actionTrigger)
    {
    case HOVER:
        std::cout << "Hover" << endl;
    break;

    case NOHOVER:
        std::cout << "No Hover" << endl;
    break;
    }
}

void _button::placeButton(float xPos, float yPos, float xScale, float yScale)
{
    pos.x = xPos;
    pos.y = yPos;

    scale.x = xScale;
    scale.y = yScale;
}
