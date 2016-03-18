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
bool get(seqlist l, int i, elemtype *x);    //return flase for fail, plz init x before call this func
int find(seqlist l, elemtype data);    //return -1 for fial
void printlist(seqlist l);
void creatlist(seqlist *l);

void seqlistsort(seqlist *l);
void delinseqlist(seqlist *l, elemtype data);

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	
	seqlist A;
	
	creatlist(&A);
	
	printlist(A);
	
//	seqlistsort(&A);
	
	elemtype r = rand()%(101);
	printf("delete:%d\n\n", r);
	delinseqlist(&A, r);
	
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
	seqlistsort(l);
}

void seqlistsort(seqlist *l) {
	elemtype tmp;
	for(int i=l->length-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(l->data[j]>l->data[j+1]) {
				tmp = l->data[j];
				l->data[j] = l->data[j+1];
				l->data[j+1] = tmp;
			}
		}
	}
}

void delinseqlist(seqlist *l, elemtype data) {
	for(int i=find(*l, data); i!=-1; i=find(*l, data)) {
		del(l, i);
	}
}

