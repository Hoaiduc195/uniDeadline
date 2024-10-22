#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define ll long long

ll P02(int n);
void executeP02();
bool isPrime(int num);
void P20(int n);
void executeP20();
int P23(int n);
void executeP23();
//////////////////////////////////
struct Date
{
	int day;
	int month;
	int year;
};

void inputDate();

int main()
{
	int choice;
	do {
		cout << "1. CHUONG TRINH P02" << endl;
		cout << "2. CHUONG TRINH P20" << endl;
		cout << "3. CHUONG TRINH P23" << endl;
		cout << "0. THOAT" << endl;
		cin >> choice;
		switch (choice) {
		case 1: executeP02(); break;
		case 2: executeP20(); break;
		case 3: executeP23(); break;
		case 0: exit;
		}

	} while (choice);

	return 0;	
}
/////////////
ll P02(int n)
{
	ll tmp = 0;
	for (int i = 0; i <= n; i++)
	{
		tmp += i * i;
	}
	return tmp;

}
void executeP02()
{
	int input;
	int inpCount = 0;
	do {
		if (inpCount)
		{
			cout << "So khong hop le!" << endl;
		}
		cout << "CHUONG TRINH P02" << endl;
		cout << "Nhap mot so: ";
		cin >> input;
		inpCount++;
	} while (input < 0);
	ll result = P02(input);
	cout << result << endl;
}
//
bool isPrime(int num)
{
	if (num < 2)
	{
		return false;
	}

	for (int i = 2; i < sqrt(num); i++)
	{
		if (!(num % i))
		{
			return false;
		}
	}
	return true;
}	
void P20(int n)
{
	if (n == 1|| isPrime(n))
	{
		cout << n;
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << " ";
		}
	}
	
	cout << endl;
}
void executeP20()
{	
	int input;
	int inpCount = 0;
	cout << "CHUONG TRINH P20" << endl;
	do {
		if (inpCount)
		{
			cout << "So khong hop le!" << endl;
		}
		cout << "Nhap mot so nguyen duong: ";
		cin >> input;
		inpCount++;
	} while (input <= 0);
	P20(input);
}
//
int P23(int n)
{
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!(n % i))
		{
			count++;
		}

	}
	return count;
}
void executeP23()
{
	cout << "CHUONG TRINH P23" << endl;
	int input;
	int inpCount = 0;
	do {
		if (inpCount)
		{
			cout << "So khong hop le!" << endl;
		}
		cout << "Nhap mot so nguyen duong: ";
		cin >> input;
		inpCount++;
	} while (input <= 0);
	int result = P23(input);
	cout << result<<endl;
}
//
bool checkDate(Date a)
{
	bool leapYear = 0;
	if ((a.year % 4 == 0 && a.year % 100 != 0) || a.year % 400 == 0)
	{
		leapYear = 1;
	}

	int dayNumInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	/*if (a.day <= 0 || a.month <= 0 || a.year < 0||a.day>31||a.year>12)
	{
		return false;
	}*/
	if (a.month != 2)
	{
		if (a.day<0 || a.day>dayNumInMonth[a.month])
		{
			return false;
		}
	}
	else
	{
		if (a.day<0 || a.day>dayNumInMonth[a.month] + (int)leapYear)
		{
			return false;
		}
	}
	return true;
}

void inputDate(Date &a)
{
	int inpCount = 0;
	do {
		if (inpCount)
		{
			cout << "Ngay khong hop le!" << endl;
		}
		cout << "Nhap ngay:";
		cin >> a.day;
		cout << "Nhap thang:";
		cin >> a.month;
		cout << "Nhap nam:";
		cin >> a.year;
		inpCount++;
	} while (!checkDate);

}