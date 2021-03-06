#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "const.h"

// Turing print defines functions that take a list, take a position in that list and print the list with a pointer to that position.
// It prints this vertically

int length(int *List){
	int i =0;
	
	while (List[i]<42){ // Por cómo construimos nuestras listas.
		i=i+1;
	}

	/*Anecdóticamente, el siguiente código da error.
	i=0;	
	while (List[i]<=9){ 
		i=i+1;
	}	
	Y lo hace porque al asignar un trozo de memoria, 
	si la lista tiene, p.ej., longitud 6, 
	List[0] hasta Lista[5] son la lista de verdad, 
	pero Lista[6] <9, y la sigue contando.
	*/
	//fprintf(stdout, "\n%d\n",i+1);
	return i;
}

void print_lista(int*L, int length, int position){
	if(L==NULL || length <= position){
		fprintf(stdout, "\nError en prettyprint");
	}

	else{
		int i=0;
		for(i=0; i<length; i++){
			if(i%20==0){
				fprintf(stdout, "\n");		
			}
			if(i==position){
				fprintf(stdout, "{ ");
			}
			else{
				fprintf(stdout, "  ");
			}

			if( L[i]==0){
				fprintf(stdout, ">");

			}

			else if(L[i]==8){
				fprintf(stdout, "X");
			}
			else if(L[i]==10){
				fprintf(stdout, "A");
			}
			else if(L[i]==11){
				fprintf(stdout, "B");
			}
			else if(L[i]==12){
				fprintf(stdout, "_");
			}

			else if(L[i]==9){
				fprintf(stdout, "W");
			}

			else{
				fprintf(stdout, "%d",L[i]);
			}

			if(i==position){
				fprintf(stdout, " } ");
			}
			else{
				fprintf(stdout, "   ");
			}
		}
		fprintf(stdout, "\n\n");		

	}

}

void print_lista2(int*L, int length, int position){
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

void print_variables(int previous_state, int state, int position, int previous_symbol, int symbol,  int movement){
	char tabs[]="\t\t\t\t\t\0";	
	fprintf(stdout,"\n%sPrevious State     = %d  -> Current state   = %d\n",tabs,previous_state, state);
	fprintf(stdout,"\n%sPrevious Symbol    = %d  -> Current Symbol  = %d\n",tabs,previous_symbol, symbol);
	fprintf(stdout,"\n%sPrevious  Position = %d -> Current Position = %d \n",tabs,position-movement,position);
	fprintf(stdout,"\n%sMovement =%d\n\n",tabs,movement);
}

void print_variables2(int state, int position, int symbol,  int movement){
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
