#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///////////////////////////////////
///////////////////////////////////

//structure saving every call as an element

typedef struct element{
	char full[80];			//ligne entière
	long long pn;			//num de tel
	// char name[100];			//nom/prénom de la personne
	// bool inout;				//appel in (0) ou out (1)
}t_el;

///////////////////////////////////
///////////////////////////////////

void fillIn(FILE* fpread, t_el tableau[]);



#endif // HEADER_H_INCLUDED