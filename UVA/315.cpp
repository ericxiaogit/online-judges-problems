#include<bits/stdc++.h>
using namespace std;
vector<int> net[100+5];
vector<int> foredge[100+5];
vector<int> backedge[100+5];
int low[100+5];
int visited[100 +5];
int seq[100 + 5];
int p,ans;
void DFS(int num,int dad)
{

    seq[num] = p+1;
    p++;
    visited[num] = 1;
    int i;
    for(i = 0;i < net[num].size();i++)
    {
        if(visited[net[num][i]] == 0)
        {
            //visited[net[num][i]] = 1;
            foredge[num].push_back(net[num][i]);
            DFS(net[num][i],num);
        }
        else if(net[num][i] != dad)
        {
            backedge[num].push_back(net[num][i]);
        }
    }
}
int find_low(int num)
{
    int i;
    if(low[num] != 0) return low[num];
    low[num] = seq[num];
    for(i = 0;i < backedge[num].size();i++)
    {
        //cout << 1 << num << " " << i << endl;
        low[num] = min(low[num],seq[backedge[num][i]]);

    }
    for(i = 0;i < foredge[num].size();i++)
    {
        //cout << 2 << num << " " << i << endl;
        low[num] = min(low[num],find_low(foredge[num][i]));

    }
    return low[num];

}
int main()
{
    int N,i,j,k,temp,q,flag;
    char trash;
    while(cin >> N)
    {
        p = 0;
        ans = 0;
        i = 0;
        j = 0;
        temp = 0;
        q = 0;
        flag = 0;
        if(N == 0) break;
        for(i = 0;i <= N;i++)
        {
            net[i].clear();
            foredge[i].clear();
            backedge[i].clear();
            low[i] = 0;
            visited[i] = 0;
            seq[i] = 0;
        }
        while(cin >> temp)
        {
            if(temp == 0) break;
            while(1)
            {
                cin >> k;
                net[temp].push_back(k);
                net[k].push_back(temp);
                cin.get(trash);
                if(trash == '\n') break;
            }
        }
        DFS(1,-1);
        for(i = 1;i <= N;i++)
        {
            q = find_low(i);
        }
        flag = 0;
        for(i = 2;i <= N;i++)
        {
            flag = 0;
            for(j = 0;j < foredge[i].size();j++)
            {
                if(low[foredge[i][j]] >= seq[i])
                {
                    flag = 1;
                }
            }
            if(flag == 1)
                ans++;
        }
        if(foredge[1].size() > 1)
            ans++;
        cout <<ans <<endl;

    }

}



