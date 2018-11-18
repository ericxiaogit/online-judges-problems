#include <iostream>
#include <algorithm>
using namespace std;
struct Point
{
    int x;
    int y;
};
Point A[4];
int main()
{
    int i,j,N,temp;
    double m,n;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < 4;j++)
            {
                cin >> A[j].x >> A[j].y;
            }
            cout << "Case " << i + 1 << ": ";
            temp = 0;
            while(1)
            {
                temp++;
                if(A[0].x == A[2].x)
                {
                    //cout << "hello" << endl;
                    if(A[1].x < A[0].x && A[3].x > A[0].x)
                        break;
                    else if(A[1].x > A[0].x && A[3].x < A[0].x)
                        break;
                }
                else
                {
                    m = ((double)(A[2].y - A[0].y)/(double)(A[2].x - A[0].x));
                    n = ((double)A[0].y - m*(double)A[0].x);
                    if(A[1].y > A[1].x*m + n && A[3].y < A[3].x*m + n) break;
                    else if(A[1].y < A[1].x*m + n && A[3].y > A[3].x*m + n) break;
                }
                //cout << m <<" " << n << endl;
                //ystem("pause");
                swap(A[1],A[2]);
                swap(A[2],A[3]);
                if(temp > 5)
                {
                    cout << "Ordinary Quadrilateral" << endl;
                    break;
                }

            }
            if(temp >5)
                continue;
            if((A[0].y - A[1].y) * (A[1].y - A[2].y) == (-1) * (A[0].x - A[1].x) * (A[1].x - A[2].x) && (A[1].y - A[2].y) * (A[2].y - A[3].y) == (-1) * (A[1].x - A[2].x) * (A[2].x - A[3].x) && (A[2].y - A[3].y) * (A[3].y - A[0].y) == (-1) * (A[2].x - A[3].x) * (A[3].x - A[0].x))
            {
                if((A[0].x - A[1].x)*(A[0].x - A[1].x) + (A[0].y - A[1].y)*(A[0].y - A[1].y) == (A[2].x - A[1].x)*(A[2].x - A[1].x) + (A[2].y - A[1].y)*(A[2].y - A[1].y))
                {
                    cout << "Square" <<endl;
                }
                else
                    cout << "Rectangle" << endl;
            }
            else if(A[0].x + A[2].x == A[1].x + A[3].x && A[0].y + A[2].y == A[1].y + A[3].y)
            {
                if((A[0].y - A[2].y) * (A[1].y - A[3].y) == (-1) * (A[0].x - A[2].x) * (A[1].x - A[3].x))
                    cout << "Rhombus" << endl;
                else
                    cout << "Parallelogram" << endl;
            }
            else if((A[0].y - A[1].y) * (A[2].x - A[3].x) == (A[2].y - A[3].y) * (A[0].x - A[1].x) || (A[0].y - A[3].y) * (A[2].x - A[1].x) == (A[2].y - A[1].y) * (A[0].x - A[3].x))
                cout << "Trapezium" << endl;
            else
                cout << "Ordinary Quadrilateral" << endl;
        }
    }

}
