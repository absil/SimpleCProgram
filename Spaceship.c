/**
* @author Panos Patros
**/

#include "Spaceship.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

int
init_spaceship(Spaceship self, char *name){
	int name_length = strlen(name);	//gets the length of the name
	self->name = malloc(name_length + 1);
	if(self->name == NULL){
		/*Malloc failed*/
		return -1;
	}
	strncpy(self->name, name, name_length);	//copies the characters 

	self->health_points = rand()%21 + 80;
	self->attack_points = rand()%11 + 10;	//between 10 and 20
	self->defense_points = rand()%11 + 5; 	//between 5 and 10
	return 0;
}

void
attack_spaceship(Spaceship self, Spaceship underAttack){
	int current_attack_points = calculate_attack_power_spaceship(self);
	int difference_points = current_attack_points - underAttack->defense_points;
	//printf("Difference points, %d \n", difference_points);
	if(difference_points > 0){		
		underAttack->health_points = underAttack->health_points - difference_points;
	}
	//print_spaceship(underAttack);
}

//get the attack points size of the spaceship for the current attack
int
calculate_attack_power_spaceship(Spaceship self){
	int fullPoints = rand()%2;
	if(fullPoints == TRUE){
		//printf("%d (Attack Points)\n", self->attack_points);
		return self->attack_points;
	}else {
		//printf("Half Points\n");
		return (self->attack_points / 2);
	}
}

//returns 1 if true (destroyed), 0 if false
int
is_destroyed_spaceship(Spaceship self){
	if(self->health_points > 0){
		return 0;
	}	
	else{
		return 1;
	}       
}

void
print_spaceship(Spaceship self){
	printf("%s: %d (HP), %d (AP), %d (DP)\n", self->name, self->health_points, self->attack_points, self->defense_points);
}

void
free_spaceship(Spaceship self){
	free(self->name);
	free(self);
}
