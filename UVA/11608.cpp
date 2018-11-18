#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int need[20];
long long int news[20];
using namespace std;
int main()
{
    int N,i,j;
    i = 0;
    while(cin >> N)
    {
        if(N < 0) break;
        i++;
        for(j =0;j < 12;j++)
        {
            cin >> news[j];
        }
        for(j =0;j < 12;j++)
        {
            cin >> need[j];
        }
        cout << "Case " << i << ":" << endl;
        for(j =0;j < 12;j++)
        {
            if(need[j] > N)
            {
                cout << "No problem. :(" << endl;
            }
            else
            {
                cout << "No problem! :D" << endl;
                N -= need[j];
            }
            N += news[j];

        }

    }

}



