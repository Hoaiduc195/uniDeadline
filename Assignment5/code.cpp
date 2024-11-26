#include <iostream>
using namespace std;

double solve(int *a, int n)
{
    if ((n % 2))
    {
        return a[(n / 2)];
    }
    else
    {
        return (a[n / 2 - 1] + a[(n / 2)]) / 2.0;
    }
}

void inputArray(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int *a;
    int n;
    inputArray(a, n);
    cout << solve(a, n) << endl;
    delete[] a;
    return 0;
}