//
//  main.cpp
//  Homework_09
//
//  Created by Aldo Ricardo Alonso Arostegui on 12/11/21.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool turnsLeft(std::pair<int,int> pointOne, std::pair<int,int> pointTwo, std::pair<int,int> pointThree)
{
    std::pair<int,int> v1, v2;
    
    v1 = std::make_pair(pointTwo.first - pointOne.first, pointTwo.second - pointOne.second);
    v2 = std::make_pair(pointThree.first - pointOne.first, pointThree.second - pointOne.second);
    
    return v1.first*v2.second - v1.second*v2.first > 0 ? false : true;
}

std::vector<std::pair<int, int>> Convex_Hull(std::vector<std::pair<int, int>> points)
{
    std::vector<std::pair<int, int>> L;
    
    for (int i = 0; i < 2; i++) {
        L.push_back(points.at(i));
    }
    
    for (int i = 2; i < points.size(); i++) {
        L.push_back(points.at(i));
        
        while (L.size() > 2 && turnsLeft(L.at(L.size()-3), L.at(L.size()-2), L.at(L.size()-1))) {
            L.erase(L.end()-2);
        }
    }
    
    return L;
}

std::vector<std::pair<int, int>> sortFromOther(std::vector<std::pair<int, int>> toSort, std::vector<std::pair<int, int>> original)
{
    std::vector<std::pair<int, int>> result;
    
    for (auto element : original) {
        if (std::find(toSort.begin(), toSort.end(), element) != toSort.end()) {
                result.push_back(element);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::pair<int, int>> points;
    std::vector<std::pair<int, int>> pointsOriginal;
    
    int* numberOfPoints = new int(atoi(argv[1]));
    
    for (int i = 2; i < *numberOfPoints+2; i++) {
        points.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+*numberOfPoints])));
    }
    
    pointsOriginal = points;
    
    std::sort(points.begin(), points.end());
    std::vector<std::pair<int, int>> L_Upper = Convex_Hull(points);

    std::sort(points.rbegin(), points.rend());
    std::vector<std::pair<int, int>> L_Lower = Convex_Hull(points);

    L_Lower.erase(L_Lower.end()-1);
    L_Lower.erase(L_Lower.begin());

    std::vector<std::pair<int, int>> result = L_Upper;
    L_Upper.clear();

    result.insert(result.end(), L_Lower.begin(), L_Lower.end());
    
    result = sortFromOther(result, pointsOriginal);
    
    for (auto point : result) {
        std::cout << point.first << ' ' << point.second << std::endl;
    }
}
