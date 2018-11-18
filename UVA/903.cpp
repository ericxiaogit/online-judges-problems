#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int A[100000 + 50];
int coun[30 + 5];

int main()
{
    int n,i,j,K,temp,t2,t1;
    while(cin >> K)
    {
        temp = sqrt(K);
        if(K == 1)
        {
            cout << "7;8;9;\n6;1;2;\n5;4;3;\n";
        }
        else if(temp*temp == K && temp % 2 == 1)
        {
            t1 = (temp + 2)*(temp + 2);
            t2 = (temp - 2)*(temp - 2);
            printf("%d;%d;%d;\n%d;%d;%d;\n%d;%d;%d;\n",t1 - 2,t1-1,t1,K-1,K,K+1,t2,t2+1,K+2);
        }
        else
        {
            temp = temp + 1;
            if(temp % 2 == 0)
            {
                temp++;
            }
            n = (temp+1)/2;
            t1 = (temp + 2)*(temp + 2);
            t2 = (temp - 2)*(temp - 2);
            if(K > temp*temp - (2*n-2))
            {

            }
            else if(K == temp*temp - (2*n-2))
            {
                printf("%d;%d;%d;\n%d;%d;%d;\n%d;%d;%d;\n",K+8*n-2,K+8*n-1,K+8*n,K+8*n-3,K,K+1,K+8*n-4,K-1,t2-(2*n-4));
            }
            else if(K > temp*temp - (4*n-4))
            {

            }
            else if(K == temp*temp - (4*n-4))
            {
                printf("%d;%d;%d;\n%d;%d;%d;\n%d;%d;%d;\n",K + 8*n -2,K+1,t2-(4*(n-1)-4),K + 8*n -3,K,K-1,K + 8*n -4,K + 8*n -5,K + 8*n -6);
            }
            else if(K > temp*temp - (6*n-6))
            {

            }
            else if(K == temp*temp - (6*n-6))
            {
                printf("%d;%d;%d;\n%d;%d;%d;\n%d;%d;%d;\n",K - 8*n +14,K-1,K+8*n-8,K + 1,K,K+8*n-7,K + 8*n -4,K + 8*n -5,K + 8*n -6);
            }
            else
            {
                cout << "t1 = " << t1 <<endl;
                int up = (K==t2+1) ? temp*temp : K - 1;
                int left1,left2,left3;
                if(K== t2 +1)
                {
                    left1 = temp*temp-1;
                    left2 = K - 1;
                    left3 = K - 8*(n-2);
                    if(K == 2)
                        left3 = 4;

                }
                else if(K == temp*temp - (6*n-6) - 1)
                {
                    left1 = K - 8*(n-2)-2;
                    left2 = K - 8*(n-2)-1;
                    left3 = K + 2;
                }
                else
                {
                    left1 = K - 8*(n-2)-2;
                    left2 = K - 8*(n-2)-1;
                    left3 =  K - 8*(n-2);
                    if(K == t2 +2)
                        left1 = t2;
                }
                printf("%d;%d;%d;\n%d;%d;%d;\n%d;%d;%d;\n",left1,up,K+8*n-8,left2,K,K+8*n-7,left3,K+1,K+8*n-6);
            }

        }

    }
}

