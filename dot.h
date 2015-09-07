#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include <SDL2/SDL.h>

struct Circle
{
    double x, y, r;
};

class Dot
{
    public:

        Dot( int x, int y, int r, double vx, double vy );

        ~Dot() {}

        bool render();

        void movement();

        Circle *getCircle();
        void setCircle( Circle *c );

        void setX( int argx );
        void setY( int argy );
        void setR( int argr );

    private:
        Circle mCirc;
        double mvx, mvy;
        Uint32 mTime;
};

#endif // DOT_H_INCLUDED
