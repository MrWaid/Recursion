#include "TXLib.h"

void Square (double x, double y, double a, int i);

int main ()
{
    txCreateWindow (600, 600);

    Square (300, 300, 120, 12);

    return 0;
}

void Square (double x, double y, double a, int i)
{
    txSetColor     (TX_WHITE);
    txSetFillColor (TX_WHITE);

    txRectangle (x-a, y-a, x+a, y+a);

    if (i > 0)
    {
        if (txGetPixel (x-a-1, y-a-1) != TX_WHITE) Square (x-a, y-a, a/2, i-1);
        if (txGetPixel (x-a-1, y+a+1) != TX_WHITE) Square (x-a, y+a, a/2, i-1);
        if (txGetPixel (x+a+1, y-a-1) != TX_WHITE) Square (x+a, y-a, a/2, i-1);
        if (txGetPixel (x+a+1, y+a+1) != TX_WHITE) Square (x+a, y+a, a/2, i-1);
    }
}
