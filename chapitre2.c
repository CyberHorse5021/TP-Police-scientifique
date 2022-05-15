#include "header.h"

t_reg* registre(t_el tableau[], int size, t_reg* reg){
	
	int nbOfContact=0;
	int returned;
	
	reg = (t_reg*)malloc(sizeof(t_reg));
	reg->tab=NULL;


	t_contact* contactList = NULL;
	contactList = (t_contact*)malloc(sizeof(t_contact));

	clock_t begin = clock();
	for(int i=0;i<size;++i){
		// printf("%d|", i);
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
	clock_t end = clock();
	
	printf("Temps de creation de l'histogramme : %ld millisecondees.\n\n", (end-begin)*1000/CLOCKS_PER_SEC);
	//on met tout dans la structure registre
	reg->contactNb = nbOfContact;
	fillRegister(contactList, reg);

	free(contactList);
    return reg;
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
    return 0;
}


///////////////////////////////////
///////////////////////////////////

void displayRegister(t_reg* registre){
	
	for(int i=0;i<registre->contactNb;++i){
		printf("--------------------------\n\n");
		printf("Name : %s\n", registre->tab[i].cfull);
		printf("Phone number : +33%lli\n", registre->tab[i].cpn);
		printf("All calls : %d\n",registre->tab[i].allcalls);
		printf("Inbound calls : %d\n",registre->tab[i].cin);
		printf("Outbounds calls : %d\n\n",registre->tab[i].cout);
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
	
	printf("Nombre de contactes : %d\n\n", reg->contactNb);
	

	for(int j=0;j<reg->contactNb;++j){
		printf("%d\n", j);
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
		
		strncpy(tempo, &reg->tab[j].cfull[indice1], lengh);
		memset(reg->tab[j].cfull,0,sizeof(reg->tab[j].cfull));
		strcpy(reg->tab[j].cfull, tempo);
		memset(tempo,0,sizeof(tempo));
		
		indice1 = 0;
		indice2 = 0;
		compteSpace=0;
	}
	
}


///////////////////////////////////
///////////////////////////////////


void fillRegister(t_contact* tableau,t_reg* monregistre){
	
	monregistre->tab = (t_contact*)malloc(sizeof(t_contact)*monregistre->contactNb);
	
	
	//on transfere les données dans le tableau du registre
	for(int i=0;i<monregistre->contactNb;++i){
		monregistre->tab[i].cpn = tableau[i].cpn;
		monregistre->tab[i].cin = tableau[i].cin;
		monregistre->tab[i].cout = tableau[i].cout;
		monregistre->tab[i].allcalls = tableau[i].allcalls;
		strcpy(monregistre->tab[i].cfull, tableau[i].cfull);
	}
}

///////////////////////////////////
///////////////////////////////////

void showHarceleur(t_reg* monRegistre){
	
	t_contact tempo;
	
	tempo = monRegistre->tab[0];
	
	for(int i=0;i<monRegistre->contactNb;++i){
		if(monRegistre->tab[i].cin>tempo.cin){
			tempo = monRegistre->tab[i];
		}
	}
	printf("  --> Voici l'harceleur : \n\n");
	
	printf("Name : %s\n", tempo.cfull);
	printf("Phone number : +33%lli\n", tempo.cpn);
	printf("All calls : %d\n",tempo.allcalls);
	printf("Inbound calls : %d\n",tempo.cin);
	printf("Outbounds calls : %d\n",tempo.cout);
}