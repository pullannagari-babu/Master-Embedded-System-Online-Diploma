#include <stdio.h>

char *print_binary(int num)
{
    int i=31;
    while(i>=0)
    {
    (num &(1<<i))? printf("1") :  printf("0");
    i--;
    }
}
int main()
{
    int num;
    printf("enter num:");
    scanf("%d",&num);
    print_binary(num);
 return 0;
}
