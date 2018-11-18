#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
int onoff[30];
int amp[30];
using namespace std;
struct letter
{
    char x;
    int y;
};
letter A[26 + 3];
bool cmp(const letter &a,const letter &b)
{
    if(a.y != b.y)
        return a.y > b.y;
    return a.x < b.x;
}
int main()
{
    string s;
    int i,T,temp = 0,j;
    long long int n,m,c;
    long long int ans,now,mx;
    char trash;
    while(cin >> n)
    {
        trash = cin.get();
        for(i = 0;i < 26;i++)
        {
            A[i].y = 0;
            A[i].x = 'A' + i;
        }
        for(i = 0;i < n;i++)
        {
            getline(cin,s);
            for(j = 0;j < s.length();j++)
            {
                if(s[j] >= 'a' && s[j] <= 'z')
                {
                    A[s[j] - 'a'].y++;
                }
                else if(s[j] >= 'A' && s[j] <= 'Z')
                {
                    A[s[j] - 'A'].y++;
                }
            }
        }
        sort(A,A+26,cmp);
        for(i = 0;i < 26;i++)
        {
            if(A[i].y > 0)
                cout << A[i].x << " " << A[i].y << endl;
        }
    }
}
