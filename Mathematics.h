//
// Created by matth on 12/27/2017.
//

#ifndef MATHEMATICS_H
#define MATHEMATICS_H


#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Mathematics
{
public:
    Mathematics();
    void Multiplication();
    void Division();
    void Addition();
    void Subtraction();
    void Factorials();
    void Percents();
    void Import();
    void Stats();
    void Testing();
    int Menu();
    vector<string> Names;
    vector<int> Scores;
    vector<string> Questions;
    vector<string> Answers;
    vector<string> Books;


};


#endif //MATHEMATICS_H
