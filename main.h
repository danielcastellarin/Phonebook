#ifndef PHONEBOOK_MAIN_H
#define PHONEBOOK_MAIN_H

#define INIT_CAP 5

typedef struct record {
    char name[21];
    char number[11];
    int room;
} record_t;

typedef struct data {
    record_t * list;
    int count;
    int capacity;
} data_t;

void print_record(record_t rec);

//TODO: sort into alphabetical order or room number prior to printing
void print_all_records(const data_t * dp);

record_t * search_record(char * name, char * number, int room);

record_t create_record(char * name, char * number, int room);

void add_record(data_t * dp, record_t rec);
//void add_record(data_t * dp, char * name, char * number, int room);

record_t edit_record(record_t rec);

record_t delete_record(record_t rec);

#endif