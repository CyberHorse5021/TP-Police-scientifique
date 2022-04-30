#include "header.h"

int main(){
	
	FILE* fpread = NULL;
	t_el tableau[1000];
	
	fpread = fopen("reltel.txt", "r");
	if(fpread==NULL){
		printf("pas de fichirs txt\n");
	}
	
	
	fillIn(fpread, tableau);		//gets datas from given txt file
	
	return 0;
}
