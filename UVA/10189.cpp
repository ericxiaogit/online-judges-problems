#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
char pro[1000][1000];
int ans[1000][1000];
using namespace std;
int main()
{
    int SZ,P,i,j,k;
    int t;
    int M,N;
    int temp;
    t = 0;
    while(cin >> N >> M)
    {
        t++;
        if(N == 0 && M == 0)
            break;
        if(t != 1)
            cout << endl;

        for(i = 0;i < N;i++)
        {
            for(j = 0;j < M;j++)
            {
                cin >> pro[i][j];
                //ans[i][j] = 0;
            }
        }
        printf("Field #%d:\n",t);
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < M;j++)
            {
                temp = 0;
                if(pro[i][j] == '*')
                {
                    cout << '*';
                    continue;
                }
                else
                {
                    if(i -1 >= 0 && pro[i-1][j] == '*')
                        temp++;
                    if(i - 1 >= 0 && j - 1 >= 0 && pro[i-1][j - 1] == '*')
                        temp ++;
                    if(i - 1 >= 0 && j + 1 < M && pro[i-1][j + 1] == '*')
                        temp ++;
                    if(j - 1 >= 0 && pro[i][j - 1] == '*')
                        temp ++;
                    if(j + 1 < M && pro[i][j + 1] == '*')
                        temp ++;
                    if(i + 1 >= 0 && j - 1 >= 0 && pro[i+1][j - 1] == '*')
                        temp ++;
                    if(i + 1 >= 0 && pro[i+1][j] == '*')
                        temp ++;
                    if(i + 1 >= 0 && j + 1 >= 0 && pro[i+1][j + 1] == '*')
                        temp ++;
                }
                cout << temp;
            }
            cout << endl;
        }
    }
}

