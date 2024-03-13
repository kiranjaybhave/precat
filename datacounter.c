#include"header.h"

int get_id()
{
    FILE *f1;
    int cnt = 0;
    StartBatch b1;
    f1 = fopen("scheduleBatch.csv", "rb");
    if(f1 == NULL)
    {
        printf("Error- File can't Open \n");
        exit(1);
    }
    
        //printf("Books Read From File : \n");
        while((fread(&b1, sizeof(StartBatch), 1, f1)) != 0 )
        {
            cnt++;
            //printf("----------------------------\n") ;       
        }
    
    fclose (f1);
    if(cnt == 0)
    {
        return 1;
    }
    else
    {
        return (cnt + 1);
    }
}