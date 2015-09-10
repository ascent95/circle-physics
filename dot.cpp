#include "dot.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>

Dot::Dot( int x, int y, int r, double vx, double vy, double restitution )
{
    mCirc.x = x;
    mCirc.y = y;
    mCirc.r = r;
    mVelocity.x = vx;
    mVelocity.y = vy;
    mTime = SDL_GetTicks();
    if( restitution <= 1 && restitution >= 0 )
    {
        mRestitution = restitution;
    }
    else
    {
        mRestitution = 0;
    }
    mInvMass = 1 / ( M_PI * pow( r, 2 ) );
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
    mCirc.x += mVelocity.x * diffTime;
    mCirc.y += mVelocity.y * diffTime;
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

Vec2d *Dot::getVelocity()
{
    return &mVelocity;
}

double Dot::getRestitution()
{
    return mRestitution;
}

double Dot::getInvMass()
{
    return mInvMass;
}
