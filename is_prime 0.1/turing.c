#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "const.h"

// Turing print defines functions that take a list, take a position in that list and print the list with a pointer to that position.
// It prints this vertically

int length(int *List){
	int i =0;
	while (List[i]<=9){ // Por cómo construimos nuestras listas.
		i=i+1;
	}
	fprintf(stdout, "%d",i);
	return i;
}

void print_lista(int*L, int length, int position){
	if(L==NULL || length <= position){
		fprintf(stdout, "\nError en prettyprint");
	}
	else{
		int i=0;
		char tabs[]="\t\t\t\t\t\t\t\0";	
		for(i=0; i<length; i++){
			if(i==position){
				fprintf(stdout, "\n%s{",tabs);
			}
			else{
				fprintf(stdout, "\n%s",tabs);
			}

			if( L[i]==0){
					fprintf(stdout, "T");

			}

			else if(L[i]==8){
					fprintf(stdout, "X");
			}

			else if(L[i]==9){
					fprintf(stdout, "W");
			}

			else{
					fprintf(stdout, "%d",L[i]);
			}

			if(i==position){
				fprintf(stdout, "}\n");
			}
			else{
				fprintf(stdout, "\n");
			}
		}

	}

}

void print_variables(int state, int position, int symbol,  int movement){
	char tabs[]="\t\t\t\t\t\t\t\0";	
	fprintf(stdout,"\n%sState =%d\n",tabs,state);
	fprintf(stdout,"\n%sPosition =%d\n",tabs,position);
	fprintf(stdout,"\n%sSymbol =%d\n",tabs,symbol);
	fprintf(stdout,"\n%sMovement =%d\n\n",tabs,movement);
}

void print_linea(){
	char tabs[]="\t\t\0";	
	fprintf(stdout,"\n%s__________________________________________________________________________________________\n",tabs);
}
