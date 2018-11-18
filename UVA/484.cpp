#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

struct num{
    int n,times;
};
bool cmp(const num &a,const num&b)
{
    return a.times <= b.times;
}
int main(){
    vector<num> A;
    int i,N;
    while(cin >> N)
    {
        for(i = 0;i < A.size();i++)
        {
            if(A[i].n == N)
            {
                A[i].times ++;
                break;
            }
        }
        if(i == A.size())
        {
            num temp;
            temp.n = N;
            temp.times = 1;
            A.push_back(temp);
        }
    }
    sort(A.begin(),A.end(),cmp);
    for(i = 0;i < A.size();i++)
    {
        cout << A[i].n << " " << A[i].times << endl;
    }
}
