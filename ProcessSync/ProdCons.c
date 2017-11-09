#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;//1
sem_t full;//0
sem_t empty;//10
int buffer[10];
void * prodFunc(void *arg)
{
    int i,index=0;
    for(i=0;i<20;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[index]=64+i;
        printf("producer added %c to buffer \n",buffer[index]);
        sem_post(&full);
        sem_post(&mutex);
        if(++index == 10) index=0;
        }
        pthread_exit("success");
    }
void * consFunc(void *arg)
{
    int i,index=0;
    for(i=0;i<26;i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("consumer consumed %c \n",buffer[index]);
        sem_post(&empty);
        sem_post(&mutex);
            if(++index == 10) index=0;
            }
        pthread_exit("success");
    }
int main()
{
    pthread_t tid1,tid2;
    void *rt1,*rt2; sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,10);
    pthread_create(&tid1,NULL,prodFunc,NULL);
    pthread_create(&tid2,NULL,consFunc,NULL);
    pthread_join(tid1,&rt1);
    printf("return status of thread function 1 is %s \n",(char * )rt1);
    pthread_join(tid2,&rt2);
    printf("return status of thread function 2 is %s \n",(char * )rt2);
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}