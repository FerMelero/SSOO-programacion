#include <stdio.h>
#include <unistd.h>


int main() {
	
	pid_t pid = getpid();
	uid_t uid = getuid();
	
	printf("PID del proceso %d\n", pid);
	printf("UID del usuario %d\n", uid);
	
	return 0;
}
