#include <stdio.h>
#include <stdlib.h>

int minStrLen(char** strs, int strsSize){
    int min;

    for (int i = 0; i < strsSize; i++){
        int current = 0;

        for (int j = 0; strs[i][j] != '\0'; j++){
            current++;
        }

        if (i == 0 || current < min){
            min = current;
        }
    }

    return min;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int minStr = minStrLen(strs, strsSize);

    char *prefix = malloc(minStr + 1);
    *prefix = '\0'; 
    int index = 0;

    char current = strs[0][0];

    for (int i = 0; i < minStr; i++){
        for (int j = 0; j < strsSize; j++){
            if (strs[j][i] != current){
                prefix[index] = '\0';

                return prefix;
            }
        }

        current = strs[0][i + 1];
        prefix[index] = strs[0][i];
        index++;
    }

    prefix[index] = '\0';

    return prefix;
}

int main(){
    char* strs[] = {"know", "knot", "knowledge", "known"};
    char* longest = longestCommonPrefix(strs, 3);

    printf("Longet Common Prefix: %s", longest);

    return 0;
}