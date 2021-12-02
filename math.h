#pragma once
#include "List.h"
#include "Matrix.h"


struct matrix m_sum(matrix* M1, matrix* M2);
struct matrix m_sub(matrix* M1, matrix* M2);
struct matrix m_mult(matrix* M1, matrix* M2);

struct sparse s_sum(sparse* M1, sparse* M2);
struct sparse s_sub(sparse* M1, sparse* M2);
struct sparse s_mult(sparse* M1, sparse* M2);