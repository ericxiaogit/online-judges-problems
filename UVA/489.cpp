#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[30];
int B[100000];
int main()
{
    int SZ,P,i,x,y,temp,k,N,j,wrong;
    string a,b;
    while(cin >> N)
    {
        if(N < 0) break;
        cin >> a >> b;// a is answer
        for(i = 0;i < 26;i++)
        {
            A[i] = 0;
        }
        k = a.length();
        wrong = 0;
        for(i = 0;i < b.length();i++)
        {
            temp = 0;
            for(j = 0;j < a.length();j++)
            {
                if(b[i] == a[j])
                    temp++;
            }
            if(A[b[i] - 'a'] == 0)
            {
                k -= temp;
                if(temp == 0)
                    wrong ++;
            }
            A[b[i] - 'a'] = 1;
            if(wrong >= 7 || k == 0) break;
        }
        cout << "Round " << N << endl;
        if(wrong >= 7)
            cout << "You lose." << endl;
        else if(k == 0)
            cout << "You win." <<endl;
        else
            cout << "You chickened out." << endl;
    }

}


