#include "main.h"

int main(void)
{
    int normalPrintf = printf("     \n");
    int customPrintf = _printf("     \n");

    printf("normalPrintf : %d\n", normalPrintf);
    printf("customPrintf : %d\n", customPrintf);

    return (0);
}