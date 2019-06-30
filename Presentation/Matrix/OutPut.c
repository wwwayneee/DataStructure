#include "header.h"
#include "function.h"

void OutPut(int Matrix_out_large[20][20], TSMatrix Matrix_sparse, int vert_dim0, int hor_dim0)
{
	for (int i = 0; i <= 19; i++)
		for (int j = 0; j <= 19; j++)
			Matrix_out_large[i][j] = 0;
	
	if (Matrix_sparse.non_zero_elem_cnt == 0)
		printf("ZERO MATRIX\n");
	else {
		for (int k = 1; k <= Matrix_sparse.non_zero_elem_cnt; k++)
			for (int i = 0; i <= vert_dim0 - 1; i++)
				for (int j = 0; j <= hor_dim0 - 1; j++)
					if (Matrix_sparse.data[k].vert_index == i && Matrix_sparse.data[k].hor_index == j)
						Matrix_out_large[i][j] = Matrix_sparse.data[k].value;
	} /*else*/
}
