#include "_collisionckeck.h"

_collisionCkeck::_collisionCkeck()
{
    //ctor
}

_collisionCkeck::~_collisionCkeck()
{
    //dtor
}
bool _collisionCkeck::isLinearCol(vec2, vec2)
{

}

bool _collisionCkeck::isRadialCol(vec3 p1, vec3 p2, float r1, float r2, float thrhld)
{
   return (sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2))-(r1+r2)<thrhld);
}

bool _collisionCkeck::isPlaneColButton(_button *b, int mouseX, int mouseY, double dimX, double dimY)
{
    // pass dim.x then change
    float mouseNormX = (mouseX/dimX)*2-1;
    float mouseNormY = 1-(mouseY/dimY)*2;

    // change to pass button
    float buttonLeft = b->pos.x - fabs(b->scale.x);
    float buttonRight = b->pos.x +fabs(b->scale.x);
    float buttonTop = b->pos.y + fabs(b->scale.y);
    float buttonBottom = b->pos.y -fabs(b->scale.y);

    /*std::cout << "Mouse Norm X: " << mouseNormX << " Y: " << mouseNormY << std::endl;
    std::cout << "Button Bounds: L=" << buttonLeft
          << " R=" << buttonRight
          << " T=" << buttonTop
          << " B=" << buttonBottom << std::endl;*/


    return (mouseNormX >= buttonLeft && // check if inside left bound
            mouseNormX <= buttonRight && // check if inside right bound
            mouseNormY >= buttonBottom && // check if inside bottom bound
            mouseNormY <= buttonTop); // check if inside top bound



}
bool _collisionCkeck::isPlaneCol(vec2 p, vec2 mousePos, int w, int h)
{

    return (mousePos.x >= p.x - w / 2 && mousePos.x <= p.x + w / 2 &&
            mousePos.y >= p.y - h / 2 && mousePos.y <= p.y + h / 2);
}

bool _collisionCkeck::isCubicCol(vec3, vec3)
{

}

bool _collisionCkeck::isSphereCol(vec3 p1, vec3 p2, float r1, float r2, float thrhld)
{
   return (sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)+pow((p1.z-p2.z),2))-(r1+r2)> thrhld);

}
