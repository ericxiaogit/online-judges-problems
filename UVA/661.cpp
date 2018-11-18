#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
int onoff[30];
int amp[30];
using namespace std;
int main()
{
    int i,T,temp = 0,j;
    long long int n,m,c;
    long long int ans,now,mx;
    while(cin >> n >> m >> c)
    {
        if(n == 0 && m == 0 && c == 0) break;
        mx = 0;
        temp++;
        //if(temp != 1)
            //cout << endl;
        ans = 0;
        for(i = 1;i <= n;i++)
        {
            cin >> amp[i];
            onoff[i] = 0;
        }
        now = 0;
        for(j = 1;j <= m;j++)
        {
            cin >> i;
            onoff[i] = onoff[i]*(-1) + 1;
            if(onoff[i] == 1)
                now += amp[i];
            else
                now -= amp[i];
            if(now > mx)
                mx = now;
            if(now > c)
            {
                ans = 1;
            }
        }
        //cout <<"ans = " << ans << endl;
        if(ans == 0)
            cout << "Sequence " << temp <<endl << "Fuse was not blown." << endl << "Maximal power consumption was " << mx <<  " amperes." <<endl<<endl;
        else
            cout << "Sequence " << temp <<endl << "Fuse was blown." << endl <<endl;

    }
}
