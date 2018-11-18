#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
char A[100];
using namespace std;
int main()
{
    char p;
    //string a,t;
    long long int high,low,mid;
    double a,b,temp;
    while(cin >> a >> b)
    {
        high = 1000000000 + 1;
        low = 1;
        while(low < high)
        {
            mid = (low + high)/2;
            temp = pow(mid,a);
            if(temp == b) break;
            else if(temp < b)
            {
                low = mid + 1;
            }
            else
                high = mid;
        }
        cout << mid << endl;
    }

}



