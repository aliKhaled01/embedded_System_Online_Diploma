#include <stdio.h>
#include <string.h>
typedef struct 
{
 float marks; 
 int roll;
 char* name;
}Dt_sstudent;
typedef struct 
{
float real;
float imaginary;
}Dt_scomplex;

union job
{
    char name[32];
    float salrary;
    int worker_no;
}u;
struct job1
{
    char name[32];
    float salrary;
    int worker_no;

}s;
void Q1_FillStruct( Dt_sstudent *student);
void Q2_FillStructs(Dt_sstudent * students,int size);
Dt_scomplex Q3_AddComplexUsingStructs(Dt_scomplex* ele1 , Dt_scomplex *ele2);


void Q1_FillStruct(Dt_sstudent * student)
{

student->name="Ali";
student->roll = 50;
student->marks = 50.234545;
printf("student name is %s , student roll is %d , strudent makrs is %.2f\n",student->name , student->roll ,student->marks); 
}

void Q2_FillStructs(Dt_sstudent * students,int size)
{
for(int i=0;i<size;i++)
{
students[i].name="Ali";
students[i].roll=i*5;
students[i].marks=i*5.6;
}
}

Dt_scomplex Q3_AddComplexUsingStructs(Dt_scomplex *ele1 , Dt_scomplex *ele2)
{
Dt_scomplex temp;
temp.real = ele1->real + ele2->real;
temp.imaginary = ele1->imaginary + ele2->imaginary;
return temp;
}
#define PI 3.14
#define AREA(r) PI*((r)*(r))
int main(void)
{
/********Question1- FillStruct ********/
Dt_sstudent student;
Q1_FillStruct(&student);


/********Question2 - FillArrayOfStructs ********/
Dt_sstudent students[10];
Q2_FillStructs(students,10);


/********Question3 - AddComplexUsingStructs ********/
Dt_scomplex complex1 , complex2 , result;
complex1.real=2.3;
complex1.imaginary=4.5;
complex2.real=3.4;
complex2.imaginary=5;
result = Q3_AddComplexUsingStructs(&complex1,&complex2);
printf("result is %.2f+%.2fi\n",result.real,result.imaginary);


/******Question4    -  Find the Output of this program*/
printf("size of union =%d\n",sizeof(u));     //Answer is 32 bytes
printf("size of structure =%d\n",sizeof(s)); //Answer is 40 bytes , no padding as we first allocate 32btyes then the compiler need to allocate another 4 bytes but the current memory address will be aligned with words (will be an address which is multipler of 4 so the compiler will not do any padding as at the current address it can use simply the strword assembly instruction directly by considering this is a 32 bit architecture and the float , int sizes are 4 bytes)

/* Question5 - Find the area of a circle giveb its radius using macros*/
int radius = 5;
printf("area is %.2f\n", AREA(radius));

}