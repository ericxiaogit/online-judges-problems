#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
struct Web
{
    string name;
    int ranks;
    int order;
};
Web A[100];
bool cmp(const Web &a,const Web &b)
{
    if(a.ranks != b.ranks)
        return a.ranks > b.ranks;
    return a.order < b.order;
}
int main()
{
    int N,i,j;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < 10;j++)
            {
                cin >> A[j].name >> A[j].ranks;
                A[j].order = j;
            }
            sort(A,A+10,cmp);
            cout << "Case #" << i+1 << ":" << endl;
            cout << A[0].name << endl;
            for(j = 1;j < 10;j++)
            {
                if(A[j].ranks == A[j- 1].ranks)
                    cout <<A[j].name << endl;
                else
                    break;
            }
        }
    }

}



