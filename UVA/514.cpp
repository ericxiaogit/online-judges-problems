#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int A[1000];
int station[1000];
int B[1000];
int used[1000];
int main()
{

    int i ,N,a,j,k,top,test;
    while(cin >> N)
    {
        if(N == 0) break;
        while(cin >> A[1])
        {
            test = 0;
            top = 0;
            if(A[1] == 0) break;
            used[1] = 0;
            station[1] = 0;
            for(i = 2;i <= N;i++)
            {
                cin >> A[i];
                used[i] = 0;
                station[i] = 0;

            }
            for(i = 1;i <= N;i++)
            {
                if(used[A[i]] ==  0)
                {
                    for(j = 1;j <= A[i];j++)
                    {
                        if(used[j] == 0)
                        {
                            station[top] = j;
                            top ++;
                            used[j] = 1;
                        }
                    }
                    top --;
                    station[top] = 0;

                }
                else
                {
                    if(station[top - 1] == A[i])
                    {
                        top --;
                        station[top] = 0;
                    }
                    else
                    {
                        test = 1;
                        break;
                    }
                }
                //cout << "top = " << top <<endl;
                /*for(j = 0;j < top;j++)
                {
                    cout <<station[j];
                }
                cout <<endl;*/
            }
            if(test == 1)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
        cout <<endl;
    }



}
