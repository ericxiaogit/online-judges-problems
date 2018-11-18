#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int yns[1005][1005];
int ans[1000];
int main()
{
    int N,i,j,k;
    string s;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> s;
            for(j = 0;j < s.length();j++)
            {
                for(k = 0;k <= j;k++)
                {
                    if(j == k)
                        yns[k][j] = 1;
                    else
                        yns[k][j] = 0;
                }
            }
            for(j = 0;j < s.length();j++)
            {
                k = 0;
                while(1)
                {
                    if(j -k >= 0 && j + k < s.length() && s[j-k] == s[j+k])
                    {
                        yns[j-k][j+k] = 1;
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j != s.length() - 1)
                {
                    k = 1;
                    while(1)
                    {
                        if(j - k + 1>= 0 && j + k < s.length() && s[j-k+1] == s[j+k])
                        {
                            yns[j-k+1][j+k] = 1;
                            k++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            ans[0] = 1;
            for(j = 1;j < s.length();j++)
            {
                ans[j] = ans[j - 1] + 1;
                for(k = 0;k < j;k++)
                {
                    if(yns[k][j])
                    {
                        if(k != 0)
                            ans[j] = min(ans[j],ans[k - 1] + 1);
                        else
                            ans[j] = 1;
                    }
                }
             }
            cout << ans[s.length()-1] << endl;
        }
    }
}
