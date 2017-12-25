#include "devices/my_device.h"

struct my_device io_devices[NUM_OF_DEVICES];


void my_device_init(int device_num){

	/// 0 or 1 or 2

	if(device_num < NUM_OF_DEVICES){

	lock_init(&(io_devices[device_num].device_lock));
	lock_init(&(io_devices[device_num].time_lock));

	list_init(&(waiting_list));

	io_devices[i].total_time = 0;
}

}

int64_t get_total_time(int device_num){

	return io_devices[device_num].total_time;
}

void request_device(int device_num, int64_t time, tid_t tid){

	
	add_total_time(device_num, time);


	lock_acquire(&(io_devices[device_num].device_lock));

	use_device(device_num, time);

	lock_release(&(io_devices[device_num].device_lock));


	remove_from_waiting_list(device_num, tid);


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

	struct waiter* w = new struct waiter();
	w->tid = id;


	list_push_back (&(io_devices[device_num].waiting_list), &(w->list_elem));
}

bool has_tid_in_waiting_list(int device_num, tid_t tid){

	struct list_elem* e;


	for( e = list_begin(&(io_devices[device_num].waiting_list));
		 e !=list_end(&(io_devices[device_num].waiting_list)); e = list_next(e) ){

		struct waiter* w = list_entry(e, struct waiter, elem);


	   if(w-> tid == tid)
	   		return true; 	

	}

	return false;
}


void remove_from_waiting_list(int device_num , tid_t tid){


	struct list_elem* e;


	for( e = list_begin(&(io_devices[device_num].waiting_list));
		 e !=list_end(&(io_devices[device_num].waiting_list)); e = list_next(e) ){

		struct waiter* w = list_entry(e, struct waiter, elem);


	   if(w-> tid == tid)
	   		list_remove (e);

	}

}
