#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
char A[5][5];
int main()
{
    int i,j,k,N,flag,ans;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            ans = 0;
            for(j = 0;j < 5;j++)
            {
                flag = 0;
                for(k = 0;k < 5;k++)
                {
                    cin >> A[j][k];
                    if(A[j][k] == '|')
                        flag = 1;
                    else if(A[j][k] == '>')
                    {
                        if(flag == 0)
                            ans = 1;
                        else
                            ans = 0;
                    }
                    else if(A[j][k] == '<')
                    {
                        if(flag == 0)
                            ans = 0;
                        else
                            ans = 1;
                    }

                }
            }
            cout << "Case " << i + 1 << ": ";
            if(ans == 0)
                cout << "No Ball" << endl;
            else
                cout << "Thik Ball" << endl;
        }
    }

}

