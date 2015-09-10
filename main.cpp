#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include "globals.h"
#include "dotcontroller.h"
#include "dot.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) )
    {
        printf( "SDL could not initialise! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Circles!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }
    return success;
}

int main( int argc, char **argv )
{
    if( !init() )
    {
        printf( "Could not initialise!\n");
    }
    else
    {
        bool quit = false;

        SDL_Event e;
        DotController dctl;
        Dot dotA ( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100, 10, 0, 0.05, 1 );
        Dot dotB ( SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2, 10, -0.05, 0, 1 );
        dctl.add( &dotA );
        dctl.add( &dotB );

        while( !quit )
        {
            while( SDL_PollEvent( &e ) )
            {
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }

            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //hollowDot.movement();
            //hollowDot.render();
            dctl.service();

            SDL_RenderPresent( gRenderer );
        }
    }
}
