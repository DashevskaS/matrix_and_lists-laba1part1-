#include "math.h"
#include "List.h"
#include "Matrix.h"
#include <stdlib.h>



matrix m_sum(matrix* M1, matrix* M2)
{
	matrix res;
	for (int i = 0; i < M1->line; i++)
	{
		std::vector<double> buf;

		for (int j = 0; j < M1->column; j++)
		{
			buf.push_back(m_get(M1, i, j) + m_get(M2, i, j));
		}

		res.mx.push_back(buf);
	}
	res.line = M1->line;
	res.column = M1->column;
	return res;

}

matrix m_sub(matrix* M1, matrix* M2)
{
	matrix res;
	for (int i = 0; i < M1->line; i++)
	{
		std::vector<double> buf;

		for (int j = 0; j < M1->column; j++)
		{
			buf.push_back(m_get(M1, i, j) - m_get(M2, i, j));
		}

		res.mx.push_back(buf);
	}
	res.line = M1->line;
	res.column = M1->column;
	return res;
}

matrix m_mult(matrix* M1, matrix* M2)
{
	matrix res;

	for (int i = 0; i < M1->line; i++)
	{
		std::vector<double> buf;
		for (int j = 0; j < M2->column; j++)
			buf.push_back(0);
		res.mx.push_back(buf);
	}

	res.line = M1->line;
	res.column = M2->column;
	
	for (int i = 0; i < max(res.column, res.line); i++)
		
		for (int j = 0; j < min(res.column, res.line); j++)
		{
			for (int k = 0; k < max(res.column, res.line); k++)
				res.mx[i][j] += M1->mx[i][k] * M2->mx[k][j];
		}

	return res;
}

sparse s_sum(sparse* S1, sparse* S2)
{
	sparse res;

	for (int i = 0; i < S1->n; i++)
	{
		for (int j = 0; j < S1->m; j++)
		{
			if (s_get(S1, i, j) + s_get(S2, i, j) != 0) {
				res.value.push_back(s_get(S1, i, j) + s_get(S2, i, j));
				res.line.push_back(i);
				res.column.push_back(j);
			}
		}

	}
	res.n = S1->n;
	res.m = S1->m;

	return res;
}

sparse s_sub(sparse* S1, sparse* S2)
{
	sparse res;

	for (int i = 0; i < S1->n; i++)
	{
		for (int j = 0; j < S1->m; j++)
		{
			if (s_get(S1, i, j) - s_get(S2, i, j) != 0) {
				res.value.push_back(s_get(S1, i, j) - s_get(S2, i, j));
				res.line.push_back(i);
				res.column.push_back(j);
			}
		}

	}
	res.n = S1->n;
	res.m = S1->m;

	return res;
}

sparse s_mult(sparse* S1, sparse* S2)
{
	 sparse res;

	for (int i = 0; i < S1->n; i++)
	{
		for (int j = 0; j < S2->m; j++)
		{
			res.line.push_back(i);
			res.column.push_back(j);
			res.value.push_back(0);
		}
	}

	res.n = S1->n;
	res.m = S2->m;

	for (int i = 0; i < max(res.n, res.m); i++)

		for (int j = 0; j < min(res.n, res.m); j++)
		{
			for (int k = 0; k < max(res.n, res.m); k++)
				s_change_by_index(&res, i,j,s_get(S1,i,k) * s_get(S2,k,j));
		}

	for (int i = 0; i < res.value.size(); i)
	{
		if (res.value[i] == 0)
		{
			res.value.erase(res.value.begin() + i);
		}
		else
			i++;
	}

	return res;
}
