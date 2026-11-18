#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int isPalindrome(int arr[], int start, int end) {
    if (start >= end) return 1; //fine
    if (arr[start] != arr[end]) return 0; // non è palindromo

    return isPalindrome(arr, start+1, end-1);
}

int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a%b);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

void binary(int n) {
    if (n > 1) binary(n/2);

    printf("%d", n%2);
}

long long unsigned int expn(long long unsigned int base, long long unsigned int exp) {
    if (exp == 0) return 1;

    return base * expn(base, exp-1);
}

int arraySum(int *arr, int size) {
    if (size == 0) return 0;
    return arr[size-1] + arraySum(arr, size-1);
}

void reverseString(char *str, int start, int end) {
    if (start >= end) return;

    char app = str[start];
    str[start] = str[end];
    str[end] = app;

    reverseString(str, start+1, end-1);
}

int fatt(int n) {
    if (n == 1) return 1;
    return n * fatt(n-1);
}

int numeroCifre(int n) {
    if (n < 10) return 1;
    return numeroCifre(n/10)+1;
}

long long int p(long long int prod1, long long int prod2) {
    if (prod1 < prod2) { return p(prod2, prod1); }
    if (prod2 == 1) return prod1;

    return prod1 + p(prod1, prod2-1);
}

int min(int arr[], int size) {
    if (size == 1) return arr[0];

    int minS = min(arr, size-1);
    return (arr[size-1] < minS) ? arr[size-1] : minS;
}

int main() {
    int arr[N] = {-1, 2, -4, 2, 2};
    char string[] = "seiznoF enitataP";
    //printf("%d\n", isPalindrome(arr, 0 , N-1));
    //printf("%d", mcd(324234, 2343));
    //printf("%d\n", fibonacci(5));
    //binary(2);
    //printf("%d\n", expn(2, 30));
    //printf("%d", arraySum(arr, N));
    //reverseString(string, 0, strlen(string)-1);
    //printf("%s\n", string);
    //printf("%d\n", fatt(3));
    //printf("%d\n", numeroCifre(300000000));
    //printf("%d\n", p(3954, 7937));
    printf("%d\n", min(arr, N));

    return 0;
}