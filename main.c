//CHAPITRE 1 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//le txt est composé d'un numéro de tel suivi par nom/prénom
//on créé une structure élément qui divise un individu en un int pour son num
//ainsi qu'une chaine de charactères contenant nom prénom 
//ainsi qu'un booléen pour définir un appel entrant ou sortant

typedef struct element{
	char full[80];			//ligne entière
	long long pn;			//num de tel
	char name[100];			//nom/prénom de la personne
	bool inout;				//appel in (0) ou out (1)
}t_el;


////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

int main(){
	
	//Récupération des donnés du .txt
	FILE* fpread = NULL;
	char *endPtr;
	
	t_el tableau[1000];
	int puissance = 8;
	int i=0;
	
	fpread = fopen("reltel.txt", "r");
	
	if(fpread==NULL){
		printf("pas de fichirs txt\n");
	}
	
	
	//on rempli le tableau des chaines de caractères lignes par lignes
	for(int i=0; i<1000; i++){
		fgets(tableau[i].full, 150, fpread);
	}
	//pour afficher debug
	
	// for(int i=0; i<1000; i++){
		// printf("%d : %s",i, tableau[i].full);
	// }

	
	
	
	//méthode
	//on split la liste de donnés dans les bons attributs du tableau d'éléments t_elt
	// for(int f=0;f<1000;++f){
		// for(int g=4;g<13;++g){
			// tableau[f].pn += pow(10, puissance) * charToInt(tableau[f].full[g]);
			// puissance--;
		// }
		// puissance = 8;
	// }
	// for(int f=0;f<1000;++f){
		// printf("%d : %d\n", f+1, tableau[f].pn);
	// }
	
	
	for(int f=0;f<1000;++f){
		
		printf("\nNEW\n");
		
		endPtr = tableau[f].full;
		
		while(endPtr!=tableau[f].full + strlen(tableau[f].full)){
			
			printf("ACTUEL : %c\n", *endPtr);
			
			//condition passer carac d'après si différent de int
			if(!isdigit(*endPtr)){
				++endPtr;
				printf("skip\n");
			}
			else{
			endPtr+=2;
			tableau[f].pn = atoll(endPtr);
			printf("num added |%ld|\n", tableau[f].pn);
			break;
			}
		}
	}
	
	// for(int k=0;k<1000;++k){
		// printf("%ld\n", tableau[k].pn);
	// }
	
	
	return 0;
}
