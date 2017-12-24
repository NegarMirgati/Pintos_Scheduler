#ifndef MYDEVICE_H_
#define MYDEVICE_H_

#include <threads/synch.h>       /**Lock**/


#define num_of_devices 3


struct my_device{

  struct lock device_lock;

  int64_t total_time;

  struct lock time_lock;
	

};


void my_device_init(int device_num);

int64_t get_total_time(int device_num);

void request_device(int device_num, int64_t use_time);

void use_device(int id);

void add_total_time(int device_num, int64_t time);

void sub_total_time(int device_num, int64_t time);
	
	
