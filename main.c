// main.c
// The primary functionality of the text-based phonebook interface
//
// author: Dan Castellarin
//
// version control: GitHub repository
// // // // // // // // // // // // // // // // // // // // // // //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    if(strncpy(rec.name, name, NAME_LEN)){
//    if(!strncpy_s(rec.name, NAME_LEN, name, NAME_LEN)){
        //TODO: check if room is valid?
        if(strncpy(rec.number, number, NUMBER_LEN)) {
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

int record_equals(record_t * r1, record_t * r2) {
    return ((strcmp(r1->name, r2->name) == 0 && strcmp(r1->number, r2->number) == 0 && r1->room == r2->room) ? 1 : 0);
    /*if(strcmp(r1->name, r2->name) && strcmp(r1->number, r2->number) && r1->room == r2->room)
        return 1;
    else
        return 0;*/
}

int search_record(data_t * dp, record_t rec) { //checks whole record equality
    for(int i = 0; i < dp->count; i++) {
        if(record_equals(&rec, &dp->list[i]))
            return i;
    }
    return -1;
}

//TODO: either invalidate duplicate names or change search mechanism to accumulate indexes of matches into an array
int search_name(data_t * dp, char * name) { //checks for first instance of name match
    for(int i = 0; i < dp->count; i++) {
        if(strcmp(name, dp->list[i].name) == 0)
            return i;
    }
    return -1;
}

int search_number(data_t * dp, char * number) { //checks for first instance of number match
    for(int i = 0; i < dp->count; i++) {
        if(strcmp(number, dp->list[i].number) == 0)
            return i;
    }
    return -1;
}

int search_room(data_t * dp, int room) { //checks for first instance of room match
    for(int i = 0; i < dp->count; i++) {
        if(room == dp->list[i].room)
            return i;
    }
    return -1;
}

// TODO: probably should expand functionality and move to own file
// TODO: fix return, might be unnecessary
record_t * edit_record(data_t  * dp, record_t old, record_t new) {
    int i = search_record(dp, old);
    if(i > 0) {
//        strcpy_s(dp->list[i].name, NAME_LEN, new.name);
//        strcpy_s(dp->list[i].number, NUMBER_LEN, new.number);
        strncpy(dp->list[i].name, new.name, NAME_LEN);
        strncpy(dp->list[i].number, new.number, NUMBER_LEN);
        dp->list[i].room = new.room;
        return &old;
    } else {
        return NULL;
    }
}

record_t delete_record(data_t * dp, record_t rec) {
    //maybe change return value
    //maybe change to linked list to make deleting easier
    int i = search_record(dp, rec);
    if(i > 0) {
        record_t del = dp->list[i];
        for(; i < dp->count; i++) {
            if(i+1 == dp->count){
//                strcpy_s(dp->list[i].name, 1, "");
//                strcpy_s(dp->list[i].number, 1, "");
                strncpy(dp->list[i].name, "", 1);
                strncpy(dp->list[i].number, "", 1);
                dp->list[i].room = 0;
            } else {
                dp->list[i] = dp->list[i+1];
            }
        }
        dp->count--;
        return del;
    }
    return (record_t){"","",0};
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

void read_input(char * in_type, char * storage, int len, FILE * fp) {
    char c;
    char tmp[len];
    while(1) {
        printf("%s", in_type);
        fgets(tmp, len + 2, fp);
        if(strlen(tmp) > len) { // if given string was too long
            printf("Please ensure that your entry is %d characters or less.\n", len - 1);
            if(strlen(tmp) != len + 1) { // if leftover chars are still in stream
                while ((c = (char) getchar()) != '\n' && c != EOF);
            }
        } else { // given string is valid
            strtok(tmp, "\n");
            strncpy(storage, tmp, len);
            break;
        }
    }
}

void process(data_t * dp) {
    printf("Welcome to your digital phonebook!\nHere is what you can do:\n"
           "1) Add record\n2) Edit record\n3) Delete record\n4) Print records\n"
           "5) Add records through a file\n6) Export records to a file\n"
           "7) Help!\n8) PURGE!!\n9) Quit\n\n");
    char c;
    int in;
    char name_in[NAME_LEN];
    char number_in[NUMBER_LEN];
    char room_in[NUMBER_LEN];
    int room = 0;
    do { // FIXME: warnings below
        printf("Enter the number of the option you wish to execute\n-> ");
        c = getchar();
        in = (int)strtol(&c, NULL, 10);
//        while ((c = getchar()) != '\n' && c != EOF);
        while (getchar() != '\n');
        // FIXME: allow one letter at a time, give option to go back if user enters wrong option
        switch (in) { // FIXME: add in actual functionality as well as helper functions to keep this terse
            case 1:
                printf("Type in the info of the record to add:\n");
                printf("Name: ");
                fgets(name_in, NAME_LEN, stdin);

                printf("Number: ");
                fgets(number_in, NUMBER_LEN, stdin);

                printf("Room: ");
                fgets( room_in, NUMBER_LEN, stdin );
                room = strtol(room_in, NULL, 10);

                add_record(dp, create_record(name_in, number_in, room));
                break;
            case 2:
                printf("type in info of record want to change");
                break;
            case 3:
                printf("type in info of record to delete");
                break;
            case 4:
                print_all_records(dp);
                break;
            case 5:
                printf("type in file to use");
                break;
            case 6:
                printf("type in name of file to export to");
                break;
            case 7:
                printf("help info:");
                break;
            case 8:
                printf("Do you really want to purge the system of all records?");
                break;
            case 9:
                printf("Exiting");
                return;
            default:
                printf("invalid input. please review help section for valid commands");
        }
    } while(c);
}

/// The main function of the phonebook. Initializes the phonebook
/// and initiates the text-based user interface
///
/// \return 0 for success, 1 for failure
int main() {
    data_t * book = init_data();
    /*
    add_record(book, create_record("Ronald", "7815458989", 822));
    add_record(book, create_record("Chuck", "8005557832", 167));
    add_record(book, create_record("Betty", "6178091264", 532));
    add_record(book, create_record("Sam", "9702403365", 142));
    print_all_records(book);

    edit_record(book, create_record("Chuck", "8005557832", 167), create_record("Chris", "3332224444", 555));
    print_all_records(book);*/

    /* Delete testing
    delete_record(book, create_record("Betty", "6178091264", 532));
    print_all_records(book);
    */
    /* Search testing
    int id;
    //id = search_record(book, create_record("Ronald", "7815458989", 822));
    id = search_room(book, 167);
    if(id != -1)
        print_record(book->list[id]);
    else
        printf("Invalid\n");
    */

    //process(book);

    char n[NAME_LEN];
    char nu[NUMBER_LEN];
    char r[NUMBER_LEN];
    read_input("Name: ", n, NAME_LEN, stdin);
    read_input("Number: ", nu, NUMBER_LEN, stdin);
    read_input("Room: ", r, NUMBER_LEN, stdin);
    int ro = (int) strtol(r, NULL, 10);
    add_record(book, create_record(n, nu, ro));
    print_all_records(book);

    getchar();

    free_data(book);

    return 0;
}
