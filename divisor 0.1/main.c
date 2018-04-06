#include <stdlib.h>
#include <stdio.h>
#include "turing.h"
#include "states.h"
#include "const.h"

#define REJECT -1
#define ACCEPT -2

// gcc -g main.c turing.c states.c turing.h states.h const.h -o main

int main(){

	int List[] = {0,1,1,8,2,2,9};
	int longitud=7;
	int state=0;
	int position=0;
	int symbol= List[position];
	int movement =0; // undefined.
	int placeholder;	
	

	while(state!=ACCEPT && state!=REJECT){

		print_lista(List, longitud, position);
		print_variables(state,position,symbol, movement);		
		fscanf(stdin,"\n%d", &placeholder);

		carry_out_step(&symbol,&state,&movement);
		
		if(state!=ACCEPT && state!=REJECT){
			List[position]=symbol;
			position = position +movement;	
			symbol=List[position];
		}
		
	}

	

}
