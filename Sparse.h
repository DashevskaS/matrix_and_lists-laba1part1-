#pragma once
#include <vector>
#include <iostream>
using namespace std;
struct sparse {
	vector<int> line;
	vector<int> column;
	vector<double> value;
	int n, m;
};


	double s_get(sparse* S,int line, int column);
	void s_change_by_index(sparse* S, int line, int column, int value);
	struct sparse s_create();
	void s_show(sparse* S);
	void s_find(sparse* S,double value);


inline double s_get(sparse* S, int line , int column)
{
	for (int n = 0; n < S->line.size(); n++)
	{
		if (S->line[n] == line && S->column[n] == column)
		{
			return S->value[n];
		}
	}
	return 0;
}

inline void s_change_by_index(sparse* S, int line, int column,int value)
{
	for (int n = 0; n < S->line.size(); n++)
	{
		if (S->line[n] == line && S->column[n] == column)
		{
			S->value[n] += value;
		}
	}
}

inline struct sparse s_create()
{
	struct sparse S;

	std::cout << "quantity of lines: ";
	std:cin >> S.n;
	std::cout << "quantity of columns: ";
	std::cin >> S.m;

	for (int i = 0; i < S.n; i++)
	{
		for (int j = 0; j < S.m; j++)
		{
			std::cout << "matrix[" << i << "][" << j << "]: ";
			double value;
			std::cin >> value;
			if (value != 0) {
				S.line.push_back(i);
				S.column.push_back(j);
				S.value.push_back(value);
			}
		}
	}
	return S;
}

inline void s_show(sparse* S)
{
	for (int i = 0; i < S->n; i++)
	{
		for (int j = 0; j < S->m; j++)
		{
			cout << s_get(S,i, j)<<" ";
		}
		cout << '\n';
	}
}

inline void s_find(sparse* S,double value)
{
	for (int i = 0; i < S->value.size(); i++)
	{
		if (S->value[i] == value)
		{
			cout << S->line[i]<<" "<< S->column[i] << '\n';
		}
	}
}