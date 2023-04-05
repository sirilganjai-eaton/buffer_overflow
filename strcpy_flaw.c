#include <stdio.h>
#include <string.h>





/*
Why strcpy is a bad function to use for copying data.
Because, it goes on forever until it sees the null character to copy data. In this process, it can also come across some malicious data
which will then be copied into the destination buffer.
It is always important to know how many bytes of data we are copying.
*/
typedef struct
{
    char primary_string[5];
    char secondary_string[5];
}data;


int main()
{
    data obj;
    /*some compilers and versions could detect this flaw, also termed as stack smashing*/
    printf("C99 stardards version: %ld\n",__STDC_VERSION__ );
    printf("Start of program\n");
    char *a= "12345--garbagestring--couldbe-malware";
    
    obj.secondary_string[0] = 'w';
    obj.secondary_string[1] = 'x';
    obj.secondary_string[2] = 'y';
    obj.secondary_string[3] = 'z';
    obj.secondary_string[4] = '\0';

    printf("secondary_string before strcpy: %s\n",obj.secondary_string);
    strcpy(obj.primary_string,a);
    printf("secondary_string after strcpy: %s\n",obj.secondary_string);
    printf("----------------------------------------------------\n");
    printf("primary_string after copying; %s\n",obj.primary_string);
    //b is the e
    
    //int sizeof_ = sizeof(a);

}