#include <iostream>
#include <algorithm>   // min and max

int main()
{
    bool doOverlap = true;
    unsigned int area, width, height;
    int bottomLeftX1, bottomLeftY1, width1, height1;
    int bottomLeftX2, bottomLeftY2, width2, height2;
    int topRightX1, topRightY1;
    int topRightX2, topRightY2;
    std::cin >> bottomLeftX1 >> bottomLeftY1 >> width1 >> height1;
    std::cin >> bottomLeftX2 >> bottomLeftY2 >> width2 >> height2;

    topRightX1 = bottomLeftX1 + width1;
    topRightY1 = bottomLeftY1 + height1;

    topRightX2 = bottomLeftX2 + width2;
    topRightY2 = bottomLeftY2 + height2;

    if (topRightX1 < bottomLeftX2 || bottomLeftX1 > topRightX2)
    {
        doOverlap = false;
    }
    else if (bottomLeftX1 > topRightY2 || topRightY1 < bottomLeftY2)
    {
        doOverlap = false;
    }
    if (!doOverlap)
    {
        area = 0;
    }
    else
    {
        width = std::min(topRightX1, topRightX2) - std::max(bottomLeftX1, bottomLeftX2); //min and max могат да бъдат заменени с тернарен оператор
        height = std::min(topRightY1, topRightY2) - std::max(bottomLeftY1, bottomLeftY2); 
        area = width * height; 
    }

     std::cout << area << std::endl;
       
    return 0;
}
