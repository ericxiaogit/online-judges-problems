#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 100000
int a,b,N,alen;
int queue_front, queue_back;
bool visited[1000][1000];
string A[7] = {"","fill A","pour A B","empty A","fill B","pour B A","empty B"};

struct Bot
{
    int a,b,parent,how,len;//fill a = 1;pour a to b = 2;empty a = 3
                       //fill b = 4;pour b to a = 5;empty b = 6
};
Bot ans;
Bot queue[SIZE];
void pushin(Bot ra,int way)
{
    if(way == 1)
        ra.a = a;
    else if(way == 2)
    {
        int sum = ra.a + ra.b;
        ra.b = min(b,ra.a +ra.b);
        ra.a = sum - ra.b;
    }
    else if(way == 3)
        ra.a = 0;
    if(way == 4)
        ra.b = b;
    else if(way == 5)
    {
        int sum = ra.a + ra.b;
        ra.a = min(a,ra.a +ra.b);
        ra.b = sum - ra.a;
    }
    else if(way == 6)
        ra.b = 0;
    //cout << "hello" << endl;
    //cout << "a = " << ra.a << " b = " << ra.b << endl;
    //cout << visited[ra.a][ra.b] <<endl;
    if(visited[ra.a][ra.b]) return;
    //cout << "hello" <<endl;
    //cout << "N = " << N << endl;
    if(ra.a == N || ra.b == N)
    {
        //cout << "hello" << endl;
        if(ra.len < alen)
        {
            //cout << "ya " << ra.len << endl;
            alen = ra.len;
            ans.a = ra.a;
            ans.b = ra.b;
            ans.parent = queue_front - 1;
            ans.how = way;
        }
        return;
    }
    //cout << "goodbye" <<endl;
    visited[ra.a][ra.b] = true;
    ra.parent = queue_front -1;
    ra.how = way;
    ra.len++;
    queue[queue_back] = ra;

    queue_back ++;

}
//Bot queue[SIZE];
int main()
{
    //string a;
    int i,j;
    while(cin >> a >> b >> N)
    {

        ans.a = 0;
        ans.b = 0;
        ans.how = 0;
        ans.len = 0;
        ans.parent = 0;
        for(i = 0;i <= a;i++)
        {
            for(j = 0;j <= b;j++)
            {
                visited[i][j] = false;
            }
        }
        queue_front = 0;
        queue_back = 0;
        queue[queue_back].a = 0;
        queue[queue_back].b = 0;
        queue[queue_back].parent = -1;
        queue[queue_back].how = 0;
        queue[queue_back].len = 1;
        queue_back ++;
        visited[0][0] = true;
        Bot c;
        alen = (a+5) * (b +5);
        while(queue_front != queue_back)
        {

            c = queue[queue_front];
            //cout << c.a << " " << c.b << " " << c.how << " " << c.parent << " " << c.len << endl;
            queue_front ++;
            pushin(c,1);
            pushin(c,2);
            pushin(c,3);
            pushin(c,4);
            pushin(c,5);
            pushin(c,6);

        }
        string answer = "";
        int now;
        //cout << "alen = "<< alen <<endl;
        for(i = 0;i < alen;i++)
            answer.append(" ");
        //cout << "ans " << ans.how << endl;;
        answer[0]= ans.how + '0';
        //cout << "ans.how = " << ans.how << endl;
        //cout <<"first = " << answer[0] << endl;
        now = ans.parent;
        //cout << ans.a << " " << ans.b << endl;
        //cout << queue[now].a << " " << queue[now].b << endl;
        if(alen == (a+5)*(b+5))
        {
            cout << "NO WAY" << endl;
            continue;
        }
        for(i = 1;i < alen +1;i++)
        {
            //cout << queue[now].a << " " << queue[now].b << endl;
            answer[i] = queue[now].how+'0';
            now = queue[now].parent;
        }
        //cout << "hello" << endl;
        for(i = alen - 1;i >= 0;i--)
        {
            cout << A[answer[i] -'0'] << endl;
        }
        cout << "success" <<endl;
        cout << "length = " << alen << endl;

        //cout << "answer = " << answer << endl;
    }
}

