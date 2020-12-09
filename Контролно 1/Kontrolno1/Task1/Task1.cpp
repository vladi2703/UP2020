#include <iostream>

int main()
{
    
    bool digit1[4];
    bool digit2[4];
    bool result[5] = {};
    bool naum = false;
 
    //Ne sum uspql da konvertiram vhoda chrez pobitovi
    //otmestvaniq, zatova go vkarvame kato otdelni bulevi
    for (int i = 0; i < 4; i++)
    {
        std::cin >> digit1[i];
    }
    for (int i = 0; i < 4; i++)
    {
        std::cin >> digit2[i];
    }
    for (int i = 3; i > 0; i--)
    {
        if (digit1[i] && digit2[i] && naum)
        {
            result[i + 1] = true;
            naum = true;
        }
        else if ((digit1[i] || digit2[i]) && naum)
        {
            result[i + 1] = false;
            naum = true;
        }
        else if (!(digit1[i] && digit2[i]) && naum)
        {
            result[i + 1] = true;
            naum = false;
        }
        
        else if (digit1[i] && digit2[i])
        {
            result[i + 1] = false;
            naum = true;
        }
        else if (digit1[i] || digit2[i])
        {
            result[i + 1] = true;
            naum = false;
        }
    }
    if (naum)
    {
        result[0] = true;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << result[i];
    }



}