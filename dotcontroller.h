#ifndef DOTCONTROLLER_H_INCLUDED
#define DOTCONTROLLER_H_INCLUDED

#include "dot.h"
#include <vector>

class DotController
{
    public:
        DotController() {}

        ~DotController() {}

        void service();

        void add( Dot *d );
    private:
        std::vector<Dot*> mDots;

        void collisions( std::vector<Dot*>::iterator toCheck );
};

#endif // DOTCONTROLLER_H_INCLUDED
