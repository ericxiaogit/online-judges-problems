#include<bits/stdc++.h>
using namespace std;
long long int GCD(long long a,long long b)
{
    if(a < b)
        swap(a,b);
    if(b == 0)
        return a;
    return GCD(b,a%b);
}
int main()
{
    long long int N,A,C,B1,m,i,j,k,ans,B2;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> A >> C;
        if(C % A != 0)
        {
            cout << "NO SOLUTION" <<endl;
            continue;
        }
        m = sqrt(C) + 1;
        ans = C;
        for(B1 = 1;B1 <= m;B1++)
        {
            if(C % B1 != 0) continue;
            B2 = C / B1;
            if(A * B1 == C * GCD(A,B1))
            {
                if(B1 < ans)
                    ans = B1;
            }
            if(A * B2== C * GCD(A,B2))
            {
                if(B2 < ans)
                    ans = B2;
            }

        }
        cout << ans << endl;
    }
}


