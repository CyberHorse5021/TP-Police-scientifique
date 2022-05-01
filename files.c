#include "header.h"
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
	
	//uncomment for debug
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
	clock_t begin = clock();
    for (i = 0; i < n - 1; i++){
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++){
            if (arr[j].pn > arr[j + 1].pn){
                swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n---------------------\nTri bulle fini.\n\n");
	printf("-->Temps tri : %f secondes\n---------------------\n\n", time_spent); 
}

///////////////////////////////////
///////////////////////////////////

void insertionSort(t_el arr[], int n){
	t_el key;
    int i, j;	
	clock_t begin = clock();
	
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
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n---------------------\nTri insertion fini.\n\n");
	printf("-->Temps tri : %f secondes\n---------------------\n\n", time_spent); 
}

///////////////////////////////////
///////////////////////////////////

