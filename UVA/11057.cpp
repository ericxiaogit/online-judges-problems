#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int price[100000];
int main()
{
    int N,i,j,Q,temp,last,from,to;
    int a,b;
    int ans1,ans2;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> price[i];
        }
        cin >> Q;
        sort(price,price + N);
        a = 0;
        b = N -1;
        while(a < b)
        {
            if(price[a] + price[b] == Q)
            {
                ans1 = price[a];
                ans2 = price[b];
                a++;
                b--;
            }
            else if(price[a] + price[b] > Q)
            {
                b--;
            }
            else if(price[a] + price[b] < Q)
            {
                a++;
            }

        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);



    }

}



