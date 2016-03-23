#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    //if use VC6.0, commt this
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//-std=gnu99

//#define bool int    //if use VC6.0, uncommt these
//#define true 1
//#define false 0

#define ElemType int
#define CREATMAX 100

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool initialize(LinkList *l);
bool insert(LinkList l, int pos, ElemType data);    //no.0 is reserved for head node, pos no.1 is the first elem
bool add(LinkList l, ElemType data);
bool del(LinkList l, int pos);
bool pop(LinkList l);
int find(LinkList l, ElemType data);
bool get(LinkList l, int pos, ElemType *data);
int getlength(LinkList l);

void printlist(LinkList l);
void creatlist(LinkList *l);


int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));

	return 0;
}

bool initialize(LinkList *l) {
	LNode *q = (LNode*)malloc(sizeof(LNode));
	q->data = 0;
	q->next = NULL;
	*l = q;
	return true;
}

bool insert(LinkList l, int pos, ElemType data) {
	LNode *p = l;
	int i = 0;
	while(p && i<pos-1) {
		p = p->next;
		i++;
	}
	if(!p || i>pos-1) {
		return false;
	}
	LNode *q = (LNode*)malloc(sizeof(LNode));
	q->data = data;
	q->next = p->next;
	p->next = q;
	return true;
}

bool add(LinkList l, ElemType data) {
	LNode *p = l;
	while(p->next) {
		p = p->next;
	}
	LNode *q = (LNode*)malloc(sizeof(LNode));
	q->data = data;
	q->next = NULL;
	p->next = q;
	return true;
}

bool del(LinkList l, int pos) {
	LNode *p = l;
	int i = 0;
	while(p->next && i<pos-1) {
		p = p->next;
		i++;
	}
	if(!(p->next) || i>pos-1) {
		return false;
	}
	LNode *q = p->next;
	p->next = p->next->next;
	free(q);
	return true;
}

bool pop(LinkList l) {
	LNode *p = l;
	while(p->next->next) {
		p = p->next;
	}
	LNode *q = p->next;
	p->next = NULL;
	free(q);
	return true;
}

int find(LinkList l, ElemType data) {
	LNode *p = l;
	if(p!=(LNode*)0x0) {    //has head node
		if(p->next) {    //has elem
			int i = 1;
			p = p->next;
			while(p) {
//				printf("%d\n", p->data);
				if(p->data==data) {
					return i;
				}
				p = p->next;
				i++;
			}
			return -1;
		}
		else {    //does not have elem
			printf("does not have elem");
			return -1;
		}
	}
	else {    //does not have head node
		printf("does not have head node");
		return -1;
	}
}

bool get(LinkList l, int pos, ElemType *data) {
	LNode *p = l;
	if(p!=(LNode*)0x0) {    //has head node
		if(p->next) {    //has elem
			while(p && pos>0) {
				p = p->next;
				pos--;
			}
			if(!p || pos<0) {
				return false;
			}
			else {
				*data = p->data;
				return true;
			}
		}
		else {    //does not have elem
			printf("does not have elem");
			return false;
		}
	}
	else {    //does not have head node
		printf("does not have head node");
		return false;
	}
}


void printlist(LinkList l) {
	LNode *p = l;
	if(!p) {
		printf("LinkList is not being initialized!");
	}
	else if(!(p->next)) {
		printf("there is not any elem in linklist");
	}
	else {
		int i = 0;
		while(p) {
			printf("Node%d:  %d\n", i, p->data);
			p = p->next;
			i++;
		}
	}
}

void creatlist(LinkList *l) {
	initialize(l);
	for(int i=0; i<CREATMAX; i++) {
		add(*l, rand()%(101));
	}
}

int getlength(LinkList l) {
    LNode *p = l;
    if(p) {    //has head node
        if(p->next) {    //has elem
            int i = -1;
            while(p) {
                p = p->next;
                i++;
            }
            return i;
        }
        else {    //does not have elem
            return 0;
        }
    }
    else {    //does not have head node
        return -1;
    }
}
