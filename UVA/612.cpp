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
struct DNA
{
    string word;
    int unsort;
    int a;
};
bool cmp(const DNA &c, const DNA &b)
{
    if(c.unsort != b.unsort)
        return c.unsort < b.unsort;
    else
        return c.a < b.a;
}

int main ()
{
    DNA A[105];
    int i,j,N,T,ans,M,k,p;
    while(cin >> T)
    {
        for(i = 0;i < T;i++)
        {
            cin >> N >> M;
            for(j = 0;j < M;j++)
            {
                cin >> A[j].word;
                A[j].a = j;
                A[j].unsort = 0;
                for(k = 0;k < N;k++)
                {
                    for(p = k + 1;p < N;p++)
                    {
                        if(A[j].word[p] < A[j].word[k])
                            A[j].unsort ++;
                    }
                }
            }
            sort(A,A+M,cmp);
            for(j = 0;j < M;j++)
            {
                cout << A[j].word << endl;

            }
            if(i != T - 1)
                cout <<endl;
        }

    }
}

