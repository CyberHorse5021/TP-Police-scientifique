#ifndef HEADER_H_
#define HEADER_H_

///////////////////////////////////
///////////////////////////////////


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>

///////////////////////////////////
///////////////////////////////////

//structure saving every call as an element

typedef struct element{
	char full[80];			//ligne entière
	long long pn;			//num de tel
	// char name[100];		//nom/prénom de la personne
	// bool inout;			//appel in (0) ou out (1)
}t_el;

typedef struct contact{
	long long cpn;
	char cfull[80];
	int cin;
	int cout;
	int allcalls;
}t_contact;

typedef struct reg{
	t_contact *tab;
	int contactNb;
}t_reg;

///////////////////////////////////
///////////////////////////////////

void fillIn(FILE* fpread, t_el tableau[]);
void swap(t_el* xp, t_el* yp);
void printArray(t_el arr[], int size);


void bubbleSort(t_el arr[], int n);
void insertionSort(t_el arr[], int n);

t_reg* registre(t_el tableau[], int size);
int ifIn(int a, t_contact* tab, int i);
int inOut(char chaine[]);
void displayRegister(t_reg* registre);

///////////////////////////////////
///////////////////////////////////

#endif // HEADER_H_INCLUDED