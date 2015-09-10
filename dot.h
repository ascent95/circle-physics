#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include <SDL2/SDL.h>

struct Circle
{
    double x, y, r;
};

struct Vec2d
{
    double x, y;
};

class Dot
{
    public:

        Dot( int x, int y, int r, double vx, double vy, double restitution );

        ~Dot() {}

        bool render();

        void movement();

        Circle *getCircle();
        void setCircle( Circle *c );

        void setX( int argx );
        void setY( int argy );
        void setR( int argr );

        Vec2d *getVelocity();
        double getRestitution();
        double getInvMass();

    private:
        Circle mCirc;
        double mRestitution;
        Uint32 mTime;
        Vec2d mVelocity;
        double mInvMass;
};

#endif // DOT_H_INCLUDED
