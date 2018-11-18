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
    int num,N,i,how,temp,nows,j,big,print,ans,x,y;
    string a,b;
    long long int c,d;
    while(cin >> a)
    {
        sort(a.begin(),a.end());
        b = a;
        //cout << "a = " <<a <<endl;
        if(a[0] == '0')
        {
            for(i = 0;i < a.length();i++)
            {
                if(a[i] != '0')
                {
                    //cout << "i = " << i <<endl;
                    swap(a[i],a[0]);
                    break;
                }

            }
        }
        //cout << "a = " <<a <<endl;
        c = 0;
        for(i = 0;i < b.length();i++)
        {
            c = c*10;
            c+=a[i]-'0';
        }
        reverse(b.begin(),b.end());
        d = 0;
        for(i = 0;i < b.length();i++)
        {
            d = d*10;
            d+=b[i] - '0';
        }
        //cout << c << " " << d << endl;
        printf("%lld - %lld = %lld = 9 * %lld\n",d,c,d-c,(d-c)/9);

    }
}

