#ifndef function_h
#define function_h

LinkList * CreateList(void);
void SetDimension(LinkList * head, int * vert_dimA, int * hor_dimA, int * vert_dimB, int * hor_dimB);
void SetOriginalMatrixSign(LinkList * head, int Matrix_signA[20][20], int Matrix_signB[20][20], int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0);
void SetOriginalMatrixUnsigned(LinkList * head, int Matrix_unsignedA[20][20], int Matrix_unsignedB[20][20], int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0);
TSMatrix CreateMatrix(int Matrix_large[20][20], int vert_dim0, int hor_dim0);
void OutPut(int Matrix_out_large[20][20], TSMatrix Matrix_sparse, int vert_dim0, int hor_dim0);
int ChooseALUop(LinkList * head);
TSMatrix Add(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB);
TSMatrix Sub(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB);
TSMatrix Multiply(TSMatrix Matrix_sparseA, TSMatrix Matrix_sparseB);
int CheckDimension(int ALUop, int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0);
int Atoi(char c);


#endif /* function_h */
