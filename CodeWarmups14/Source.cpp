#include <iostream>
#include <string>
#include <vector>
struct Point { int x; int y; };

std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;
    // TODO: write code that "splits" the input string by the seperator
    int i = 0;
    std::string substring;
    while (str[i] != '\0')
    {
        if (str[i] != seperator)
        {
            substring.push_back(str[i]);
        }
        else
        {
            if (substring != "")
            {
                result.push_back(substring);
            }
            substring.clear();
        }

        i++;
    }
    if (substring != "")
    {
        result.push_back(substring);
    }


    // store each word in the resuts.

    return result;
}

std::vector<Point> ParsePointString(const std::string& sPoints)
{
    std::vector<Point> result;
    
    Point point;

    auto points = Explode(' ', sPoints.c_str());

    for (auto pointsToSep : points)
    {
        auto sepPoints = Explode(',', pointsToSep.c_str());
        point.x = std::stoi(sepPoints[0]);
        point.y = std::stoi(sepPoints[1]);
        result.push_back(point);
    }
    return result;
}
int main(int argc, char** argv)
{
    std::string sPoints = "0,0 -3,-214 187,-422 196,-862 -95,-1044 -461,-1219 -732,-1310 -950,-1338 -1213,-1339";
    auto points = ParsePointString(sPoints);
    for (auto& point : points)
    {
        std::cout << point.x << "\t" << point.y << std::endl;
    }
    return 0;
}