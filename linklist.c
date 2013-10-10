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
		printf("%d ", q->data);
		head->next = q->next;
		printf("%d ", head->data);
		q->next = p;
		p = q;
		printf("%d\n", p->data);
	}
	head = p;
	printf("%d\n", head->data);
}

/*int *search (List *head, int elem) {
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
	q->next = newElem;
	return head;
}*/

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
	List* head = (List *)malloc(sizeof(List)), * p;
	p = head;
	FILE* fp;
	int data;
	fp = fopen("test", "r");
	while (fscanf(fp, "%d", &data) != -1) {
		p->next = (List *)malloc(sizeof(List));
		p->data = data;
		p = p->next;
	}
	free(p);
	p = NULL;
	int c, i = 1, c1;
	while (i) {
		printf("选择操作：");
		scanf("%d", &c);
		switch (c) {
			case 1:
				scanf("%d", &c1);
				//search(head, c1);
				break;
			case 2:
				scanf("%d", &c1);
				//append(head, c1);
				break;
			case 3:
				scanf("%d", &c1);
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
				//printf("%d\n", head->data);
				break;
			case 0:
				i = 0;
		}
	}
}