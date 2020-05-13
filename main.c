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

record_t create_record(char * name, int number, int room) {
    record_t rec;
    if(!strncpy_s(rec.name, 21, name, 21)){
        //TODO: check if number and room are valid?
        rec.number = number;
        rec.room = room;
        return rec;
    } else {
        //TODO: check errno? need to set it to something
    }
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

void print_record(record_t rec) {
    printf("Name: %s\nNumber: %d\nRoom: %d\n", rec.name, rec.number, rec.room);
}

int main() {
    printf("Hello, World!\n");

    data_t * book = init_data();

    add_record(book, create_record("Ronald", 7815458989, 400));
    print_record(book->list[0]);

    free_data(book);

    return 0;
}
