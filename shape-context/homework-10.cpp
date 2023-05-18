/*
    Title: Homework 10 - Shape Context.
    Description: Main and implementation code for the 'Homework 10 - Shape Context' algorithms test-cases.

    Author: Aldo Ricardo Alonso Arostegui - A01029011

    Proffesor: Leonardo Chang Fernández
    First release: December 1st, 2021.
*/


#include <iostream>
#include <vector>
#include <math.h>

struct Coord
{
    int x, y;
};

float getAngle(Coord c1, Coord c2) { // Get distance between two coords
    float angle = atan2(c2.y-c1.y, c2.x-c1.x) * (180/3.14159265);
    if(angle < 0) {
        angle += 360;
    }
    return angle;
}

float getDistance(Coord c1, Coord c2) { // Get angle between two coords
    int dx = c2.x - c1.x;
    int dy = c2.y - c1.y;

    float* result = new float(sqrt(pow(dx, 2) + pow(dy, 2)));

    return *result;
}

void shape_context_main(std::vector<int> xArr, std::vector<int> yArr, int vertexes){
    std::vector<std::vector<std::vector<int>>> histograms;
    std::vector<Coord> coords;

    for(int i = 0; i < vertexes; i++){
        Coord p;
        p.x = xArr.at(i);
        p.y = yArr.at(i);

        coords.push_back(p);
    }
    
    for(int h = 0; h < vertexes; h++){
        std::vector<std::vector<int>> temporary;
        for(int i=0; i<5; i++){
            std::vector<int> temp;
            for(int j=0; j<12; j++){
                temp.push_back(0);
            }
            temporary.push_back(temp);
        }
        histograms.push_back(temporary);
    }

    for(int i = 0; i < vertexes; i++){
        for (int j = 0; j < vertexes; j++){
            if (i != j) {
                double sizeCutAway, angleCutAway; // Check if size or angle in cutaway
                float posDistance = getDistance(coords.at(i), coords.at(j));
                int positionSize;

                if(posDistance<=10){
                    sizeCutAway = fmod(posDistance, 2);
                    positionSize = floor(posDistance/2);

                    if(sizeCutAway==0){
                        if(positionSize!=0){
                            positionSize -= 1;
                        }
                    }
                }

                float positionAngle = getAngle(coords.at(i), coords.at(j));
                int posAngle = floor(positionAngle/30);
                angleCutAway = fmod(positionAngle, 30);

                if (angleCutAway == 0){
                    if(posAngle != 0) {
                        posAngle = posAngle - 1;
                    }
                }

                if(posDistance <= 10){
                    histograms.at(i).at(positionSize).at(posAngle) += 1;
                }
            }
        }
    }
    
    for(int i=0; i<vertexes; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<12; k++){
                if(k<11){
                std::cout << histograms.at(i).at(j).at(k) << " ";
                } else {
                    std::cout << histograms.at(i).at(j).at(k);
                }
            }
            std::cout << std::endl;
        }
        if (i<vertexes-1) {
            std::cout << std::endl;
        }
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> xArr;
    std::vector<int> yArr;

    int vertexesCount = atoi(argv[1]);

    for(int i = 2; i < vertexesCount+2; i++){
        xArr.push_back(atoi(argv[i]));
        yArr.push_back(atoi(argv[i+vertexesCount]));
    }

    shape_context_main(xArr, yArr, vertexesCount);
    return 0;
}
