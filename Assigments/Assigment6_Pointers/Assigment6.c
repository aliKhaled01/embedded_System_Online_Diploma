#include <stdio.h>
#include <string.h>
typedef struct
{
  char* name;
  double salary; 
}Dts_empolyeedata;
#define ALPHABETS_COUNT 26
#define FIRST_CHAR 0
void Q1_getAlphabets(char * alph)
{ 

    for(int current_char=FIRST_CHAR;current_char<ALPHABETS_COUNT;current_char++)
    {
        *alph = 'a'+current_char; 
        alph++;
    }

}
void Q2_reverse_string(char*str)
{
    int i=0,j=strlen(str)-1;
    while(i<j)
    {
        char temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
int main()
{
/*Question1 Print All alphanets using pointers*/
char alph[ALPHABETS_COUNT];
Q1_getAlphabets(alph);
for(int i=FIRST_CHAR;i<ALPHABETS_COUNT;i++)
{
    printf("%c\t",alph[i]);
}

/*Question2 reverse string using pointers*/
char str[10]="GOOGLE";
Q2_reverse_string(str);
printf("\n%s",str);

/*Question3 write a program to express pointer to an array of 3 elements each element in the array is a pointer to strucutre */
Dts_empolyeedata emp1 = {"Ahmed",10000};
Dts_empolyeedata emp2 = {"Sayed",15000};
Dts_empolyeedata emp3 = {"Ali",30000};
Dts_empolyeedata* (arr[3]) = {&emp1,&emp2,&emp3};
Dts_empolyeedata*(*ptr)[3] = &arr;
for(int i =0; i<3;i++)
{
    printf("\nName is %s  , Salaray is %f", (*(*ptr+i))->name,(*(*ptr+i))->salary);
}

}
