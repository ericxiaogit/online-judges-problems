#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
string A[10000 + 10];
int main()
{
    int i,j,T;
    double t;
    int trash;
    int N;
    int head;
    string a,str;
    while(cin >> N)
    {
        head = 0;
        for(i = 0;i < N;i++)
        {
            cin >> a;
            if(a == "Test")
            {
                if(head == 0)
                    cout << "Not in a dream" << endl;
                else
                    cout << A[head - 1] << endl;
            }
            else if(a == "Kick")
            {
                if(head > 0)
                    head--;
            }
            else
            {
                cin >> str;
                A[head] = str;
                head++;
            }
        }


    }
}

