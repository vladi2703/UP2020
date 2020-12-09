#include <iostream>

int main()
{
    bool digit1[4];
    bool digit2[4];
    bool b1, b2; 
    std::cin >> b1;
    for (int i = 0; i < 4; i++)
    {
        digit1[3-i] = (b1 >> i) & 1;
    }
    for (int i = 0; i < 4; i++)
    {
        std::cout << digit1[i] << ' ';
    }
   
}
