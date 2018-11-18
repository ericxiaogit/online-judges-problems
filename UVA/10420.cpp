#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
struct Pi
{
    string country;
    int num;
};
Pi A[2000 + 5];
bool cmp(const Pi &a,const Pi &b)
{
    return a.country < b.country;
}
int main()
{
    int SZ,P,i,j,ll;
    double t;
    int even,odd,evans;
    int temp;
    int N;
    string trash;
    int flag;
    string str;
    while(cin >> N)
    {
        SZ = 0;
        for(i = 0;i < N;i++)
        {
            cin >> str;
            getline(cin,trash);
            flag = 0;
            for(j = 0;j < SZ;j++)
            {
                if(A[j].country == str)
                {
                    A[j].num ++;
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                A[SZ].country = str;
                A[SZ].num = 1;
                SZ++;
            }
            sort(A,A + SZ,cmp);
        }
        for(j = 0;j < SZ;j++)
        {
            cout << A[j].country << " " << A[j].num << endl;
        }
    }
}

