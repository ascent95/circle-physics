#include "dot.h"
#include "collisions.h"
#include <cmath>
#include <algorithm>

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

void resolveCollision( Dot *a, Dot *b )
{
    double maxRestitution = std::max( a->getRestitution(), b->getRestitution() );
    Vec2d n, u;
    n = find_n( a, b );
    u = find_u( a, b );
    printf( "n is (%f,%f) and u is (%f,%f) and e is %f\n", n.x, n.y, u.x, u.y, maxRestitution);
    if( u.x >= 0 && u.y >= 0 )
    {
        printf( "Already separating!\n" );
        return;
    }
    double j = ( 1 + maxRestitution ) * dotProduct( n, u );
    double ainv = a->getInvMass();
    double binv = b->getInvMass();

    j /= ainv + binv;

    Vec2d *va = a->getVelocity();
    Vec2d *vb = b->getVelocity();
    va->x += j * n.x * ainv;
    va->y += j * n.y * ainv;
    vb->x -= j * n.x * binv;
    vb->y -= j * n.y * binv;
    printf( "Final velocities: a is (%f, %f) and b is (%f, %f)\n", va->x, va->y, vb->x, vb->y );
}

//Assuming they are colliding
Vec2d find_n( Dot *a, Dot *b )
{
    Vec2d n;
    n.x = b->getCircle()->x - a->getCircle()->x;
    n.y = b->getCircle()->y - a->getCircle()->y;
    double mag = sqrt( pow( n.x, 2 ) + pow( n.y, 2 ) );
    n.x /= mag;
    n.y /= mag;
    return n;
}

Vec2d find_u( Dot *a, Dot *b )
{
    Vec2d u;
    u.x = b->getVelocity()->x - a->getVelocity()->x;
    u.y = b->getVelocity()->y - a->getVelocity()->y;
    return u;
}

double dotProduct( Vec2d a, Vec2d b )
{
    printf( "Dot product: %f * %f + %f * %f\n", a.x, b.x, a.y, b.y );
    return a.x * b.x + a.y * b.y;
}
