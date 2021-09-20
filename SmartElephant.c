#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//먼저 코끼리나이 및 iq를 가지고있는 구조체 정보를 생성
typedef struct elephant{
    int weight;
    int iq;
    int flag;//처음 받은 위치를 저장하기 위해 입력
}Elephant;

void sorting(Elephant *);
void smp(Elephant *);

int main(){

    Elephant *ele = (Elephant *)malloc(sizeof(Elephant)*1000);

    for(int i=0;i<9;i++){
        scanf("%d %d", &ele[i].weight, &ele[i].iq);
        ele[i].flag=i+1;
    }

    sorting(ele);

    for(int i=0;i<9;i++){
        printf("weight: %d iq: %d flag: %d \n",ele[i].weight,ele[i].iq,ele[i].flag);
    } 

    smp(ele);

    return 0;
}

void sorting(Elephant *ele){
    Elephant tmp;
    int i,j;

    for(int i=0;i<8;i++){
        for(int j=0;j<8-i;j++){
            if(ele[j].weight>ele[j+1].weight){
                tmp = ele[j];
                ele[j]=ele[j+1];
                ele[j+1]=tmp;
            }
        }
    }
  
}

void smp(Elephant *ele){
    int count=0;
    int location[9];
    int j=0;
    for(int i=0;i<9;i++){
        if(ele[i].iq>ele[i+1].iq){
            location[count]=ele[i].flag;
            count++;
        }
    }//코끼리 의 갯수이므로 예를들어 3가지 케이스가있다면 3마리가아닌 4마리
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d\n",location[i]);
    }
}