#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 100000
int queue_front, queue_back;
bool visited[9][9];
char a,c;
int b,d;
struct Bot
{
    int y,step;
    char x;//fill a = 1;pour a to b = 2;empty a = 3
                       //fill b = 4;pour b to a = 5;empty b = 6
};
int ans;
Bot queue[SIZE];
void pushin(Bot ra,int way)
{
    //cout << ra.x << " ---- " << ra.y <<endl;
    if(way == 1)
    {
        ra.x += 2;
        ra.y += 1;
    }
    else if(way == 2)
    {
        ra.x += 2;
        ra.y += (-1);
    }
    else if(way == 3)
    {
        ra.x += 1;
        ra.y += (-2);
    }
    else if(way == 4)
    {
        ra.x += (-1);
        ra.y += (-2);
    }
    else if(way == 5)
    {
        ra.x += (-2);
        ra.y += (-1);
    }
    else if(way == 6)
    {
        ra.x += (-2);
        ra.y += 1;
    }
    else if(way == 7)
    {
        ra.x += (-1);
        ra.y += 2;
    }
    else if(way == 8)
    {
        ra.x += 1;
        ra.y += 2;
    }
    if(ra.x - 'a' < 0|| ra.y < 1) return;
    if(ra.x - 'h' > 0|| ra.y > 8) return;
    if(visited[ra.x - 'a' +1][ra.y]) return;
    //cout << ra.x << " - " << ra.y <<endl;
    if(ra.x == c && ra.y == d)
    {
        ans = ra.step + 1;
        //cout << "yes" <<endl;
        return;
    }

    //cout << "goodbye" <<endl;
    visited[ra.x-'a'+1][ra.y] = true;
    ra.step++;
    queue[queue_back] = ra;

    queue_back ++;

}
//Bot queue[SIZE];
int main()
{
    //string a;
    int i,j;
    while(cin >>a >> b >> c >> d)
    {
        ans = 0;
        for(i = 0;i <= 8;i++)
        {
            for(j = 0;j <= 8;j++)
            {
                visited[i][j] = false;
            }
        }
        queue_front = 0;
        queue_back = 0;
        queue[queue_back].x = a;
        queue[queue_back].y = b;
        queue[queue_back].step = 0;
        queue_back ++;
        visited[a-'a'+1][b] = true;
        Bot e;
        while(queue_front != queue_back)
        {

            e = queue[queue_front];
            //cout << c.a << " " << c.b << " " << c.how << " " << c.parent << " " << c.len << endl;
            queue_front ++;
            for(i = 1;i < 9;i++)
            {
                pushin(e,i);
                if(ans != 0) break;
            }
            if(ans != 0) break;
            //cout << "queue:" << queue_back - queue_front << endl;

        }
        cout << "To get from "<< a << b <<" to "<< c << d <<" takes "<< ans <<" knight moves." << endl;


    }
}

