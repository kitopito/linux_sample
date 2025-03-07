
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void	*ntp(void *arg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("thread%d started at %ld.%06ld\n", *(int *)arg, tv.tv_sec,
		tv.tv_usec);
}

// measure the time difference in starting two threads
int	main(void)
{
	pthread_t thread1, thread2;
	int a = 0;
	int b = 1;
	// if (pthread_create(&thread1, NULL, ntp, &a))
	// {
	// 	fprintf(stderr, "Error creating thread 1\n");
	// 	return (1);
	// }

	// if (pthread_create(&thread2, NULL, ntp, &b))
	// {
	// 	fprintf(stderr, "Error creating thread 2\n");
	// 	return (1);
	// }

	pthread_create(&thread1, NULL, ntp, &a);
	pthread_create(&thread2, NULL, ntp, &b);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return (0);
}