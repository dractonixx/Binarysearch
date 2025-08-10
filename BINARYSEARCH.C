#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Bs(int nums[], int n, int look) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int midPos = left + (right - left) / 2;  
        if (nums[midPos] == look) {
            return midPos;
        }
        if (nums[midPos] < look) {
            left = midPos + 1;
        } else {
            right = midPos - 1;
        }
    }
    return -1;
}

void sort(int nums[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - pass - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void fillArray(int nums[], int n) {
    for (int k = 0; k < n; k++) {
        int randomVal = rand() % (n * 5);
        nums[k] = randomVal - (n * 2);
    }
    sort(nums, n);
}

int main() {
    srand(time(NULL));
    int sizesList[] = {10, 100, 1000, 10000, 100000};
    int totalSizes = sizeof(sizesList) / sizeof(sizesList[0]);

    printf("CaseType,ArraySize,Target,ExecutionTime(ms)\n");

    // Best case
    for (int s = 0; s < totalSizes; s++) {
        int n = sizesList[s];
        int *nums = (int *)malloc(n * sizeof(int));

        fillArray(nums, n);
        int targetVal = nums[n / 2];

        clock_t startT = clock();
        Bs(nums, n, targetVal);
        clock_t endT = clock();

        double elapsed = ((double)(endT - startT) / CLOCKS_PER_SEC) * 1000;
        printf("Best,%d,%d,%.6f\n", n, targetVal, elapsed);

        free(nums);
    }

    // Worst case
    for (int s = 0; s < totalSizes; s++) {
        int n = sizesList[s];
        int *nums = (int *)malloc(n * sizeof(int));

        fillArray(nums, n);
        int targetVal = nums[n - 1] + 999;

        clock_t startT = clock();
        Bs(nums, n, targetVal);
        clock_t endT = clock();

        double elapsed = ((double)(endT - startT) / CLOCKS_PER_SEC) * 1000;
        printf("Worst,%d,%d,%.6f\n", n, targetVal, elapsed);

        free(nums);
    }

    // Average case
    for (int s = 0; s < totalSizes; s++) {
        int n = sizesList[s];
        int *nums = (int *)malloc(n * sizeof(int));

        fillArray(nums, n);
        int targetVal = nums[n / 3];

        clock_t startT = clock();
        Bs(nums, n, targetVal);
        clock_t endT = clock();

        double elapsed = ((double)(endT - startT) / CLOCKS_PER_SEC) * 1000;
        printf("Average,%d,%d,%.6f\n", n, targetVal, elapsed);

        free(nums);
    }

    return 0;
}
