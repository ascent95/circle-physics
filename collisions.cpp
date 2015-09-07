#include "dot.h"

bool colliding( Dot *a, Dot *b )
{
    Circle *ca = a->getCircle();
    Circle *cb = b->getCircle();
    double rad = ca->r + cb->r;
    double diffx = cb->x - ca->x;
    double diffy = cb->y - ca->y;
    double dist = diffx * diffx + diffy * diffy;
    if( dist >= rad * rad )
    {
        return false;
    }
    else
    {
        return true;
    }
}
