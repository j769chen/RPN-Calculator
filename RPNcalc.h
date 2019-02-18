#ifndef RPNCALC_H_INCLUDED
#define RPNCALC_H_INCLUDED

#include "linkedlist.h"
#include <cmath>
#include <math.h>

class RPNcalc: public linkedlist {
    public:
        void operate(char c);
        void clearcalc();
};


#endif // RPNCALC_H_INCLUDED
