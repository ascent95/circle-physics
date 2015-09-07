#include "dot.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

Dot::Dot( int x, int y, int r, double vx, double vy )
{
    mCirc.x = x;
    mCirc.y = y;
    mCirc.r = r;
    mvx = vx;
    mvy = vy;
    mTime = SDL_GetTicks();
}

bool Dot::render()
{
    bool success = true;
    if( circleRGBA( gRenderer, (int)mCirc.x, (int)mCirc.y, (int)mCirc.r, 0xFF, 0x00, 0xFF, 0xFF ) )
    {
        success = false;
    }
    return success;
}

void Dot::movement()
{
    Uint32 currTime = SDL_GetTicks();
    Uint32 diffTime = currTime - mTime;
    mCirc.x += mvx * diffTime;
    mCirc.y += mvy * diffTime;
    mTime = currTime;
}

Circle *Dot::getCircle()
{
    return &mCirc;
}

void Dot::setCircle( Circle *c )
{
    mCirc = *c;
}

