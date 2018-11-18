#include <iostream>
using namespace std;
int main()
{
    int N,S = 0;
    int i;
    cout << "PERFECTION OUTPUT" << endl;
    while(cin >> N)
    {
        if(N == 0)
        {
            cout << "END OF OUTPUT" << endl;
            break;
        }
        S = 0;
        for(i = 1;i < N;i++)
        {
            if(N % i == 0)
            {
                S += i;
            }
        }
        if(N < 10)
            cout << "    ";
        else if(N<100)
            cout << "   ";
        else if(N < 1000)
            cout << "  ";
        else if(N < 10000)
            cout << " ";
        cout << N;
        cout << "  ";
        if(S == N)
        {
            cout <<"PERFECT" <<endl;
        }
        else if(S > N)
        {
            cout << "ABUNDANT" << endl;
        }
        else
            cout << "DEFICIENT" << endl;
    }
}
