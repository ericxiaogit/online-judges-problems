#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int left[100000 + 10];
    int right[100000 + 10];
    int S,B,L,R;
    int i,j;
    while(cin >> S >> B)
    {
        if(S == 0 && B ==0) break;
        for(i = 0;i <= S;i++)
        {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        for(i = 0;i < B;i++)
        {
            cin >> L >> R;
            if(left[L] <= 0)
                cout << '*';
            else
                cout << left[L];
            cout << " ";
            if(right[R] > S)
                cout << '*';
            else
                cout << right[R];
            cout << endl;
            left[right[R]] = left[L];
            right[left[L]] = right[R];
        }
        cout << '-' << endl;
    }
}

