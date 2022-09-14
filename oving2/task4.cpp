#include <iostream>

int main()
{
    int a = 5;
    int &b = a; //Feil: Manglet inititsialisering
    int *c;
    c = &b;
    a = b + *c; //Feil: 'a' er en vanlig int, så vi kan ikke bruke '*' operatoren på den
    b = 2; //Feil: Man kan ikke sette adressen til en referanse 

    return 0;
}
