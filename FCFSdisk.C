#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("How many processes\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*n);
    printf("position per process");
    for(int i=0;i<n;i++){
        printf("\nProcess %d:\t",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nInitial Head position\n");
    int head;
    scanf("%d",&head);
    printf("\nTravel time per cylinder in ms(default 5ms)\n");
    int tpc;
    scanf("%d",&tpc);
    int rpm;
    printf("RPM of disk(default 7200)");
    scanf("%d",&rpm);
    float latency=60000.0/rpm;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(arr[i]-head);
        head=arr[i];
    }
    printf("Total movement: %d",sum);
    printf("Total seek time: %d",sum*tpc);
    printf("Total seektime with latency:%f",sum*tpc+n*latency);
}