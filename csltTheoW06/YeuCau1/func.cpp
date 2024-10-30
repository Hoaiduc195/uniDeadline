#include <iostream>
#include <string.h>
#include <string>
#include "func.h"
using namespace std;

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}


void solve(char myString[])
{
    int count[100];

    for (int i = 0; i < strlen(myString); i++)
    {
        count[i] = 1;
    }

    for (int i = 0; i < strlen(myString); i++)
    {
        if (myString[i] == ' ')
        {
            continue;
        }
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (myString[i] == myString[j])
                {
                    count[i]++;
                }
            }
        }
    }

    for (int i = 0; i < strlen(myString); i++)
    {
        cout << count[i] << " ";
    }

    int maxA = max(count,strlen(myString));
    int tmp = 0;
    for(int i= 0;i<strlen(myString);i++)
    {
        cout<<maxA - tmp<<": ";
        if(count[i] == maxA - tmp)
        {
            cout<<myString[i]<<' ';
            for(int j=0;j<strlen(myString);j++)
            {
                if(j == i)
                {
                    continue;
                }else
                {
                    if(myString[j] == myString[i])
                    {
                        count[j] = 0;
                    }
                }
            }
            tmp++;
        }
        cout<<endl;
    }

}