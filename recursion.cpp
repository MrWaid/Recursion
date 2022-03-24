#include "TXLib.h"

struct Figure
{
    double x_, y_;
    int mice_;

    Figure ();

    void Mouse ();
};

const int LENGTH = GetSystemMetrics (SM_CXSCREEN) - 200 - GetSystemMetrics (SM_CXSCREEN) % 100;
const int WIDTH = GetSystemMetrics (SM_CYSCREEN) - 100 - GetSystemMetrics (SM_CYSCREEN) % 100;

void Square (Figure Tops[], int number,
             int t, double K);

int main ()
{
    srand (time(0));

    double K = 0.11;
    double dk = 0.01;

    txCreateWindow (LENGTH, WIDTH, false);
    txTextCursor (false);

    int number = 0;
    printf ("Введите количество вершин многоугольника!\n");
    scanf  ("%d", &number);

    if (number == 0)
    {
        printf("Неверный ввод! Запустите заново!");
        txSleep (500);
        return 0;
    }

    printf ("Чтобы выйти, нажмите ESCAPE");
    Figure Tops[number];

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin ();

        txSetFillColor (TX_BLACK);
        txClear ();

        Square (Tops, number, 20, K);

        for (int i = 0; i < number; i ++)
        {
            txSetColor     (TX_BLUE);
            txSetFillColor (TX_BLUE);
            txCircle (Tops[i].x_, Tops[i].y_, 15);

            txSetColor (TX_RED);
            char str[10];
			sprintf(str, "%d", i + 1);
			txDrawText (Tops[i].x_ - 15, Tops[i].y_ - 15, Tops[i].x_ + 15, Tops[i].y_ + 15, str);
        }

        txEnd ();

        K = K + dk;
        if (K >= 0.95 || K <= 0.05) dk *= -1;

        for (int i = 0; i < number; i ++)
        {
            Tops[i].Mouse ();
        }
    }

    return 0;
}

void Square (Figure Tops[], int number,
             int t, double K)
{
    txSetColor (RGB (255, 255, 255), 5);

    Figure Copy[number];

    for (int i = 0; i < number; i ++)
    {
        txLine (Tops[i].x_, Tops[i].y_, Tops[(i + 1) % number].x_, Tops[(i + 1) % number].y_);

        Copy[i].x_ = Tops[i].x_ + (Tops[(i + 1) % number].x_ - Tops[i].x_) * K;
        Copy[i].y_ = Tops[i].y_ + (Tops[(i + 1) % number].y_ - Tops[i].y_) * K;
    }

    if (t >= 0) Square (Copy, number, t - 1, K);
}

void Figure::Mouse ()
{
    if (txMouseButtons () & 1)
    {
        if (((txMouseX () - x_) * (txMouseX () - x_) + (txMouseY () - y_) * (txMouseY () - y_)
            <= 15 * 15) || mice_ == 1)
        {
            mice_ = 1;
            x_ = txMouseX ();
            y_ = txMouseY ();
        }
    }
    else mice_ = 0;
}

Figure::Figure ():
    x_ (random (10, LENGTH - 10)),
    y_ (random (10, WIDTH  - 10)),
    mice_ (0)
    {}
