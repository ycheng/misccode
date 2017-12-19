#include <stdio.h>
#include <pthread.h>

#ifdef _32BIT_
  #define PR(x) printf(#x ": %u\n", sizeof(x))
#else
  #define PR(x) printf(#x ": %lu\n", sizeof(x))
#endif

int main() {
	PR(pthread_t);
	PR(pthread_attr_t);
	PR(pthread_once_t);
	PR(pthread_mutex_t);
	PR(pthread_rwlock_t);
	PR(pthread_rwlockattr_t);
	PR(pthread_cond_t);
	PR(pthread_condattr_t);
	PR(pthread_key_t);
#ifndef BIONIC
	PR(pthread_spinlock_t);
	PR(pthread_barrier_t);
	PR(cpu_set_t);
#endif /* BIONIC */
	PR(struct sched_param);
	PR(size_t);
	return 0;
}
