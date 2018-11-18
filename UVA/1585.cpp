#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
int A[15];

int main()
{
    //string a;
    int i,j,k;
    int x,y;
    int start_x,start_y;
    int T;
    long long int N,K,X;
    int a,b,c,d,e,f;
    int trash,ans;
    string str;
    while(cin >> K)
    {
        for(i = 0;i < K;i++)
        {
            trash = 0;
            ans = 0;
            cin >>str;
            for(j = 0;j < str.length();j++)
            {
                if(str[j] == 'O')
                {
                    //cout << "hello" << endl;
                    trash++;
                    ans+=trash;
                }
                else
                    trash = 0;
            }
            cout << ans << endl;
        }
    }


}

