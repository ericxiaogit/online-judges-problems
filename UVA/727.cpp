#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
string stac[100];

int main()
{
    int N,i,j,k,head;
    string a;
    char c;
    cin >> N;
    getline(cin ,a);
    getline(cin ,a);
    //cout << "a = " << a << endl;
    for(i = 0;i < N;i++)
    {
        //getline(cin,a);
        head = 0;
        while(getline(cin,a))
        {
            if(a == "") break;
            if(a[0] <='9' && a[0] >= '0')
            {
                cout << a;
            }
            else if(head == 0)
            {
                stac[head] = a;
                head++;
            }
            else if(a == "+" || a == "-")
            {
                while(head > 0 && (stac[head - 1] == "*" || stac[head - 1] == "/" || stac[head - 1] == "+" || stac[head - 1] == "-"))
                {
                    //cout << 111 << endl;
                    head--;
                    cout << stac[head];
                }
                stac[head] = a;
                head++;
            }
            else if(a == "*" || a == "/")
            {
                while(head > 0 && (stac[head - 1] == "*" || stac[head - 1] == "/"))
                {
                    //cout << 111 << endl;
                    head--;
                    cout << stac[head];
                }
                stac[head] = a;
                head++;
            }
            else if(a == "(")
            {
                stac[head] = a;
                head++;
            }
            else if(a == ")")
            {
                //cout << "sh = " << head << endl;
                while(stac[head - 1] != "(")
                {
                    head--;
                    cout << stac[head];
                    //cout <<"head = " << head << endl;
                    //system("pause");
                }
                head--;
            }
            //cout << "nowh = " << head << endl;
        }
        for(j = head-1;j >= 0;j--)
            cout << stac[j];
        cout << endl;
    }


}

