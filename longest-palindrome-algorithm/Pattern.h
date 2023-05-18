/*
    Title: Homework 04 - Longest palindrome algorithm.
    Description: Header and implementation code for Pattern class.

    Author: Aldo Ricardo Alonso Arostegui - A01029011

    Proffesor: Leonardo Chang Fernández
    First release: September 22nd, 2021.
*/



#ifndef PATTERN_H
#define PATTERN_H
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>



class Pattern
{
    public:
        Pattern(){};
        Pattern(std::string _text);
        virtual ~Pattern();

        void setText(std::string _text) { text = _text; };

        std::vector<int> boyerMooreMatches(std::string str);
        void boyerMooreMatchesPrint(std::string str);

        void printLargestPalindromeLine(std::string line);
        void printLargestPalindromeFile(std::istream& file);
        void print_LCS_file(std::istream& fileX, std::istream& fileY);

    private:
        std::string text;
        std::map<char, std::vector<int>> bcr_table;
        std::vector<int> gsr_table;
        std::vector<char> t;                            // Value t for the palindrome algorithm.

        void setBcr_table();                            // Fills the BCR-heuristic-method table with the required values.
        int r(int index, char x);
        int getBcrMove(int index, char x);              // Gets the BCR heuristic optimum steps to move to the right.

        void setGsr_table();
        int getGsr(int index);
        int getGsrMove(int index);                      // Gets the GSR heuristic optimum steps to move to the right.

        void setT(std::string _t);

        std::pair<int, int> getLargestPalindromeLine(std::string line);

        std::pair<int, int> longest_common_string(std::string textX, std::string textY);
};





Pattern::Pattern(std::string _text)
{
    text = _text;
}

Pattern::~Pattern()
{
    text.clear();
    t.clear();
}

void Pattern::setBcr_table()                // Fills the BCR-heuristic-method table with the required values.
{
    std::vector<int> toAdd;

    for (int i = text.length() - 1; i >= 0; i--) {
        if (bcr_table.find(text.at(i)) != bcr_table.end()) {
            bcr_table[text.at(i)].push_back(i);
        } else {
            toAdd.push_back(i);
            bcr_table[text.at(i)] = toAdd;

            toAdd.clear();
        }
    }
}

int Pattern::r(int index, char x)
{
    if (bcr_table.find(x) != bcr_table.end()) {
        for (int i = 0; i < bcr_table[x].size(); i++) {
            if (index > bcr_table[x].at(i)) {
                return bcr_table[x].at(i);
            }
        }
    }
    return -1;
}

int Pattern::getBcrMove(int index, char x)  // Gets the BCR heuristic optimum steps to move to the right.
{
    int r = this->r(index, x);

    if (r != -1) {
        return index-r;
    }

    return text.size();
}

void Pattern::setGsr_table()
{
    if (text != "") {
        gsr_table.insert(gsr_table.end(), text.size(), -1);

        for (int i = ceil(text.size()/2); i < text.size(); i++) {
            gsr_table.at(i) = this->getGsr(i);
        }
    }
}

int Pattern::getGsr(int index)             // Gets the GSR heuristic optimum steps to move to the right.
{
    std::string alpha = text.substr(index, text.size()-index);

    for (index -= alpha.size(); index >= 0; index--) {
        if (text.substr(index, alpha.size()) == alpha) {
            return text.size()-alpha.size()-index;
        }
        index--;
    }

    for (index = alpha.size(); index > 0; index--) {
        if (text.substr(0, index) == alpha.substr(alpha.size()-index, index)) {
            return text.size()-index;
        }
    }

    return text.size();
}

int Pattern::getGsrMove(int index)
{
    if (index >= text.size()) { return 0; }

    return index >= ceil(text.size()/2) ? gsr_table.at(index) : text.size();
}

std::vector<int> Pattern::boyerMooreMatches(std::string str)
{
    std::vector<int> positions;
    int savedIndex;
    int i = 0;

    this->setBcr_table();
    this->setGsr_table();

    while (i+text.size() <= str.size()) {
        savedIndex = text.size()-1;

        for (int j = text.size()-1; j >= 0 && str.at(i+j) == text.at(j); j--) {
            savedIndex = j;

            if (j == 0) {
                positions.push_back(i);
                savedIndex = text.size()-1;
            }
        }

        i += std::max({this->getBcrMove(savedIndex, str.at(savedIndex < text.size()-1 ? savedIndex+i+1 : savedIndex+i)), this->getGsrMove(savedIndex+1), 1});
    }

    bcr_table.clear();
    gsr_table.clear();

    return positions;
}

void Pattern::boyerMooreMatchesPrint(std::string str)
{
    std::vector<int> matches = this->boyerMooreMatches(str);
    if (matches.size() > 0) {
        std::cout << "The pattern is in the positions: ";

        for (int i = 0; i < matches.size(); i++) {
            std::cout << (i == 0 ? "" : ", ") << matches.at(i);
        }

        std::cout << "." << std::endl;
    } else {
        std::cout << "The pattern is not in the text." << std::endl;
    }
}

void Pattern::setT(std::string _t)
{
    t.clear();
    t.push_back('#');
    for (int i = 0; i < _t.size(); i++) {
        t.push_back(_t.at(i));
        t.push_back('#');
    }
}

std::pair<int, int> Pattern::getLargestPalindromeLine(std::string line)
{
    this->setT(line);
    std::vector<int> p(t.size(), 0);

    int c = 0;
    int r = 0;
    int mirror;

    char a;
    char b;

    for (int i = 1; i < p.size(); i++) {
        mirror = 2*c-i;

        if (i < r) {
            p.at(i) = std::min(r-i, p.at(mirror));
        }

        a = i + (1+p.at(i)) < t.size() ? t.at(i + (1+p.at(i))) : '$';
        b = i - (1+p.at(i)) >= 0 ? t.at(i - (1+p.at(i))) : '@';

        while (a == b) {
            p.at(i)++;

            a = i + (1+p.at(i)) < t.size() ? t.at(i + (1+p.at(i))) : '$';
            b = i - (1+p.at(i)) >= 0 ? t.at(i - (1+p.at(i))) : '@';
        }

        if (i+p.at(i) > r) {
            c = i;
            r = i + p.at(i);
        }
    }

    return std::make_pair(max_element(p.begin(), p.end()) - p.begin(), *max_element(p.begin(), p.end()));
}

void Pattern::printLargestPalindromeLine(std::string line)
{
    std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){ return std::tolower(c); });
    remove(line.begin(), line.end(), ' ');

    std::pair<int, int> result = this->getLargestPalindromeLine(line);

    std::cout << floor(result.first/2)-result.second/2 << " " << result.second << std::endl;
}

void Pattern::printLargestPalindromeFile(std::istream& file)
{
    std::pair<int, int> result;

    std::vector<int> positions;
    std::vector<int> sizes;

    std::string* currentLine = new std::string;

    while (!file.eof()) {
        file >> *currentLine;

        result = this->getLargestPalindromeLine(*currentLine);

        positions.push_back(floor(result.first/2));
        sizes.push_back(result.second);
    }

    int* sizeOfPalindrome = new int(*max_element(sizes.begin(), sizes.end()));

    std::cout << max_element(sizes.begin(), sizes.end()) - sizes.begin()+1 << " " << positions.at(max_element(sizes.begin(), sizes.end()) - sizes.begin()) - *sizeOfPalindrome/2 << " " << *sizeOfPalindrome << std::endl;

    delete sizeOfPalindrome;
    delete currentLine;
}

std::pair<int, int> Pattern::longest_common_string(std::string textX, std::string textY)
{
    int m = textX.size();
    int n = textY.size();
    int lMax = 0;
    int pMax = 0;

    std::vector<std::vector<int>> d(m, std::vector<int>(n,-1));

    for(int i = 0; m > i; i++){
        d.at(i).at(0) = 0;
    }

    for(int j = 0; n > j; j++){
        d.at(0).at(j) = 0;
    }

    for(int i = 1; m > i; i++){
        for(int j = 1; n > j; j++){
            if(textX.at(i) != textY.at(j)){
                d.at(i).at(j) = 0;
            }else{
                d.at(i).at(j) = d.at(i-1).at(j-1) + 1;
                if(d.at(i).at(j) > lMax){
                    lMax = d.at(i).at(j);
                    pMax = i;
                }
            }
        }
    }

    return std::make_pair(lMax, pMax);
}

void Pattern::print_LCS_file(std::istream& fileX, std::istream& fileY)
{
    std::string* currentLine = new std::string;

    std::vector<std::string> fileXList;

    while (!fileX.eof()) {
        fileX >> *currentLine;
        fileXList.push_back(*currentLine);
    }

    std::vector<int> largestSubstring(3, 0);
    std::pair<int, int> result;

    while (!fileY.eof()) {
        fileY >> *currentLine;

        for (int i = 0; i < fileXList.size(); i++) {
            result = this->longest_common_string(fileXList.at(i), *currentLine);

            if (result.first > largestSubstring.at(2)) {
                largestSubstring.at(0) = i;
                largestSubstring.at(1) = result.second;
                largestSubstring.at(2) = result.first;
            }
        }
    }

    std::cout << largestSubstring.at(0) << " ";
    std::cout << largestSubstring.at(1) << " ";
    std::cout << largestSubstring.at(2) << " ";
}



 

#endif // PATTERN_H

