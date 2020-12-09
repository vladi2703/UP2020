#include <iostream>

int main()
{
    double x1, x2, x3, y1, y2, y3;
    std::cin >>
        x1 >> y1 >>
        x2 >> y2 >>
        x3 >> y3;
    double slope1and2 = (y2 - y1) / (x2 - x1);
    double slope2and3= (y3 - y2) / (x3 - x2);
    if (slope1and2 == slope2and3)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No"; 
    }

}