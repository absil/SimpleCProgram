#include "Record.h"

typedef struct Log_struct *Log;

typedef struct Log_struct {
	//the head of the list
	Record head;
} Log_struct;

void init_log(Log self);
void add_record(Log self, Record newRec);
	
void free_log(Log self);

void print_list(Log self);
