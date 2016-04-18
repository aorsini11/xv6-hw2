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

int pthread_mutex_destroy(pthread_mutex_t *mutex){
	return mutex_destroy(mutex->mid);
}

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr){
	return mutex_init();
}

int pthread_mutex_lock(pthread_mutex_t *mutex){
	return mutex_lock(mutex->mid);
}

int pthread_mutex_unlock(pthread_mutex_t *mutex){
	return mutex_unlock(mutex->mid);
}

