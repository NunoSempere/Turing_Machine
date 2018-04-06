#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "const.h"

// Turing print defines functions that take a list, take a position in that list and print the list with a pointer to that position.
// It prints this vertically

void print_lista(int*L, int length, int position){
	if(L==NULL || length <= position){
		fprintf(stdout, "\nError en prettyprint");
	}
	else{
		int i=0;
		char tabs[]="\t\t\t\t\t\t";
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
	fprintf(stdout,"\nState =%d\n",state);
	fprintf(stdout,"\nPosition =%d\n",position);
	fprintf(stdout,"\nSymbol =%d\n",symbol);
	fprintf(stdout,"\nMovement =%d\n\n",movement);
}

