#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int A[100 + 5];
int GCD(int A,int B)
{
    if(A < B)
        swap(A,B);
    if(A % B == 0)
        return B;
    else
        return GCD(B,A%B);
}
int main()
{
    int N,i;
    char trash;
    int t;
    int j,k;
    int ans;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            t = 0;
            while(1)
            {
                cin >> A[t];
                t++;
                cin.get(trash);
                if(trash == '\n')
                    break;
                else
                {
                    trash = cin.peek();
                    if(trash != ' ') continue;
                    trash = cin.get();
                }
            }
            ans = 1;
            for(j = 0;j < t;j++)
            {
                for(k = j + 1;k < t;k++)
                {
                    //cout << A[k] << " " << A[j] << " " << GCD(A[j],A[k]) << endl;
                    ans = max(ans,GCD(A[j],A[k]));
                }
            }
            cout << ans << endl;
        }
    }

}
