#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

volatile int buffer[16]; 
volatile int add;
volatile int remove;
void clearbuffer()
{
    add = 0; remove = 0;
    for ( int i=0; i<16;i++ ) 
    {
        buffer[i] = 0;
    }
}

int next( int current )
{
    return ( current + 1 ) % 16;
}

void addtobuffer( int value )
{
    while( buffer[next(add)] != 0 ){}
    buffer[add] = value;
    add = next(add);
}

int removefrombuffer()
{
    int value;
    while((value = buffer[remove]) == 0) {}
    buffer[remove] = 0;
    remove = next(remove);
    return value;
}
void * producer( void *param )
{
    for( int i=1; i<10000000; i++ )
    {
        addtobuffer(i);
    }
}
void *consumer(void *param)
{
    while (removefrombuffer() != 9999999) {}
}

int main()
{
    clearbuffer();
    pthread_t threads[2];
    pthread_create( &threads[0], 0, producer, 0 ); 
    pthread_create( &threads[1], 0, consumer, 0 ); 
    pthread_join( threads[1], 0 );
    pthread_join( threads[0], 0 );
}