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
    int i,j,k;
    double x;
    double a1,a2;
    string str1,str2;
    int sameplace,samething;
    int flag;
    int G,T;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> x;
            //cout << x << endl;
            //cout << x*x*acos(-1)/25 << endl;
            a1 = x*x*acos(-1)/25;
            a2 = x*x*3/5 - x*x*acos(-1)/25;
            //cout << a1 << " " << a2 << endl;
            printf("%.2f %.2f\n",a1,a2);

        }
    }
}
