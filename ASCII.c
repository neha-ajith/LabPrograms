#include <stdio.h>

int main() {  

    char v;

    printf("Enter a string: ");

    scanf("%c", &v);  

    

    // %d displays the integer value of a character

    // %c displays the actual character

    printf("ASCII value of %c = %d", v, v);

    

    return 0;

}

