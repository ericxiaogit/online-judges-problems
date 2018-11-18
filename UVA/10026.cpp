#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
struct Case
{
    int num,day,fund;
};
Case A[1000+5];
bool compare(const Case &a,const Case &b)
{
    int afirst = a.day * b.fund;
    int bfirst = b.day * a.fund;
    if(afirst == bfirst)
        return a.num < b.num;
    return afirst<bfirst;
}
int main()
{
    int i,j,T;
    double t;
    int trash;
    int N;
    while(cin >> N)
    {
        for(i = 0;i <N;i++)
        {
            if(i > 0)
                cout << endl;
            cin>>T;
            for(j = 0;j < T;j++)
            {
                cin >> A[j].day >> A[j].fund;
                A[j].num = j;
            }
            sort(A,A+T,compare);
            for(j = 0;j < T;j++)
            {
                cout << A[j].num + 1;
                if(j < T-1)
                    cout << " ";
            }
            cout << endl;
        }


    }
}

