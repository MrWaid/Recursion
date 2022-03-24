#include "TXLib.h"
const int M = 800;
const int N = 600;
const int I = 100;

void Rec (double x1, double y1, double x2, double y2, double x3, double y3, int i )
{
    double k = 0.007;

	if (i > 0)
	{
		POINT tri[3] = {x1, y1, x2, y2, x3, y3};

		txSetFillColor (RGB (255/I * i, 255/I * i, 255/I * i));
		txSetColor     (RGB (255/I * i, 255/I * i, 255/I * i));

		txPolygon (tri, 3);

		Rec (x1 + k * (x3 - x1), y1 + k * (y3 - y1),
             x2 + k * (x1 - x2), y2 + k * (y1 - y2),
             x3 + k * (x2 - x3), y3 + k * (y2 - y3), i-1);
	}
}

int main()
{
	txCreateWindow(M, N);

	Rec (100, 100, 700, 100, 400, 500, I);

    return 0;
}
