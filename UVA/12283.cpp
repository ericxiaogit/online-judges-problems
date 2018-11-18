#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int N,M,head,now;
int A[105];
int stacks[100000];
int last[100000];
int greedy(int a)
{

    if(a >= N)
    {
        return now;
    }
    if(head == 0)
    {
        stacks[0] = A[0];
        head++;
        now++;
        int temp = greedy(a + 1);
        now--;
        head--;
        return temp;
    }
    int tempa,tempb;
    stacks[head] = A[a];
    head++;
    now++;
    tempa = greedy(a + 1);
    head--;
    now--;
    int i,place = -1;
    for(i = head-1;i >= 0;i--)
    {
        if(stacks[i] == A[a])
            place = i;
    }
    //cout << " a = " << a <<" head = " << head <<endl;
    //for(int j = 0;j < head;j++)
    //{
    //    cout << stacks[j] << " ";
    //}
    //cout << endl;
    //cout <<"place = " << place << endl;
    if (place == -1)
        return tempa;
    int lasth = head;
    head = place+1;
    for(int j = lasth;j < head;j++)
    {
        last[j] = stacks[j];
    }
    tempb = greedy(a + 1);
    for(int j = lasth;j < head;j++)
    {
        stacks[j] = last[j];
    }
    head = lasth;
    return min(tempa,tempb);

}
int main()
{
    int i,a,b,c,d,temp,j,t,big,K;
    int rolls,cig,ans;
    cin >> K;
    for(i = 0;i < K;i++)
    {
        cin >> N>> M;
        for(j = 0;j < N;j++)
        {
            cin >> A[j];
        }
        head = 0;
        now = 0;
        cout << "Case " << i+1 << ": ";
        cout <<greedy(0) << endl;
    }
}

