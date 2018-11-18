#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
char A[200];
using namespace std;
int main()
{
    char p;
    string a,t;
    int num,top,i,N,j;
    cin >>N;
    cin.get(p);
    for(j = 0;j < N;j++)
    {
        top = 0;
        getline(cin,a);
        for(i = 0;i < a.length();i++)
        {
            p = a[i];
            if(p == '(' || p == ')' || p == '[' || p == ']' )
            {
                    if((p == ']' && A[top - 1] == '[') || (p == ')' && A[top - 1] == '('))
                {

                    top --;
                }
                else
                {
                    A[top] = p;
                    top ++;
                }
            }

            //cout << top << endl;
        }
        if(top == 0)
            cout <<"Yes" << endl;
        else
            cout << "No" << endl;
    }



}



