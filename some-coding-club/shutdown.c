#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void delay(unsigned int millis)
{
    clock_t st = clock();
    while (clock() - st < millis * CLOCKS_PER_SEC / 1000)
        ;
}
int main()
{
#if defined _WIN32 || defined __WIN32__
    system("shutdown /f /s /t 5");
#endif
#ifdef linux
    system("sleep 5; poweroff -pf");
#endif
    puts("Ha ha.");
    delay(2500);
    puts("Good-bye.");
    delay(1500);
    puts(";-)");
    for (;;)
        ;
}