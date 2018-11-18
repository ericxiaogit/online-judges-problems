#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int color[26];
int se[26];
int K;
string a,b;
int ans[1000][1000];
int dp(int q,int r)
{
    int nowk;
    if(q == a.length() && r == b.length())
    {
        return 0;
    }
    if(ans[q][r] != -1)
        return ans[q][r];
    int as = -1,bs = -1;
    nowk = K;
    if(q != a.length())
    {
        if(color[a[q]-'A'] == 1)
            K--;
        if(se[a[q]-'A'] == 0)
            K++;
        color[a[q]-'A']--;
        se[a[q]-'A']++;
        as = nowk + dp(q+1,r);
        color[a[q]-'A']++;
        se[a[q]-'A']--;
        K = nowk;
    }
    if(r != b.length())
    {
        if(color[b[r]-'A'] == 1)
            K--;
        if(se[b[r]-'A'] == 0)
            K++;
        color[b[r]-'A']--;
        se[b[r]-'A']++;
        bs = nowk + dp(q,r + 1);
        color[b[r]-'A']++;
        se[b[r]-'A']--;
        K = nowk;
    }
    //cout << q << " " << r << " " << as << " " << bs << " " << nowk  << endl;
    if(as == -1 || bs == -1)
        ans[q][r] = (-1)*as*bs;
    else
         ans[q][r] = min(as,bs);
    return ans[q][r];
}
int main()
{
    int N,i,j,k;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> a >> b;
            for(j = 0;j < 26;j++)
            {
                color[j] = 0;
                se[j] = 0;
            }
            for(j = 0;j < a.length();j++)
            {
                color[a[j] - 'A'] ++;
            }
            for(j = 0;j < b.length();j++)
            {
                color[b[j] - 'A'] ++;
            }
            for(j = 0;j <= a.length();j++)
            {
                for(k = 0;k <= b.length();k++)
                {
                    ans[j][k] = -1;
                }
            }
            K = 0;
            cout << dp(0,0) << endl;

        }

    }

}

