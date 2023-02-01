#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    //char c = 'a';
    char s[3] = "abc"; //01100001 01100010 01100011
    int *buf;
    int i = 0;
    int k = 0;
    int bit2 = 0;
    size_t len;

    len = ft_strlen(s);
    buf = (int *)malloc(sizeof(int) * ((len * 8) + 1UL)); //free
    if (!buf)
        return 1;
    //    error();

    //文字をバイナリに
    while (i < (8 * len))
    {
        printf("%c", s[k]);
        if ((s[k] >> bit2 & 0x01) == 1) // 0x01 == 1
        {
            buf[i] = '1';
            //SIGUSR1
        }    
        else
        {
            buf[i] = '0';
            //SIGUSR2
        }
        i++;
        bit2++;
        if (i % 8 == 0)
        {
            k++;
            bit2 = 0;
        }
    }
    buf[i] = '\0';
 
    //チェック
    i = 0;
    while (i < (8 * len))
    {
        printf("buf[%i] %c, ", i, buf[i]);
        i++;
    }
    printf("\n");


    //バイナリを文字に
    //2進数（文字列）->2進数(int)->10進数
    //文字列をintに
    //printf("%s\n", buf);
    static int bit;
    i = 0;
    static char j;

    while (i < (8 * len))
    {
        printf("bit:%i j:%i i:%i buf[i]:%c\n", bit, j, i, buf[i]);
        if (buf[i] == '1')
            j |= (0x01 << bit); //j = j | (0x01 << bit)
        bit++;
        if (bit % 8 == 0)
        {
            write(1, &j, 1);
            write(1, "\n", 1);
            j = '\0';
            bit = 0;
        }
        
        i++;
    }
   free(buf);
}
