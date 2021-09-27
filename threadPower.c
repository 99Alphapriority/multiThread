// program to pass argument to the function being used in thread

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* power2(void* a) {
    int c =*(int*)a;
    printf("a^2 = %d\n",c*c);
    sleep(3);
    printf("Thread 1 completed\n");
}

void* power3(void* a) {
    int c =*(int*)a;
    printf("a^3= %d\n", c*c*c);
    sleep(3);
    printf("thread 2 completed\n");
}

void main(){
    pthread_t t1, t2;
    int a;
    printf("Enter a number: \t");
    scanf("%d", &a);
    pthread_create(&t1, NULL, &power2, &a);
    pthread_create(&t2, NULL, &power3, &a);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}