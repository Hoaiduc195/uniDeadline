#include <iostream>

using namespace std;

void inputArray(int *&a, int& n)
{
    cin>>n;
    a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void dispArray(int *a, int n)
{
    if(!n)
    {
        return;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int solve(int *a, int n)
{
    if(!n)
    {
        return -1;
    }
    int *tick;
    int max = -1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }

    tick = new int[max+1];

    for(int i=0;i<max+1;i++)
    {
        tick[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        tick[a[i]]++;
    }
    int tickMax = -1;
    int idx = -1;
    for(int i=0;i<max+1;i++)
    {
        if(tick[i]>tickMax)
        {
            tickMax = tick[i];
            idx = i;
        }
    }
    if(tickMax == 1)
    {
        return -1;
    }
    return idx;

}

int main()
{
    int *a = nullptr;
    int n;
    inputArray(a,n);
    dispArray(a,n);
    cout<<solve(a,n)<<endl;

    return 0;
}