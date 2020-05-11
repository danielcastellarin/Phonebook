#ifndef PHONEBOOK_MAIN_H
#define PHONEBOOK_MAIN_H

typedef struct record {
    char name[20];
    int number;
    int room;
} record_s;

struct data {
    record_s * list;
    int count;
};

void print_record(record_s rec);

void print_all_record(record_s rec);

record_s search_record(char * name, int number, int room);

record_s add_record(record_s rec);
//record_s add_record(char * name, int number, int room);

record_s edit_record(record_s rec);

record_s delete_record(record_s rec);

#endif