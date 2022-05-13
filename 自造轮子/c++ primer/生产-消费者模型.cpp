
#define N 100

typedef int semaphore;
semaphore mutex=1;
semaphore empty=N;
semaphore full=0;

void producer(){
    while(1){
        int item=produce_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        up(&mutex);
        up(&full);
    }
}


void consumer(){
    while(1){
        down(&full);
        down(&mutex);
        int item=remove_item();
        consume_item(item);
        up(&mutex);
        up(&empty);
    }
}