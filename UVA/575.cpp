#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

using namespace std;
int main()
{
    string str;
    int a;
    int from,to;
    int ans,i,temp;
    int now;
    while(cin >> str)
    {
        if(str == "0") break;
        ans = 0;
        now = 1;
        for(i = 0;i < str.length();i++)
        {
            ans += (str[str.length() - i - 1] - '0') * now;
            now = now *2 +1;
        }
        cout << ans << endl;
    }
}
