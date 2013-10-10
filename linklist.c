#include <stdlib.h>
#include <stdio.h>

typedef struct list {
	int data;
	struct list *next;
} List;

void search (List *head, int elem) {
	List *p = head;
	int i = 0;
	while (p != NULL) {
		if (p != head) {
			i++;
			if (p->data == elem)
				printf("你查找的是：%d ,存在位置:%d", elem, i);
		}
		p = p->next;
	}
	printf("\n");
}

List *append (List *head, int elem) {
	List *p;
	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	List *newElem = (List *)malloc(sizeof(List));
	newElem->data = elem;
	newElem->next = NULL;
	p->next = newElem;
	return head;
}

List *delete (List *head, int elem) {
	List *p = head, *q, *r;
	while (p->next != NULL) {
		r = p;
		p = p->next;
		if (p->data == elem) {
			q = p;
			r->next = p->next;
			free(q);
		}
	}
	return head;
}

int getLength (List *head) {
	List *p = head;
	int i = 0;
	while (p != NULL) {
		if (p != head)
			i++;
		p = p->next;
	}
	return i;
}

void printOut (List *head) {
	List *p = head;
	while (p != NULL) {
		if (p != head)
			printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

List* revers (List *head) {		//list逆序
	List *p, *q, *c = head;
	head = head->next;
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
	return head;
}

void main () {
	List* head = (List *)malloc(sizeof(List)), * p;
	p = head;
	FILE* fp;
	int data;
	fp = fopen("test", "r");
	while (fscanf(fp, "%d", &data) != -1) {
		p->next = (List *)malloc(sizeof(List));
		p = p->next;
		p->data = data;
		p->next = NULL;
	}
	p = NULL;
	int c, i = 1, c1;
	while (i) {
		printf("选择操作：\n");
		printf("1 查询\n");
		printf("2 添加\n");
		printf("3 删除\n");
		printf("4 获取长度\n");
		printf("5 输出全部\n");
		printf("6 逆序重建\n");
		printf("0 退出\n");
		scanf("%d", &c);
		switch (c) {
			case 1:
				printf("输入target数字:");
				scanf("%d", &c1);
				search(head, c1);
				break;
			case 2:
				printf("输入target数字:");
				scanf("%d", &c1);
				head = append(head, c1);
				break;
			case 3:
				printf("输入target数字:");
				scanf("%d", &c1);
				head = delete(head, c1);
				break;
			case 4:
				printf("%d\n", getLength(head));
				break;
			case 5:
				printOut(head);
				break;
			case 6:
				head->next = revers(head);
				break;
			case 0:
				i = 0;
		}
	}
}