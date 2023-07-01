#include <stdio.h>
#define MAXN 10

int p[MAXN];      
int dir[MAXN];    

// Print the current permutation
void printPermutation(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

// Swap two elements in the permutation
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Generate all permutations using the Johnson-Trotter algorithm
void generatePermutations(int n) {
    // Printing the initial permutation
    printPermutation(n);

    int mobile, mobileIndex;
    while (1) {
        mobile = 0;
        mobileIndex = -1;

        // Find the largest mobile element and its index
        for (int i = 0; i < n; i++) {
            if ((dir[i] == -1 && i > 0 && p[i] > p[i - 1]) ||
                (dir[i] == 1 && i < n - 1 && p[i] > p[i + 1])) {
                if (p[i] > mobile) {
                    mobile = p[i];
                    mobileIndex = i;
                }
            }
        }

        // If there is no mobile element, we have generated all permutations
        if (mobileIndex == -1) {
            break;
        }

        // Swap the mobile element with the adjacent element in its direction
        if (dir[mobileIndex] == -1) {
            swap(&p[mobileIndex], &p[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
            mobileIndex--;
        }
        else if (dir[mobileIndex] == 1) {
            swap(&p[mobileIndex], &p[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
            mobileIndex++;
        }

        // Reverse the direction of all elements greater than the mobile element
        for (int i = 0; i < n; i++) {
            if (p[i] > mobile) {
                dir[i] = -dir[i];
            }
        }

        // Print the current permutation
        printPermutation(n);
    }
}

int main() {
    int n;

    printf("Enter the value of n (maximum %d): ", MAXN);
    scanf("%d", &n);

    if (n <= 0 || n > MAXN) {
        printf("Invalid value of n!\n");
        return 0;
    }

    // Initialize the permutation and direction arrays
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = -1;
    }

    // Generate all permutations
    generatePermutations(n);

    return 0;
}
