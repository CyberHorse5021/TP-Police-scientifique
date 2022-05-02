#include "header.h"

///////////////////////////////////
///////////////////////////////////

void fillIn(FILE* fpread, t_el* tableau){
	
	char *endPtr;
	//on rempli le tableau des chaines de caractères lignes par lignes
	for(int i=0; i<1000; i++){
		fgets(tableau[i].full, 150, fpread);
	}
	
	for(int f=0;f<1000;++f){
		endPtr = tableau[f].full;
		
		while(endPtr!=tableau[f].full + strlen(tableau[f].full)){	
			//condition passer carac d'après si différent de int
			if(!isdigit(*endPtr)){
				++endPtr;
			}
			else{
			endPtr+=2;
			tableau[f].pn = atoll(endPtr);
			break;
			}
			
		}
	}
	
	//uncomment to show
	// for(int k=0;k<1000;++k){
		// printf("%ld\n", tableau[k].pn);
	// }
	
}

///////////////////////////////////
///////////////////////////////////

//from geeksforgeeks.org
void swap(t_el* xp, t_el* yp){
    t_el temp = *xp;
    *xp = *yp;
    *yp = temp;
}


///////////////////////////////////
///////////////////////////////////


// A function to implement bubble sort
void bubbleSort(t_el arr[], int n){
	
    int i, j;
	clock_t begin, end;
	begin = clock();
    for (i = 0; i < n - 1; i++){
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++){
            if (arr[j].pn > arr[j + 1].pn){
                swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n-------------------------------\nTri bulle fini.\n\n");
	printf("-->Temps tri : %f secondes\n-------------------------------\n\n", time_spent); 
}

///////////////////////////////////
///////////////////////////////////

void printArray(t_el arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d : %s \n", i, arr[i].full);
	}	
}

///////////////////////////////////
///////////////////////////////////

void insertionSort(t_el arr[], int n){
	t_el key;
    int i, j;	
	clock_t begin, end;
	
	begin = clock();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j].pn > key.pn) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
	end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n-------------------------------\nTri insertion fini.\n\n");
	printf("-->Temps tri : %f secondes\n-------------------------------\n\n", time_spent); 
}

///////////////////////////////////
///////////////////////////////////


t_reg* registre(t_el tableau[], int size){
	
	int nbOfContact=0;
	int returned;
	
	
	printf("debug\n");	
	t_reg* monregistre = NULL;
	monregistre = (t_reg*) malloc(sizeof(t_reg)*1);
	
	t_contact* contactList = NULL;
	contactList = (t_contact*)malloc(sizeof(t_contact));
	
	
	for(int i=0;i<size;++i){
		
		//on vérifie si si le numero est deja dans la liste de contactes
		returned = ifIn(tableau[i].pn, contactList, nbOfContact);
		
		//numéro deja enregistré dans le répertoire
		if(returned!=-1){
			
			contactList[returned].allcalls++;
			
			if(inOut(tableau[i].full)==1){
				contactList[returned].cout++;
			}
			if(inOut(tableau[i].full)==2){
				contactList[returned].cin++;
			}
		}
		
		//numero pas encore enregistré
		else{
			nbOfContact++;
			realloc(contactList, sizeof(t_contact)*nbOfContact);
			contactList[nbOfContact-1].cpn = tableau[i].pn;
			strcpy(contactList[nbOfContact-1].cfull, tableau[i].full);
			contactList[nbOfContact-1].allcalls=1;
			
			if(inOut(contactList[nbOfContact-1].cfull)==1){
				contactList[nbOfContact-1].cout=1;
				contactList[nbOfContact-1].cin=0;
			}
			if(inOut(contactList[nbOfContact-1].cfull)==2){
				contactList[nbOfContact-1].cin=1;
				contactList[nbOfContact-1].cout=0;
			}
		}
	}
	
	
	// POUR DEBUG SUPPRIMER APRES
	printf("------------------------------------------------\n");
	printf("------------------------------------------------\n");
	for(int j=0;j<nbOfContact;++j){
		printf("%d | All infos : %s",j, contactList[j].cfull);
		printf("%d | numero : +33%ld\n",j, contactList[j].cpn);
		printf("%d | nbappels : %d\n",j,contactList[j].allcalls);
		printf("%d | appels IN : %d\n", j,contactList[j].cin);
		printf("%d | appels OUT : %d\n", j,contactList[j].cout);
		printf("\n\n");
	}
	printf("------------------------------------------------\n");
	printf("------------------------------------------------\n");
	
	
	
	//fonction pour récuper prenom nom uniquement
	//on met tout dans la structure registre (a doublecheck)
	monregistre->tab = (t_contact*) malloc(sizeof(t_contact)*nbOfContact);
	monregistre->tab = contactList;
	monregistre->contactNb = nbOfContact;
	printf("debug\n");
	return monregistre;
}

///////////////////////////////////
///////////////////////////////////	
	
int ifIn(int a, t_contact* tab, int i){
	for(int j=0;j<i;++j){
		if(a == tab[j].cpn){
			return j;
		}
	}
	return -1;
}

///////////////////////////////////
///////////////////////////////////

int inOut(char chaine[]){
	//on sait qu'il y'a 4 espoces dans le format du fichier txt
	//on met un compteur d'espace et on prend la première lettre après le 5eme espace
	//si S comme sortant -> return 1, sinon E return 0;
	
	int spaceCounter=0;
	char *cursor;
	cursor = chaine;
	
	while(spaceCounter!=4){
		if(*cursor==' '){
			spaceCounter++;
		}
		cursor++;
	}
	
	if(*cursor=='S'){
		return 1;
	}
	if(*cursor=='E'){
		return 2;
	}
}


///////////////////////////////////
///////////////////////////////////

void displayRegister(t_reg* registre){
	
	for(int i=0;i<registre->contactNb;++i){
		printf("--------------------------\n\n");
		printf("Name : %s", registre->tab[i].cfull);
		printf("Phone number : +33%ld\n", registre->tab[i].cpn);
		printf("All calls : %d\n",registre->tab[i].allcalls);
		printf("Inbound calls : %d\n",registre->tab[i].cin);
		printf("Outbounds calls : %d\n\n",registre->tab[i].cout);
	}		
	printf("--------------------------\n");
	
}

///////////////////////////////////
///////////////////////////////////