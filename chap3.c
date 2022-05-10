#include "header.h"

void chapitre3(){
		
	int tableau[1000];
	
	t_entite* histo = NULL;
	histo = (t_entite*)malloc(sizeof(t_entite));
	
	t_reg3* monRegistre = NULL;
	monRegistre = (t_reg3*)malloc(sizeof(t_reg3));
	if(monRegistre==NULL){
		printf("alloc failed\n");
	}
	monRegistre->histo=NULL;
	
	int compteur=0;
	int returned;
	
	
	for(int i=0;i<1000;++i){
		tableau[i]=rand()%25;
	}
	
	for(int j=0;j<1000;++j){
		returned = isInInt(tableau[j], histo, compteur);
		if(returned!=-1){
			histo[returned].occurence++;
		}
		else{
			compteur++;
			realloc(histo, sizeof(t_entite)*compteur);
			histo[compteur-1].nombre=tableau[j];
			histo[compteur-1].occurence=1;
		}
	}

    printf(("%d\n"), compteur);

	//on remplie l'histograme
	monRegistre->nbtotal = compteur;
    printf("COUCOU\n");
	fillRegister3(histo, monRegistre);


	//on libère la mémoire
	free(histo);
	//on affiche l'histogramme
	showRegister3(monRegistre);
	
	
	printf("Histograme de la génération :\n");
	
}

///////////////////////////////////
///////////////////////////////////	

int isInInt(int nb, t_entite* tab, int tabsize){
	for(int i=0;i<tabsize;++i){
		if(nb == tab[i].nombre){
			return i;
		}
	}
	return -1;
}

///////////////////////////////////
///////////////////////////////////	

void fillRegister3(t_entite* tableau, t_reg3* registre){
    printf("COUCOU1\n");
	registre->histo = (t_entite*)malloc(sizeof(t_entite)*(int)registre->nbtotal);
    printf("COUCOU2\n");
	for(int i = 0;i<registre->nbtotal;++i){
		registre->histo[i] = tableau[i];
	}
}

///////////////////////////////////
///////////////////////////////////	

void showRegister3(t_reg3* registre){
	
	for(int i=0;i<registre->nbtotal;++i){
		printf("Entier : %d\n", registre->histo[i].nombre);
		printf("Occurence : %d\n", registre->histo[i].occurence);
		printf("\n\n");
	}
}