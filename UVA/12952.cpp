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
    long long int i,T,temp = 0,j;
    long long int n,m,c,N;
    long long int ans,now,mx,sum;
    char trash;
    long long int last;
    while(cin >> n >> m)
    {
        cout << max(n,m) << endl;


    }
}
