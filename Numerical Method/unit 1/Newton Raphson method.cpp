#include <stdio.h>
#include <math.h>

#define F(x) (a3 * x * x * x + a2 * x * x + a1 * x + a0)
#define FD(x) (3 * a3 * x * x + 2 * a2 * x + a1)

float a0, a1, a2, a3;

int main()
{
    float x0, x1, fx0, fdx0, E, Era;
    int count = 0, max_iter = 1000;

    printf("Compiled by Sarfraj Alam\n");
    printf("Newton-Raphson Method\n\n");

    printf("Enter the coefficients a3, a2, a1 and a0: \n");
    scanf("%f%f%f%f", &a3, &a2, &a1, &a0);

    printf("Enter initial guess and Error: \n");
    scanf("%f%f", &x0, &E);

    while (count++ < max_iter)
    {
        fx0 = F(x0);
        fdx0 = FD(x0);

        if (fdx0 == 0.0)
        {
            printf("Mathematical error: Derivative is zero.\n");
            return 1;
        }

        x1 = x0 - (fx0 / fdx0);
        Era = fabs((x1 - x0) / x1);

        printf("Iter %d: x = %.6f, f(x) = %.6f, Error = %.6f\n", count, x1, fx0, Era);

        if (Era < E)
        {
            printf("\nRoot = %.6f\n", x1);
            return 0;
        }

        x0 = x1;
    }

    printf("Method did not converge in %d iterations.\n", max_iter);
    return 1;
}
