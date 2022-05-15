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
#include <stdbool.h>


///////////////////////////////////
///////////////////////////////////


typedef struct element{
	char full[80];			//ligne entière
	long long pn;			//num de tel
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

typedef struct entite{
	int nombre;
	int occurence;
}t_entite;


typedef struct regchap3{
	t_entite *histo;
	int nbtotal;
}t_reg3;

///////////////////////////////////
///////////////////////////////////

//CHAPITRE 1

void fillIn(FILE* fpread, t_el tableau[]);
void swap(t_el* xp, t_el* yp);
void printArray(t_el arr[], int size);
void bubbleSort(t_el arr[], int n);
void insertionSort(t_el arr[], int n);

bool is_sorted(t_el *a, int n);
void shuffle(t_el *a, int n);
void bogosort(t_el *a, int n);

///////////////////////////////////
///////////////////////////////////

//CHAPITRE 2

t_reg* registre(t_el tableau[], int size, t_reg* reg);
int ifIn(long long a, t_contact* tab, int i);
int inOut(char chaine[]);
void displayRegister(t_reg* registre);
void resizeName(t_reg *reg);
void fillRegister(t_contact* tableau,t_reg* monregistre);
void showHarceleur(t_reg* monRegistre);

///////////////////////////////////
///////////////////////////////////

//CHAPITRE 3

void chapitre3(t_reg3* reg, t_entite* histo);
int isInInt(int nb, t_entite* tab, int tabsize);
void fillRegister3(t_entite* tableau, t_reg3* registre);
void showRegister3(t_reg3* registre);

///////////////////////////////////
///////////////////////////////////

#endif // HEADER_H_