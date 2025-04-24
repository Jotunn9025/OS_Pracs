#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter number of partitions\n");
    int n;
    scanf("%d",&n);
    int* arr=(int * )malloc(sizeof(int )*n);
    printf("\nEnter size of each partition");
    for(int i=0;i<n;i++){
        printf("\nProcess %d:\t",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nEnter size of incoming Process\n");
    int size;
    scanf("%d",&size);
    int max=0xFFFFFFFF;
    int mindex=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>max && arr[i]>=size){
            max=arr[i];
            mindex=i;
        }
    }
    if(mindex==-1){
        printf("cannot fit");
    }
    else{
        printf("\n%d allocated to partition %d\n",size,mindex+1);
        arr[mindex]-=size;
        for(int i=0;i<n;i++){
            printf("%d\t|",arr[i]);
        }
    }
    return 0;
}