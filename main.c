#include "header.h"

int main(){
	
	FILE* fpread = NULL;
	t_el tableau[1000];
	
	int choix=0;
	int debug=-1;
	
	while(choix!=3){
		
		fpread = fopen("reltel.txt", "r");
		if(fpread==NULL){
			printf("pas de fichirs txt\n");
		}

		int choix=0;
		int debug=-1;

		//remplis le tableau depuis le fichier txt
		
		fillIn(fpread, tableau);		//gets datas from given txt file
		printf("-----------------------\n");
		printf("Bienvenu sur la plateforme de tri.\n");
		printf("Le fichier .txt est deja load.\n\n");
		printf("Quel algorithme vouez vous utiliser :\n");
		printf("1) Bubble sort\n2) Insertion sort\n3) Quitter\n");
		do{
		printf("\n--->");
		fflush(stdin);
		scanf("%d", &choix);
		}while(!(choix==1 || choix==2 || choix ==3));
		if(choix==3){
			printf("A bientot !\n");
			fclose(fpread);
			return 0;
		}
		printf("-----------------------\n");
		printf("\n\n Voulez vous voir le debug (0/1) :\n");
		do{
			printf("\n--->");
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
	
	fclose(fpread);
	return 0;
}
