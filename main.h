#ifndef PHONEBOOK_MAIN_H
#define PHONEBOOK_MAIN_H

#define INIT_CAP 5

typedef struct record { //TODO: fix number storage, change to long
    char name[21];
    int number;
    int room;
} record_t;

typedef struct data {
    record_t * list;
    int count;
    int capacity;
} data_t;

void print_record(record_t rec);

void print_all_records(record_t rec);

record_t * search_record(char * name, int number, int room);

record_t create_record(char * name, int number, int room);

void add_record(data_t * dp, record_t rec);
//void add_record(data_t * dp, char * name, int number, int room);

record_t edit_record(record_t rec);

record_t delete_record(record_t rec);

#endif