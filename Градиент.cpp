0#include "TXLib.h"

const int LENGTH = 1200;
const int WIDTH  = 600;

double Lerp   (double x1, double x2, double t);
void gradient (int x0, int y0, int x1, int y1, int r0, int g0, int b0, int r1, int g1, int b1);

int main ()
{

    const int NUMBER = LENGTH / 6;

	txCreateWindow (LENGTH, WIDTH);

	gradient (0*NUMBER, 0, 1*NUMBER, WIDTH, 255, 0,   0,   255, 255, 0);
	gradient (1*NUMBER, 0, 2*NUMBER, WIDTH, 255, 255, 0,   0,   255, 0);
	gradient (2*NUMBER, 0, 3*NUMBER, WIDTH, 0,   255, 0,   0,   255, 255);
	gradient (3*NUMBER, 0, 4*NUMBER, WIDTH, 0,   255, 255, 0,   0,   255);
	gradient (4*NUMBER, 0, 5*NUMBER, WIDTH, 0,   0,   255, 255, 0,   255);
	gradient (5*NUMBER, 0, 6*NUMBER, WIDTH, 255, 0,   255, 255, 0,   0);

    return 0;
}

void gradient (int x0, int y0, int x1, int y1, int r0, int g0, int b0, int r1, int g1, int b1)
{
	double r = r0, g = g0, b = b0;

    for (double t = 0; t < 1; t += 0.005)
    {
		b = Lerp (b0, b1, t);
		g = Lerp (g0, g1, t);
		r = Lerp (r0, r1, t);

		txSetColor (RGB (r, g, b));
		txLine     (Lerp (x0, x1, t), y0, Lerp (x0, x1, t), y1);
	}
}

double Lerp (double x1, double x2, double t)
{
    x1 = x1 + t * (x2 - x1);

    return x1;
}
