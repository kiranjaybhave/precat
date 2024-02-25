#include"header.h"
Batch b[10];
StartBatch prev_startBatch[4];
int count=2;
void add_Batch() {
    Batch batch;

    FILE* fp = fopen("batch.csv", "a+");
    if (!fp) 
    {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    printf("enter batch name:: \n");
    scanf("%s",&batch.batch_name);
    for (int i = 0; i < 10; i++)
    {
        if (!(strcmp(b[i].batch_name, batch.batch_name))) {
            printf("%s is already present\n",batch.batch_name);
            printf("Enter Other name for new batch\n");
            return;
        }
    }

        if (batch.batch_name[0] == 'p' || batch.batch_name[0] == 'P') {
            batch.batch_name[0]='P';
            // printf("batch.batch_name[%d] %c :: \n",0,batch.batch_name[0]);
        } 
        if (batch.batch_name[1] == 'm' || batch.batch_name[1] == 'M') {
            batch.batch_name[1]='M';
            // printf("batch.batch_name[%d] %c :: \n",1,batch.batch_name[1]);
        }
        if (batch.batch_name[1] == 'h' || batch.batch_name[1] == 'H') {
            batch.batch_name[1]='H';
            // printf("batch.batch_name[%d] %c :: \n",1,batch.batch_name[1]);
        }
        if (batch.batch_name[0] != 'P') {
            printf("Batch First Latter Must be 'P'\n");
            return;
        }
        if (batch.batch_name[1]!='M' && batch.batch_name[1]!='H') {
            printf("Batch Second Latter Must be 'M' or 'H'\n");
            return;
        }
    printf("enter batch admission Count:: \n");
    scanf("%d",&batch.admission);
    // Saving data in file
	fprintf(fp, "%s, %d\n", batch.batch_name,batch.admission);
	printf("\nNew Batch added to record\n");
	fclose(fp);
}
void read_Batch_data()
{
    FILE* fp = fopen("batch.csv", "r");
    if (!fp) 
    {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[10];
        for (int i = 0; i < 10; i++)
        {
           fgets(buffer,10,fp);
           char *p = strtok(buffer,",");
           if(strstr(p,"PM") || strstr(p,"pm")) {
                strcpy(b[i].batch_name,p);
            }
            if(strstr(p,"PH") || strstr(p,"ph")) {
                strcpy(b[i].batch_name,p);
            }
            p = strtok(NULL,",");
            b[i].admission=atoi(p);
            if(b[i].admission == 0)
                break;
        }
	fclose(fp);
     
 }
void print_Batch() {
    printf("BatchName      |        Capacity\n");
    for(int i=0; i<10; i++) {
        if (b[i].batch_name == NULL || b[i].admission == 0)
        {
            return;
        }
        
        printf("%s    | %d\n",b[i].batch_name,b[i].admission);
    }
 }

int compare(char a[],char b[])  
{  
    int flag=0,i=0;  // integer variables declaration  
    while(a[i]!='\0' &&b[i]!='\0')  // while loop  
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
} 


int isEmptyHall(char hallName[]) {
    
    // for (int i = 0; i < count; i++)
    // {
    //     printf("venue %s  | %s\n",hallName,prev_startBatch[i].venue.lec_hall_name);
    //     char name[15];
    //     strcpy(name,prev_startBatch[i].venue.lec_hall_name); 
    //     printf("strcmp :: %d\n",strcmp(hallName,name)==0);
    //     if (strcmp(hallName,name)==0)
    //     {
    //         return 0;
    //     }
        
    // }
    return 1;
}
void new_Batch_Schedule() {
    read_Batch_data();
    read_venue_Data();
    read_Batch_Schedule();
    count++;
    StartBatch startBatch;
    int isPresent=0;

    char lec_hall_name[10];

    printf("Enter A Batch Name To Schedule Batch\n");
    scanf("%s",&startBatch.newBatch.batch_name);

    if (startBatch.newBatch.batch_name[0] == 'p' || startBatch.newBatch.batch_name[0] == 'P') {
            startBatch.newBatch.batch_name[0]='P';
        } 
        if (startBatch.newBatch.batch_name[1] == 'm' || startBatch.newBatch.batch_name[1] == 'M') {
            startBatch.newBatch.batch_name[1]='M';
        }
        if (startBatch.newBatch.batch_name[1] == 'h' || startBatch.newBatch.batch_name[1] == 'H') {
            startBatch.newBatch.batch_name[1]='H';
        }
        if (startBatch.newBatch.batch_name[0] != 'P') {
            printf("Batch First Latter Must be 'P'\n");
            return;
        }
        if (startBatch.newBatch.batch_name[1]!='M' && startBatch.newBatch.batch_name[1]!='H') {
            printf("Batch Second Latter Must be 'M' or 'H'\n");
            return;
        }
    // printf("%s",startBatch.newBatch.batch_name);
     FILE* fp = fopen("scheduleBatch.csv", "a+");
    if (!fp) {
		printf("Can't open file\n");
		exit(0);
	}
    for (int i = 0; i < 10; i++) {     
      if (!(strcmp(startBatch.newBatch.batch_name, b[i].batch_name))) {
            isPresent=1;
            printf("BatchName      |        Capacity\n");
            printf("%s     |  %d\n",b[i].batch_name,b[i].admission);
            startBatch.newBatch.admission = b[i].admission;
            break;
    }
    }
    int hallCount=0;
    Hall :
    printf("Venue List For Lecture and Capacity\n");
    for (int i = 0; i < 5; i++) {
        if (v1[i].lec_hall_capacity >=startBatch.newBatch.admission) {
            printf("%s   |   %d\n", v1[i].lec_hall_name,v1[i].lec_hall_capacity);
        } 
        
    }
    hallCount++;
    printf("Choose any one\n");
    scanf("%s",lec_hall_name);
    
    for (int i = 0; i < count-1; i++)
    {
        printf("%s   |  %s\n",lec_hall_name, prev_startBatch[i].venue.lec_hall_name);
        int result3 = compare(lec_hall_name,prev_startBatch[i].venue.lec_hall_name);
        printf("result3 :%d\n",result3);
        if(result3 == 0) {
            printf("%s Hall is Busy\n",lec_hall_name);
            if(hallCount<2)
                goto Hall;
            if(hallCount >= 2) {
                printf("All Hall is Busy\n");
                return;
            }    
                
        } else {
            printf("You can conduct lecture in Hall %s\n",lec_hall_name);
            strcpy(startBatch.venue.lec_hall_name,lec_hall_name);
            printf("%s\n",startBatch.venue.lec_hall_name);
        }

        for (int i = 0; i < 5; i++) {
            int result = compare(v1[i].lec_hall_name,startBatch.venue.lec_hall_name);
        if (v1[i].lec_hall_capacity >=startBatch.newBatch.admission && !result) {
            // printf("%s   |   %d\n", v1[i].lec_hall_name,v1[i].lec_hall_capacity);
            startBatch.venue.lec_hall_capacity=v1[i].lec_hall_capacity;
            // printf("%d\n",startBatch.venue.lec_hall_capacity);
        }
     }

    }

    Date :
    printf("Enter Batch Start Date\n");
    scanf("%d%d%d",&startBatch.startDate.dd,&startBatch.startDate.mm,&startBatch.startDate.yy);
    
    printf("Enter Batch End Date\n");
    scanf("%d%d%d",&startBatch.endDate.dd,&startBatch.endDate.mm,&startBatch.endDate.yy);
    
    int result =datecmp(startBatch.startDate,startBatch.endDate);
    if(result == 0 || result >0) {
        printf("Please Enter Correct Date\n");
        goto Date;
    } else {
        printf("Date valid\n");
    }
    
    


    //printf("%d-%d-%d\n",startBatch.startDate.dd,startBatch.startDate.mm,startBatch.startDate.yy);
    // printf("%s %d\n",startBatch.venue.lec_hall_name,startBatch.venue.lec_hall_capacity);
    // printf("%s  %d",startBatch.newBatch.batch_name,startBatch.newBatch.admission);
   
   
    fprintf(fp, "%s,%d,%s,%d,%d,%d,%d,%d,%d,%d\n", 
    startBatch.newBatch.batch_name,startBatch.newBatch.admission,
    startBatch.venue.lec_hall_name,startBatch.venue.lec_hall_capacity,
    startBatch.startDate.dd,startBatch.startDate.mm,startBatch.startDate.yy,
    startBatch.endDate.dd,startBatch.endDate.mm,startBatch.endDate.yy);
	
    printf("\nNew Batch Schedule added to record\n");
    fclose(fp);
    count++;
}

void read_Batch_Schedule() {
    FILE* fp = fopen("scheduleBatch.csv", "r");
    if (!fp) 
    {
		// Error in file opening
		printf("Can't open file\n");
		exit(0);
	}
    char buffer[256];
    
        for (int i = 0; i < count; i++)
        {
          fgets(buffer,256,fp);
          char *p=strtok(buffer,",");
          if (strcpy(prev_startBatch[i].newBatch.batch_name,p)) {
           printf("%s ",prev_startBatch[i].newBatch.batch_name);
            p = strtok(NULL,",");
            prev_startBatch[i].newBatch.admission=atoi(p);
            printf("%d ",prev_startBatch[i].newBatch.admission);
            p = strtok(NULL,",");
            strcpy(prev_startBatch[i].venue.lec_hall_name,p);
            printf("%s ",prev_startBatch[i].venue.lec_hall_name);
            p = strtok(NULL,",");
            prev_startBatch[i].venue.lec_hall_capacity=atoi(p);
            printf("%d ",prev_startBatch[i].venue.lec_hall_capacity);
            p = strtok(NULL,",");
            prev_startBatch[i].startDate.dd=atoi(p);
            printf("%d ",prev_startBatch[i].startDate.dd);
            p = strtok(NULL,",");
            prev_startBatch[i].startDate.mm=atoi(p);
            printf("%d ",prev_startBatch[i].startDate.mm);
            p = strtok(NULL,",");
            prev_startBatch[i].startDate.yy=atoi(p);
            printf("%d ",prev_startBatch[i].startDate.yy);
            p = strtok(NULL,",");
            prev_startBatch[i].endDate.dd=atoi(p);
            printf("%d ",prev_startBatch[i].endDate.dd);
            p = strtok(NULL,",");
            prev_startBatch[i].endDate.mm=atoi(p);
            printf("%d ",prev_startBatch[i].endDate.mm);
            p = strtok(NULL,",");
            prev_startBatch[i].endDate.yy=atoi(p);
            printf("%d",prev_startBatch[i].endDate.yy);
            p = strtok(NULL,",");
            printf("\n");
            }
        }
	fclose(fp);
    print_Batch_Schedule(); 
 }

void print_Batch_Schedule() {
    printf("BatchName      |        \n");
    for(int i=0; i<count; i++) {
        if (prev_startBatch[i].newBatch.batch_name == NULL || prev_startBatch[i].newBatch.admission == 0) {
            return;
        }
        printf("%s | %d | %s | %d | %d | %d | %d | %d | %d | %d\n",
                prev_startBatch[i].newBatch.batch_name,prev_startBatch[i].newBatch.admission,
                prev_startBatch[i].venue.lec_hall_name,prev_startBatch[i].venue.lec_hall_capacity,
                prev_startBatch[i].startDate.dd,prev_startBatch[i].startDate.mm,prev_startBatch[i].startDate.yy,
                prev_startBatch[i].endDate.dd,prev_startBatch[i].endDate.mm,prev_startBatch[i].endDate.yy
                );
    }
 }
   