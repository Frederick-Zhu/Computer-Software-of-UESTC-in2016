#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    //if use VC6.0, commt this line
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//-std=gnu99

//#define bool int    //if use VC6.0, uncommt thses three line
//#define true 1
//#define false 0

#define MAXNUM 1000    //if MAXNUM large than 0x7FFF plz change type of SeqList.length
#define CREATLEN 500
#define elemtype student

typedef struct Student {
	int number;
	int math;
}student;

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
void delbynumber(seqlist *l, int number);
int findbynumber(seqlist l, int number);
student newstudent(int number, int math);

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	
	seqlist A;
	creatlist(&A);
	printlist(A);
	int r = rand()%(900)+100;
	printf("delete:%d\n\n", r);
	delbynumber(&A, r);
	
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
		*x = l.data[i];
		return true;
	}
}

int find(seqlist l, elemtype data) {
	for(int i=0; i<l.length; i++) {
		if(l.data[i].number==data.number && l.data[i].math==data.math) {
			return i;
		}
	}
	return -1;
}
void printlist(seqlist l) {
	printf("length:%d\n\n", l.length);
	for(int i=0; i<l.length; i++) {
		printf("%d\t%d\n", l.data[i].number, l.data[i].math);
	}
	printf("\n\n");
}

void creatlist(seqlist *l) {
	initialize(l);
	for(int i=0; i<CREATLEN; i++) {
		add(l, newstudent(rand()%(900)+100, rand()%(101)));
	}
	seqlistsort(l);
}

void seqlistsort(seqlist *l) {
	elemtype tmp;
	for(int i=l->length-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(l->data[j].number>l->data[j+1].number) {
				tmp = l->data[j];
				l->data[j] = l->data[j+1];
				l->data[j+1] = tmp;
			}
		}
	}
}

void delbynumber(seqlist *l, int number) {
	for(int i=findbynumber(*l, number); i!=-1; i=findbynumber(*l, number)) {
		del(l, i);
	}
}

int findbynumber(seqlist l, int number) {
	for(int i=0; i<l.length; i++) {
		if(l.data[i].number==number) {
			return i;
		}
	}
	return -1;
}

student newstudent(int number, int math) {
	student s;
	s.number = number;
	s.math = math;
	return s;
}

