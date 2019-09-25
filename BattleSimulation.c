#include "BattleSimulation.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

int
init_battle_simulator(BattleSimulator self, int id, int maxRounds){
	self->id = id;
	self->maxRounds = maxRounds;
	self->currRound = 1;
	self->s1 = (Spaceship) malloc(sizeof(Spaceship_struct));	//allocate memory for spaceship1
	self->s2 = (Spaceship) malloc(sizeof(Spaceship_struct));	//allocate mem for s2
	//Create USS Enterprise
	init_spaceship(self->s1, "USS Enterprise");
	//Create a Borg Cube
	init_spaceship(self->s2, "A Borg Cube");

	if(self->s1 == NULL || self->s2 == NULL){
		//malloc failed
		printf("malloc failed\n");
		return -1;
	}
	return 0;
}

void 
all_attacks(BattleSimulator self){
	for(int i = 0; i < self->maxRounds; i++){
		//switch around attacking ship
		if(i % 2 == 0){
			attack_spaceship(self->s1, self->s2);
			//printf("S1 is attacking \n");
		}
		else{
			attack_spaceship(self->s2, self->s1);
			//printf("S2 is attacking \n");
		}
		//IF DESTROYED, BREAK
		if(is_destroyed_spaceship(self->s1) == TRUE || is_destroyed_spaceship(self->s2)){
			//printf("ship is destroyed \n");
			//print_spaceship(self->s1);
			//print_spaceship(self->s2);
			break;
		}	
		self->currRound++;	
	}
	//printf("%d \n", self->currRound);
	
}

void
free_battle_simulator(BattleSimulator self){
	free(self->s1);
	free(self->s2);
	free(self);
}

