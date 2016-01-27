#include <stdio.h>
#include <string.h>

int overflow();

int main(int argc, char *argv[])
{
    /* initialize failure count
     *
     * failures are when the arrays are too far apart
     * for the overflow function to work
     *
     */
    int fails = 0;

    /*
     * initialize a list to keep track of when the arrays
     * overflow
     */
    int list[100];
    for (int i=0; i < sizeof(list) / 4; i++)
    {
        list[i] = 0;
    }

    /*
     * repeatedly attempt overflowing an array to see
     * where the overflow typically occurs
     */
    int loops = 10000000;
    for (int i=0; i < loops; i++)
    {
        int x = overflow();
        if (x >= 0)
            list[x]++;
        else
            fails++;
    }

    /* 
     * print out the number of failures and how long it
     * took before overflowing occurred
     */
    printf("failures: %d\n", fails);
    for (int i=0; i < sizeof(list) / 4; i++)
    {
        if (list[i] != 0)
            printf("%d: %d\n", i, list[i]);
    }

    return 0;
}

int overflow()
{
    /*
     * returns when the first array overflows into the second
     */
    char* a = strdup("a");
    char* b = strdup("b");

    for (int i=1; i < 1000; i++)
    {
        a[i] = 'x';
        if (b[0] != 'b')
        {
            return i;
        }
    }
    return -1;
}