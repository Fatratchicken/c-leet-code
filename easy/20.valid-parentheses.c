#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[strlen(s)];
    int top = 0;


    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[top] = s[i];
            top++;
        }

        else{
            if (top == 0) return false;

            char topStack = stack[top - 1];
            
            if (topStack == '(' && s[i] != ')') return false;
            if (topStack == '[' && s[i] != ']') return false;
            if (topStack == '{' && s[i] != '}') return false;

            top--;
        }
    } 

    if (top != 0){
        return false;
    }

    return true;

} 

int main(){
    char s[] = "()[]{}";

    printf("%s\n", isValid(s) ? "True": "False");

    return 0;
}

// REDO THIS ONE!!!