#include <stdio.h>
#include <math.h>
float f(float x)
{
    // return exp(-x * x);
     return sqrt(x);
}
int main()
{
    int n, m, i;
    float a, b, h, sum = 0.0, ics, x;
    printf("Compiled by Sarfraj Alam\n");
    printf("composite Simpson's 3 by 8 rule\n");
    printf("\n Give lower & upper limits  a,b :");
    scanf("%f %f", &a, &b);
    do
    {
        printf("\n Give number of segments n(divisible by 3):");
        scanf("%d", &n);
    } while (n % 3 != 0);
    
    h = (b - a) / n;
    m = n / 3;
    for (i = 1; i <= m; i++)
    {
        x = a + (3 * i - 2) * h;
        sum = sum + 3 * (f(x) + f(x + h));
        if (i != m)
            sum = sum + 2 * f(x + 2 * h);
    }
    sum = sum + f(a) + f(b);
    ics = sum * 3 * h / 8.0;
    printf("\nIntegration between %f and %f when h = %f is %f.", a, b, h, ics);
    return 0;
}
