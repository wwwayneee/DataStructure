#include "header.h"
#include "function.h"

TSMatrix Add(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB)
{
	TSMatrix Matrix_Answer;
	if (Matrix_sparseA.non_zero_elem_cnt == 0)
		Matrix_Answer = Matrix_sparseB;
	else if (Matrix_sparseB.non_zero_elem_cnt == 0)
		Matrix_Answer = Matrix_sparseA;
	else {
		int non_zero_cnt = 0;
		int check_A_cnt = 0;
		int matrix_data_index_add = 1;
//		Matrix_Answer.vert_dimension = Matrix_sparseA.vert_dimension;
//		Matrix_Answer.hor_dimension = Matrix_sparseA.hor_dimension;
//		for (int i = 1; i <= Matrix_sparseA.non_zero_elem_cnt; i++) {
//			Matrix_Answer.data[i].vert_index = Matrix_sparseA.data[i].vert_index;
//			Matrix_Answer.data[i].hor_index = Matrix_sparseA.data[i].hor_index;
//			Matrix_Answer.data[i].vert_index = Matrix_sparseA.data[i].value;
//		}
		Matrix_Answer = Matrix_sparseA;
		/* now Matrix_Answer = Matrix_sparseA */
		for (int j = 1; j <= Matrix_sparseB.non_zero_elem_cnt; j++) {
			for (int i = 1; i <= Matrix_sparseA.non_zero_elem_cnt; i++, check_A_cnt++) {
				if (Matrix_sparseB.data[j].vert_index == Matrix_sparseA.data[i].vert_index && Matrix_sparseB.data[j].hor_index == Matrix_sparseA.data[i].hor_index) {
					Matrix_Answer.data[i].value += Matrix_sparseB.data[j].value;
					check_A_cnt = 0;
					
					/*当前B的非零元与A重合，已经加到Answer中，前往下一个B的非零元*/
//					goto NEXT_B;
					break;
				}
			}
			/* 如果把A的非零元全部遍历还是没有能和B中该非零元匹配的,则在Answer中单独添加 */
			if (check_A_cnt == Matrix_sparseA.non_zero_elem_cnt) {
				Matrix_Answer.non_zero_elem_cnt++;
//				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt + matrix_data_index_add].vert_index = Matrix_sparseB.data[j].vert_index;
//				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt + matrix_data_index_add].hor_index = Matrix_sparseB.data[j].hor_index;
//				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt + matrix_data_index_add].value = Matrix_sparseB.data[j].value;
				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].vert_index = Matrix_sparseB.data[j].vert_index;
				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].hor_index = Matrix_sparseB.data[j].hor_index;
				Matrix_Answer.data[Matrix_Answer.non_zero_elem_cnt].value = Matrix_sparseB.data[j].value;
				++matrix_data_index_add;
			}
//		NEXT_B:
//			;
		}
		/* 现在AB中重合的部分 以及 全部的A中非零元 都已经全部加到Answer 中了，还剩下B中有的 但A中没有的非零元需要加到Answer中 */
	}
	
	
	return Matrix_Answer;
}
