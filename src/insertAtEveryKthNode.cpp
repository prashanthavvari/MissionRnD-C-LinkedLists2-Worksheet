/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
int insaf(struct node **h, int K, int count1)
{
	struct node *q, *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	int count = 1, i = 1, var = 1;
	q = *h;
	p = *h;
	if ((*h == 0) || (K < 1))
		return NULL;

	while (i < K&&p->next != NULL&&K != 1)
	{
		i = i + 1;
		p = p->next;
	}
	if (p->next != NULL)
	{
		temp->num = count1;
		temp->next = p->next;
		p->next = temp;
		return 1;
	}
	if (p->next == NULL)
		return 0;
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *q, *p, *temp, *f;
	temp = (struct node *)malloc(sizeof(struct node));
	int count = 0, r = 1, n = 0,retvalue;
	q = NULL;
	p = head;
	f = head;
	if ((head == 0) || (K <1))
		return NULL;
	else
	{
		while (p->next != NULL)
		{
			count += 1;
			if (count%K == 0)
			{
				if (n == 0)
				{
					retvalue = insaf(&head, K, K);
					n = n + K;
				}
				else
				{
					retvalue = insaf(&head, (2 * n + 1), K);
					n = n + K;
				}
				if (retvalue == 0)
				{
					count = 1;
					break;
				}
				count = 0;
			}
			p = p->next;
		}
		while (p->next != NULL)
			p = p->next;
		if (p->next == NULL && ((count) % K) == 0)
		{
			temp->next = NULL;
			temp->num = K;
			p->next = temp;
		}
	}
	return head;
}
