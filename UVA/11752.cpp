#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[1005];
int main()
{
    //string a;
    long long int num,N,i,how,temp,nows,j,big,print,ans,x,y;
    long long int c,d;
    x = 0;
    while(cin >> N)
    {
        x++;
        if(N == 0) break;
        temp = sqrt(2*N);
        i = temp;
        while(1)
        {
            if((i - 3)*i/2 >= N) break;
            i++;
        }
        cout << "Case " << x << ": ";
        cout << i <<endl;
    }
}

