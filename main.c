#include "header.h"

int main(){
	
	FILE* fpread = NULL;
	t_el tableau[1000];
	
	int choix=0;
	int debug=-1;
		
	
	while(choix!=4){
		
		fpread = fopen("reltel.txt", "r");
		if(fpread==NULL){
			printf("pas de fichirs txt\n");
		}
		
		int choix=0;
		int debug=-1;

		//remplis le tableau depuis le fichier txt
		
		// printf("HAHAHAHAHAHAHAAHHAAHAHAHAHAHAHAHA\n");
		fillIn(fpread, tableau);		//gets datas from given txt file
		// printArray(tableau, 1000);
		
		printf("-----------------------\n");
		printf("Bienvenu sur la plateforme de tri.\n");
		printf("Le fichier .txt est deja load.\n\n");
		printf("Quel algorithme vouez vous utiliser :\n");
		printf("1) Bubble sort\n2) Insertion sort\n3) Display unsorted list\n4) Quit\n");
		
		do{
		printf("\n--->");
		fflush(stdin);
		scanf("%d", &choix);
		}while(!(choix==1 || choix==2 || choix ==3 || choix ==4));
		
		if(choix==4){
			printf("A bientot !\n");
			fclose(fpread);
			return 0;
		}
		
		printf("-----------------------\n");
		
		if(choix==3){
			printArray(tableau, 1000);
		}
		else{
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
	}
	
	fclose(fpread);
	return 0;
}
