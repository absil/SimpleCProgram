#include "BattleSimulation.h"

typedef struct Record_struct *Record;

typedef struct Record_struct {
	//pointer to a battlesim
	BattleSimulator sim;
	//hp of ship a
	int hpA;
	//hp of ship b
	int hpB;
	//attack rounds lasted
	int roundsLasted;
	//outcome
	int outcome;	//the outcome of the battle
	Record nextRecord;	//a pointer to the next record, used to create a linked list
	
} Record_struct;

void
init_record(Record self, BattleSimulator b);

void
free_record(Record self);

void
finish_battle(Record self);

void 
set_next_record(Record self, Record next);

void
set_health_points(Record self);

void print_record(Record self);
