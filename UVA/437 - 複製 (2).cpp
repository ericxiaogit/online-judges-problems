#include<bits/stdc++.h>
using namespace std;
deque<pair<long long ,long long>> mn;
deque<pair<long long ,long long>> mx;
vector<pair<long long,long long>> ans;
int main()
{
    long long int N,M,K,i,temp;
    cin >> N >> M >> K;
    for(i = 1;i <= N;i++)
    {
        cin >> temp;
        if(mx.size() > 0 && mx.front().second + M <= i)
        {
            mx.pop_front();
        }
        if(mn.size() > 0 && mn.front().second + M <= i)
        {
            mn.pop_front();
        }
        while(mx.size() > 0 && mx.back().first < temp)
        {
            mx.pop_back();
        }
        mx.push_back({temp,i});
        while(mn.size() > 0 && mn.back().first > temp)
        {
            mn.pop_back();
        }
        mn.push_back({temp,i});
        if(mx.front().first-mn.front().first==K)
        {
            ans.push_back({max((long long)1,i-M+1),i});
        }
    }
    for(i = N-M+2;i < N;i++)
    {
        if(mx.size() > 0 && mx.front().second < i)
        {
            mx.pop_front();
        }
        if(mn.size() > 0 && mn.front().second < i)
        {
            mn.pop_front();
        }
        if(mx.front().first-mn.front().first==K)
        {
            ans.push_back({i,N});
        }
    }
    cout <<ans.size() << endl;
    for(i = 0;i < ans.size();i++)
    {
        cout <<ans[i].first << " " << ans[i].second <<endl;
    }

}
