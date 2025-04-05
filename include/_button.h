#ifndef _BUTTON_H
#define _BUTTON_H
#include "_textureloader.h"

class _button
{
    public:
        _button();
        virtual ~_button();
        vec3 pos;
        _textureLoader* texture = new _textureLoader();
        vec2 scale;
        enum{HOVER, NOHOVER};
        int actionTrigger, xMax, xMin, yMax, yMin;

    void initButton(char*);
    void drawButton(int width, int height);
    void buttonAction();
    void placeButton(float xPos, float yPos, float xScale, float yScale);


    protected:

    private:
};

#endif // _BUTTON_H
