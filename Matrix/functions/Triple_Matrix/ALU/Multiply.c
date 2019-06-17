//#include "header.h"
//#include "function.h"
//
//TSMatrix Sub(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB)
//{
//	TSMatrix Matrix_Answer;
//	Matrix_Answer.vert_dimension = Matrix_sparseB.vert_dimension;
//	Matrix_Answer.hor_dimension = Matrix_sparseA.hor_dimension;
//	Matrix_Answer.non_zero_elem_cnt = 0;
//	if (Matrix_sparseA.non_zero_elem_cnt == 0)
//		Matrix_Answer = Matrix_sparseA;
//	else if (Matrix_sparseB.non_zero_elem_cnt == 0)
//		Matrix_Answer = Matrix_sparseB;
//	else {
//		for (int i = 1; i <= Matrix_sparseA.non_zero_elem_cnt; i++) {
//			for (int j = 1; j <= Matrix_sparseB.non_zero_elem_cnt; j++) {
//				if (Matrix_sparseA.data[i].hor_index == Matrix_sparseB.data[j].vert_index) {
//					Matrix_Answer.non_zero_elem_cnt++;
//					
//					
//				}
//			}
//		}
//	}
//}
