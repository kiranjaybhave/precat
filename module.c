// C program for the above approach
#include"header.h"
// Driver Code
Venue v1[5];
Module m[5]; 
Faculaty f1[7];

void read_moduleData()
{
	FILE* fp = fopen("module.csv", "r");
    if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[50];
    while (fgets(buffer,50,fp)!=NULL)
    {
        char *p= NULL;
        p = strtok(buffer,",");

        for (int i = 0; i < 5; i++)
        {
            if(i != 0)
                p=strtok(NULL,",");
            m[i].duration=atoi(p);
            p=strtok(NULL,",");
            strcpy(m[i].module_name,p);
            printf("%s ",m[i].module_name);
            printf("%d\n",m[i].duration);

        }
    }   
		fclose(fp);
}


void read_venue_Data()
{

	FILE* fp = fopen("venu.csv", "r");
    if (!fp) 
    {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[29];
        for (int i = 0; i < 5; i++)
        {
           fgets(buffer,29,fp);
           char *p = strtok(buffer,",");
           if(strcmp(p,"l") == 0)
           {
                strcpy(v1[i].name_type,p);
                p = strtok(NULL,",");
                strcpy(v1[i].lab_name,p);

                p = strtok(NULL,",");
                v1[i].lab_capacity = atoi(p);

                strcpy(v1[i].lec_hall_name,"NA");
                v1[i].lec_hall_capacity = 0;
           }
           if(strcmp(p,"h") == 0)
           {
                strcpy(v1[i].name_type,p);
                p = strtok(NULL,",");
                strcpy(v1[i].lec_hall_name,p);

                p = strtok(NULL,",");
                v1[i].lec_hall_capacity = atoi(p);

                strcpy(v1[i].lab_name,"NA");
                v1[i].lab_capacity = 0;
           }
            p = strtok(NULL,",");
            strcpy(v1[i].location_name,p);
   
        }
	fclose(fp);
    //  print_venue();
 }

 void print_venue()
 {
    printf("Name         Type   Capacity Location     \n");
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(v1[i].name_type,"l") == 0)
            printf("%s %s %d %s",v1[i].lab_name,v1[i].name_type,v1[i].lab_capacity,v1[i].location_name);
        if(strcmp(v1[i].name_type,"h") == 0)
            printf("%s %s %d %s",v1[i].lec_hall_name,v1[i].name_type,v1[i].lec_hall_capacity,v1[i].location_name);
    }
 }




void read_faculty_Data()
{
    FILE *fp = fopen("factulaty.csv", "r");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        exit(1);
    }
    
    char buffer[256]; // Buffer size increased
    for (int i = 0; i < 7; i++) {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Using strtok to tokenize the buffer
            char *p = strtok(buffer, ",");
            strcpy(f1[i].faculaty_name, p);
            
            // Initializing flags to 0
            f1[i].C_prog = 0;
            f1[i].Ds = 0;
            f1[i].CPP = 0;
            f1[i].Os = 0;
            f1[i].Apti = 0;

            while (p != NULL) {
                // Check each token for course keywords
                if (strstr(p, "c-prog") != NULL) {
                    f1[i].C_prog = 1;
                } else if (strstr(p, "data-stuct") != NULL) {
                    f1[i].Ds = 1;
                } else if (strstr(p, "cpp") != NULL) {
                    f1[i].CPP = 1;
                } else if (strstr(p, "oprs") != NULL) {
                    f1[i].Os = 1;
                } else if (strstr(p, "apti") != NULL) {
                    f1[i].Apti = 1;
                }
                p = strtok(NULL, ",");
            }
        }
    }
    fclose(fp);
    // print_faculty();
}

 void print_faculty(void) {
    printf("Name\t\tC-prog\tDS\tCPP\tOS\tApti\n");
    for (int i = 0; i < 7; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", f1[i].faculaty_name, f1[i].C_prog, f1[i].Ds, f1[i].CPP, f1[i].Os, f1[i].Apti);
    }
}









