#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int letters[26];
int coun[30 + 5];

int main()
{
    int sum,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int W , N,M;
    int day,month,year,qy;
    trash = 0;
    int zero;
    int flag;
    string a;
    while(cin >> N)
    {
        sum = 0;
        trash++;
        for(i = 0;i < N;i++)
        {
            cin >> a;
            for(j = 0;j < 35;j++)
            {
                if(j < 26)
                    letters[j] = 0;
                coun[j] = 0;
            }
            for(j = 0;j < a.length();j++)
            {
                letters[a[j]-'a'] ++ ;
            }
            flag = 0;
            zero = 0;
            for(j = 0;j < 26;j++)
            {
                if(coun[letters[j]] > 0 && letters[j] != 0)
                {
                    flag = 1;
                    break;
                }
                if(letters[j] == 0)
                    zero++;
                coun[letters[j]]++;
            }
            if(flag == 0 && zero < 25)
            {
                sum++;
            }
        }
        cout << "Case " << trash << ": " << sum <<endl;

    }
}

