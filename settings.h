//
// Created by suvom on 17-02-2021.
//

#ifndef COURSEPROJECT_SETTINGS_H
#define COURSEPROJECT_SETTINGS_H

// These variables will be initialized from the files
// which maintains the count of keywords and properties

int employee_row    = 0;
int employee_col    = 0;
int shop_row        = 0;
int shop_col        = 0;
int customer_row    = 0;
int customer_col    = 0;


// Memory allocated to the inventory table will be as per following:
// 1. key_count + value initialized for key_size for keywords
// 2. property_count + value initialized for property_size for properties
//    The property count is initialized to 2 as currently the properties
//    cannot be added once the value is set in this version release.
// 3. length of each word in table as set in word_length variable.
// Any modified settings can be done to respective variables
// accordingly.

int key_size        = 20;
int property_size   = 2;
int word_length     = 25;


// Flog file pointer is used to write the log files

FILE *flog;


// Below mentioned are error status/status codes

#define SUCCESS                     1
#define FAILURE                     0
#define FILE_OPEN_ERROR             1001
#define MEMORY_ALLOCATION_ERROR     1002
#define FILE_DELETE_ERROR           1003
#define COUNT_EXCEED_ERROR          1004
#define RESULT_NOT_FOUND            1005
#define FILE_EMPTY_ERROR            1006
#define SIZE                        1000
#define SIZE_P                      30

#endif //COURSEPROJECT_SETTINGS_H