#include <stdio.h>
#include <syscall.h>
#include "threads/thread.h"

int main(){

	struct thread *cur = thread_current();
	int tid = cur -> tid;


	
	inform_io(1, tid);
}