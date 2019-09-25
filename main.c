/**
* @author Panos Patros
**/

#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

int
main(){
/*
	Spaceship s1, s2;
	s1 = (Spaceship) malloc(sizeof(Spaceship_struct));	//allcates memory for the while spaceship struct
	if(s1 == NULL){
		printf("Malloc failed for s1!\n");
		return 1;
	}

	s2 = (Spaceship) malloc(sizeof(Spaceship_struct));
	if(s2 == NULL){
			printf("Malloc failed for s2!\n");
			return 1;
	}


	//Create USS Enterprise
	init_spaceship(s1, "USS Enterprise");

	//Create a Borg Cube
	init_spaceship(s2, "A Borg Cube");

	//Print info
	print_spaceship(s1);
	print_spaceship(s2);

	/*while(1){
		attack_spaceship(s1, s2);
		if(is_destroyed_spaceship(s1) == TRUE || is_destroyed_spaceship(s2)){
			print_spaceship(s1);
			print_spaceship(s2);
			break;
		}
	}*/

	//Free both
	//free_spaceship(s1);
	//free_spaceship(s2);
/*
	BattleSimulator bs;
	bs = (BattleSimulator) malloc(sizeof(BattleSimulator_struct));	//allcates memory for battle sim struct
	init_battle_simulator(bs, 1, 50);

	BattleSimulator bs1;
	bs1 = (BattleSimulator) malloc(sizeof(BattleSimulator_struct));	//allcates memory for battle sim struct
	init_battle_simulator(bs1, 2, 30);

	BattleSimulator bs2;
	bs2 = (BattleSimulator) malloc(sizeof(BattleSimulator_struct));	//allcates memory for battle sim struct
	init_battle_simulator(bs2, 3, 22);

	Record r;
	r = (Record) malloc(sizeof(Record_struct));
	init_record(r, bs);
	set_health_points(r);
	all_attacks(bs);
	finish_battle(r);

	Record r1;
	r1 = (Record) malloc(sizeof(Record_struct));
	init_record(r1, bs1);
	set_health_points(r1);
	all_attacks(bs1);
	finish_battle(r1);

	Record r2;
	r2 = (Record) malloc(sizeof(Record_struct));
	init_record(r2, bs2);
	set_health_points(r2);
	all_attacks(bs2);
	finish_battle(r2);

	Log l;
	l = (Log) malloc(sizeof(Log_struct));
	init_log(l);
	add_record(l, r);
	add_record(l, r1);
	add_record(l, r2);
	print_list(l);*/

	Log list;
	list = (Log) malloc(sizeof(Log_struct));
	init_log(list);
	int i;
	for(i = 0; i <= 1000; i = i + 1){
		BattleSimulator bs;
		bs = (BattleSimulator) malloc(sizeof(BattleSimulator_struct));	//allcates memory for battle sim struct
		init_battle_simulator(bs, i, 50);
		Record r;
		r = (Record) malloc(sizeof(Record_struct));
		init_record(r, bs);
		set_health_points(r);
		all_attacks(bs);
		finish_battle(r);
		add_record(list, r);	
	}
	print_list(list);
	free_log(list);

	return 0;
}
