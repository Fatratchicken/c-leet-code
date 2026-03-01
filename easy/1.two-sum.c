#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size){
    for (int i = 0; i < size; i++){
        if (i == 0){
            printf("[%d,", arr[i]);
        }

        else if(i >= size - 1){
            printf("%d]\n", arr[i]);
        }

        else{
            printf("%d,", arr[i]);
        }
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    int *returnArr = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++){
        int x = nums[i];

        for (int j = i + 1; j < numsSize; j++){
            int y = nums[j];

            if (x + y == target){
                returnArr[0] = i;
                returnArr[1] = j;

                return returnArr;
            }
        }
    }

    returnArr[0] = numsSize - 2;
    returnArr[1] = numsSize - 1;

    return returnArr;
}

int main(){
    int nums[] = {2,7,11,15};
    int target = 22;
    int length = 2;

    int *sum = twoSum(nums, 4, target, &length);
    

    printArr(sum, length);
    free(sum);
    
    return 0;
}

