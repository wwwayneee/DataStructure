#include "header.h"
#include "function.h"

TSMatrix CreateMatrix(int Matrix_large[20][20], int vert_dim0, int hor_dim0)
{
	TSMatrix Matrix_sparse;
	int non_zero_cnt = 0;
	int col;
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
	
	int num[MAXSIZE + 1];
	Matrix_sparse.rpos[1] = 1;
	for (col = 1; col <= Matrix_sparse.vert_dimension; col++)
		num[col] = 0;
	for (int i = 1; i <= Matrix_sparse.non_zero_elem_cnt; i++)
		num[Matrix_sparse.data[i].vert_index + 1]++;
	for (col = 2; col <= Matrix_sparse.vert_dimension; col++)
		Matrix_sparse.rpos[col] = Matrix_sparse.rpos[col - 1] + num[col - 1];
	
	return Matrix_sparse;
}
