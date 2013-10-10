#include <stdlib.h>
#include <stdio.h>

typedef struct list {
	int data;
	struct list *next;
} List;

void revers (List *head) {
	List *p, *q; 
	p = head->next;
	head->next = p->next;
	p->next = head;
	while (head->next != NULL) {
		q = head->next;
		head->next = q->next;
		q->next = p;
		p = q;
	}
	head = p;
}

int *search (List *head, int elem) {
	List *p = head;
	int numArr = ;
	while (p != NULL) {
		if (p->data == elem)

		p = p->next;
	}
	return numArr;
}

List *append (List *head, int elem) {
	List *p, *q;
	p->next = head;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	List *newElem;
	newElem->data = elem;
	newElem->next = NULL;
	q.next = newElem;
	return head;
}

List *delete (List *head, int elem) {
	List *p, *q;
	p->next = head;
	while (p->next != NULL) {
		q = p;
		if (p->next->data == elem)
			q->next = p->next->next;
			//return head;
		p = p->next;
	}
	return head;
}

int getLength (List *head) {
	List *p;
	p->next = head;
	int i = 0;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

void printOut (List *head) {
	List *p;
	p->next = head;
	while (p->next != NULL)
		printf("%d\n", p->next->data);
}

void main () {
	List *head = NULL;
	//read file here
	int c, i = 1, c1;
	scanf(&c);
	while (i)
		switch (c) {
			case 1:
				scanf(&c1);
				search(head, c1);
				break;
			case 2:
				scanf(&c1);
				append(head, c1);
				break;
			case 3:
				scanf(&c1);
				delete(head, c1);
				break;
			case 4:
				getLength(head);
				break;
			case 5:
				printOut(head);
				break;
			case 6:
				revers(head);
				break;
			case 0:
				i = 0;
		}
}