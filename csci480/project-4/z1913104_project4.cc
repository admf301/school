
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>

char shared_string[] = "All work and no play makes Jack a dull boy.";
sem_t rw_sem;										//used by both readers and writers
sem_t cs_sem;										//used for protecting critical section of readers
int read_count = 0;

/********************************************************************
Function:       reader

Use:            Handles functionality and synchronization of the
		reader in the reader-writer problem

Arguments:      1. param: id for printing individual readers

Returns:        nothing
********************************************************************/
void *reader(void *param) {

        int* reader_temp = (int*)param;							//printing id for each reader
	int reader_id = *reader_temp;
        while(1) {

		if(shared_string[0] == '\0') {						//checking when the string is empty
			printf("reader %d is exiting ...\n", reader_id);
			fflush(stdout);
			break;
		}

		sem_wait(&cs_sem);							//enter the critical section

		if(shared_string[0] == '\0') {
			printf("reader %d is exiting ...\n", reader_id);
			fflush(stdout);
			sem_post(&cs_sem);						//exit critical section early
			break;
		}

		read_count++;
		printf("read_count increments to: %d.\n", read_count);
		fflush(stdout);

                if(read_count == 1) {
                        sem_wait(&rw_sem);						//wait read_count > 0
       		}

		if(shared_string[0] == '\0') {
			read_count--;
			printf("read_count decrements to: %d.\n", read_count);
			printf("reader %d is exiting ...\n", reader_id);
			fflush(stdout);
			sem_post(&rw_sem);						//signal since read_count = 0
			sem_post(&cs_sem);						//exit critical section early
			break;
		}

		sem_post(&cs_sem);							//exit the critical section

                printf("reader %d is reading ... content: %s\n", reader_id, shared_string);
		fflush(stdout);								//reading is performed

                sem_wait(&cs_sem);							//enter critical section

                read_count--;
                printf("read_count decrements to: %d.\n", read_count);
		fflush(stdout);

                if(read_count == 0) {
                        sem_post(&rw_sem);						//signal read_count = 0
                }

                sem_post(&cs_sem);							//exit critical section
                sleep(1);
        }
        pthread_exit(0);
}

/********************************************************************
Function:       writer

Use:            Handles functionality and synchronization of the
                writer in the reader-writer problem

Arguments:      1. param: id for printing individual writers

Returns:        nothing
********************************************************************/
void *writer(void *param) {

        int* writer_temp = (int*)param;							//printing id for each writer
	int writer_id = *writer_temp;
        while(1) {

                sem_wait(&rw_sem);                                                      //wait read/write sem

                if(shared_string[0] == '\0') {
                        printf("writer %d is exiting ...\n", writer_id);
                        fflush(stdout);
                        sem_post(&rw_sem);
                        break;
                }

                printf("writer %d is writing ...\n", writer_id);                        //writing is performed
                fflush(stdout);
                shared_string[strlen(shared_string) - 1] = '\0';                        //writing (deleting) 1 char from the string

                sem_post(&rw_sem);                                                      //signal read/write sem
                sleep(1);
        }
        pthread_exit(0);
}

int main(int argc, char *argv[]) {

        if(argc != 3) {									//error checking
                printf("Usage: [number of readers] [number of writers]\n"); 		//verifying number of arguments
                return 1;
        }

        int num_readers = atoi(argv[1]);						//get command line arguments
        int num_writers = atoi(argv[2]);

        if(num_readers <= 0 || num_writers <= 0) {					//error checking
                printf("Error: Both numbers must be positive integers.\n");		//verifying positive input
                return 1;
        }

        printf("*** Reader-Writer Problem Simulation ***\n");
        printf("Number of reader threads: %d\n", num_readers);
        printf("Number of writer threads: %d\n", num_writers);

        sem_init(&rw_sem, 0, 1);							//initialization of semaphores
        sem_init(&cs_sem, 0, 1);

        pthread_t reader_threads[num_readers];						//creating the specified amount of reader threads
	int reader_ids[num_readers];							//and giving them an identifier
        for(int i = 0; i < num_readers; i++) {
		reader_ids[i] = i;
                pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
        }

        pthread_t writer_threads[num_writers];						//creating the specified amount of writer threads
        int writer_ids[num_writers];							//and giving them an identifier
	for(int i = 0; i < num_writers; i++) {
		writer_ids[i] = i;
                pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
        }

	int reader_status[num_readers];							//array for checking reader threads return values
        for(int i = 0; i < num_readers; i++) {						//waiting for all reader threads to finish
                pthread_join(reader_threads[i], (void**)&reader_status[i]);

		if(reader_status[i] != 0) {						//error checking return value of each reader thread
			printf("Error: reader thread: %d\n", i);			//to ensure operation was successful
			return 1;
		}
        }

	int writer_status[num_writers];							//array for checking writer threads return values
        for(int i = 0; i < num_writers; i++) {						//waiting for all writer threads to finish
                pthread_join(writer_threads[i], (void**)&writer_status[i]);

		if(writer_status[i] != 0) {						//error checking return value of each writer thread
			printf("Error: writer thread: %d\n", i);			//to ensure operation was successful
			return 1;
		}
        }

        printf("All threads are done.\n");
        sem_destroy(&rw_sem);								//cleaning up resources
        sem_destroy(&cs_sem);
        printf("Resources cleaned up.\n");
        return 0;
}
