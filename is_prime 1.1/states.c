#include <stdlib.h>
#include <stdio.h>
#include "const.h"
#include "states.h"

// States of a Turing Machine that checks whether a number DOESN'T divide another number
// NTS: Check that the first number is smaller? Actually not necessary: see state 2.

/*
Initially, I defined a triplet, which was what the different states, which are functions returned.

typedef struct  {

	int state; // Finite list of states: initial (0), state 1, state 2, state 3, ..., state 7.
	int symbol; // Finite list of symbols: 0,1,2,3,4,5,6,7,8,9
	int movement; // Left = -1, Right =1;

}  ssm;

But I thought that modifying pointers was easier and more elegant.
*/

void state0(int *symbol, int *state, int *movement);
void state1(int *symbol, int *state, int *movement);
void state2(int *symbol, int *state, int *movement);
void state3(int *symbol, int *state, int *movement);
void state4(int *symbol, int *state, int *movement);
void state5(int *symbol, int *state, int *movement);
void state6(int *symbol, int *state, int *movement);
void state7(int *symbol, int *state, int *movement);
void state8(int *symbol, int *state, int *movement);
/*void state9(int *symbol, int *state, int *movement);
void state10(int *symbol, int *state, int *movement);
*/
// This function is the delta of which Kozen speaks of in p.210 &ss in Automata and Computability.
void carry_out_step(int *symbol, int *state, int *movement){  // I could make this a bigger if/else tree, but I don't want to.
// Initially, I thought to use https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work, but this proved unnecessary.
	
	if(*state==0){
		state0(symbol,state, movement);
	}
	else if(*state==1){ 
	// Nótese que los else ifs son necesarios, porque después de state0, *state es =1, pero queremos que se de cuenta en la siguiente vuelta
		state1(symbol,state, movement);
	}
	else if(*state==2){
		state2(symbol,state, movement);
	}
	else if(*state==3){
		state3(symbol,state, movement);
	}
	else if(*state==4){
		state4(symbol,state, movement);
	}
	else if(*state==5){
		state5(symbol,state, movement);
	}
	
	else if(*state==6){
		state6(symbol,state, movement);
	}	

	else if(*state==7){
		state7(symbol,state, movement);
	}

	else if(*state==8){
		state8(symbol,state, movement);
	}
	/*
	else if(*state==9){
		state9(symbol,state, movement);
	}
	else if(*state==10){
		state10(symbol,state, movement);
	}
*/
}

void state0(int *symbol, int *state, int *movement){
	if(*symbol ==0){
		*symbol=0; // This is the left endmarker. It isn't changed. This line could be ommited.
		*movement= 1; // Move to the right (0 would be to the left).
		*state=1; // Change to state 1.
	}

	else{
		*state = REJECT; // This is defined as a constant in const.h 
		// The program ends, because it has unspecified behaviour
		*movement= 0;
	}

}

void state1(int *symbol, int *state, int *movement){
	if(*symbol ==1){
		*symbol=3; // Another symbol.
		*movement= 1; // Move to the right (-1 would be to the left).
		*state=2; // Change to state 2.
	}

	else if(*symbol ==3){  // Note that we need an else because otherwise after it changes a 1 to a 3, symbol=3 and it goes back to state1.
	// Note that we have inadvertently created a function to see whether m is(n't) k modulo n; we would only have to start with n-k 3s at the beginning
		*symbol=3;
		*movement= 1; 
		*state=1; 
	}
	
	else if(*symbol ==8){ // 8 = X
		*symbol=8;
		*movement= 1; 
		*state=4; 
	}
	
	else{
		*symbol=*symbol;
		*movement= 1; 
		*state=1; 
	}
}

void state2(int *symbol, int *state, int *movement){

	if(*symbol ==2){
		*symbol=4; 
		*movement= -1; 
		*state=3; 
	}

	else if(*symbol ==9){
		*symbol=9; 
		*movement= -1; 
		*state=7; 
	}

	else{
		*symbol=*symbol;
		*movement= 1; 
		*state=2; 
	}
}

void state3(int *symbol, int *state, int *movement){

	if(*symbol ==0){
		*symbol=0; 
		*movement= 1; 
		*state=1; 
	}

	else {
		*symbol=*symbol;
		*movement = -1;
		*state= 3;
	}
}

void state4(int *symbol, int *state, int *movement){

	if(*symbol ==2){
		*symbol=4; 
		*movement=-1; 
		*state=5;
	}

	else if(*symbol ==9){
		*symbol=9; 
		*movement=-1;  // Only because it rejects
		*state = 6; 
	}

	else{
		*symbol = *symbol;
		*movement =1;
		*state=4;
	}

}

void state5(int *symbol, int *state, int *movement){
	// Note that after state 4, the TM is in m-territory.
	if(*symbol ==3){
		*symbol=1; 
		*movement=-1; 
		*state=5; 
	}
	
	else if(*symbol ==5){
		*symbol=6; 
		*movement= -1; 
		*state = 5; 
	}

	else if(*symbol ==0){
		*symbol=0; 
		*movement= 1; 
		*state = 1; 
	}

	else{
		*symbol = *symbol;
		*movement =-1;
		*state=5;
	}

}

void state6(int *symbol, int *state, int *movement){
	if(*symbol ==5){
		*symbol=5; 
		*movement=0; // Only because it accepts. And it accepts because the first divisor of m is m.
		*state=ACCEPT; 
		fprintf(stdout, "\nIt accepts because the first time that n fits in m, it reaches the end of m, so n=m. \n");
	}

	else if(*symbol ==6){
		*symbol=6;
		*movement= 0; // When the function ends, I want it to stay in the same place. But ultimately it doesn't matter.
		*state = REJECT; 
		fprintf(stdout, "\nIt rejects because m is bigger than n and n | m.\n");
	}

	else if (*symbol !=6 && *symbol !=5){
		*symbol = *symbol;
		*movement =-1;
		*state=6;
	}

}

void state7(int *symbol, int *state, int *movement){
	if(*symbol ==4){
		*symbol=2; 
		*movement=-1;
		*state=7;
	}

	else if(*symbol ==3){
		*symbol=1;
		*movement= -1;
		*state = 7;
	}
	else if(*symbol ==6){
		*symbol=5;
		*movement= -1;
		*state = 7;
	}
	else if(*symbol ==0){
		*symbol=0;
		*movement= 1;
		*state = 8;
	}
	else{
		*symbol=*symbol;
		*movement= -1;
		*state = 7;
	}

}

void state8(int *symbol, int *state, int *movement){
	if(*symbol ==8){
		*symbol=1; 
		*movement=1;
		*state=8;
	}

	else if(*symbol ==7){
		*symbol=8;
		*movement= -1;
		*state = 3;
	}
	else if(*symbol ==2){
		*symbol=2;
		*movement= 0;
		*state = ACCEPT;
	}
	else{
		*symbol=*symbol;
		*movement= 1;
		*state = 8;
	}

}

/*
void state8(int *symbol, int *state, int *movement){

	if(*symbol ==4){
		*symbol=2; 
		*movement=-1; 
		*state=8; 
	}

	else if(*symbol ==3){
		*symbol=1; 
		*movement= -1; 
		*state = 8; 
	}

	else if(*symbol ==0){
		*symbol=0; 
		*movement= 1; 
		*state = 9; 
	}


	else{
		*symbol = *symbol;
		*movement =-1;
		*state=8;
	}

}

void state9(int *symbol, int *state, int *movement){

	if(*symbol ==8){
		*symbol=1; 
		*movement=1; 
		*state=9; 
	}

	else if(*symbol ==5){
		*symbol=8; 
		*movement= 1; 
		*state = 10; 
	}

	else if(*symbol ==2){
		*symbol=2; 
		*movement= 0;  // Only because it accepts
		*state = ACCEPT; 
	}

	else if(*symbol ==4){
		*symbol=4; 
		*movement= 0;  // Only because it accepts
		*state = ACCEPT; 
	}

	else{
		*symbol = *symbol;
		*movement =1;
		*state=9;
	}

}

void state10(int *symbol, int *state, int *movement){

	if(*symbol ==0){
		*symbol=0; 
		*movement=1; 
		*state=1; 
	}

	else {
		*symbol = *symbol;
		*movement =-1;
		*state=10;
	}

}*/
