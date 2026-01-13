#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// int day_of_year(int*date_arr){
// int format=date_arr[0];
// int day=(date_arr[1]*10)+(date_arr[2]);
// int month=(date_arr[3]*10)+(date_arr[4]);

// }

int datevalidater(int *date_arr);
int datearrangment(char *date, int *date_arr);
int values(char *date, int start, int end);

int datearrangment(char *date, int *date_arr)
{
    //  int day = (date_arr[1] * 10) + (date_arr[2]);
    //     int month = (date_arr[3] * 10) + (date_arr[4]);
    //     int year = (date_arr[5] * 1000) + (date_arr[6] * 100) + (date_arr[7] * 10) + (date_arr[8]);
    // for (int size = 0; size < date_size; size++)
    // {

    //     int number =atoi( date[size]);

    //     date_arr[size + 1] = number;
    // }
    date_arr[1] = values(date, 0, 3);
    date_arr[2] = values(date, 4, 5);
    date_arr[3] = values(date, 6, 7);

    return datevalidater(date_arr);
}


int values(char *date, int start, int end)
{
    int length = end - start + 1;

    char number[length+1];
    int index=0;
    for (int i = 0; i < length; i++)
    {

        number[i] = date[i+start];
        index++;

    }
    number[index]='\0';
    return atoi(number);
}




int main()
{
    int arr[] = {1, 1, 6, 0, 1, 2, 0, 2, 6};
    // int z=day_of_year(arr);
int n=4;
    int a[n];
    // printf("%d-->", datearrangment("20061212",a));
    datearrangment("20061312",a);
a[0]=1;
for (int i = 0; i < n; i++)
{
    printf("%d->",a[i]);
}


}


int datevalidater(int *date_arr)
{

    // int day = (date_arr[1] * 10) + (date_arr[2]);
    // int month = (date_arr[3] * 10) + (date_arr[4]);
    // int year = (date_arr[5] * 1000) + (date_arr[6] * 100) + (date_arr[7] * 10) + (date_arr[8]);
    int year = date_arr[1];
    int month = date_arr[2];
    int day = date_arr[3];
    if (month < 0 || month > 12)
    {
        return 0;
    }
    int valid_date_range = 30 + (month + (month / 8)) % 2;

    if ((month == 2))
    {
        int isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap)
        {
            if (day > 29)
            {

                return 0;
            }
        }
        else
        {

            if (day > 28)
            {

                return 0;
            }
        }
    }
    if (day >= 0 && day <= valid_date_range)
    {

        return 1;
    }

    return 0;
}
