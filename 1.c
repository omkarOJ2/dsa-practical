/* Develop a Program in C for the following:
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
7 days of a week. Each Element of the array is a structure having three fields. The first
field is the name of the Day (A dynamically allocated String), The second field is the
date of the Day (A integer), the third field is the description of the activity for a
particular day (A dynamically allocated String).
b) Write functions create(), read() and display(); to create the calendar, to read the data
from the keyboard and to print weeks activity details report on screen. 
  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Days 7

typedef struct 
{
    char *day;
    int date;
    char *activity;
} Activity;

Activity* createCal();
void readCal(Activity *);
void displayCal(Activity *);
void freeCal(Activity*);

int main()
{
    Activity *weekActivity = createCal();
    readCal(weekActivity);
    displayCal(weekActivity);
    freeCal(weekActivity);
    return 0;
}

Activity* createCal()
{   
    Activity *cal = (Activity *)calloc(Days, sizeof(Activity));
    for (int i = 0; i < Days; i++)
    {
        cal[i].day = (char *)calloc(10, sizeof(char));
        cal[i].activity = (char *)calloc(25, sizeof(char));
    }
    return cal;
}

void readCal(Activity* weekActivity)
{ 
    for(int i = 0; i < Days; i++)
    { 
        int x = 0;
        printf("\n Enter for Day-%d\n", i+1);
        
        printf("\nEnter the date: ");
        scanf("%d", &weekActivity[i].date);

        printf("Enter the day name: ");
         scanf(" %9[^\n]", weekActivity[i].day);
        
        printf("\nEnter (1) if there is any activity else (0): ");
        scanf("%d", &x);
        
        
        if (x == 1)
        {
            printf("\nEnter the Activity: ");
            scanf(" %24[^\n]", weekActivity[i].activity);
        }
        printf("\n====================================\n");
    }
}

void displayCal(Activity* Ac)
{
    printf("The Activity list of the week is: \n");
    printf("sl no.\tDate\tDay\t\tActivity\n");

    for(int i = 0; i < Days; i++)
    {
        printf("%d\t%d\t%s\t\t%s\n", i, Ac[i].date, Ac[i].day, Ac[i].activity);
    }
}

void freeCal(Activity* Ac)
{
    for (int i = 0; i < Days; i++)
    {
        free(Ac[i].day);
        free(Ac[i].activity);
    }
    free(Ac);
}
