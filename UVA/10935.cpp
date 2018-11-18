#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 55

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

int queue_pop()
{
    if(queue_front == queue_back)
    {
        cout << "pop: nothing in queue" << endl;
        return -1;
    }
    else
    {
              //head++;

        queue_front++;
        queue_front = queue_front % SIZE;
        return queue[(queue_front - 1+SIZE)% SIZE];

    }
}
int main()
{
    //string a;
    int num,head,tail,N,i,how,temp;
    int discard[50];
    while(cin >> N)
    {
        if(N == 0) break;
        queue_front = 0;
        queue_back = 0;

       // top = N;
        how = 0;
        for(i = 0;i < 55;i++)
        {
            queue[i] = 0;
        }
        for(i = 0;i < N;i++)
        {
            queue_push(i + 1);
        }
        while(N >= 2)
        {
            discard[how] = queue_pop();
            N --;
            how ++;
            temp = queue_pop();
            queue_push(temp);
        }
        cout << "Discarded cards:";
        if(how != 0)
            cout << ' ';
        for(i = 0;i < how;i++)
        {
            cout << discard[i];
            if(i != how - 1)
            {
                cout << ", ";
            }
        }
        cout <<endl;
        cout << "Remaining card: " << queue_pop() <<endl;

    }
}

