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
typedef struct Time{
    int batch_Start_Time;
    int batch_End_Time;
}Time; 
typedef struct Module{
    char module_name[10];
    char Faculaty_name[10];
    int duration;
    Date startDate;
    Date endDate;
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
    char faculaty_name[10];
    int C_prog;
    int CPP;
    int Apti;
    int Os;
    int Ds;
} Faculaty;

typedef struct StartBatch{
    Batch newBatch;
    Venue venue;
    Faculaty faculaty[4];
    Module module[4];
    Date startDate;
    Date endDate;
    Time batchTime;
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
extern Module m[5]; 
extern Faculaty f1[7];
int get_id();

#endif