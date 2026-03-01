#include <stdio.h>
#include <stdbool.h>

long power(int base, int exponent){
    long result = 1;

    for (int i = 0; i < exponent; i++){
        result *= base;    
    }

    return result;
}

int integerLength(int x){
    int result = 0;

    while(x > 0){
        x /= 10;
        result++;
    }

    return result;
}

int reverseInt(int x){
    int result = 0;
    int length = integerLength(x);

    for (int i = length; i > 0; i--){
        result += (power(10, i - 1) * (x % 10));
        x /= 10;
    }

    return result;
}

bool isPalindrome(int x){
    int reverse = reverseInt(x);

    if (reverse == x){
        return true;
    }

    return false;
}

int main(){
    printf("%d", isPalindrome(11211));
    return 0;
}