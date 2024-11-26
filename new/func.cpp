#include "func.h"

struct Seat
{
    bool sold = false;
};

struct Row
{
    Seat seat[30];
    uint price;
};

struct SeatList
{
    Row row[15];
};

void inputPrice(SeatList &sl)
{
    for (int i = 0; i < 15; i++)
    {
        cin >> sl.row[i].price;
    }
}

void dispCur(SeatList sl)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (sl.row[i].seat[j])
            {
                cout << "#";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void purchaseTicket(SeatList &sl)
{
    int **purchased;
    int numPurchase;
    cout << numPurchase;
    cin >> numPurchase;
    int totalPrice = 0;

    purchased = new int *[numPurchase];
    for (int i = 0; i < numPurchase; i++)
    {
        purchased[i] = new int[2];
    }
    cout << "Input row and index of seats for purchasing: ";
    for (int i = 0; i < numPurchase; i++)
    {
        cout << i + 1 << ": ";
        cout << "Row: ";
        cin >> purchased[i][0];
        cout << "Seat: ";
        cin >> purchased[i][1];
        totalPrice += sl.row[purchase]
    }
}