#include <iostream>

using namespace std;

bool isPrime(int a);
void P04(int a[], int n);
void executeP04();

void rmOneMem(int a[], int &n, int pos);
void P08(int a[], int &n, int pos, int k);
void executeP08();

int P12(int a[], int n);
void executeP12();

void P26(int a[], int b[], int na, int nb);
void executeP26();

int main()
{
    int choice;

    do
    {
        cout << "HOMEWORK" << endl;
        cout << "1. P04" << endl;
        cout << "2. P08" << endl;
        cout << "3. P12" << endl;
        cout << "4. P26" << endl;
        cout << "5. P322" << endl;
        cout << "6. P347" << endl;
        cout << "7. P398" << endl;
        cout << "8. P423" << endl;
        cout << "9. P457" << endl;
        cout << "10. P471" << endl;
        cout << "0. THOAT" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            executeP04();
            break;
        }
        case 2:
        {
            executeP08();
        }
        case 3:
        {
            executeP12();
        }
        case 4:
        {
            executeP26();
        }
        case 0:
        {
            exit;
        }
        default:
        {
            exit;
        }
        }
    } while (choice);

    return 0;
}

bool isPrime(int a)
{
    if (a < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

void P04(int a[], int n)
{
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            cout << a[i] << " ";
        }
    }
}

void executeP04()
{
    int a[100];
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap " << n << " phan tu: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    P04(a, n);
    cout<<endl;
}
//
void rmOneMem(int a[], int &n, int pos)
{
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

void P08(int a[], int &n, int pos, int k)
{
    for (int i = k; i>0; i--)
    {
        rmOneMem(a, n, pos);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void executeP08()
{
    int a[100];
    int n;
    int pos;
    int k;
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap vi tri xoa: ";
    cin >> pos;
    cout << "Nhap so phan tu xoa: ";
    cin >> k;
    cout << "Nhap " << n << " phan tu: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    P08(a, n, pos, k);

    cout<<endl;
}
//
int P12(int a[], int n)
{
    int max1 = 0;
    int max2 = 0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>max1)
        {
            max1 = a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<max1 && a[i]>max2)
        {
            max2 = a[i];
        }
    }
    return max2;
}

void executeP12()
{
    int a[100];
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;
    cout<<"Nhap phan tu: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout<<P12(a,n)<<endl;
    
}
//
void P26(int a[], int b[], int na, int nb)
{
    for(int i=0;i<na;i++)
    {
        for(int j=0;j<nb;j++)
        {
            if(a[i] == b[j])
            {
                cout<<a[i]<<" ";
            }
        }
    }
}

void executeP26()
{
    int a[100];
    int na;
    int b[100];
    int nb;

    cout << "Nhap so phan tu cua a: ";
    cin >> na;
    cout << "Nhap so phan tu cua b: ";
    cin >> nb;

    cout<<"Nhap phan tu cua a: "<<endl;
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }

    cout<<"Nhap phan tu cua b: "<<endl;
    for (int i = 0; i < nb; i++)
    {
        cin >> b[i];
    }

    P26(a,b,na,nb);
    cout<<endl;
}
