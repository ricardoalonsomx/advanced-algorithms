/*
    Title: Homework 04 - Longest palindrome algorithm.
    Description: Main code for the 'Homework 04 - Longest palindrome algorithm' algorithms test-cases.

    Author: Aldo Ricardo Alonso Arostegui - A01029011

    Proffesor: Leonardo Chang Fernández
    First release: September 22nd, 2021.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pattern.h"

int main(int argc, const char * argv[])
{
    Pattern* pat = new Pattern;

    std::string line = "";
    
    for (int i = 1; i < argc; i++) {
        line = line + argv[i] + " ";
    }
    
    pat->printLargestPalindromeLine(line);
    
    delete pat;

    return 0;
}

 
