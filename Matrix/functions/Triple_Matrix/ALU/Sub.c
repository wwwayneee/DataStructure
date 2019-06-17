#include "header.h"
#include "function.h"

TSMatrix Sub(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB)
{
	for (int i = 1; i <= Matrix_sparseB.non_zero_elem_cnt; i++)
		Matrix_sparseB.data[i].value *= -1;
	return Add(Matrix_sparseA, Matrix_sparseB);
}
