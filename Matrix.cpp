#include "Matrix.h"
#include "List.h"
#include <iostream>
#include <vector>

matrix m_create()
{
	struct matrix M;
	


	std::cout << "quantity of lines: ";
	std:cin >> M.line;
	std::cout << "quantity of columns: ";
	std::cin >> M.column;

	for(int i = 0; i < M.line; i++)
	{
		std::vector<double> buf;

		for(int j = 0; j < M.column; j++)
		{
			std::cout << "matrix[" << i << "][" << j << "]: ";
			double value;
			std::cin >> value;
			buf.push_back(value);
		}

		M.mx.push_back(buf);	
	}
	return M;
}

void m_show(matrix* M)
{
	for (int i = 0; i < M->mx.size(); i++)
	{
		for (int j = 0; j < M->mx[i].size(); j++)
		{
			std::cout << M->mx[i][j] << " ";
		}
		std::cout << '\n';
	}
}

double m_get(matrix* M, int line, int column)
{
	return M->mx[line][column];
}
void m_find(matrix* M,double value)
{
	for (int i = 0; i < M->mx.size(); i++)
	{
		for (int j = 0; j < M->mx[i].size(); j++)
		{
			if (M->mx[i][j] == value)
			{
				std::cout << "\nLine: " << i << "\nColumn: " << j << '\n';
			}
		}
	}
}