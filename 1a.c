#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<strings.h>
#include<limits.h>
#include<pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t forks[5];

void* p1(){
	printf("Philosopher 1 is thinking\n");
	sem_wait(&forks[0]);
	sem_wait(&forks[1]);
  	//critical section
  	printf("Philosopher 1 is eating!\n");
    sleep(10);
    printf("Philosopher 1 has finished eating!\n");
    //signal
    sem_post(&forks[0]);
	sem_post(&forks[1]);
	return NULL; 
}

void* p2(){
	printf("Philosopher 2 is thinking\n");
	sem_wait(&forks[1]);
	sem_wait(&forks[2]);
    //critical section
    printf("Philosopher 2 is eating!\n");
    sleep(10);
    printf("Philosopher 2 has finished eating!\n");    
    //signal
    sem_post(&forks[1]);
	sem_post(&forks[2]);
	return NULL; 
}

void* p3(){
	printf("Philosopher 3 is thinking\n");
	sem_wait(&forks[2]);
	sem_wait(&forks[3]); 
    //critical section
    printf("Philosopher 3 is eating!\n");
    sleep(10);
    printf("Philosopher 3 has finished eating!\n");     
    //signal
    sem_post(&forks[2]);
	sem_post(&forks[3]);
	return NULL; 
}

void* p4(){
	printf("Philosopher 4 is thinking\n");
	sem_wait(&forks[3]);
	sem_wait(&forks[4]);
    //critical section
    printf("Philosopher 4 is eating!\n");
    sleep(10);
    printf("Philosopher 4 has finished eating!\n");  
    //signal
    sem_post(&forks[3]);
	sem_post(&forks[4]);
	return NULL; 
}

void* p5(){
	printf("Philosopher 5 is thinking\n");
	sem_wait(&forks[4]);
	sem_wait(&forks[0]);
    //critical section
    printf("Philosopher 5 is eating!\n");
    sleep(10);
    printf("Philosopher 5 has finished eating!\n");   
    //signal
    sem_post(&forks[4]);
	sem_post(&forks[0]);
	return NULL; 
}

int main(){
	sem_init(&forks[0], 0, 1);
	sem_init(&forks[1], 0, 1);
	sem_init(&forks[2], 0, 1);
	sem_init(&forks[3], 0, 1);
	sem_init(&forks[4], 0, 1);
	pthread_t thread1 , thread2 , thread3 , thread4 , thread5;
	pthread_create(&thread1 , NULL , p1 , NULL); 
	pthread_create(&thread2 , NULL , p2 , NULL); 
	pthread_create(&thread3 , NULL , p3 , NULL); 
	pthread_create(&thread4 , NULL , p4 , NULL); 
	pthread_create(&thread5 , NULL , p5 , NULL); 
	pthread_join(thread1 , NULL);
	pthread_join(thread2 , NULL); 
	pthread_join(thread3 , NULL); 
	pthread_join(thread4 , NULL); 
	pthread_join(thread5 , NULL);
	sem_destroy(&forks[0]); 
	sem_destroy(&forks[1]); 
	sem_destroy(&forks[2]); 
	sem_destroy(&forks[3]);  
	sem_destroy(&forks[4]); 

	return 0;
}