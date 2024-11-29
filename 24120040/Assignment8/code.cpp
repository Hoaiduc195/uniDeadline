#include <iostream>
using namespace std;

struct Station
{
    int numOfStation;
    int *userID;
};

struct Lab
{
    Station *station;
};

Lab* createNewLabs(int labNum)
{
    Lab* tmp = new Lab[labNum];
    for(int i=0;i<labNum;i++)
    {
        int temp;
        cout<<"Input number of station for lab"<<i+1<<": ";
        do
        {
            cin>>temp;
        } while (temp<0);
        tmp[i].station = new Station[temp];
        tmp[i].station->numOfStation = temp;

        for(int j=0;j<temp;j++)
        {
            tmp[i].station[j].userID = 0;
        }
        
    }
    return tmp;
}

void disLab(lab* lab, int labNum)
{

}
void logIn(int userID, Lab *lab, int labNum)
{
    int uid;
    cout<<"Input user ID and lab information to log in: ";
    if(labNum >)
}

int main()
{
    Lab *myLab;
    myLab = createNewLabs(5);




    return 0;
}