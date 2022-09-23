#include<stdio.h>

#define maximum 1000

int main(void){
    int i,j;

    int numProcess, numResource;

    printf("Enter the number of processes and number of resources: ");
    scanf("%d %d", &numProcess, &numResource);

    int allocation[numProcess][numResource], max[numProcess][numResource], available[numResource];

    printf("Enter the allocated matrix: ");
    for(i=0;i<numProcess;i++){
        for(j=0; j<numResource; j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum need matrix: ");
    for(i=0;i<numProcess;i++){
        for(j=0; j<numResource; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available matrix: ");
    for(j=0; j<numResource; j++){
        scanf("%d", &available[j]);
    }
    

    int seq[numProcess], index[numProcess], need[numProcess][numResource], flag=0;
    int k=0, p=0, m=0,x=0;

    for(i=0;i<numProcess;i++){
        index[i]=0;
    }


    while(m<numProcess){
        for(i=0;i<numProcess;i++){
            if(index[i]==1)continue;
            for(j=0;j<numResource;j++){
                flag=0;
                need[i][j]= max[i][j]-allocation[i][j];
                if(need[i][j]>available[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(k=0;k<numResource;k++){
                    available[k]+=allocation[i][k];
                }
                seq[p++]=i;
                index[i]=1;
            }
            printf("no %d index= %d\t",i, index[i]);
        }
        printf("\n");
        m++;
    }

    for(i=0;i<numProcess;i++){
        printf("index= %d \n", i);
        if(index[i]==0){
            printf("Not Safe");
            return 0;
        }
    }

    printf("The safe sequence is:\n");
    for(i=0;i<numProcess;i++){
        printf("%d ", seq[i]);
        if(i<numProcess-1)printf("-> ");
    }
}

/*
Input:
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

5 3 2
*/  

/*
input:
5 3

0 1 0 2 0 0 3 0 2 2 1 1 0 0 2

7 5 3 3 2 2 9 0 2 2 2 2 4 3 3

3 3 2
*/

