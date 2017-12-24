#include "devices/my_device.h"

struct my_device io_devices[NUM_OF_DEVICES];

void my_device_init(int device_num){

	lock_init(&(io_devices[device_num]));
	lock_init(&(io_devices[device_num]));
}

int64_t get_total_time(int device_num){

	return io_devices[device_num].total_time;
}


void use_device(int id, int64_t use_time){


	/**** IMPLEMENT THIS FUNCTION ****/
}