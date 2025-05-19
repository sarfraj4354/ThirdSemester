#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	cout << "Compiled by Sarfraj Alam\n";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int Xr, Yr, x1, y1, p, k = 0;
    cout << "Enter the x-radius of ellipse: ";
    cin >> Xr;
    cout << "Enter the y-radius of ellipse: ";
    cin >> Yr;
    cout << "Enter the centre coordinates of ellipse: ";
    cin >> x1 >> y1;
    p = pow(Yr, 2) - pow(Xr, 2) * Yr + 1 / 4 * pow(Xr, 2);
    int x = 0, y = Yr;
    while (2 * Yr * Yr * x < 2 * Xr * Xr * y)
    {
        putpixel(x + x1, y + y1, 1);
        putpixel(-x + x1, y + y1, 2);
        putpixel(x + x1, -y + y1, 3);
        putpixel(-x + x1, -y + y1, 4);
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * pow(Yr, 2) * x + pow(Yr, 2);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Yr, 2);
        }
        delay(50);
    }

    p = Yr * Yr * (x + 1 / 2) * (x + 1 / 2) + Xr * Xr * (y - 1) * (y - 1) - Xr * Xr * Yr * Yr;
    while (y >= 0)
    {
        putpixel(x + x1, y + y1, 1);
        putpixel(-x + x1, y + y1, 2);
        putpixel(x + x1, -y + y1, 3);
        putpixel(-x + x1, -y + y1, 4);
        if (p > 0)
        {
            y = y - 1;
            p = p - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        }
        delay(50);
    }
    getch();
    closegraph();
}                                      

