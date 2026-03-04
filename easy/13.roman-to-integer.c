#include <stdio.h>

int getInt(char c){
    int size = 7;
    char symbol[] = "IVXLCDM";
    int value[] = {1,5,10,50,100,500,1000};

    for (int i = 0; i < size; i++){
        if (c == symbol[i]){
            return value[i];
        }
    }

    return 0;
}

int romanToInt(char* s){
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++){
        if (s[i+1] == '\0'){
            total += getInt(s[i]);
            return total;
        }
        
        int current = getInt(s[i]);
        int next = getInt(s[i+1]);

        if (next > current){
            total -= getInt(s[i]);
        }

        else{
            total += getInt(s[i]);
        }
    }

    return total;
}

int main(){
    char* c;

    printf("Enter a roman numeral: ");
    scanf("%s", c);
    printf("Your char is %d\n", romanToInt(c));
    return 0;
}
