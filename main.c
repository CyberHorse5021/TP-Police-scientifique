#include "header.h"

int main(){
	
	FILE* fpread = NULL;
	t_el tableau[1000];
	t_reg* myRegistre = NULL;
	
	int choix=0;
	int debug=-1;
	
	fpread = fopen("reltex.txt", "r");
	if(fpread==NULL){
		printf("pas de fichirs txt\n");
		return 0;
	}
	
	//remplis le tableau depuis le fichier txt
	fillIn(fpread, tableau);		//gets datas from given txt file
		
		choix=0;
		debug=-1;
		
		printf("\n\n------------------------------------------------\n");
		printf("------------------------------------------------\n\n");
		
		printf("\nBienvenue sur la plateforme de tri.\n");
		printf("Le fichier .txt est deja load.\n\n");
		printf("Pour des raisons de chargement de fichiers, veuillez restart le programme a chaques tris/options.\n\n");
		printf("Quel algorithme vouez vous utiliser :\n");
		printf("1) Bubble sort\n2) Insertion sort\n3) Display unsorted list\n4) Quit\n");
		
		do{
		printf("\n  --> ");
		fflush(stdin);
		scanf("%d", &choix);
		}while(!(choix==1 || choix==2 || choix ==3 || choix ==4));
		
		if(choix==4){
			printf("A bientot !\n");
			fclose(fpread);
			return 0;
		}
		
		
		
		if(choix==3){
			printArray(tableau, 1000);
			return 0;
		}
		else{
			printf("\n  Voulez vous voir la sorted list (0/1) :\n");
			printf("  (le temps d'execution s'affiche avant l'affichage de la liste)\n");
			do{
				printf("\n  --> ");
				fflush(stdin);
				scanf("%d", &debug);
			}while(!(debug==0 || debug==1));
			
			if(choix==1){
				bubbleSort(tableau, 1000);
				if(debug==1){
					printArray(tableau, 1000);
				}
			}
			if(choix==2){
				insertionSort(tableau, 1000);
				if(debug==1){
					printArray(tableau, 1000);
				}
			}
		}
		
	printf("\n\n------------------------------------------------\n");
	printf("------------------------------------------------\n\n");

	printf("Chaptire 2 :\n");
	printf("Creating a contact list...\n\n");
	
	
	//implémenter la mise en registre 
	myRegistre = registre(tableau, 1000);
	
	
	//stops because of 15th element
	displayRegister(myRegistre);
	

	printf("fin");
	fclose(fpread);
	free(myRegistre);
	
	return 0;
}
