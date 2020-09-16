#include <stdio.h>
#include <cs50.h>

void space(int k)
{
    for (int i=0; i<k; i++) 
    printf(" ");
}
void stars(int k)
{
    for (int i=0; i<k; i++) 
    printf("#");
}

void square(int k)
{
    while (k < 1 || k > 8)
        k = get_int("Lütfen 1-8 arasında yüksekliği belirtiniz: ");
    int star = 1;
    for (int i=1; i<=k; i++ , star++)
    {
        space(k-i);
        stars(star);
        printf("  ");
        stars(star);
        printf("\n");
    }
}

int main(void)
{
    int k = get_int("Lütfen 1-8 arasında yüksekliği belirtiniz: ");
    square(k);
}
