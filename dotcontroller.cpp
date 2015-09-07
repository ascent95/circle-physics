#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "dotcontroller.h"
#include "collisions.h"

void DotController::service()
{
    for( std::vector<Dot*>::iterator it = mDots.begin(); it != mDots.end(); ++it )
    {
        collisions( it );
        (**it).movement();
        (**it).render();
    }
}

void DotController::collisions( std::vector<Dot*>::iterator toCheck )
{
    Dot *start = *toCheck;
    toCheck++;
    for(; toCheck != mDots.end(); toCheck++ )
    {
        if( colliding( start, *toCheck ) )
        {
            printf( "Colliding!\n" );
        }
    }
}

void DotController::add( Dot *d )
{
    mDots.insert(mDots.end(), 1, d);
}
