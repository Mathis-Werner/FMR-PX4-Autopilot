#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/airspeed.h>
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/fmr_log.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct airspeed_s  px4_Bus_airspeed ;
typedef struct failsafe_flags_s  px4_Bus_failsafe_flags ;
typedef struct fmr_log_s  px4_Bus_fmr_log ;
typedef struct home_position_s  px4_Bus_home_position ;
typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct sensor_gps_s  px4_Bus_sensor_gps ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
