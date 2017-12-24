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

void use_device(int id, int64_t use_time);
	
	
