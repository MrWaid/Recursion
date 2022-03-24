#include "TXLib.h"

void Fractal (double x, double y, double a, int i);

int main ()
{
    txTextCursor (false);
    txCreateWindow (600, 600);

    Fractal (300, 300, 120, 5);

    return 0;
}

void Fractal (double x, double y, double a, int i)
{
    txSetColor (TX_WHITE);

    txLine (x-a, y, x+a, y);
    txLine (x-a, y-a, x-a, y+a);
    txLine (x+a, y-a, x+a, y+a);

    if (i > 0)
    {
        Fractal (x-a, y-a, a/2, i-1);
        Fractal (x-a, y+a, a/2, i-1);
        Fractal (x+a, y-a, a/2, i-1);
        Fractal (x+a, y+a, a/2, i-1);
    }
}
