#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, counter = 1;
    double k, k1 = 1, k2 = 0, step = 1, answer;
    cout << "Enter number: ";
    cin >> k;
    
    while(k < 0)
    {
        cout << "Enter nonnegative number: ";
        cin >> k;
    }

    cout << "How many numbers after decimal point: ";
    cin >> n;

    while(n < 0)
    {
        cout << "Enter nonnegative number for numbers after dot: ";
        cin >> n;
    }

    for(int i = 0; i <= n; i++) // factor function
    {
        step /= 10;
    }

    k1 = 1;
    k2 = k / 2;

    for(double i = 1; i >= k * step; i /= 10)
    {

        for(double j = k1; j < k2; j += i)
        {
            if(j * j < k && (j + i) * (j + i) > k)
            {
                k1 = j;
                k2 = j + i;
                counter++;
            }
        }
        answer = k1;

        if(i * i == k)        // има точен корен
        {
            cout << i << '.';
            for(int i = 0; i < n; i++)
            {
                cout << '0';
            }

                cout << "\n";
        }
    }

    cout << fixed << showpoint;
    cout << setprecision(n);
    cout << answer;

    return 0;
}
