#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool number(char text[],const int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
         return false;

        if (text[i] >= 'a' && text[i] <= 'z')
         return false; 
    }
    return true;
}
int convertNumber(char number[],const int size)
{
    int num = 0;
    for (int i = 0; i<size ; i++)
    {
        num *= 10;
        num += number[i] - '0'; 
    }
    return num;
}
void encrypt(char text[],const int key,const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int key2 = ((text[i] - 'A') + key) % 26;
            text[i] = 'A' + key2;
        }
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int key2 = ((text[i] - 'a') + key) % 26;
            text[i] = 'a' + key2;
        }
        else continue;
    }
}
int main(int argc, string argv[])
{
    
    if (argc != 2 || !number(argv[1],strlen(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    const int size = strlen(argv[1]);
    int key = convertNumber(argv[1],size);
   
    string plainText = get_string("plaintext : ");
    encrypt(plainText,key,strlen(plainText));
    printf("ciphertext: %s\n",plainText);
    
}
