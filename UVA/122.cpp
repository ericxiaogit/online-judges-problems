#include<iostream>
#include<algorithm>
using namespace std;
int ans;
int head,tail;
struct Tree
{
    int num;
    bool empt;
    Tree *left,*right;
}*root;
Tree* create()
{
    Tree *p = new Tree;
    p -> num = 0;
    p->empt = false;
    p->left = NULL;
    p->right = NULL;
    return p;

}
Tree* A[10000000];
void add(int in,string sr,Tree *s,int now)
{
    /*
    if(s->empt == 0)
    {
        s->empt = true;
        s->num = in;
    }*/
    if(now == sr.length()&& s->empt == 0)
    {
        s-> num = in;
        s->empt = 1;
        return;
    }
    else if(sr[now] == 'R')
    {
        if(s->right == NULL)
        {
            s->right = create();
        }
        add(in,sr,s->right,now + 1);
    }
    else if(sr[now] == 'L')
    {
        if(s->left == NULL)
        {
            s->left = create();
        }
        add(in,sr,s->left,now+1);
    }
    else
    {
        ans = 1;
    }
}
void show(Tree* s)
{
    if(s == NULL)
    {
        return;
    }
    show(s->left);
    cout << s->num << " ";
    show(s->right);
    return;
}
bool searc(Tree *s,int goal)
{
    if(s == NULL)
        return false;
    if(s->num == goal)
        return true;
    else if(s->num < goal)
    {
        searc(s->right,goal);
    }
    else
    searc(s->left,goal);
}

int main()
{
    int N,i,a,b,j,k,si,counts;
    char c;
    root = create();
    //root->empt = 0;
    string str,temp;
    ans = 0;
    root->empt = 0;
    counts = 0;
    while(cin >> str)
    {
        if(str == "()")
        {
            ans = 0;
            root->empt = 0;
            //show(root);
            head = 0;
            tail = 0;
            A[head] = root;
            tail++;
            while(head != tail)
            {
                if(A[head] -> num == 0)
                {
                    ans = 1;
                    break;
                }
                if(A[head] -> left != NULL)
                {
                    A[tail] = A[head]->left;
                    tail++;
                }
                if(A[head] -> right != NULL)
                {
                    A[tail] = A[head]->right;
                    tail++;
                }
                head ++;
            }
            if(head == counts && ans == 0)
            {
                for(i = 0;i < head;i++)
                {
                    cout << A[i]->num;
                    if(i != head - 1)
                        cout << " " ;
                }
                cout << endl;
            }
            else
            {
                cout << "not complete" << endl;
            }
            root = create();
            ans = 0;

        }
        else
        {
            a = 0;
            temp = "";
            for(i = 1;str[i] <= '9' && str[i] >= '0';i++)
            {
                a = a*10;
                a += str[i] - '0';
                si = i;
            }

            for(i = si + 2;i < str.length() - 1;i++)
            {
                temp = temp + " ";
                temp[temp.length() - 1] = str[i];
            }
            //cout << "temp = " << temp << endl;
            counts ++;
            add(a,temp,root,0);
        }
    }

}
