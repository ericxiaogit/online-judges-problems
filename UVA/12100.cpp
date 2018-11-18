#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 200

int queue[SIZE], queue_front, queue_back;

void queue_push( int n )
{
    if(queue_front == (queue_back+1)%SIZE)
    {
        cout << "push:queue is full" << endl;
    }
    else
    {
        queue[queue_back] = n;
        queue_back++;
        queue_back = queue_back % SIZE;
    }
    return;
}

void queue_pop()
{
    if(queue_front == queue_back)
    {
        cout << "pop: nothing in queue" << endl;
        return;
    }
    else
    {
              //head++;

        queue_front++;
        queue_front = queue_front % SIZE;
        return;// queue[(queue_front - 1 + SIZE)% SIZE];

    }
}

int main()
{
    //string a;
    int num,N,i,how,temp,nows,j,a,big,print;
    int pri[10];
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> how >> nows;
            big = 0;
            for(j = 0;j < 10;j++)
            {
                pri[j] = 0;
            }
            queue_front = 0;
            queue_back = 0;
            for(j = 0;j < how;j++)
            {
                cin >> a;
                if(a > big)
                    big = a;
                pri[a]++;
                queue_push(a);
            }
            print = 0;
            while(1)
            {
                //cout << print << " " <<nows << endl;
                a = queue[queue_front];
                if(a != big)
                {
                    if(nows == 0)
                    {
                        //cout << "how = " << how << " print = " << print << endl;
                        nows = how - print;
                    }
                    queue_push(a);
                    queue_pop();
                }
                else
                {
                    if(nows == 0)
                    {
                        break;
                    }
                    else
                    {
                        print ++;
                        queue_pop();
                        pri[big] --;
                        while(pri[big] == 0 && big > -1)
                        {
                            big--;
                        }
                    }
                }
                nows --;
                //cout << print << " " <<nows << endl;
            }
            cout << print + 1 << endl;
        }
    }
}

