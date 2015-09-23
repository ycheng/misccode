
#include <sched.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main() {
	struct sched_param param;
	param.sched_priority = 0;
	printf("sched_setscheduler return %i\n",
		sched_setscheduler(getpid(), SCHED_OTHER, &param)
	);
	return 0;
}
