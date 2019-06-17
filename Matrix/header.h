#ifndef header_h
#define header_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE	400
#define MAXRC		20
#define VALID		1
#define INVALID	0
typedef int ElemType;
typedef enum {ADD, SUB, MULTIPLY} ALUop;
typedef struct {
	int vert_index, hor_index;			/* 非零元行下标以及列下标 */
	ElemType value;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];		/* 非零元三元组表，data[0] 未用 */
	int rpos[MAXRC + 1];
	int vert_dimension, hor_dimension, non_zero_elem_cnt;			/* 矩阵行数、列数、非零元个数 */
}TSMatrix;

typedef struct input {
	char data;
	struct input * next;
}LinkList;

#endif /* header_h */


