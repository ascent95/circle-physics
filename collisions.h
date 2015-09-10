#ifndef COLLISIONS_H_INCLUDED
#define COLLISIONS_H_INCLUDED

bool colliding( Dot *a, Dot *b );
void resolveCollision( Dot *a, Dot *b );
Vec2d find_n( Dot *a, Dot *b );
Vec2d find_u( Dot *a, Dot *b );
double dotProduct( Vec2d a, Vec2d b );

#endif // COLLISIONS_H_INCLUDED
