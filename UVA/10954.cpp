#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int heap[100000];
int head;
void add(int s)
{
    heap[head] = s;
    int y = head;
    while(y != 1)
    {
        if(heap[y] < heap[y/2])
        {
            swap(heap[y],heap[y/2]);
            y = y/2;
        }
        else break;
    }
    head++;

}
int pop()
{
    int p = heap[1];
    heap[1] = heap[head - 1];
    head--;
    int y = 1;
    while(1)
    {
        if(y*2 >= head) break;
        else if(y*2 + 1 >= head)
        {
            if(heap[y] > heap[y*2])
                swap(heap[y],heap[y*2]);
            break;
        }
        else if(heap[y] < heap[y*2] && heap[y] < heap[y*2+1]) break;
        if(heap[y*2] <= heap[y*2+1])
        {
            swap(heap[y],heap[y*2]);
            y = y*2;
        }
        else
        {
            swap(heap[y],heap[y*2+1]);
            y = y * 2 + 1;
        }
    }
    return p;
}
int main()
{
    int SZ,P,i,x,y,temp,N,a,b,ans;
    double t;
    while(cin >> N)
    {
        if(N == 0) break;
        ans = 0;
        head = 1;
        for(i = 0;i < N;i++)
        {
            cin >> temp;
            add(temp);
        }
        /*
        for(i = 1;i < head;i++)
        {
            cout << heap[i] <<" ";
        }*/
        //cout << endl;
        while(head > 2)
        {
            a = pop();
            b = pop();
            //cout << a << " " << b <<endl;
            ans += (a +b);
            add(a + b);
        }
        cout << ans << endl;
    }


}

