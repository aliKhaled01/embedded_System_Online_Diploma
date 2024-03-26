#include <stdio.h>
#include <stdlib.h>
int check_prime(int num)
{
    int prime_flag =1;
    for(int i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            prime_flag=0;
            break;
        }
    }
    return prime_flag;
}
int calc_factorial_recursion(int num)
{
    int ret = num;
    if(num>1)
    {
    ret = num *  calc_factorial_recursion(num-1);      
    }
    else
    {
        // do no thing
    }
    return ret;
}
void string_revsere_recursion()
{
char c;
scanf("%c",&c);
if(c!='\n')
{
string_revsere_recursion();
printf("%c",c);
}
}
int calc_power_recursion(int base, int expo)
{
    int ret = 0;
    if(expo ==0)
    {
        ret =1;
    }
    else
    {
    ret =  base * calc_power_recursion(base,expo-1);
    }
    return ret;
        
}
int main(void) {
printf("%d",calc_power_recursion(2,0));
}


