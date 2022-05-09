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
	
	
	t_reg* monregistre = NULL;
	monregistre = (t_reg*) malloc(sizeof(t_reg));
	monregistre->tab=NULL;
	
	
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
	
	
	
	// UNCOMMENT FOR DEBUG
	
	printf("------------------------------------------------\n");
	printf("------------------------------------------------\n");
	for(int j=0;j<nbOfContact;++j){
		printf("%d | All infos : %s",j, contactList[j].cfull);
		printf("%d | Numero : +33%lli\n",j, contactList[j].cpn);
		printf("%d | Appels totals : %d\n",j,contactList[j].allcalls);
		printf("%d | Appel entrants : %d\n", j,contactList[j].cin);
		printf("%d | Appels sortants : %d\n", j,contactList[j].cout);
		printf("\n\n");
	}
	printf("------------------------------------------------\n");
	printf("------------------------------------------------\n");
	

	///////////////////////////////
	///////////////////////////////



	//on met tout dans la structure registre
	monregistre->contactNb = nbOfContact;
	printf("111111111111111\n");
	fillRegister(contactList, monregistre);
	printf("111111111111111\n");
	free(contactList);
	
	
	
	
	//vérification tempo
	printf("nb of contact : %d\n\n", monregistre->contactNb);
	for(int n=0;n<monregistre->contactNb;++n){
		printf("%d | All infos : %s",n, monregistre->tab[n].cfull);
		printf("%d | Numero : +33%lli\n",n, monregistre->tab[n].cpn);
		printf("%d | Appels totals : %d\n",n,monregistre->tab[n].allcalls);
		printf("%d | Appel entrants : %d\n", n,monregistre->tab[n].cin);
		printf("%d | Appels sortants : %d\n", n,monregistre->tab[n].cout);
		printf("\n\n");
	}
	
	//on return le registre d'appels
	
	return monregistre;
}


///////////////////////////////////
///////////////////////////////////	
	
	
int ifIn(long long a, t_contact* tab, int i){
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
	
	//on isole les prenoms
	resizeName(registre);
	
	
	for(int i=0;i<registre->contactNb;++i){
		printf("--------------------------\n\n");
		printf("Name : %s", registre->tab[i].cfull);
		// printf("Phone number : +33%lli\n", registre->tab[i].cpn);
		// printf("All calls : %d\n",registre->tab[i].allcalls);
		// printf("Inbound calls : %d\n",registre->tab[i].cin);
		// printf("Outbounds calls : %d\n\n",registre->tab[i].cout);
	}		
	printf("--------------------------\n");
	
	
	
}

///////////////////////////////////
///////////////////////////////////

//fonction pour récuper prenom nom uniquement
void resizeName(t_reg *reg){
	
	char tempo[80];
	char* curs;
	int indice1=0, indice2=0, compteSpace=0, lengh;
	
	printf("size : %d\n\n", reg->contactNb);
	
	
	//debug purpose
	for(int k =0;k<reg->contactNb;++k){
		printf("CHAINE  : %s\n", reg->tab[k].cfull);
	}

	for(int j=0;j<reg->contactNb;++j){
		
		printf("nb %d\n", j);
		curs = reg->tab[j].cfull;
		
		while(compteSpace!=2){
		if(*curs==' '){
			compteSpace++;
		}
		curs++;
		indice1++;
		}	
	
		curs = reg->tab[j].cfull;
		compteSpace=0;
		
		while(compteSpace!=4){
			if(*curs==' '){
				compteSpace++;
			}
			curs++;
			indice2++;
		}
		
		lengh = indice2-indice1;
		
		// strncpy(reg->tab[j].cfull, &reg->tab[j].cfull[indice1], lengh);
		strncpy(tempo, &reg->tab[j].cfull[indice1], lengh);
		memset(reg->tab[j].cfull,0,sizeof(reg->tab[j].cfull));
		strcpy(reg->tab[j].cfull, tempo);
		memset(tempo,0,sizeof(tempo));
		
		// reg->tab[j].cfull[indice2-1]='\0';
		// strcpy(reg->tab[j].cfull, reg->tab[j].cfull);
		
		printf("resultat : %s\n", reg->tab[j].cfull);
		
		indice1 = 0;
		indice2 = 0;
		compteSpace=0;
	}
	
}


///////////////////////////////////
///////////////////////////////////


void fillRegister(t_contact* tableau,t_reg* monregistre){
	
	monregistre->tab = (t_contact*)malloc(sizeof(t_contact)*monregistre->contactNb);
	
	for(int i=0;i<monregistre->contactNb;++i){
		printf("%d\n", i);
		monregistre->tab[i].cpn = tableau[i].cpn;
		monregistre->tab[i].cin = tableau[i].cin;
		monregistre->tab[i].cout = tableau[i].cout;
		monregistre->tab[i].allcalls = tableau[i].allcalls;
		strcpy(monregistre->tab[i].cfull, tableau[i].cfull);
	}
	//on transfere les données dans le tableau du registre

	
}
