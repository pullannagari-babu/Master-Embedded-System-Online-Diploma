#include <stdio.h>
// this logic will print the 0 is front
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
/*
//another logic 
#include <stdio.h>

void printBinary(unsigned int num) {
    int started = 0;  // To skip leading zeros
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            started = 1;  // Start printing once we find the first '1'
            putchar('1');
        } else if (started) {
            putchar('0');
        }
    }
    if (!started) {
        putchar('0');  // If num is 0, print "0"
    }
    putchar('\n');
}

int main() {
    unsigned int num = 18;
    printBinary(num);
    return 0;
}

*/
