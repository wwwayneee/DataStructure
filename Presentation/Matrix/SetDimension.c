#include "header.h"
#include "function.h"
	//[[0,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]-[[0,0,0,-103,0];[0,0,265,0,0];[0,-32,0,0,0];[4,0,0,0,0]]

void SetDimension(LinkList * head, int * vert_dimA, int * hor_dimA, int * vert_dimB, int * hor_dimB)
{
	int left_bracket_cntA = 0;
	int right_bracket_cntA = 0;
	int left_bracket_cntB = 0;
	int right_bracket_cntB = 0;
	LinkList *p = head->next;
	
	while ((p->data != '+' && p->data != '-' && p->data != '*') || (left_bracket_cntA != right_bracket_cntA || (left_bracket_cntA == 0 && right_bracket_cntA == 0))) {
//	while (p->data != '#') {
		if (p->data == ';') {
			++(*vert_dimA);
			p = p->next;
			continue;
		}
		if (p->data == '[') {
			++left_bracket_cntA;
			p = p->next;
			continue;
		}
		else if (p->data == ']') {
			++right_bracket_cntA;
			p = p->next;
			continue;
		}
		
		if (left_bracket_cntA == 2 && right_bracket_cntA == 0) {
			if ((p->data >= 0x30 && p->data <= 0x39) || p->data == '-')
				p = p->next;
			else if (p->data == ',') {
				++(*hor_dimA);
				p = p->next;
			}
			continue;
		}
		else {
			p = p->next;
			continue;
		}
	} /*while*/
	
	if ((p->data == '+' || p->data == '-' || p->data == '*') && left_bracket_cntA == right_bracket_cntA && left_bracket_cntA > 2)
//	if (p->data == '#')
		p = p->next;
	
	while (p != NULL) {
		if (p->data == ';') {
			++(*vert_dimB);
			p = p->next;
			continue;
		}
		if (p->data == '[') {
			++left_bracket_cntB;
			p = p->next;
			continue;
		}
		else if (p->data == ']') {
			++right_bracket_cntB;
			p = p->next;
			continue;
		}
		
		if (left_bracket_cntB == 2 && right_bracket_cntB == 0) {
			if ((p->data >= 0x30 && p->data <= 0x39) || p->data == '-')
				p = p->next;
			else if (p->data == ',') {
				++(*hor_dimB);
				p = p->next;
			}
			continue;
		}
		else {
			p = p->next;
			continue;
		}
	}
	++(*vert_dimA);
	++(*hor_dimA);
	++(*vert_dimB);
	++(*hor_dimB);
}
