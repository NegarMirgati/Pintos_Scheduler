#ifndef MYDEVICE_H_
#define MYDEVICE_H_

#include <threads/synch.h>       /**Lock**/

#include <list.h>
#include <stdint.h>
#include <limits.h>
#include <debug.h>
#include "threads/malloc.h"
#include "timer.h"


#define NUM_OF_DEVICES 3

typedef int tid_t;


struct waiter{

	tid_t tid;
	struct list_elem elem;
};


struct my_device{

  struct lock device_lock;

  int64_t total_time;

  struct lock time_lock;

  struct list waiting_list;
	

};


void my_device_init(int device_num);

int64_t get_total_time(int device_num);

void request_device(int device_num, int64_t use_time, tid_t tid);

void use_device(int id, int64_t use_time);

void add_total_time(int device_num, int64_t time);

void sub_total_time(int device_num, int64_t time);

void add_to_waiting_list(int device_num, tid_t id);

void remove_from_waiting_list(int device_num , tid_t tid);

bool has_tid_in_waiting_list(int device_num, tid_t tid);
	
	
#endif