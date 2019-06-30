#include "header.h"
#include "function.h"

LinkList * CreateList(void)
{
	LinkList *head, *p;
	head = (LinkList *)malloc(sizeof(LinkList));
	p = head;
	char c;
	c = getchar();
	while (c != EOF && c != '\n') {
		p->next = (LinkList *)malloc(sizeof(LinkList));
		(p->next)->data = c;
		p = p->next;
		c = getchar();
	}
	p->next = NULL;
	return head;
}
