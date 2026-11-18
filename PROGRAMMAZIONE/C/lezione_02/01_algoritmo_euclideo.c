#include <stdio.h>

int main(void) {
    int a, b, i = 0; //Deve essere a,b > 0

    do {
        printf("Inserire due interi maggiori di 0\nper il quale calcolare il M.C.D. (num1, num2) > ");
        scanf("%d, %d", &a, &b);
    } while (a <= 0 && b <= 0);

    printf("\nIl M.C.D. di %d e %d e': ", a, b);
    
    while (a != b) {  //Fino a quando a e b sono diversi...
        if (a > b) //Se a > b,
            a = a-b;
        else //Altrimenti,
            b = b-a; 
        i++;
    }
    
    printf("%d\n",a);
    printf("\nIl numero di passaggi effettuati per calcolare il M.C.D. è stato di %d.\n", i);

    return 0;
}