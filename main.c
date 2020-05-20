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
        //TODO: check if room is valid?
        if(strncpy(rec.number, number, NUMBER_LEN)) {
            rec.room = room;
            return rec;
        }
    }
    //TODO: check errno? need to set it to something if either name or number is invalid
    //TODO: handle return here
}

void set_record(data_t  * dp, int i, record_t new) {
    strncpy(dp->list[i].name, new.name, NAME_LEN);
    strncpy(dp->list[i].number, new.number, NUMBER_LEN);
    dp->list[i].room = new.room;
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
record_t edit_record(data_t  * dp, int i, char * name, char * number, char * room) {
    record_t old = dp->list[i];
    printf("Here is the record you have selected:\n");
    print_record(old);
    printf("Enter the new data for the record:\n");
    read_input("Name: ", name, NAME_LEN, stdin);
    read_input("Number: ", number, NUMBER_LEN, stdin);
    read_input("Room: ", room, NUMBER_LEN, stdin);
    int ro = (int) strtol(room, NULL, 10);
    set_record(dp, i, create_record(name, number, ro));
    return old;
}

//record_t delete_record(data_t * dp, record_t rec) {
//    //maybe change return value
//    //maybe change to linked list to make deleting easier
//    int i = search_record(dp, rec);
//    if(i >= 0) {
//        record_t del = dp->list[i];
//        for(; i < dp->count; i++) {
//            if(i+1 == dp->count){
//                strncpy(dp->list[i].name, "", 1);
//                strncpy(dp->list[i].number, "", 1);
//                dp->list[i].room = 0;
//            } else {
//                dp->list[i] = dp->list[i+1];
//            }
//        }
//        dp->count--;
//        return del;
//    }
//    return (record_t){"","",0};
//}

record_t delete_record(data_t * dp, int i) {
    //maybe change return value
    //maybe change to linked list to make deleting easier
    record_t del = dp->list[i];
    for(; i < dp->count; i++) {
        if(i+1 == dp->count){
            strcpy(dp->list[i].name, "");
            strcpy(dp->list[i].number, "");
            dp->list[i].room = 0;
        } else {
            dp->list[i] = dp->list[i+1];
        }
    }
    dp->count--;
    return del;
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
    char type_in[NUMBER_LEN];       ///< storage for type of input
    char name_in[NAME_LEN];         ///< storage for name
    char number_in[NUMBER_LEN];     ///< storage for number
    char room_in[NUMBER_LEN];       ///< storage for room
    int room = 0;
    int index = 0;
    do { // FIXME: warnings below
        printf("Enter the number of the option you wish to execute\n-> ");
        c = (char) getchar();
        in = (int) strtol(&c, NULL, 10);
//        while ((c = getchar()) != '\n' && c != EOF);
        while (getchar() != '\n');
        // FIXME: allow one letter at a time, give option to go back if user enters wrong option
        switch (in) { // FIXME: add in actual functionality as well as helper functions to keep this terse
            case 1: // Add record
                printf("Type in the info of the record to add:\n");
                read_input("Name: ", name_in, NAME_LEN, stdin);
                read_input("Number: ", number_in, NUMBER_LEN, stdin);
                read_input("Room: ", room_in, NUMBER_LEN, stdin);
                room = (int) strtol(room_in, NULL, 10);

                add_record(dp, create_record(name_in, number_in, room));
                break;
            case 2: // Edit record TODO: break up into methods
                printf("How would you like to identify the record?\n1: Name\n2: Number\n3: Room\n-> ");
                c = (char) getchar();
                in = (int) strtol(&c, NULL, 10);
                while (getchar() != '\n');
                switch (in) {
                    case 1: // TODO: loop if input does not exist, also check if data is empty
                        printf("Enter the name of the record you wish to edit:\n");
                        read_input("Name: ", name_in, NAME_LEN, stdin);
                        if((index = search_name(dp, name_in)) >= 0) {
                            edit_record(dp, index, name_in, number_in, room_in);
                        } else {
                            printf("No record with name \"%s\" exists in this phonebook.\n", name_in);
                        }
                        break;
                    case 2:
                        printf("Enter the number of the record you wish to edit:\n");
                        read_input("Number: ", number_in, NUMBER_LEN, stdin);
                        if((index = search_number(dp, number_in)) >= 0) {
                            edit_record(dp, index, name_in, number_in, room_in);
                        } else {
                            printf("No record with number \"%s\" exists in this phonebook.\n", number_in);
                        }
                        break;
                    case 3:
                        printf("Enter the room of the record you wish to edit:\n");
                        read_input("Room: ", room_in, NUMBER_LEN, stdin);
                        room = (int) strtol(room_in, NULL, 10);
                        if((index = search_room(dp, room)) >= 0) {
                            edit_record(dp, index, name_in, number_in, room_in);
                        } else {
                            printf("No record with room \"%d\" exists in this phonebook.\n", room);
                        }
                        break;
                    default:
                        printf("Invalid input. Please return to the edit menu and enter valid input.");
                }
                break;
            case 3: // Delete record
                printf("How would you like to identify the record?\n1: Name\n2: Number\n3: Room\n-> ");
                c = (char) getchar();
                in = (int) strtol(&c, NULL, 10);
                while (getchar() != '\n');
                switch (in) {
                    case 1: // TODO: loop if input does not exist, also check if data is empty
                        printf("Enter the name of the record you wish to delete:\n");
                        read_input("Name: ", name_in, NAME_LEN, stdin);
                        if((index = search_name(dp, name_in)) >= 0) {
//                            delete_record(dp, dp->list[index]);
                            delete_record(dp, index);
                        } else {
                            printf("No record with name \"%s\" exists in this phonebook.\n", name_in);
                        }
                        break;
                    case 2:
                        printf("Enter the number of the record you wish to delete:\n");
                        read_input("Number: ", number_in, NUMBER_LEN, stdin);
                        if((index = search_number(dp, number_in)) >= 0) {
//                            delete_record(dp, dp->list[index]);
                            delete_record(dp, index);
                        } else {
                            printf("No record with number \"%s\" exists in this phonebook.\n", number_in);
                        }
                        break;
                    case 3:
                        printf("Enter the room of the record you wish to delete:\n");
                        read_input("Room: ", room_in, NUMBER_LEN, stdin);
                        room = (int) strtol(room_in, NULL, 10);
                        if((index = search_room(dp, room)) >= 0) {
//                            delete_record(dp, dp->list[index]);
                            delete_record(dp, index);
                        } else {
                            printf("No record with room \"%d\" exists in this phonebook.\n", room);
                        }
                        break;
                    default:
                        printf("Invalid input. Please return to the delete menu and enter valid input.");
                }
                break;
            case 4: // Print records
                print_all_records(dp);
                break;
            case 5: // Add records through a file
                printf("type in file to use");
                break;
            case 6: // Export records to a file
                printf("type in name of file to export to");
                break;
            case 7: // help information
                printf("help info:");
                break;
            case 8: // The Purge(TM)
                printf("Do you really want to purge the system of all records? (Y/N)\n");
                c = (char) getchar();
                while (getchar() != '\n');
                if(c == 'Y') {
                    printf("Nothing will be the same again.\n");
                    for(int j = dp->count - 1; j >= 0; j--) {
                        delete_record(dp, j);
                    }
                    printf("Purge complete.\n");
                } else {
                    printf("Wise decision.\n");
                }
                break;
            case 9: // Quit
                printf("Exiting");
                return;
            default:
                printf("Invalid input. please review help section for valid commands");
        }
    } while(c);
}

/// The main function of the phonebook. Initializes the phonebook
/// and initiates the text-based user interface
///
/// \return 0 for success, 1 for failure
int main() {
    data_t * book = init_data();

    add_record(book, create_record("Ronald", "7815458989", 822));
    add_record(book, create_record("Chuck", "8005557832", 167));
    add_record(book, create_record("Betty", "6178091264", 532));
    add_record(book, create_record("Sam", "9702403365", 142));
    print_all_records(book);
/*
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

    process(book);

    free_data(book);

    return 0;
}
