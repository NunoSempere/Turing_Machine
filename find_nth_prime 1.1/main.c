#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "states.h"
#include "const.h"

#define REJECT -1
#define ACCEPT -2

// gcc -g main.c turing.c states.c turing.h states.h const.h -o main

int main(){

	int List[] = {0,10,10,10,10,5,1,8,2,9,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,42};
	// 0 == |- ; leftmost character. This TM is only infinite in one direction.
	// 5: A character to detect whether the first divisor of n is m.
	// 10 ==A: Every time it finds a prime, it changes an A to a B. When it runs out of As, it stops.
	// 11 ==B. Wie gesagt.
	// At every step, it checks whether a number n, represented by a number of 1s followed by an 8.
			// For example: 10= 1111111118;  1x9, and 8x1.
	// divides a number m, represented by a number of 2s followed by a 9.
	// 12: Blanks. Out Turing Machine should have infinite of those to the right.
		// m will be moved to the right, to make room for 7s between n and m.
	// 7s: Between n and m, regulate the maximum size of the divisors of the current number.

	int longitud=length(List);
	
	fprintf(stdout,"\nEsta función acepta cuando ha encontrado el enésimo primo\n");
	
	int state=0;
	int previous_state=0;

	int position=0;

	int symbol= List[position];
	int previous_symbol=List[position];

	int movement =0; // undefined.
	int placeholder;	

	fprintf(stdout,"\nIt starts at State=0, Symbol =0, Position =0, \n");	
	print_lista(List, longitud, position);	
		fprintf(stdout, "\n");
	while(state!=ACCEPT && state!=REJECT){
		fscanf(stdin,"\n%d", &placeholder);
	
		previous_state=	state;
		previous_symbol=symbol;
		
		carry_out_step(&symbol,&state,&movement);
		
		List[position]=symbol;
		position = position +movement;	
		symbol=List[position];
		
		print_linea();
		print_variables(previous_state, state,position,previous_symbol, symbol, movement);
		print_lista(List, longitud, position);
	}

	return 1;
}
