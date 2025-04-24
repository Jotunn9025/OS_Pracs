#include<stdio.h>
#include <stdlib.h>
#define size 4
int p[size]={0},c[size]={0};
void togglePhil(int x){
    int r=(x+1)%size;
    if(!p[x] &&(!c[x]&&!c[r])){
        p[x]=1;
        c[x]=1;
        c[r]=1;
    }
    else if(!p[x]){
        printf("\n Chopstick occupied");
    }
    else if(p[x]){
            p[x]=0;
            c[x]=0;
            c[r]=0;
    }
}
int main(){
    int cont=10;
    do{
        for(int i=0;i<size;i++){
            if(p[i]==0)
                printf("\nphilosopher %d is thinkin",i+1);
            else
                printf("\nphilosopher %d is eatin",i+1);
        }
        printf("\n Do you want to toggle a philospher.\nEnter number\n");
        int x;
        scanf("%d",&x);
        togglePhil(x-1);
    }while(cont--);
    return 0;
}