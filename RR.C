#include <stdio.h>
#include <stdlib.h>
int q[100]={0};
int head=0;
int tail=0;
typedef struct Job{
    int id,rt,bt,at,tat,wt,completed;
}Job;
int checkArrivals(Job* arr,int timer,int n){
    int found=0;
    for(int i=0;i<n;i++){
        if(arr[i].at==timer){
            q[tail++]=i;
            found=1;
        }   
    }
    return found;
}
int main(){
    printf("Enter number of Jobs and Quantum\n");
    int n,quantum,gant[100]={0},gindex=0;
    scanf("%d %d",&n,&quantum);
    Job* arr= (Job*)malloc(sizeof(Job)*n);
    printf("\nEnter ID, Burst Time and Arrival Time of each Process");
    for(int i=0;i<n;i++){
        printf("\nJOB %d:\t",i+1);
        scanf("%d %d %d",&arr[i].id,&arr[i].bt,&arr[i].at);
        arr[i].rt=arr[i].bt;
        arr[i].completed=0;
    }
    int i=0,timer=0;
    float avwt=0,avtat=0;
    checkArrivals(arr,timer,n);
    while(i<n){
        if (tail==head){
            timer++;
            checkArrivals(arr,timer,n);
        }
        else{
            int next=q[head++];
            if(gindex==0||(gindex>0 && gant[gindex-1]!=arr[next].id))
                gant[gindex++]=arr[next].id;
            int execTime=arr[next].rt<quantum?arr[next].rt:quantum;
            for(int j=0;j<execTime;j++){
                timer++;
                checkArrivals(arr,timer,n);
                arr[next].rt--;
            }
            if(arr[next].rt>0){
                q[tail++]=next;
            }
            else{
                arr[next].completed=1;
                arr[next].tat=timer-arr[next].at;
                arr[next].wt=arr[next].tat-arr[next].bt;
                avwt+=arr[next].wt;
                avtat+=arr[next].tat;
                i++;
            }
        }
    }
    for(int i=0;i<gindex;i++){
        printf("%d\t|",gant[i]);
    }
    avwt /= n;
    avtat /= n;
    printf("\nAverage Waiting Time: %.2f", avwt);
    printf("\nAverage Turnaround Time: %.2f\n", avtat);

    return 0;
}