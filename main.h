#ifndef PHONEBOOK_MAIN_H
#define PHONEBOOK_MAIN_H

#define INIT_CAP 5
#define NAME_LEN 23
#define NUMBER_LEN 13

//TODO: Might change to map structure for quicker traversal, but probably unnecessary

/// The phone record structure
typedef struct record {
    char name[NAME_LEN];        ///< the person who uses the phone
    char number[NUMBER_LEN];    ///< the phone number
    int room;                   ///< the room where the phone is located
} record_t;

/// The phonebook structure, which utilizes dynamically allocated memory
/// to accommodate any number of phone records
typedef struct data {
    record_t * list;    ///< the list of records
    int count;          ///< the number of records in the list
    int capacity;       ///< the max possible number of records in the list
} data_t;

/// Creates an empty phonebook
///
/// \return a pointer to the newly created structure
data_t * init_data();

/// Releases the resources of the phonebook
///
/// \param dp  the pointer to the phonebook to be released
void free_data(data_t * dp);

/// Prints a single phone record
///
/// \param rec  the record to be printed
void print_record(record_t rec);

//TODO: sort into alphabetical order or room number prior to printing
/// Prints all the records in a phonebook
///
/// \param dp  the pointer to the phonebook to be printed
void print_all_records(const data_t * dp);

//TODO: move search functionality into own c file
//int search_record(data_t * dp, char * name, char * number, int room);
/// Searches for a record in a phonebook
///
/// \param dp   the pointer to the phonebook to be searched
/// \param rec  the record the search is looking for
/// \return the index of the record if it is in the phonebook, -1 otherwise
int search_record(data_t * dp, record_t rec); // return its index in data

/// Searches for any occurrences of a name in a phonebook
///
/// \param dp    the pointer to the phonebook to be searched
/// \param name  the name the search is looking for
/// \return the index of the record if the name is in the phonebook, -1 otherwise
int search_name(data_t * dp, char * name);

/// Searches for any occurrences of a number in a phonebook
///
/// \param dp      the pointer to the phonebook to be searched
/// \param number  the number the search is looking for
/// \return the index of the record if the number is in the phonebook, -1 otherwise
int search_number(data_t * dp, char * number);

/// Searches for any occurrences of a room in a phonebook
///
/// \param dp    the pointer to the phonebook to be searched
/// \param room  the room the search is looking for
/// \return the index of the record if the number is in the phonebook, -1 otherwise
int search_room(data_t * dp, int room);

/// Checks if two records have the same name, number, and room.
/// This is used as a helper function
///
/// \param r1  the first record
/// \param r2  the second record
/// \return 1 if the records are equal, 0 otherwise
int record_equals(record_t * r1, record_t * r2);

// TODO: add more description below

/// Creates a new record structure
///
/// \param name    the name the record will be given
/// \param number  the number the record will be given
/// \param room    the room the record will be given
/// \return the newly created record
record_t create_record(char * name, char * number, int room);

/// Changes the name, number, and room of a record
///
/// \param dp   the pointer to the phonebook holding the record
/// \param i    the index of the record to be modified
/// \param new  the record after modification
//record_t * edit_record(data_t  * dp, record_t old, record_t new);
void set_record(data_t  * dp, int i, record_t new);

/// Appends a record to a phonebook. If the phonebook can't fit the record,
/// it will reallocate to make room.
///
/// \param dp   the pointer to the phonebook to be modified
/// \param rec  the record to be added
void add_record(data_t * dp, record_t rec);
//void add_record(data_t * dp, char * name, char * number, int room);

// TODO: maybe split this up, checking if record is there should be done externally
// TODO: maybe if given record does not exist, add it to phonebook

/// Executes the procedure for editing a record in the phonebook.
/// Utilizes set_record to actually change the contents of the record
///
/// \param dp      the pointer to the phonebook holding the record
/// \param i       the index of the record to be modified
/// \param name    the storage for the new name of the record
/// \param number  the storage for the new number of the record
/// \param room    the storage for the new room of the record
/// \return a copy of the original record
//record_t * edit_record(data_t * dp, record_t old, record_t new);
record_t edit_record(data_t * dp, int i, char * name, char * number, char * room);

// TODO: more detail below. Might need to change once return is finalized

/// Removes a record from the phonebook. The record must already exist
/// for this function to execute
///
/// \param dp  the pointer to the phonebook to be modified
/// \param i   the index of the record to be deleted
/// \return a copy of the record that was deleted
//record_t delete_record(data_t * dp, record_t rec);
record_t delete_record(data_t * dp, int i);

/// Processes an individual input from the user.
/// Will make the user re-enter if the input is too long
///
/// \param in_type  a string to print to prompt the user
/// \param storage  reference to where the input will be stored
/// \param len      the max length of the input
/// \param fp       the file to be read
void read_input(char * in_type, char * storage, int len, FILE * fp);

#endif