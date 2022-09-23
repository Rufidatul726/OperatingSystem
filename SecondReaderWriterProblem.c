//secondReaderWriterProblem

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define nthread 100

sem_t semread;
sem_t semwrite;
int read=0;
//static const int nreadthread=20, nwritethread=5;
pthread_t reader[nthread], writer[nthread];

void *readerpart(void *);
void *writerpart(void *);

int main(){
    sem_init(&semread, 0 , 1);
    sem_init(&semwrite, 0, 1);
    int i=0, r;
    char *random;

    while(i<nthread){
        r=i%2+1;
        random[0]=r+'0';
        random[1]='\0';
        pthread_create(&reader[i], NULL, readerpart, random);
        pthread_create(&writer[i], NULL, writerpart, random);
        i++;
    }

    i=0;
     while(i<nthread){
        pthread_join(reader[i], NULL);
        i++;
    }

    i=0;
     while(i<nthread){
        pthread_join(writer[i], NULL);
        i++;
    }

    sem_destroy(&semread);
    sem_destroy(&semwrite);

}

void *readerpart(void *p){
    sem_wait(&semread);
    read++;
    if(read==1)sem_wait(&semwrite);

    sem_post(&semread);
    printf("Reader %s is Reading\n",p);
    sem_wait(&semread);
    read--;

    if(read==0)sem_post(&semwrite);
    sem_post(&semread);
}


void *writerpart(void *p){
    sem_wait(&semwrite);
    printf("Writer %s is writing\n ",p);
    sem_post(&semwrite);
}