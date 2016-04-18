#ifndef XV6_PTHREAD
#define XV6_PTHREAD

// Define all functions and types for pthreads here.
// This can be included in both kernel and user code.

typedef struct
{
	int pid;
	void *stack;
} pthread_t;

typedef struct
{
	void *attr;
} pthread_attr_t;

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *),void *arg);
int pthread_join(pthread_t thread, void **retval);
int pthread_exit(void *retval);

#endif
