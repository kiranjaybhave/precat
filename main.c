#include"header.h"

int menu() {
    int choice;
    printf("\nEnter Your Choice\n");
    printf("0. Exit\n");
    printf("1. Add New Batch\n");
    printf("2. See All Batches\n");
    printf("3. Set date for New Batch\n");
    printf("4. Final Scheduling\n");
    scanf("%d",&choice);
    return choice;
}
int main() {

    // read_moduleData();
    // printf("\n");
    // printf("==================================\n");
    // read_venue_Data();
    // printf("\n");
    // printf("===================================\n");
    // read_faculty_Data();
    // add_Batch();
    // printf("\n");
    // printf("=====================================\n");
    // read_Batch_data();
    // printf("==========================\n");

    int count;
    int choice;
    printf("Choice Batch\n");
    do
    {
        switch (choice =menu())
        {
            case 0:
                printf("\nExit....\n");
                break;
            case 1:
                printf("\n Add New Batch\n");
                read_Batch_data();
                add_Batch();
                break;
            case 2:
                printf("\n See All Batches\n");
                read_Batch_data();
                print_Batch();
                break;
            case 3:
                printf("\nSchedule A Batch\n");
                new_Batch_Schedule();
                break;
            case 4:
                // printf("\ninside case 4\n");
                finalSchedule();
                break;
            case 5:
                count = get_id();
                printf("count : %d\n",count); 
                break;   
            default:
                printf("Something Wrong\n");
                break;
        }
        
    } while (choice != 0);
    
    
    return 0;
}