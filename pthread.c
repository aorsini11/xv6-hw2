#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "pthread.h"

// Implement your pthreads library here.

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *),void *arg){
	
	thread->stack = malloc(STACKSIZE);
	thread->func = (void *) start_routine;
	thread->arg = arg;
	
	thread->pid = clone(thread->func,thread->arg,thread->stack);
	
	return thread->pid;
}

int pthread_join(pthread_t thread, void **retval){
	int val = join(thread.pid, (void **) thread.stack, retval);
	free(thread.stack); //free here because thread not accessible in exit method
	return val;
}

int pthread_exit(void *retval){
	texit(retval);
	return 0;
}
