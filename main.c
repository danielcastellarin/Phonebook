#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

data_t * init_data() {
    data_t * dp = NULL;
    dp = (data_t *) malloc(sizeof(data_t));
    dp->list = (record_t *) malloc(sizeof(record_t) * INIT_CAP);
    dp->count = 0;
    dp->capacity = INIT_CAP;
    return dp;
}

void free_data(data_t * dp) {
    free(dp->list);
    dp->list = NULL;
    free(dp);
    dp = NULL;
}

record_t create_record(char * name, char * number, int room) {
    record_t rec;
    if(!strncpy_s(rec.name, 21, name, 21)){
        //TODO: check if room is valid?
        if(!strncpy_s(rec.number, 11, number, 11)) {
            rec.room = room;
            return rec;
        }
    }
    //TODO: check errno? need to set it to something if either name or number is invalid
    //TODO: handle return here
}

void add_record(data_t * dp, record_t rec) {
    if(dp->count == dp->capacity) {
        record_t * tmp = (record_t *) realloc(dp->list, sizeof(record_t) * dp->capacity * 2);
        if(tmp) {
            dp->list = tmp;
            dp->capacity *= 2;
        }
    }
    dp->list[dp->count++] = rec;
}

void print_record(const record_t rec) { //TODO: make print fancy for number
    printf("Name: %s\nNumber: %s\nRoom: %d\n", rec.name, rec.number, rec.room);
}

void print_all_records(const data_t * dp) {
    for(int i = 0; i < dp->count; i++) {
        print_record(dp->list[i]);
        printf("-------------------------------\n");
    }
}

int main() {
    data_t * book = init_data();

    add_record(book, create_record("Ronald", "7815458989", 822));
    //print_record(book->list[0]);
    add_record(book, create_record("Chuck", "8005557832", 167));
    add_record(book, create_record("Betty", "6178091264", 532));
    add_record(book, create_record("Sam", "9702403365", 142));
    print_all_records(book);

    free_data(book);

    return 0;
}
