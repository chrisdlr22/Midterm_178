#ifndef _COLLISIONCKECK_H
#define _COLLISIONCKECK_H

#include<_common.h>
#include<_button.h>

class _collisionCkeck
{
    public:
        _collisionCkeck();
        virtual ~_collisionCkeck();

        bool isLinearCol(vec2, vec2); // xy positions of the objects
        bool isRadialCol(vec3, vec3, float, float,float); // positions of objects,radius, threshold
        bool isPlaneCol(vec2, vec2, int, int);

        bool isCubicCol(vec3,vec3);// x,y,z components of cubes
        bool isSphereCol(vec3,vec3,float,float, float);
        bool isPlaneColButton(_button *b, int, int, double dimX, double dimY);


    protected:

    private:
};

#endif // _COLLISIONCKECK_H
