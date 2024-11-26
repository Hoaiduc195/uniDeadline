#include <iostream>
using namespace std;

void solve(int *&a, int &n)
{
    int *b = new int[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        if (i < n)
        {
            b[i] = a[i];
        }
        else
        {
            b[i] = 0;
        }
    }
    a = b;
    n *= 2;
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
void outputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *a;
    int n;
    inputArray(a, n);
    solve(a, n);
    outputArray(a, n);

    return 0;
}