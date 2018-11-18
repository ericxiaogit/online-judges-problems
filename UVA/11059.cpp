#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[20];
int main()
{
    long long int T,N,D,i,j,ans,temp,start,now,second;
    long long int small;
    int flag;
    long long int product;
    now = 0;
    while(cin >> T)
    {
        now++;
        flag = 0;
        product = 1;
        ans = 0;
        small = 1;
        for(i = 0;i < T;i++)
        {
            cin >> A[i];
            if(A[i] == 0)
            {
                flag = 0;
                product = 1;
                small = 1;
            }
            else
            {
                product *= A[i];
                if(product < 0 && flag == 0)
                {
                    small = product;
                    flag = 1;
                    continue;
                }
                if(product > ans)
                    ans = product;
                else if(product/small > ans)
                    ans = product/small;
            }

        }
        //cout << ans << endl;
        cout << "Case #" << now << ": The maximum product is " << ans << "." << endl << endl;
        //printf("Case #%d: The maximum product is %lld.\n",now,ans);

    }

}

