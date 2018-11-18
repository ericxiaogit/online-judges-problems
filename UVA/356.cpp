#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int A[30];
int B[20];
int g(int a,int b)
{
    int t,c,d;
    c = a;
    d = b;
    while(1)
    {
        a = a % b;
        if(a == 0 || b == 0)
        {
            break;
        }
        b = b % a;
        if(a == 0 || b == 0)
        {
            break;
        }
    }
    t = abs(a - b);
    return (c * d) / t;
}
int f(int a,int b,int c,int d)// X%a == b  X % c == d return
{
    int i = 1;
    for(i = 1;2 > 1;i++)
    {
        if(i % a == b && i % c == d)
        {
            return i;
            break;
        }
    }

}
int main()
{
    int i,c,d,j,t,K;
    t = 0;
    int ans1,ans2;
    int a,b;
    int temp;
    int N;
    int sum;
    temp = 0;
    int big,small;
    while(cin >> N)
    {
        temp++;
        if(temp != 1)
            cout << endl;
        ans1= 4 * (N*2 -1);
        big = (N*2 -1);
        ans2 = 0;
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < N;j++)
            {
                if(i * i + j * j <= (big/2.0) * (big/2.0) && (i +1)* (i + 1 )+ j * j <= (big/2.0) * (big/2.0) && i * i + (j + 1)* (j + 1 )<= (big/2.0) * (big/2.0) && (i + 1)* (i + 1 )+ (j + 1) * (j + 1) <= (big/2.0) * (big/2.0))
                {
                    ans2 ++;
                }
            }
        }
        ans2 *= 4;
        printf("In the case n = %d, %d cells contain segments of the circle.\n",N,ans1);
        printf("There are %d cells completely contained in the circle.\n",ans2);

    }


}

