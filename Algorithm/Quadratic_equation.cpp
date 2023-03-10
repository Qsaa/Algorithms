#include <iostream>

using namespace std;

void quadratic_equcation(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "multiple roots" << endl;
            }
            else
            {
                cout << "no roots" << endl;
            }
        }
        else
        {
            double ans = (static_cast<double>(-c)) / b;
            cout << ans << endl;
        }
    }
    else
    {
        long int D = b * b - 4 * a * c;
        if (D < 0)
        {
            cout << "no roots" << endl;
        }
        else
        {
            double sqrtD = sqrt(static_cast<double>(D));
            double ans1 = (-b - sqrtD) / (2 * a);
            double ans2 = (-b + sqrtD) / (2 * a);
            if (ans1 < ans2)
            {
                cout << ans1 << " " << ans2 << endl;
            }
            else
            {
                cout << ans2 << " " << ans1 << endl;
            }
        }
    }
}

void test_the_quadratic_equcation()
{
    quadratic_equcation(1, 2, 1);
    quadratic_equcation(1, 1, 1);
    quadratic_equcation(0, 1, 1);
    quadratic_equcation(0, 0, 1);
    quadratic_equcation(0, 0, 0);
    quadratic_equcation(-5, 4, 1);
}