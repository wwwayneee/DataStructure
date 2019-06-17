#include "header.h"
#include "function.h"

int ChooseALUop(LinkList * head)
{
	LinkList *p = head->next;
	int left_bracket_cntA = 0;
	int right_bracket_cntA = 0;
	while ((p->data != '+' && p->data != '-' && p->data != '*') || (left_bracket_cntA != right_bracket_cntA || (left_bracket_cntA == 0 && right_bracket_cntA == 0))) {
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
		p = p->next;
	} /*while*/
	
	if ((p->data == '+' || p->data == '-' || p->data == '*') && left_bracket_cntA == right_bracket_cntA && left_bracket_cntA > 2) {
		if (p->data == '+')
			return ADD;
		else if (p->data == '-')
			return SUB;
		else if (p->data == '*')
			return MULTIPLY;
		else
			return -1;
	}
	
	else	/* this statement will never run */
		return -1;
}
