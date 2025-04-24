#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Job{
    int id;
    int completed;
    int at;
    int bt;
    int wt;
    int tat;
    int rt;
} Job;
int main(){
    printf("Enter number of Jobs\n");
    int n;
    scanf("%d",&n);
    Job* arr= (Job*)malloc(sizeof(Job)*n);
    printf("\nEnter ID, Burst Time and Arrival Time of each Process");
    for(int i=0;i<n;i++){
        printf("\nJOB %d:\t",i+1);
        scanf("%d %d %d",&arr[i].id,&arr[i].bt,&arr[i].at);
        arr[i].rt=arr[i].bt;
        arr[i].completed=0;
    }
    int i=0,timer=0,gant[100],gindex=0;
    float avwt=0,avtat=0;
    while (i<n)
    {
        int min=INT_MAX;
        int mindex=-1;
        for(int i=0;i<n;i++)
            if(arr[i].completed==0 && arr[i].at<=timer && arr[i].rt<min){
                min=arr[i].rt;
                mindex=i;
            }
        if(mindex==-1){
            timer++;
            continue;
        }
        if(gindex==0||gindex>0 && gant[gindex-1]!=arr[mindex].id){
            gant[gindex++]=arr[mindex].id;
        }
        arr[mindex].rt--;
        timer++;
        if(arr[mindex].rt==0 && arr[mindex].completed==0){
            arr[mindex].completed=1;
            i++;
            arr[mindex].tat=timer-arr[mindex].at;
            arr[mindex].wt=arr[mindex].tat-arr[mindex].bt;
            avwt+=arr[mindex].wt;
            avtat+=arr[mindex].tat;
        }
    }
    printf("\nGANTT CHART:\n");
    for(int i=0;i<gindex;i++)
        printf("%d\t|",gant[i]);
    printf("\nAVG WAIT TIME:%0.2f\nAVG TA TIME:%0.2f",avwt/n,avtat/n);
    return 0;
}