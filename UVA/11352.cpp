#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
int a,b,N,alen;
int queue_front, queue_back;
//bool visited[1000][1000];
char maps[10000][10000];
int block[10000][10000];
struct Node
{
    int xx;
    int yy;
    int steps;
};
Node queu[SIZE];

int main()
{
    //string a;
    int i,j,k;
    int x,y;
    int start_x,start_y;
    scanf("%d",&N);


        for(i = 0;i < N;i++)
        {
            queue_front = 0;
            queue_back = 0;
            cin >>x >> y;
            for(j = 0;j < x;j++)
            {
                for(k = 0;k < y;k++)
                {
                    block[j][k] = 0;
                    cin >> maps[j][k];
                    if(maps[j][k] == 'A')
                    {
                        start_x = j;
                        start_y = k;
                    }
                }
            }
            for(j = 0;j < x;j++)
            {
                for(k = 0;k < y;k++)
                {
                    if(maps[j][k] == 'Z')
                    {
                        block[j][k] = 1;
                        if(j - 2 >= 0 && k - 1 >= 0 && maps[j - 2][k - 1] == '.')
                            block[j - 2][k - 1] = 1;
                        if(j - 2 >= 0 && k + 1 < y && maps[j - 2][k + 1] == '.')
                            block[j - 2][k + 1] = 1;
                        if(j - 1 >= 0 && k + 2 < y && maps[j - 1][k + 2] == '.')
                            block[j - 1][k + 2] = 1;
                        if(j + 1 < x && k + 2 < y && maps[j + 1][k + 2] == '.')
                            block[j +1][k + 2] = 1;
                        if(j + 2 < x && k + 1 < y && maps[j + 2][k + 1] == '.')
                            block[j+2][k + 1] = 1;
                        if(j + 2 < x && k - 1 >= 0 && maps[j + 2][k - 1] == '.')
                            block[j + 2][k - 1] = 1;
                        if(j + 1 < x && k - 2 >= 0 && maps[j + 1][k - 2] == '.')
                            block[j + 1][k - 2] = 1;
                        if(j - 1 >= 0 && k - 2 >= 0 && maps[j - 1][k - 2] == '.')
                            block[j - 1][k - 2] = 1;
                    }
                }
            }
            /*
            for(j = 0;j < x;j++)
            {
                for(k = 0;k < y;k++)
                {
                    cout << block[j][k];
                }
                cout <<endl;
            }*/
            queu[queue_front].xx = start_x;
            queu[queue_front].yy = start_y;
            queu[queue_front].steps = 0;
            queue_back++;
            int ans = 0;
            int  nowx,nowy;
            while(queue_front < queue_back)
            {
                if(maps[queu[queue_front].xx][queu[queue_front].yy] == 'B')
                {
                    ans = queu[queue_front].steps;
                    break;
                }
                nowx = queu[queue_front].xx;
                nowy = queu[queue_front].yy;
                block[queu[queue_front].xx][queu[queue_front].yy] = 2;
                if(nowx + 1 < x && nowy + 1 <  y && block[nowx + 1][nowy + 1] == 0)
                {
                    queu[queue_back].xx = nowx +1;
                    queu[queue_back].yy = nowy +1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx + 1 < x && nowy + 0 <  y && block[nowx + 1][nowy + 0] == 0)
                {
                    queu[queue_back].xx = nowx +1;
                    queu[queue_back].yy = nowy + 0;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx + 1 < x && nowy - 1 >= 0 && block[nowx + 1][nowy - 1] == 0)
                {
                    queu[queue_back].xx = nowx +1;
                    queu[queue_back].yy = nowy - 1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx + 0 < x && nowy - 1 >= 0 && block[nowx + 0][nowy - 1] == 0)
                {
                    queu[queue_back].xx = nowx +0;
                    queu[queue_back].yy = nowy - 1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx - 1 >= 0 && nowy - 1 >= 0 && block[nowx - 1][nowy - 1] == 0)
                {
                    queu[queue_back].xx = nowx -1;
                    queu[queue_back].yy = nowy -1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx - 1 >= 0 && nowy + 0 <  y && block[nowx - 1][nowy + 0] == 0)
                {
                    queu[queue_back].xx = nowx - 1;
                    queu[queue_back].yy = nowy + 0;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx - 1 >= 0 && nowy + 1 <  y && block[nowx - 1][nowy + 1] == 0)
                {
                    queu[queue_back].xx = nowx - 1;
                    queu[queue_back].yy = nowy + 1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                if(nowx + 0 < x && nowy + 1 <  y && block[nowx + 0][nowy + 1] == 0)
                {
                    queu[queue_back].xx = nowx +0;
                    queu[queue_back].yy = nowy +1;
                    queu[queue_back].steps = queu[queue_front].steps + 1;
                    queue_back ++;
                }
                queue_front++;
            }
            if(ans == 0)
                printf("King Peter, you can't go now!\n");
                //cout << "King Peter, you can't go now!" << endl;
            else
            printf("Minimal possible length of a trip is %d\n",ans);
                //cout << "Minimal possible length of a trip is " << ans << endl;
        }

}

