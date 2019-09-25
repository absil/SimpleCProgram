#define TRUE 1
#define FALSE 0

#include "Spaceship.h"

typedef struct BattleSimulator_struct *BattleSimulator;

typedef struct BattleSimulator_struct {
	int id;
	Spaceship s1;
	Spaceship s2;
	int maxRounds;
	int currRound;	
} BattleSimulator_struct;

int
init_battle_simulator(BattleSimulator self, int id, int maxRounds);

void 
all_attacks(BattleSimulator self);

void
free_battle_simulator(BattleSimulator self);
