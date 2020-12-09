#include <iostream>
#include <cmath>
using namespace std;

int main ()
{

int nRound, lastDigit, sinXtoN, abslastDigit;
float X, sinX, cosX, sinXrounded;
cout << "Enter X (rad) = ";
cin >> X;
cout << "Enter nRound = ";
cin >> nRound;

double sine, cosine;
sine = sin(X / 180);
cout << "sinX = " << sine << endl;
cosine = cos(X / 180);
//cout << "cosX = " << cosine << endl;

sinXtoN = sine * pow(10,nRound+1);
//cout << "sin X to 10^n = " << sinXtoN << endl;
lastDigit = sinXtoN % 10;
abslastDigit = abs(lastDigit);
//cout << "Last digit = " << abslastDigit << endl;


if (abslastDigit < 5) 
{
    sinXtoN -= lastDigit;
   sinXrounded = sinXtoN / pow(10, nRound+1);
  cout << "sinX rounded= " << sinXrounded << endl;
}

else if (abslastDigit >=5)
{
    if (sinXtoN<0)
    {
        sinXtoN = sinXtoN - lastDigit-10;
    }
    else
    {
        sinXtoN = sinXtoN - lastDigit + 10;

    }
    
    //cout << "New sinXtoN = " << sinXtoN << endl;
    sinXrounded = sinXtoN / pow(10, nRound+1);
    cout << "sinX rounded = " << sinXrounded << endl;
}

    return 0;
}