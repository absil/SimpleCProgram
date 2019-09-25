#include "Record.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

void
init_record(Record self, BattleSimulator sim){
	self->sim = sim;	
	self->hpA = 0;	//get ship 1's hp
	self->hpB = 0;	//get ship 2's hp
	self->roundsLasted = 0;
}

void 
finish_battle(Record self){
	//set the outcome 0 = ship1 has won, 1 = ship 2 has won, 2 = draw
	if(self->sim->s1->health_points <= 0){
		self->outcome = 1;	
		//printf("Ship 2 Wins \n");	 
	}
	else if(self->sim->s2->health_points <= 0){
		self->outcome = 0;		
		//printf("Ship 1 Wins \n");	 
	}
	else{
		self->outcome = 2;		
		//printf("Draw \n");	 
	}
	
	//get the rounds lasted
	self->roundsLasted = self->sim->currRound;
	
	
	//printf("rounds lasted: %d \n", self->roundsLasted);
}

void
set_health_points(Record self){
	self->hpA = self->sim->s1->health_points;
	self->hpB = self->sim->s2->health_points;
}

void 
set_next_record(Record self, Record next){
	self->nextRecord = next;
}

void
free_record(Record self){
	//free battleSim, which frees ships
	free_battle_simulator(self->sim);
	//free the record being pointed to
	if(self->nextRecord != NULL)
		free_record(self->nextRecord);
	//free record
	free(self);
}

void print_record(Record self){
	printf("ID : %d \n", self->sim->id);
	printf("Rounds lasted: %d \n", self->roundsLasted);
	int outcome = self->outcome;
	if(outcome == 1)
		printf("Ship 2 Wins \n");
	else if(outcome == 0)
		printf("Ship 1 Wins \n");
	else
		printf("Draw \n");
	print_spaceship(self->sim->s1);
	print_spaceship(self->sim->s2);
}
