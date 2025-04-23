#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,size=3,empty=size,x=0;
int wait(int s){
    return --s;
}
int signal(int s){
    return ++s;
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    printf("\nProducer makes item %d",++x);
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumers item %d",x--);
    mutex=signal(mutex);
}
int main(){
    printf("\nPlease enter the max number of items.\n");
    int size;
    scanf("%d",&size);
    empty=size;
    printf("\n1.Produce Item.\n2.Consume Item.\n3.Exit.");
    int cond=1;
    while(cond){
        printf("\nEnter choice\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(mutex && full!=size)
                    producer();
                else
                    printf("\nBuffer Full");
                break;
            case 2:
                if(mutex && empty!=size)
                    consumer();
                else
                    printf("\nBuffer Empty");
                break;
            case 3:
            default:
                cond=0;
                break;
        }
    }
    return 0;
}