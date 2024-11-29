#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void loadCorrectAns(char path[], char *&answer, int& n)
{
    fstream input(path);
    if(!input)
    {
        cout<<"Can not open file."<<endl;
        return;
    }
    input>>n;
    input.ignore();
    answer = new char[n];
    for(int i=0;i<n;i++)
    {
        input>>answer[i];
        input.ignore();
    }
    input.close();
}

void loadStudentAns(char path[], char *&answer, int& n, int cN)
{
    fstream input(path);

    if(!input)
    {
        cout<<"Can not open file"<<endl;
        return;
    }

    input>>n;
    input.ignore();
    answer = new char[cN];
    for(int i=0;i<cN;i++)
    {
        input.get(answer[i]);
        if(answer[i] == '\n')
        {
            answer[i] = 'X';
            continue;
        }
        input.ignore();
    }

    for(int i=0;i<cN;i++)
    {
        cout<<answer[i];
    }
    cout<<endl;
    input.close();
}

void findMissAns(char *cAns, char *sAns, int n)
{
    int missed = 0;
    for(int i=0;i<n;i++)
    {
        if(cAns[i]!=sAns[i])
        {
            if(sAns[i] != 'X')
            {
                cout<<i+1<<": Correct answer: "<<cAns[i]<<", Student's answer: "<<sAns[i]<<endl; 
                missed++;
            }else{
                cout<<i+1<<": Correct answer: "<<cAns[i]<<", Student's answer: none"<<endl;
                missed++;
            }
        }
    }
    cout<<"Missed answer: "<<missed<<endl;
    float percentage = (100.0*(n-missed)/(1.0*n));
    cout<<"The percentage of questions answered correctly: "<<percentage<<"%"<<endl;

    if(percentage>=70.0)
    {
        cout<<"The student passed the exam."<<endl;
    }else
    {
        cout<<"The student failed the examm."<<endl;
    }

}

int main()
{
    char path[] = "CorrectAnswers.txt";
    char *correctAns;
    int n;
    loadCorrectAns(path,correctAns,n);

    char studentPath[] = "StudentAnswers.txt";
    char *studentAns;
    int sn;
    loadStudentAns(studentPath,studentAns,sn,n);

    findMissAns(correctAns, studentAns, n);
    
    return 0;
}