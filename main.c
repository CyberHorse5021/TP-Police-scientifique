#include "header.h"

int main(){
	
	FILE* fpread = NULL;
	t_el tableau[1000];
	
	fpread = fopen("reltel.txt", "r");
	if(fpread==NULL){
		printf("pas de fichirs txt\n");
	}
	
	fillIn(fpread, tableau);		//gets datas from given txt file
	
	
	printArray(tableau, 1000);
	printf("---------------------NEXT----------------------\n");
	bubbleSort(tableau, 1000);
	// insertionSort(tableau, 1000);
	printArray(tableau, 1000);
	
	return 0;
}
