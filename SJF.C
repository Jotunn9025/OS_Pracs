#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Job{
    int id;
    int at;
    int bt;
    int wt;
    int tat;
    int completed;
} Job;
int main(){
    printf("Enter Number of Jobs\n");
    int n;
    scanf("%d",&n);
    Job* arr=(Job*)malloc(sizeof(Job)*n);
    printf("\nEnter ID, Burst Time and Arrival Time of each Process");
    for(int i=0;i<n;i++){
        printf("\nJOB %d:\t",i+1);
        scanf("%d %d %d",&arr[i].id,&arr[i].bt,&arr[i].at);
        arr[i].completed=0;
    }
    int i=0,timer=0;
    float avwaittime=0,avtatime=0;
    printf("\nGANTT CHART:\n");
    while(i<n){
        int min=INT_MAX;
        int mindex=-1;
        for(int j=0;j<n;j++){
            if(arr[j].at<=timer && arr[j].bt<min && arr[j].completed==0){
                min=arr[j].bt;
                mindex=j;
            }
        }
            if(mindex==-1){
                timer++;
                continue;
            }
            timer+=arr[mindex].bt;
            arr[mindex].completed=1;
            arr[mindex].tat=timer-arr[mindex].at;
            arr[mindex].wt=arr[mindex].tat-arr[mindex].bt;
            printf("%d\t|",arr[mindex].id);
            avwaittime+=arr[mindex].wt;
            avtatime+=arr[mindex].tat;
            i++;
    }
    printf("\nAVG WAIT TIME:%0.2f\nAVG TA TIME:%0.2f",avwaittime/n,avtatime/n);
    return 0;
}