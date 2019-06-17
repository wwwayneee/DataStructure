#include "header.h"
#include "function.h"

void SetOriginalMatrixUnsigned(LinkList * head, int Matrix_unsignedA[20][20], int Matrix_unsignedB[20][20], int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0)
{
	LinkList *p = (head->next)->next;
	
	for (int i = 0; i <= 19; i++)
		for (int j = 0; j <= 19; j++) {
			Matrix_unsignedA[i][j] = 0;
			Matrix_unsignedB[i][j] = 0;
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
		
		
		if (p->data >= 0x30 && p->data <= 0x39) {		/* first digit */
			Matrix_unsignedA[right_bracket_cntA][horA] = Matrix_unsignedA[right_bracket_cntA][horA] * 10 + Atoi(p->data);
			p = p->next;
			if (p->data == ',') {	/* second digit */
				++horA;
				p = p->next;
			}
			else if (p->data == ']') {		/* second digit */
				p = p->next;
				++right_bracket_cntA;
				++vertA;
				horA = 0;
			}
			else if (p->data >= 0x30 && p->data <= 0x39) {		/* real second digit */
				Matrix_unsignedA[right_bracket_cntA][horA] = Matrix_unsignedA[right_bracket_cntA][horA] * 10 + Atoi(p->data);
				p = p->next;
				if (p->data == ',') {	/* third digit */
					++horA;
					p = p->next;
				}
				else if (p->data == ']') {		/* third digit */
					p = p->next;
					++right_bracket_cntA;
					++vertA;
					horA = 0;
				}
				else if (p->data >= 0x30 && p->data <= 0x39) {		/* real third digit */
					Matrix_unsignedA[right_bracket_cntA][horA] = Matrix_unsignedA[right_bracket_cntA][horA] * 10 + Atoi(p->data);
					p = p->next;
					if (p->data == ',') {	/* fourth digit */
						++horA;
						p = p->next;
					}
					else if (p->data == ']') {		/* fourth digit */
						p = p->next;
						++right_bracket_cntA;
						++vertA;
						horA = 0;
					}
					else if (p->data >= 0x30 && p->data <= 0x39) {		/* real fourth digit */
						Matrix_unsignedA[right_bracket_cntA][horA] = Matrix_unsignedA[right_bracket_cntA][horA] * 10 + Atoi(p->data);
						p = p->next;
					}
				}
			}
		}
		else if (p->data == '-')	/* first digit */
			p = p->next;
		
	} /* while */
	
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
		
		
		if (p->data >= 0x30 && p->data <= 0x39) {		/* first digit */
			Matrix_unsignedB[right_bracket_cntB][horB] = Matrix_unsignedB[right_bracket_cntB][horB] * 10 + Atoi(p->data);
			p = p->next;
			if (p->data == ',') {	/* second digit */
				++horB;
				p = p->next;
			}
			else if (p->data == ']') {		/* second digit */
				p = p->next;
				++right_bracket_cntB;
				++vertB;
				horB = 0;
			}
			else if (p->data >= 0x30 && p->data <= 0x39) {		/* real second digit */
				Matrix_unsignedB[right_bracket_cntB][horB] = Matrix_unsignedB[right_bracket_cntB][horB] * 10 + Atoi(p->data);
				p = p->next;
				if (p->data == ',') {	/* third digit */
					++horB;
					p = p->next;
				}
				else if (p->data == ']') {		/* third digit */
					p = p->next;
					++right_bracket_cntB;
					++vertB;
					horB = 0;
				}
				else if (p->data >= 0x30 && p->data <= 0x39) {		/* real third digit */
					Matrix_unsignedB[right_bracket_cntB][horB] = Matrix_unsignedB[right_bracket_cntB][horB] * 10 + Atoi(p->data);
					p = p->next;
					if (p->data == ',') {	/* fourth digit */
						++horB;
						p = p->next;
					}
					else if (p->data == ']') {		/* fourth digit */
						p = p->next;
						++right_bracket_cntB;
						++vertB;
						horB = 0;
					}
					else if (p->data >= 0x30 && p->data <= 0x39) {		/* real fourth digit */
						Matrix_unsignedB[right_bracket_cntB][horB] = Matrix_unsignedB[right_bracket_cntB][horB] * 10 + Atoi(p->data);
						p = p->next;
					}
				}
			}
		}
		else if (p->data == '-')	/* first digit */
			p = p->next;
		
	} /* while */
}
