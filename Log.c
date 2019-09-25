#include "Log.h"
#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <string.h> /*strncpy, strlen*/

void init_log(Log self){
	self->head = NULL;
}

void add_record(Log self, Record newRec){
	newRec->nextRecord = self->head;
	self->head = newRec;
}

void free_log(Log self){
	free_record(self->head);
	free(self);
}

void print_list(Log self){
	Record current = self->head;
	int empty = 0;
	while(empty == 0){
		print_record(current);
		current = current->nextRecord;
		if(current == NULL){
			empty = 1;
		}
	}
	
}
