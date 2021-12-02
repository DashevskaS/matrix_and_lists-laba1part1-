#pragma once
#include "List.h"
#include "vector"
using namespace std;
struct matrix
{
    vector<vector<double>> mx;
    int line, column;
};
matrix m_create();
void m_show(matrix* M);
double m_get(matrix* M,int line , int column);
void m_find(matrix* M, double value);
