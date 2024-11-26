#include <iostream>
#include <limits>
using namespace std;

void inputArray(int **&a, int &n)
{
    cin >> n;
    a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[7];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> a[i][j];
        }
    }
}
void outputArray(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int **a, int n)
{
    int sum = 0;
    double avgSum;
    int sumR = 0;
    int max = -1;
    int min = numeric_limits<int>::max();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            sum += a[i][j];
            sumR += a[i][j];
        }
        if (sumR < min)
        {
            min = sumR;
        }
        if (sumR > max)
        {
            max = sumR;
        }
        sumR = 0;
    }
    avgSum = (1.0 * sum) / (n * 7 * 1.0);
    cout << avgSum << endl
         << min << endl
         << max << endl;
}

int main()
{
    int **monkeyReport;
    int n;
    inputArray(monkeyReport, n);
    outputArray(monkeyReport, n);
    solve(monkeyReport, n);

    return 0;
}