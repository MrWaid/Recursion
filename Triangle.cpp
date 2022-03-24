#include "TXLib.h"

void Triangle (double x1, double y1,
               double x2, double y2,
               double x3, double y3,
               int i);

int main ()
{
    txTextCursor (false);
    txCreateWindow (600, 600);

    Triangle (300, 150, 100, 500, 500, 500, 12);

    return 0;
}

void Triangle (double x1, double y1,
               double x2, double y2,
               double x3, double y3,
               int i)
{
    txSetColor (TX_WHITE);

    txLine (x1, y1, x2, y2);
    txLine (x1, y1, x3, y3);
    txLine (x2, y2, x3, y3);

    if (i > 0)
    {
        Triangle (x1 - (x1-x2)/2, y1 - (y1-y2)/2,
                  x1 - (x1-x3)/2, y1 - (y1-y3)/2,
                  x1, y1, i - 1);
        Triangle (x2 - (x2-x1)/2, y2 - (y2-y1)/2,
                  x2 - (x2-x3)/2, y2 - (y2-y3)/2,
                  x2, y2, i - 1);
        Triangle (x3 - (x3-x1)/2, y3 - (y3-y1)/2,
                  x3 - (x3-x2)/2, y3 - (y3-y2)/2,
                  x3, y3, i - 1);
    }
}
