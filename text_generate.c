#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char alpha[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    , 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int count = 0;
    int i;
    while (count < 11000)
    {
        i = rand()%52;
        printf("%c", alpha[i]);
        count++;
    }
    printf("%i\n", count);


return 0;
}