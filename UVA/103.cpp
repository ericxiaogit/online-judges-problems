#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
struct T
{
    int arr[50];
    int index;
};
T A[50];
int ans[100];
int from[100];
int last[50];
int M;
bool cmp(const T &a,const T &b)
{
    int i = 0;
    while(i < M)
    {
        if(a.arr[i] != b.arr[i])
        {
            return a.arr[i] < b.arr[i];
        }
        i++;
    }
    return 0;
}
int main()
{
    int N,i,j,k,temp,head,p;
    while(cin >> N >> M)
    {
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < M;j++)
            {
                cin >> A[i].arr[j];
            }
            A[i].index = i+1;
            sort(A[i].arr,A[i].arr+M);
        }
        sort(A,A+N,cmp);
        /*
        for(i = 0;i <N;i++)
        {

            cout << A[i].index <<":" <<endl;
            for(j = 0;j < M;j++)
            {
                cout << A[i].arr[j] << " ";
            }
            cout <<endl;
        }*/
        for(i = 0;i < N;i++)
        {
            ans[i] = 1;
            from[i] = i;
            for(j = 0;j < i;j++)
            {
                temp = 0;
                for(k = 0;k < M;k++)
                {
                    if(A[i].arr[k] <= A[j].arr[k])
                    {
                        temp = 1;
                        break;
                    }
                }
                if(temp == 0)
                {
                    if(ans[j] + 1 > ans[i])
                    {
                        ans[i] = ans[j] + 1;
                        from[i] = j;
                    }
                }
                //cout <<"i = " << i << " j = " << j << " " << temp << endl;
            }
        }
        head = 0;
        temp = 0;

        for(i = 0;i < N;i++)
        {
            if(ans[i] > temp)
            {
                temp = ans[i];
                head = i;
            }
            //cout << from[i] <<" ";
        }
        p = 0;
        while(1)
        {
            last[p] = head;
            p++;
            if(from[head] == head) break;
            head = from[head];
        }
        /*
        cout << temp <<endl;
        for(i = p-1;i >= 0;i--)
        {
            cout << last[i];
            if(i != 0)
                cout << " ";
        }
        cout <<endl;*/
        cout << p << endl;
        for(i = p-1;i >= 0;i--)
        {
            cout << A[last[i]].index;
            if(i != 0)
                cout << " ";
        }
        cout << endl;

    }

}



