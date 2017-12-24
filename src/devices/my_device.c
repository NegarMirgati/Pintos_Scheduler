#include "devices/my_device.h"

struct my_device io_devices[NUM_OF_DEVICES];

void my_device_init(int device_num){

	lock_init(&(io_devices[device_num].device_lock));
	lock_init(&(io_devices[device_num].time_lock));

	io_devices[i].total_time = 0;
}

int64_t get_total_time(int device_num){

	return io_devices[device_num].total_time;
}

void request_device(int device_num, int64_t time){

	
	add_total_time(device_num, time);


	lock_acquire(&(io_devices[device_num].device_lock));

	use_device(device_num, time);

	lock_release(&(io_devices[device_num].device_lock));


    sub_total_time(device_num, time);


}


void use_device(int id, int64_t use_time){


	/**** IMPLEMENT THIS FUNCTION ****/
}


void add_total_time(int device_num, int64_t time){

	lock_acquire(&(io_devices[device_num].time_lock));

	io_devices[device_num].total_time += time;

	lock_release(&(io_devices[device_num].time_lock));

}

void sub_total_time(int device_num, int64_t time){

	lock_acquire(&(io_devices[device_num].time_lock));

	io_devices[device_num].total_time -= time;

	lock_release(&(io_devices[device_num].time_lock));
}


void add_to_waiting_list(int device_num, tid_t id){

	list_push_back (/*struct list */ io_devices[device_num].waiting_list, /*struct list_elem **/ );
}