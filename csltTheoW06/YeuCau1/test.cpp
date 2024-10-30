#include <iostream>
#include <string.h>
#include <string>
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
bool notMetBefore(char a[100], char b, int indx)
{
    for(int i=indx;i>=0;i++)
    {
        if(a[i]==b)
        {
            return true;
        }
    }

    return true;
}


int main()
{
    char myString[100];
    int count[100];

    fgets(myString, 100, stdin);
    myString[strlen(myString)-1] = '\0';

    for (int i = 0; i < strlen(myString); i++)
    {
        count[i] = 1;
    }

    for (int i = 0; i < strlen(myString); i++)
    {
        if (myString[i] == ' ')
        {
            count[i] = 0;
        }
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (myString[i] == myString[j])
                {
                    count[j] = count[i]+1;
                    count[i] = count[j];
                }
            }
        }
    }

    for (int i = 0; i < strlen(myString); i++)
    {
        cout << count[i] << " ";
    }
    cout<<endl;


    int maxA = max(count,strlen(myString)-1);    

    for(int i = maxA;i>0;i--)
    {
        int cCount = 0;
        for(int j=0;j<strlen(myString);j++)
        {
            
            if(count[j] == i && notMetBefore(myString,myString[j],j))
            {
                if(!cCount)
                {
                    cout<<i<<": "<<myString[j]<<" ";
                    // containerChar = myString[j];
                    cCount++;
                }else
                {
                    cout<<myString[j]<<" ";
                }
            }
        }
        cout<<endl;
    }

    
    
    return 0;
}