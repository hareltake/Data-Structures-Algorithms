#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct polynode {
	double coef;
	int exp;
	struct polynode *link;
};
typedef struct polynode PolyNode;

PolyNode *attach(int coef, int exp, PolyNode *d) {
	PolyNode *x;
	x = (PolyNode *) malloc(sizeof(PolyNode));
	x->coef = coef;
	x->exp = exp;
	x->link = NULL;
	d->link = x;
	return x;
}

PolyNode *polyAdd(PolyNode *a, PolyNode *b) {
	PolyNode *p, *q, *d, *c;
	int x;
	p = a;
	q = b;
	c = (PolyNode *) malloc(sizeof(PolyNode));;
	d = c;
	while (p != NULL && q != NULL) {
		if (p->exp == q->exp) {
			x = p->coef + q->coef;
			if (x != 0)
				d = attach(x, p->exp, d);
			p = p->link;
			q = q->link;
		}
		if (p->exp < q->exp) {
			d = attach(q->coef, q->exp, d);
			q = q->link;
		}
		if (p->exp > q->exp) {
			d = attach(p->coef, p->exp, d);	
			p = p->link;
		}
	}
	while (p != NULL) {
		d = attach(p->coef, p->exp, d);
		p = p->link;
	}
	while (q != NULL) {
		d = attach(q->coef, q->exp, d);
		q = q->link;
	}
	d->link = NULL;
	//p = c;
	//c = c->link;
	//free(p);
	return c;
}

void main () {
	PolyNode *a = (PolyNode *) malloc(sizeof(PolyNode)),
			 *b = (PolyNode *) malloc(sizeof(PolyNode)),
			 *a1 = a, *b1 = b;
	int i = 2;
	while (i < 5) {
		a->coef = i;
		a->exp = i - 1;
		a->link = (PolyNode *) malloc(sizeof(PolyNode));
		a = a->link;
		b->coef = i + 1;
		b->exp = i + 2;
		b->link = (PolyNode *) malloc(sizeof(PolyNode));
		b = b->link;
		i++;
	}
	a = NULL;
	b = NULL;
	PolyNode *result = polyAdd(a1, b1),
			 *p = NULL;
	printf("%d\n", result->link->exp);
	while (result->link != NULL) {
		p = result;
		result = result->link;
		printf("%f*x^", result->coef);
		printf("%d", result->exp);
		if (result != NULL)
			printf("+");
		free(p);
	}
	while (a1->link != NULL) {
		a1 = a1->link;
		free(a1);
	}
	while (b1->link != NULL) {
		b1 = b1->link;
		free(b1);
	}
}