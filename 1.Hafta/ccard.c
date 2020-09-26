#include <stdio.h>
#include <cs50.h>

int digits(long card,int* character){
    int digit = 0;
    while (card > 0){
        if (card > 10 && card < 100) *character = card;
        digit++; card /= 10;
    }
    return digit;
}

bool control(long card){
    int a =0, b=0;
    while (card > 0){
        a += card % 10;
        card /= 10;
        if (card > 0){
            int c = (card % 10)*2;
            b += c/10;
            b += c%10;
            card /= 10;
        }
    }
    int reamining = (a+b)%10;
    if (reamining == 0) return true;
    return false;
}

int main(){

    long card = get_long("Kredi karti numaranizi giriniz : ");
    if (card <= 0) card = get_long("Lütfen geçerli bir kredi karti numarasi giriniz : ");
    int character = 0;
    int digit = digits(card,&character);
    if (digit < 13 || digit > 16 || digit == 14 || !control(card)) printf("INVALID\n");
    else{
        if (character == 34 && digit == 15) printf("AMERICAN EXPRESS\n");
         if (character == 37 && digit == 15) printf("AMEX\n");
        else if ((character / 10 == 4) && (digit == 13 || digit == 16)) printf("VISA\n");
        else if ((character == 51 || character == 52 ||character == 53 ||character ==54 || character ==55) && digit == 16) printf("MASTERCARD\n");
        else printf("INVALID\n");
    }

}
