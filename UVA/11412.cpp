#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
string F(int s,int t)//turn s into t
{
    string ans = "";
    double k = 1/double(t);
    int temp = log(s) / log(t) + 1;
    int how,i;
    int p = 0;
    int c = 0;
    for(i = temp;i >= 0;i--)
    {
        how = s / pow(t,i);
        if(how != 0 && p == 0)
            p = 1;
        if(p == 0)
        {
            c++;
            continue;

        }
        ans = ans + " ";
        if(how >= 10)
        {
            ans[temp-i-c] = ('a' + int(how) - 10);

        }
        else
        {
            ans[temp-i-c] = ('0' + int(how));
        }
        double a = t,b = i;
        int y = 1;
        int j;
        for(j = 0;j < i;j++)
        {
            y *= t;
        }
        //int y = int(pow(a,b));
        //y += (pow(a,b)-y);
        //cout << y << endl;
        s = s % y;
        //cout << "i = " << i << " ans =" << ans<< "!" << endl;
    }
    return ans;
}
using namespace std;
int main()
{
    int N;
    int i,a1,b1,a2,b2,j,k;
    string str1,str2;
    int sameplace,samething;
    int flag;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> str1 >> a1 >> b1;
            cin >> str2 >> a2 >> b2;
            sameplace = 0;
            samething = 0;
            for(j = 0;j < 4;j++)
            {
                for(k = 0;k < 4;k++)
                {
                    if(str1[j] == str2[k])
                    {
                        if(j == k)
                        {
                            sameplace ++;
                        }
                        samething++;

                    }
                }
            }
            flag = 0;
            if(abs(a1 - a2) > (4 - sameplace))
                flag = 1;
            if((4 - sameplace) > (4 - a1) && abs(a1 - a2) < a1 - sameplace)
                flag = 1;
            if(abs((a1 + b1) - (a2 + b2)) > (4 - samething))//4 - some..... = change
                flag = 1;
            if((4 - samething) > 4 - (a1 + b1) && abs((a1 + b1) - (a2 + b2)) < (4 - samething) + a1 + a2 - 4)
                flag = 1;
            if(flag == 0)
                cout << "Possible" << endl;
            else
                cout << "Cheat" << endl;
        }
    }
}
