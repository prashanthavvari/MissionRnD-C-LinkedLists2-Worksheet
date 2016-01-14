/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *h) {
	if (h != NULL)
	{
		node *p, *q;
		p = h;
		q = h;
		int i = 0, x = 0, var = 0;
		while (p->next != NULL)
		{
			p = p->next;
			i++;
		}
		if ((i - 1) % 2 == 1)
		{
			while (q->next != NULL&& x != i / 2)
			{
				x = x + 1;
				q = q->next;
			}
			return q->num;
		}
		else
		{
			while (q->next != NULL&& x != (i - 1) / 2)
			{
				x = x + 1;
				q = q->next;
			}
			var = q->num;
			if (q->next != NULL)
				q = q->next;
			return ((var+ q->num)/2);
		}
	}
	else
	return -1;
}
