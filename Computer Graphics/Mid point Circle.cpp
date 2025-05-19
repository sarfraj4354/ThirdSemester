#include <iostream>
#include <graphics.h>
#include <conio.h> // For getch()

void drawCircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, 7);
        putpixel(x0 + y, y0 + x, 7);
        putpixel(x0 - y, y0 + x, 7);
        putpixel(x0 - x, y0 + y, 7);
        putpixel(x0 - x, y0 - y, 7);
        putpixel(x0 - y, y0 - x, 7);
        putpixel(x0 + y, y0 - x, 7);
        putpixel(x0 + x, y0 - y, 7);

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

int main()
{
	std::cout << "Compiled by Sarfraj Alam\n";
    int gdriver = DETECT, gmode, error, x, y, r;
    initgraph(&gdriver, &gmode," ");

    std::cout << "Enter radius of circle: ";
    std::cin >> r;

    std::cout << "Enter coordinates of center (x and y): ";
    std::cin >> x >> y;

    drawCircle(x, y, r);

    getch();
    closegraph();
    return 0;
}

