/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
void xtranode(struct node **h)   //creating an extra dummy node at the end so we can access all the original nodes
{
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->num = 0;
	p = *h;
	while ((p)->next != NULL)
	{
		p = (p)->next;
	}
	(p)->next = temp;
}
void insaf(struct node **h, int data1, int itr) //inserting a node after certain point
{
	node *temp1, *temp;
	int i = 0;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = data1;
	temp->next = NULL;
	if (*h == NULL)
	{
		*h = temp;
	}
	else
	{
		if (itr != 0)
		{
			temp1 = *h;
			while (temp1->next != NULL&&i < itr - 1)
			{
				temp1 = temp1->next;
				i++;
			}
			temp->next = temp1->next;
			temp1->next = temp;
		}
		else
		{
			temp->next = *h;
			*h = temp;
		}
	}
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 != NULL || head2 != NULL)
	{
		if (head1 == NULL)
			return head2;
		else if (head2 == NULL)
			return head1;
		else if (head1 != NULL&&head2 != NULL){
			node *pointerh1, *pointerh2, *prev;
			int i = 0, j = 0, k = 0;
			xtranode(&head2);
			pointerh1 = head1;
			pointerh2 = head2;
			prev = head1;
			while (pointerh1->next != NULL&&pointerh2->next != NULL)  //comparing until both list size is same
			{
				k = 1;
				if (pointerh1->num < pointerh2->num)
				{
					pointerh1 = pointerh1->next;
					i = i + 1;
				}
				else if (pointerh1->num >= pointerh2->num)
				{
					j = pointerh2->num;
					insaf(&prev, j, i);                                         //inserting a node in between 
					pointerh2 = pointerh2->next;
					i = i + 1;
				}
			}
			while (pointerh2->next != NULL)  //if h1 size is less than h2
			{
				if (pointerh1->next == NULL)
				{
					if (pointerh1->num > pointerh2->num)
					{
						j = pointerh2->num;
						insaf(&prev, j, i);
						pointerh2 = pointerh2->next;
						i++;
					}
					else
					{
						i = i + 1;
						j = pointerh2->num;
						insaf(&prev, j, i);          //inserting remaining nodes
						pointerh2 = pointerh2->next;
					}
				}
				else
				{
					i = i + 1;
					j = pointerh2->num;
					insaf(&prev, j, i);          //inserting remaining nodes
					pointerh2 = pointerh2->next;
				}
			}
			head1 = prev;
			return head1;
		}
	}
	else
	return NULL;
}
