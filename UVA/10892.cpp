#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,i,j,k,ans,temp,p;
    while(cin >> N)
    {
        if(N == 0) break;
        p = N;
        k = sqrt(N) + 1;
        ans = 1;
        for(i = 2;i <= k;i++)
        {
            temp = 0;
            while(N%i == 0)
            {
                N /= i;
                temp ++;
            }
            ans *= (temp * 2 +1);
        }
        if(N != 1)
            ans *= 3;

        cout << p <<" " <<(ans/2) + 1 <<endl;
    }
}



