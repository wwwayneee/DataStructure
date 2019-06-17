
///* 加减乘 */

#include "header.h"
#include "function.h"

//[[4,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]-[[1,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]
	//[[1,2,3,4];[5,6,7,8];[9,10,11,12]]*[[1,2,3];[4,5,6];[7,8,9];[10,11,12]]
	//[[3,0,0,5];[0,-1,0,0];[2,0,0,0]]*[[0,2];[1,0];[-2,4];[0,0]]
	//[[1,2];[3,4]]*[[1,2];[3,4]]
//[[0];[1]]-[[2];[3]]
//注意区分负号和减号！

int main(int argc, const char * argv[])
{
	printf("input format(OJ style):[[0,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]+[[0,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]\n");
	
	LinkList *head;
	head = CreateList();
	LinkList *p;
	
	/*********************************************************************************************************************************/
		    p = head->next;
		    while (p != NULL) {
		        printf("%c", p->data);
		        p = p->next;
		    }
		    printf("\n");
	/*********************************************************************************************************************************/
	
	int hor_dimA = 0;
	int vert_dimA = 0;
	int hor_dimB = 0;
	int vert_dimB = 0;
	SetDimension(head, &vert_dimA, &hor_dimA, &vert_dimB, &hor_dimB);
		/*********************************************************************************************************************************/
	printf("vert_dimA:%d hor_dimA:%d vert_dimB:%d hor_dimB:%d\n", vert_dimA, hor_dimA, vert_dimB, hor_dimB);
		/*********************************************************************************************************************************/
	const int hor_dimA0 = hor_dimA;
	const int vert_dimA0 = vert_dimA;
	const int hor_dimB0 = hor_dimB;
	const int vert_dimB0 = vert_dimB;
	
	int Matrix_unsignedA[20][20];
	int Matrix_unsignedB[20][20];
	int Matrix_signA[20][20];
	int Matrix_signB[20][20];
	int MatrixA[vert_dimA0][hor_dimA0];
	int MatrixB[vert_dimB0][hor_dimB0];
	int Matrix_largeA[20][20];
	int Matrix_largeB[20][20];
	int Matrix_out_largeA[20][20];
	int Matrix_out_largeB[20][20];
	int Matrix_outA[vert_dimA0][hor_dimA0];
	int Matrix_outB[vert_dimB0][hor_dimB0];
	int Matrix_Answer_out_large[20][20];
	
	SetOriginalMatrixSign(head, Matrix_signA, Matrix_signB, vert_dimA0, hor_dimA0, vert_dimB0, hor_dimB0);
		/*********************************************************************************************************************************/
	printf("Matrix_signA:\n");
	for (int i = 0; i <= vert_dimA0 - 1; i++) {
		for (int j = 0; j <= hor_dimA0 - 1; j++) {
			printf("%4d ", Matrix_signA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matrix_signB:\n");
	for (int i = 0; i <= vert_dimB0 - 1; i++) {
		for (int j = 0; j <= hor_dimB0 - 1; j++) {
			printf("%4d ", Matrix_signB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
		/*********************************************************************************************************************************/
	SetOriginalMatrixUnsigned(head, Matrix_unsignedA, Matrix_unsignedB, vert_dimA0, hor_dimA0, vert_dimB0, hor_dimB0);
	/*********************************************************************************************************************************/
	printf("Matrix_unsignedA\n");
	for (int i = 0; i <= vert_dimA0 - 1; i++) {
		for (int j = 0; j <= hor_dimA0 - 1; j++) {
			printf("%4d ", Matrix_unsignedA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matrix_unsignedB\n");
	for (int i = 0; i <= vert_dimB0 - 1; i++) {
		for (int j = 0; j <= hor_dimB0 - 1; j++) {
			printf("%4d ", Matrix_unsignedB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	/*********************************************************************************************************************************/
	for (int i = 0; i <= vert_dimA0 - 1; i++)
		for (int j = 0; j <= hor_dimA0 - 1; j++)
			MatrixA[i][j] = Matrix_unsignedA[i][j] * Matrix_signA[i][j];
	for (int i = 0; i <= vert_dimB0 - 1; i++)
		for (int j = 0; j <= hor_dimB0 - 1; j++)
			MatrixB[i][j] = Matrix_unsignedB[i][j] * Matrix_signB[i][j];
	/*********************************************************************************************************************************/
	printf("MatrixA\n");
	for (int i = 0; i <= vert_dimA0 - 1; i++) {
		for (int j = 0; j <= hor_dimA0 - 1; j++) {
			printf("%4d ", MatrixA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("MatrixB\n");
	for (int i = 0; i <= vert_dimB0 - 1; i++) {
		for (int j = 0; j <= hor_dimB0 - 1; j++) {
			printf("%4d ", MatrixB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	/*********************************************************************************************************************************/
	
	for (int i = 0; i <= 19; i++)
		for (int j = 0; j <= 19; j++) {
			Matrix_largeA[i][j] = 0;
			Matrix_largeB[i][j] = 0;
		}
	for (int i = 0; i <= vert_dimA0 - 1; i++)
		for (int j = 0; j <= hor_dimA0 - 1; j++)
			Matrix_largeA[i][j] = MatrixA[i][j];
	
	for (int i = 0; i <= vert_dimB0 - 1; i++)
		for (int j = 0; j <= hor_dimB0 - 1; j++)
			Matrix_largeB[i][j] = MatrixB[i][j];

	TSMatrix Matrix_sparseA = CreateMatrix(Matrix_largeA, vert_dimA0, hor_dimA0);
	TSMatrix Matrix_sparseB = CreateMatrix(Matrix_largeB, vert_dimB0, hor_dimB0);
	OutPut(Matrix_out_largeA, Matrix_sparseA, vert_dimA0, hor_dimA0);
	OutPut(Matrix_out_largeB, Matrix_sparseB, vert_dimB0, hor_dimB0);
	for (int i = 0; i <= vert_dimA0 - 1; i++)
		for (int j = 0; j <= hor_dimA0 - 1; j++)
			Matrix_outA[i][j] = Matrix_out_largeA[i][j];
	for (int i = 0; i <= vert_dimB0 - 1; i++)
		for (int j = 0; j <= hor_dimB0 - 1; j++)
			Matrix_outB[i][j] = Matrix_out_largeB[i][j];
	
	/*********************************************************************************************************************************/
	printf("Matrix_outA\n");
	for (int i = 0; i <= vert_dimA0 - 1; i++) {
		for (int j = 0; j <= hor_dimA0 - 1; j++) {
			printf("%4d ", Matrix_outA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Matrix_outB\n");
	for (int i = 0; i <= vert_dimB0 - 1; i++) {
		for (int j = 0; j <= hor_dimB0 - 1; j++) {
			printf("%4d ", Matrix_outB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d %d %d\n", ADD, SUB, MULTIPLY);	/*********************************************************************************************************************************/
	int ALUop = ChooseALUop(head);
	printf("%d\n", ALUop);
	
	if (!CheckDimension(ALUop, vert_dimA0, hor_dimA0, vert_dimB0, hor_dimB0)) {
		printf("INVALID INPUT\n");
		return -1;
	}
	
	int vert_dim_Answer;
	int hor_dim_Answer;
	TSMatrix Matrix_Answer;
	if (ALUop == ADD) {
		vert_dim_Answer = vert_dimA0;
		hor_dim_Answer = hor_dimA0;
		Matrix_Answer = Add(Matrix_sparseA, Matrix_sparseB);
	}
	else if (ALUop == SUB) {
		vert_dim_Answer = vert_dimA0;
		hor_dim_Answer = hor_dimA0;
		Matrix_Answer = Sub(Matrix_sparseA, Matrix_sparseB);
	}
	else if (ALUop == MULTIPLY) {
		vert_dim_Answer = vert_dimA0;
		hor_dim_Answer = hor_dimB0;
		Matrix_Answer = Multiply(Matrix_sparseA, Matrix_sparseB);
	}
	const int vert_dim_Answer0 = vert_dim_Answer;
	const int hor_dim_Answer0 = hor_dim_Answer;
	int Matrix_Answer_out[vert_dim_Answer0][hor_dim_Answer0];
	OutPut(Matrix_Answer_out_large, Matrix_Answer, vert_dim_Answer0, hor_dim_Answer0);
	for (int i = 0; i <= vert_dim_Answer0 - 1; i++)
		for (int j = 0; j <= hor_dim_Answer0 - 1; j++)
			Matrix_Answer_out[i][j] = Matrix_Answer_out_large[i][j];
	printf("Matrix_out_Answer\n");
	for (int i = 0; i <= vert_dim_Answer0 - 1; i++) {
		for (int j = 0; j <= hor_dim_Answer0 - 1; j++) {
			printf("%4d ", Matrix_Answer_out[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}
