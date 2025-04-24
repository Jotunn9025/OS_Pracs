#include <stdio.h>
#include <stdlib.h>
typedef struct Job{
    int id;
    int bt;
    int at;
    int wt;
    int tat;
}Job;
void swap(Job*a,Job*b){
    Job temp=*a;*a=*b;*b=temp;
}
int main(){
    printf("Enter Number of jobs\n");
    int n;
    scanf("%d",&n);
    Job * arr=(Job *)malloc(sizeof(Job)*n);
    printf("\nEnter ID, Burst Time and Arrival Time of each Process");
    for(int i=0;i<n;i++){
        printf("\nJOB %d:\t",i+1);
        scanf("%d %d %d",&arr[i].id,&arr[i].bt,&arr[i].at);
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j].at>arr[j+1].at)
                swap(&arr[j],&arr[j+1]);
    int i=0;
    int timer=0;
    float avwaittime=0,avtatime=0;
    printf("\nGANTT CHART:\n");
    while(i<n){
        if(arr[i].at>timer){
            timer++;
            continue;
        }
        timer+=arr[i].bt;
        arr[i].tat=timer-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        avwaittime+=arr[i].wt;
        avtatime+=arr[i].tat;
        printf("%d\t|",arr[i].id);
        i++;
    }
    printf("\nAVWAITTIME:%f\nAVTURNAROUNDTIME:%f",avwaittime/n,avtatime/n);
    return 0;
}