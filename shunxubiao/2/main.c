#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//-std=gnu99

#define MAXNUM 1000    //if MAXNUM large than 0x7FFF plz change type of SeqList.length
#define elemtype int

typedef struct SeqList {
	elemtype data[MAXNUM];
	int length;
}seqlist;

bool initialize(seqlist *l);
bool insert(seqlist *l, int i, elemtype data);    //i is begin at 0
bool add(seqlist *l, elemtype data);
bool del(seqlist *l, int i);    //i is begin at 0
bool pop(seqlist *l);
bool get(seqlist l, int i, elemtype *x);    //return flase for fail
int find(seqlist l, elemtype data);    //return -1 for fial
void printlist(seqlist l);
void creatlist(seqlist *l);

void intersection(seqlist *A, seqlist B);    //intersection

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	
	seqlist A;
	seqlist B;
//	printf("%x\n", &A);
//	printf("%x\n", &B);
	creatlist(&A);
	creatlist(&B);
//	initialize(&A);
//	initialize(&B);
//	
//	add(&A, 1);
//	add(&A, 2);
//	add(&A, 3);
//	add(&A, 4);
//	add(&A, 5);
//	add(&B, 4);
//	add(&B, 5);
//	add(&B, 6);
//	add(&B, 7);
//	add(&B, 8);
	
	printlist(A);
	printlist(B);
//	printf("%d\n", find(A, 5));
//	pop(&A);
//	del(&A, 2);
	intersection(&A, B);
	printlist(A);
	return 0;
}

bool initialize(seqlist *l) {
	l -> length = 0;
	return true;
}

bool insert(seqlist *l, int i, elemtype data) {
	if(l->length>=MAXNUM) {
		printf("List is full!");
		return false;
	}
	else if(i<0 || i>l->length) {
		printf("i out of range!");
		return false;
	}
	else {
		for(int j=l->length; j>i; j--) {
			l->data[j] = l->data[j-1];
		}
		l->data[i] = data;
		l->length++;
		return true;
	}
}

bool add(seqlist *l, elemtype data) {
	return insert(l, l->length, data);
}

bool del(seqlist *l, int i) {
	if(i<0 || i>l->length-1) {
		printf("i out of range!");
		return false;
	}
	else {
		for(int j=i; j<l->length-1; j++) {
			l->data[j] = l->data[j+1];
		}
		l->length--;
		return true;
	}
}

bool pop(seqlist *l) {
	return del(l, l->length-1);
}

bool get(seqlist l, int i, elemtype *x) {
	if(i<0 || i>l.length-1) {
		printf("i out of range!");
		x = NULL;
		return false;
	}
	else {
		return l.data[i];
	}
}

int find(seqlist l, elemtype data) {
	for(int i=0; i<l.length; i++) {
		if(l.data[i]==data) {
			return i;
		}
	}
	return -1;
}

void printlist(seqlist l) {
	printf("length:%d\n\n", l.length);
	for(int i=0; i<l.length; i++) {
		printf("%d\t", l.data[i]);
	}
	printf("\n\n");
}

void creatlist(seqlist *l) {
	initialize(l);
	for(int i=0; i<50; i++) {
		add(l, rand()%(101));
	}
}

void intersection(seqlist *A, seqlist B) {
	for(int i=0; i<A->length; i++) {
		if(find(B, A->data[i])==-1) {
			del(A, i);
			i--;
		}
	}
}

