#include "header.h"
#include "function.h"

void SetOriginalMatrixSign(LinkList * head, int Matrix_signA[20][20], int Matrix_signB[20][20], int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0)
{
	LinkList *p = (head->next)->next;
	
	for (int i = 0; i <= 19; i++)
		for (int j = 0; j <= 19; j++) {
			Matrix_signA[i][j] = 1;
			Matrix_signB[i][j] = 1;
		}
	
	int vertA = 0;
	int horA = 0;
	int vertB = 0;
	int horB = 0;
	int left_bracket_cntA = 0;
	int right_bracket_cntA = 0;
	int left_bracket_cntB = 0;
	int right_bracket_cntB = 0;
	
	while ((p->data != '+' && p->data != '-' && p->data != '*') || ((left_bracket_cntA + 1) != right_bracket_cntA)) {
//	while (p->data != '#') {
		if (p->data == '[') {
			p = p->next;
			++left_bracket_cntA;
			continue;
		}
		else if (p->data == ']') {
			p = p->next;
			++right_bracket_cntA;
			++vertA;
			horA = 0;
			continue;
		}
		else if (p->data == ';') {
			p = p->next;
			continue;
		}
		
		if (p->data >= 0x30 && p->data <= 0x39)
			p = p->next;
		else if (p->data == ',') {
			horA++;
			p = p->next;
		}
		else if (p->data == '-') {
			Matrix_signA[right_bracket_cntA][horA] = -1;
			p = p->next;
		}
		
	} /* while (p->data != '#') */
	
	if ((p->data == '+' || p->data == '-' || p->data == '*') && ((left_bracket_cntA + 1) == right_bracket_cntA))
//	if (p->data == '#')
		p = (p->next)->next;
	
	while (p != NULL) {
		if (p->data == '[') {
			p = p->next;
			++left_bracket_cntB;
			continue;
		}
		else if (p->data == ']') {
			p = p->next;
			++right_bracket_cntB;
			++vertB;
			horB = 0;
			continue;
		}
		else if (p->data == ';') {
			p = p->next;
			continue;
		}
		
		if (p->data >= 0x30 && p->data <= 0x39)
			p = p->next;
		else if (p->data == ',') {
			horB++;
			p = p->next;
		}
		else if (p->data == '-') {
			Matrix_signB[right_bracket_cntB][horB] = -1;
			p = p->next;
		}
		
	} /* while (p != NULL) */
}
