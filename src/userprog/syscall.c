#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"


static void syscall_handler (struct intr_frame *);
void check_valid_ptr (const void *vaddr);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  
  int arg[MAX_ARGS];
  check_valid_ptr((const void*) f->esp);

  thread_exit ();
}


void check_valid_ptr (const void *vaddr)
{
  if (!is_user_vaddr(vaddr) || vaddr < USER_VADDR_BOTTOM){

      exit(ERROR);
    }

    switch (* (int *) f->esp){

    	case SYS_IO : {

    		/**************** Implement system call ******************/
    	}
    }
}
