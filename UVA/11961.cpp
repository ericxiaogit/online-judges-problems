#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
string A[10000000];
int head;
void DFS(int left,string s,int now)
{
    if(left <= 0)
    {
        A[head] = s;
        head++;
        return;
    }
    int i;
    char temp;
    for(i = now;i < s.length() - left + 1;i++)
    {
        temp = s[i];
        //cout << s[i] << endl;

        if(s[i] != 'A')
        {
            s[i] = 'A';
            DFS(left - 1,s,i+1);
            s[i] = temp;
        }
        if(s[i] != 'C')
        {
            s[i] = 'C';
            DFS(left - 1,s,i+1);
            s[i] = temp;
        }
        if(s[i] != 'G')
        {
            //cout << "s[i] = " << s[i] << endl;
            s[i] = 'G';
            DFS(left - 1,s,i+1);
            s[i] = temp;
        }
        if(s[i] != 'T')
        {
            s[i] = 'T';
            DFS(left - 1,s,i+1);
            s[i] = temp;
        }

    }
}
int main()
{
    int T;
    double e;
    int i,j;
    int ans;
    string str;
    int N,K;
    while(cin >> T)
    {
        for(i = 0;i < T;i++)
        {

            //cin >> N >> K >> str;
            //scanf("%d %d",&N,&K);
            //scanf("%d",&K);
            cin >> N >> K >> str;
            head = 0;
            //cout << "K = " << K << endl;
            //cout << "str = " << str << endl;
            for(j = 0;j <= K;j++)
            {
                DFS(j,str,0);
            }

            printf("%d\n",head);
            //system("pause");
            sort(A,A+head);
            for(j = 0;j < head;j++)
            {
                //cout << A[i] << endl;
                printf("%s\n",A[j].c_str());
            }
        }
    }
}


