#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
#define SIZE 1000

int queue[SIZE], queue_front, queue_back;
int stack[SIZE],stop;
int pri[SIZE],ptop;

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
       // cout << "pop: nothing in queue" << endl;
        return -1;
    }
    else
    {
              //head++;

        queue_front++;
        queue_front = queue_front % SIZE;
        return queue[(queue_front - 1 + SIZE)% SIZE];

    }
}
int main ()
{
    int a,b,c;//a : stack
              //b : queue
              //c : priority queue
    int N,i,t,temp,rf;
    while(cin >> N)
    {
        stop = 0;
        ptop = 0;
        queue_front = 0;
        queue_back = 0;
        a = 0;
        b = 0;
        c = 0;
        for(i = 0;i < N;i++)
        {
            cin >> t >> temp;
            if(t == 1)
            {
                if(a == 0)
                {
                    stack[stop] = temp;
                    stop++;
                }
                if(b == 0)
                {
                    queue_push(temp);
                }
                if(c == 0)
                {
                    pri[ptop] = temp;
                    ptop++;
                }
            }
            else if(t == 2)
            {
                if(a == 0)
                {
                    stop--;
                    rf = stack[stop];
                    if(rf != temp)
                    {
                        a = 1;
                    }
                }
                if(b == 0)
                {
                    rf = queue_pop();
                    if(rf != temp)
                    {
                        b = 1;
                    }
                }
                if(c == 0)
                {
                    sort(pri,pri + ptop);
                    reverse(pri,pri + ptop);
                    rf = pri[0];
                    pri[0] = 0;
                    if(rf != temp)
                    {
                        c = 1;
                    }
                   // cout << rf << " " << temp <<endl;
                }

            }
            //if(a == 1 && b == 1 & c ==1 ) break;
        }
        if(a + b + c == 2)
        {
            if(a == 0)
                cout << "stack" << endl;
            else if(b == 0)
                cout << "queue" << endl;
            else if(c == 0)
                cout << "priority queue" << endl;
        }
        else if(a + b + c == 3)
            cout << "impossible" <<endl;
        else
            cout << "not sure" <<endl;
    }

}

