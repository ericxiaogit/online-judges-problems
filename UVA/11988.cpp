#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Data
{
    char n;
    Data* next;
};

Data *head, *tail,*now;
string N;
int main()
{
    while(getline(cin,N))
    {
        head = new Data;
        tail = head;
        head->next = NULL;
        now = head;
        int i;
        Data* p;
        //cout << "N = " <<N <<endl;
        for(i = 0;i < N.length();i++)
        {
            if(N[i] == '[')
            {
                now = head;
            }
            else if(N[i] == ']')
            {
                now = tail;
            }
            else
            {
                Data *temp;
                temp = now->next;
                now->next = new Data;
                now->next->n = N[i];
                now->next->next = temp;
                if(tail == now)
                    tail = tail->next;
                now = now->next;

            }
        }
        for(p = head->next;p != NULL;p = p->next)
        {
            cout << p->n;
        }
        cout << endl;

    }

}
