#include "header.h"

void chapitre3(t_reg3* monRegistre, t_entite* histo){
	

	int tableau[1000];	//on va y mettre les 1000 entiers
	
	int histoRapide[25];


	int compteur=0;
	int returned;
	
	
	for(int i=0;i<1000;++i){
		tableau[i]=rand()%25;
	}
	clock_t begin = clock();
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
	clock_t end = clock();

	monRegistre->nbtotal = compteur;
	fillRegister3(histo, monRegistre);
	
	printf("Histograme de la generation METHODE 1:\n");
	showRegister3(monRegistre);
	printf("  --> Temps creation histogramme : %ld millisecondes \n", (end-begin)*1000/CLOCKS_PER_SEC);
	
	
	printf("\n\n---------------------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------------------------\n\n");
	
	
	//version rapide METHODE 2
	for(int f=0;f<25;++f){
		histoRapide[f]=0;
	}
	clock_t begin2 = clock();
	for(int o = 0;o<1000;++o){
		histoRapide[tableau[o]]++;
	}
	clock_t end2 = clock();
	printf("Histograme de la generation METHODE 2:\n\n");
	
	for(int g=0;g<25;++g){
		printf("Nombre : %d\n", g);
		printf("Occurence : %d\n", histoRapide[g]);
		printf("------------------\n");
	}
	printf("\n\n-->Temps de creation histogramme 2 : %ld millisecondes.", (end2-begin2)*1000/CLOCKS_PER_SEC);
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
	registre->histo = (t_entite*)malloc(sizeof(t_entite)*(int)registre->nbtotal);
	for(int i = 0;i<registre->nbtotal;++i){
		registre->histo[i] = tableau[i];
	}
}

///////////////////////////////////
///////////////////////////////////	

void showRegister3(t_reg3* registre){
	
	for(int i=0;i<registre->nbtotal;++i){
		printf("-----------------\n");
		printf("Entier : %d\n", registre->histo[i].nombre);
		printf("Occurence : %d\n", registre->histo[i].occurence);
		printf("-----------------\n");
	}
	printf("\n\n");
}