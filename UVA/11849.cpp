#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int num;
    Node* next;
};
Node* hashs[100291];
void clears(Node *s)
{
    if(s->next != NULL)
    {
        clears(s->next);
        delete s->next;
    }

}
int main()
{
    long long int N,M,i,j,found,temp,t;
    Node *r;
    for(i = 0;i < 100291;i++)
    {
        hashs[i] = new Node;
        hashs[i]->next = NULL;
    }
    while(cin >> N >> M)
    {
        if(N == 0 && M == 0) break;
        found = 0;
        for(i = 0;i < 100291;i++)
        {
            clears(hashs[i]);
            hashs[i]->next = NULL;
        }
        for(i = 0;i < N;i++)
        {
            cin >> temp;
            t = temp % 100291;
            if(hashs[t]->next == NULL)
            {
                hashs[t]->next = new Node;
                hashs[t]->next->num = temp;
                hashs[t]->next->next = NULL;
            }
            else
            {
                r = new Node;
                r->num = temp;
                r->next = hashs[t]->next;
                hashs[t]->next = r;
            }
        }
        for(i = 0;i <M;i++)
        {
            cin >> temp;
            t = temp % 100291;
            for(r = hashs[t];r->next != NULL;r = r->next)
            {
                if(r->next->num == temp)
                {
                    found ++;
                    break;
                }
            }
        }
        cout << found << endl;
    }
}
