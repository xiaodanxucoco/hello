//test cond_wait

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//using namespace std;

int x;
int * ptr;
pthread_t child, child2, child3, child4;

void setup() {
}

void teardown() {
}

void * routine1(void * arg) {
    ptr = NULL;
    
}


void * routine2(void * arg) {
    x = 4;
    ptr = &x;
    
}

void * routine3(void * arg) {
    x = 5;
    ptr = &x;
    
}

void * routine4(void * arg) {
    x = 3;
    ptr = &x;
    
}



int main(int argc, char *argv[]) {

    setup();
    x = 0;
    ptr = &x;
    pthread_create(&child, NULL, routine1, NULL);
    pthread_create(&child2, NULL, routine2, NULL);
    pthread_create(&child3, NULL, routine3, NULL);
    pthread_create(&child4, NULL, routine4, NULL);

    pthread_join(child, NULL);
    pthread_join(child2, NULL);
    pthread_join(child3, NULL);
    pthread_join(child4, NULL);

    if(*ptr==1)
        printf("X is %d\n", 1);
    else if(*ptr==2)
        printf("X is %d\n", 2);
    else if(*ptr==3)
        printf("X is %d\n", 3);
    else if(*ptr==4)
        printf("X is %d\n", 4);
    else
        printf("X is %d\n", *ptr);

    teardown();
}

