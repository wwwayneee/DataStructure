#include "header.h"
#include "function.h"

TSMatrix CreateMatrix(int Matrix_large[20][20], int vert_dim0, int hor_dim0)
{
	TSMatrix Matrix_sparse;
	int non_zero_cnt = 0;
	int index = 1;		/* 注意 data[0] 未用，index 从1开始 */
	for (int i = 0; i <= vert_dim0 - 1; i++)
		for (int j = 0; j <= hor_dim0 - 1; j++) {
			if (Matrix_large[i][j] != 0) {
				non_zero_cnt++;
				Matrix_sparse.data[index].value = Matrix_large[i][j];
				Matrix_sparse.data[index].vert_index = i;
				Matrix_sparse.data[index].hor_index = j;
				index++;
			}
			else
				continue;
		}
	
	Matrix_sparse.non_zero_elem_cnt = non_zero_cnt;
	Matrix_sparse.vert_dimension = vert_dim0;
	Matrix_sparse.hor_dimension = hor_dim0;
	
	return Matrix_sparse;
}
