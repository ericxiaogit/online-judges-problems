#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int A[3];
int B[2];
int main()
{
    int N,i,j,ans;
    int a,b,c,d,e;
    while(cin >> A[0] >> A[1] >> A[2] >> B[0] >> B[1])
    {
        if(A[0] == 0) break;
        sort(A,A + 3);
        sort(B,B + 2);
        a = A[0];
        b = A[1];
        c = A[2];
        d = B[0];
        e = B[1];
        if(c < d)
        {
            ans = 1;
        }
        else if(d < a && c < e)
        {
            ans = c + 1;
        }
        else if(a < d && d < b && c < e)
        {
            ans = c + 1;
        }
        else if(b < d && e < c)
        {
            ans = b+1;
        }
        else if(b < d && d < c && c <e)
        {
            ans = b+1;
        }
        else
        {
            ans = -1;
        }
        if(ans != -1)
        {
            while(ans == a || ans == b || ans == c || ans == d || ans == e)
            {
                ans ++;
            }
            if(ans > 52)
                ans = -1;
        }
        cout << ans << endl;
    }
}
