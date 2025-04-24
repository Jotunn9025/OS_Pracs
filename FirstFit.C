#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter number of memory partitions");
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("\nEnter size of each partition\n");
    for (int i = 0; i < n; i++) {
        printf("Partition %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter Incoming Process Size\n");
    int size;
    scanf("%d", &size);

    for(int i = 0; i < n; i++) {
        if (arr[i] >= size) {
            printf("\nProcess of size %d allocated to partition %d of size %d", size, i + 1, arr[i]);
            arr[i] -= size; 
            break;
        }
    }
    printf("\nRemaining Partitions:\n");
    for (int i = 0; i < n; i++) {
        printf("Partition %d:\t%d\n", i + 1, arr[i]);
    }
    free(arr);
    return 0;
}