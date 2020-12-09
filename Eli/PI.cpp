#define  _USE_MATH_DEFINES
#include  <iostream>
#include  <cmath>
#include  <iomanip>

using namespace std;

int main ()

{
    double  pi3_14 = 3.14;
    double  myDoublePi = 3.141592653589793;
    cout << setprecision(22);
    cout << "PI as the 3.14 approximation = " << pi3_14 << endl
         << "C++ PI in double precision   = " << M_PI << endl
         << "My PI in double precision    = " << myDoublePi << endl;
    return 0;
}
