#ifndef PHONEBOOK_MAIN_H
#define PHONEBOOK_MAIN_H

#define INIT_CAP 5

//TODO: Might change to map structure for quicker traversal, but probably unnecessary
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

//TODO: move search functionality into own c file
//int search_record(data_t * dp, char * name, char * number, int room);
int search_record(data_t * dp, record_t rec); // return its index in data

int name_cmp(record_t * r1, record_t * r2);

record_t create_record(char * name, char * number, int room);

void add_record(data_t * dp, record_t rec);
//void add_record(data_t * dp, char * name, char * number, int room);

record_t edit_record(record_t rec);

record_t delete_record(data_t * dp, record_t rec);

#endif