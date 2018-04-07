#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "states.h"
#include "const.h"

#define REJECT -1
#define ACCEPT -2

// gcc -g main.c turing.c states.c turing.h states.h const.h -o main

int main(){

	int List[] = {0,5,1,1,8,2,2,2,2,2,9};
	int longitud=length(List);
	
	fprintf(stdout,"\nEsta función acepta cuando n no divide a m, o cuando n=m");
	
	int state=0;
	int position=0;
	int symbol= List[position];
	int movement =0; // undefined.
	int placeholder;	
	

	while(state!=ACCEPT && state!=REJECT){
		
		print_linea();
		print_variables(state,position,symbol, movement);		
		print_lista(List, longitud, position);

		fscanf(stdin,"\n%d", &placeholder);

		carry_out_step(&symbol,&state,&movement);
		
		List[position]=symbol;
		position = position +movement;	
		symbol=List[position];
		
	}
	
	print_linea();
	print_variables(state,position,symbol, movement);		
	print_lista(List, longitud, position);


}
