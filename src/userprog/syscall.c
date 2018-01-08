#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "devices/my_device.h"
#include <stdlib.h>
#include <stdio.h>
#include "threads/vaddr.h"

#define USER_VADDR_BOTTOM ((void *) 0x08048000)
#define ERROR -1
#define MAX_ARGS 3


static void syscall_handler (struct intr_frame *);
void check_valid_ptr (const void *vaddr);
void get_arg (struct intr_frame *f, int *arg, int n);
void exit (int status);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

void exit (int status)
{
  struct thread *cur = thread_current();
 /* if (thread_alive(cur->parent))
    {
      cur->cp->status = status;
    }*/
  printf ("%s: exit(%d)\n", cur->name, status);
  thread_exit();
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  
  int arg[MAX_ARGS];
  check_valid_ptr((const void*) f->esp);

  switch (* (int *) f->esp){

  	case SYS_IO: {

  		
  		get_arg(f, arg, 2);

  		/* arg[0] -> int device num, arg[1] -> tid */
  		add_to_waiting_list(arg[0], arg[1]);

  	}

    case SYS_DO_IO: {

      get_arg(f, arg, 3);

      request_device(arg[0], arg[1], arg[2]);


    }

  }

  //thread_exit ();
}


void check_valid_ptr (const void *vaddr)
{
  if (!is_user_vaddr(vaddr) || vaddr < USER_VADDR_BOTTOM)
    {
      exit(ERROR);
      //abort();
      //thread_exit();
    }
}


void get_arg (struct intr_frame *f, int *arg, int n)
{
  int i;
  int *ptr;
  for (i = 0; i < n; i++)
    {
      ptr = (int *) f->esp + i + 1;
      check_valid_ptr((const void *) ptr);
      arg[i] = *ptr;
    }
}
