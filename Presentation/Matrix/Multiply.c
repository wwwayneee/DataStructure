#include "header.h"
#include "function.h"

TSMatrix Multiply(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB)
{
	TSMatrix Matrix_Answer;
	Matrix_Answer.vert_dimension = Matrix_sparseA.vert_dimension;
	Matrix_Answer.hor_dimension = Matrix_sparseB.hor_dimension;
	Matrix_Answer.non_zero_elem_cnt = 0;
	int arrow, tp, brow, ccol, p, t, q;
	int ctemp[MAXSIZE + 1];
	if (Matrix_sparseA.non_zero_elem_cnt == 0)
		Matrix_Answer = Matrix_sparseA;
	else if (Matrix_sparseB.non_zero_elem_cnt == 0)
		Matrix_Answer = Matrix_sparseB;
	else {
		for (arrow = 1; arrow <= Matrix_sparseA.vert_dimension; arrow++) {	/* 对于A的每一行 */
			memset(ctemp, 0, sizeof(ctemp));
			Matrix_Answer.rpos[arrow] = Matrix_Answer.non_zero_elem_cnt + 1;
			
			if (arrow < Matrix_sparseA.vert_dimension)
				tp = Matrix_sparseA.rpos[arrow + 1];	/* tp：A的下一行第一个非零元位置，also本行最后一个非零元的位置加一 */
			else
				tp = Matrix_sparseA.non_zero_elem_cnt + 1;	/* tp：A的最后一行最后一个非零元的位置加一 */
			
			for (p = Matrix_sparseA.rpos[arrow]; p < tp; p++) {		/* 对于A中当前行（arrow）中每一个非零元 */
				brow = Matrix_sparseA.data[p].hor_index + 1;	/* A中该非零元的横坐标 */
				
				if (brow < Matrix_sparseB.vert_dimension)		/* 若A中该非零元的横坐标严格小于B的纵向维数 */
					t = Matrix_sparseB.rpos[brow + 1];		/* t：B中本行（brow）最后一个非零元位置加一 */
				else	/* brow对应B的最后一行时 */
					t = Matrix_sparseB.non_zero_elem_cnt + 1;		/* t：B中本行（brow）最后一个非零元位置加一 */
				
				for (q = Matrix_sparseB.rpos[brow]; q < t; q++) {	/* 从B中当前行(brow)的第一个非零元到最后一个非零元 */
					ccol = Matrix_sparseB.data[q].hor_index + 1;	/* (B中brow行的)该非零元的横坐标 */
					ctemp[ccol] += Matrix_sparseA.data[p].value * Matrix_sparseB.data[q].value;
				}
			} /* 遍历A中当前行（arrow）中每一个非零元 */
			for (ccol = 1; ccol <= Matrix_Answer.hor_dimension; ccol++)
				if (ctemp[ccol]) {
					Matrix_Answer.non_zero_elem_cnt++;
					Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].vert_index = arrow - 1;
					Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].hor_index = ccol - 1;
					Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].value = ctemp[ccol];
				}
		}
	} /*else*/
	return Matrix_Answer;
}
