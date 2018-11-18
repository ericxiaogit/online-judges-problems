#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 100000
int queue_front, queue_back;
bool visited[9][9];
struct Bot
{
    int y,step;
    char x;//fill a = 1;pour a to b = 2;empty a = 3
                       //fill b = 4;pour b to a = 5;empty b = 6
};
int ans;
Bot queue[SIZE];

//Bot queue[SIZE];
int main()
{
    //string a;
    int i,j;
    double x1,y1,x2,y2,x3,y3;
    double something,before;
    double a,b,c,r;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3)
    {
        /*
        if(x1 == x2 || y1 == y2)
        {
            swap(x2,x3);
            swap(y2,y3);
        }
        if(x2 == x3)
        {
            swap(x1,x2);
            swap(y1,y2);
        }
        something = (x1 + x2)/2 + (y1 - y2)*(y1 - y3)/(2*(x1-x2));
        before = 2*(y2 - y3)*(x1 - x2)/((x2 -x3) * (y1 - y2));
        a = ((something * before)- x2 -x3)/(before - 2);
        if(y2 == y3)
        {
            swap(x1,x2);
            swap(y1,y2);
        }

        b = (y2 + y3)/2 + (x2 - x3) * (x2 + x3 - 2*a)/(2*(y2 - y3));
        r = sqrt((x1 - a)* (x1 -a) + (y1 - b) * (y1 - b));
        */
        //cout << a << " " << b << " " << r << endl;
        //printf("%.2Lf\n",2 * r * 3.141592653589793);
        a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        b = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
        c = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
        double s = (a + b + c)/2;
        double area = sqrt(s*(s - a)*(s - b) * (s - c));
        r = a*b*c/(area*4);
        int temp = ((2 * r * 3.141592653589793+0.005)*100);	//四捨五入到
        double ans = (double)temp/100;	//小數點第三位
        printf("%.2lf\n",ans);

    }
}

