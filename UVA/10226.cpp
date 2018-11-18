#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int sum;
struct Tree
{
    string str;
    int much;
    bool empt;
    Tree *left,*right;
}*root;
Tree* create()
{
    Tree *p = new Tree;
    p->empt = false;
    p->left = NULL;
    p->right = NULL;
    p->much = 0;
    return p;

}
void add(Tree *s,string r)
{
    if(s->empt == 0)
    {
        s->empt = true;
        s->str = r;
        s->much++;
    }
    else if(s->str < r)
    {
        if(s->right == NULL)
        {
            s->right = create();
        }
        add(s->right,r);
    }
    else if(s->str > r)
    {
        if(s->left == NULL)
        {
            s->left = create();
        }
        add(s->left,r);
    }
    else
    {
        s->much ++;
    }
}
void show(Tree* s)
{
    if(s == NULL)
    {
        return;
    }
    show(s->left);
    cout << s->str << " ";
    double w = (s->much)*100.0/sum;
    //cout <<w <<endl;
    printf("%.4f\n",w);
    show(s->right);
    return;
}
/*
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
}*/
int main()
{
    int N,i,a,b,j,k;
    char c;
    string temp;
    root = create();
    //root->empt = 0;
    cin >> N;
    getline(cin,temp);
    getline(cin,temp);
    sum = 0;
    for(i = 0;i < N;i++)
    {
        //cout << "i = " << i << endl;
        while(getline(cin,temp))
        {
            //cout << "[" << temp << "]" <<endl;
            if(temp == "")
            {
                //cout << "hello" << endl;
                if(i != N-1)
                    show(root);
                cout << endl;
                sum = 0;
                root = create();
                break;
            }
            sum ++;
            add(root,temp);
        }
        //cout << endl;


    }
    show(root);
}
