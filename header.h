#ifndef _HEADER_H
#define _HEADER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
typedef struct Date
{
    int dd;
    int mm;
    int yy;
}Date;

typedef struct Module{
    char module_name[10];
    char Faculaty_name[10];
    int duration;
} Module;

typedef struct Batch{
    char batch_name[10];
    int admission;
} Batch;

typedef struct Venue{
    char name_type[5];
    char lec_hall_name[15];
    char lab_name[15];
    char location_name[15];
    int lab_capacity;
    int lec_hall_capacity;
} Venue;

typedef struct Faculaty{
    char facility_name[10];
    int C_prog;
    int CPP;
    int Apti;
    int Os;
    int Ds;
} Faculaty;

typedef struct StartBatch{
    Batch newBatch;
    Venue venue;
    Faculaty faculaty[3];
    Module module[3];
    Date startDate;
    Date endDate;
} StartBatch;

typedef struct CheckIsEmpty
{
    Venue venueCheck;
    int isFull;
}CheckIsEmpty;


void read_moduleData();
void read_venue_Data();
void print_venue();

void read_faculty_Data();
void print_faculty(void);

void add_Batch();
void read_Batch_data();
void print_Batch();

void new_Batch_Schedule();
int datecmp(Date d1,Date d2);
bool isLeapYear(int year);
bool isValidDate(Date d);

void read_Batch_Schedule();
void print_Batch_Schedule(); 
extern Venue v1[5];


#endif