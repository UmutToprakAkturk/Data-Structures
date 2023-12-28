#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 20

struct priority_queue{
    int data[Q_SIZE+1];
    int cnt;
};
typedef struct priority_queue pqueue;
void init(pqueue*p){
    p->cnt=0;
}
void swap(int *p1, int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
void enqueue(pqueue*p,int x){
    if(p->cnt==Q_SIZE)
        printf("it is full");
    else{
        p->data[++p->cnt]=x;
        int index=p->cnt;
        while(index!=1 && p->data[index]<p->data[index/2]){
            swap(&p->data[index],&p->data[index/2]);
            index=index/2;
        } 
    }    
}

int delete(pqueue*p){
    if(p->cnt==0)
        printf("it is empty");
    else{
        int min=p->data[1];
        p->data[1]=p->data[p->cnt--];
        int index=1;//when we percolate down it is 1

        while(2*index<=p->cnt && (p->data[index]>p->data[2*index]||p->data[index]>p->data[2*index+1]))//eğer olmayan değer var ise
        {
            if(2*index+1<=p->cnt)//2 çocuk
            {
                if(p->data[2*index]<p->data[2*index+1]){
                    swap(&p->data[index],&p->data[2*index]);
                    index=2*index;
                }
                else{
                    swap(&p->data[index],&p->data[2*index+1]);
                    index=2*index+1;
                }
            }
            else{
                    swap(&p->data[index],&p->data[2*index]);
                }
            break;
        }
        p->data[p->cnt+1]=0;//
        return min;
    }
}

void print(pqueue*p){
    int i=1;
    while(i!=p->cnt+1){
        printf("%d",p->data[i]);
        i++;
    }
    printf("\n");
}

int main(){
    pqueue *p=(pqueue*)malloc(sizeof(pqueue));
    init(p);
    int i=0;
    int x=0;
    while(i!=-1){
        scanf("%d\t",&i);
        if(i!=-1)
            enqueue(p,i);
    }

    while(i!=-2){
        
        scanf("%d",&i);
        printf("--------------\n");
        if(i!=-2)
            x=delete(p);
            printf("%d",x);
    }
    


}