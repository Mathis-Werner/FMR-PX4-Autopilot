//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: UrbanConderController2.h
//
// Code generated for Simulink model 'UrbanConderController2'.
//
// Model version                  : 1.203
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Mar 27 11:16:59 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef UrbanConderController2_h_
#define UrbanConderController2_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_Actuators.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Write.h"
#include "UrbanConderController2_types.h"
#include <uORB/topics/fmr_log.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/airspeed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Block signals (default storage)
struct B_UrbanConderController2_T {
  px4_Bus_fmr_log BusAssignment;       // '<S25>/Bus Assignment'
  px4_Bus_sensor_gps In1;              // '<S21>/In1'
  px4_Bus_sensor_gps r;
  px4_Bus_vehicle_odometry In1_g;      // '<S33>/In1'
  px4_Bus_vehicle_odometry r1;
  px4_Bus_failsafe_flags In1_m;        // '<S12>/In1'
  px4_Bus_failsafe_flags r2;
  px4_Bus_input_rc In1_i;              // '<S24>/In1'
  px4_Bus_input_rc r3;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_home_position r4;
  real_T Merge[5];                     // '<S9>/Merge'
  real32_T servoValues[8];
  px4_Bus_airspeed In1_a;              // '<S31>/In1'
  px4_Bus_airspeed r5;
  real_T Modeswitch1;                  // '<S6>/Round1'
  real_T Modeswitch2;                  // '<S6>/Round2'
  real_T Flapswitch;                   // '<S6>/Round'
  real_T Yawcmd;                       // '<S6>/Saturation3'
  real_T Pitchcmd;                     // '<S6>/Saturation2'
  real_T Rollcmd;                      // '<S6>/Saturation1'
  real_T Throttlecmd;                  // '<S6>/Saturation'
  real_T DataTypeConversion1;          // '<S44>/Data Type Conversion1'
  real32_T ParamStep;
  real32_T ParamStep_c;
  real32_T ParamStep_k;
  real32_T ParamStep_cx;
  real32_T ParamStep_b;
  real32_T ParamStep_p;
  real32_T ParamStep_cv;
  real32_T ParamStep_f;
  real32_T ParamStep_g;
  real32_T ParamStep_g1;
};

// Block states (default storage) for system '<Root>'
struct DW_UrbanConderController2_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_f;// '<S32>/SourceBlock'
  px4_internal_block_Subscriber_T obj_ff;// '<S28>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S23>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S20>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S17>/SourceBlock'
  px4_internal_block_Subscriber_T obj_hn;// '<S11>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_n;// '<S25>/PX4 Timestamp'
  px4_internal_block_ParameterU_T obj_d;// '<S5>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_lj;// '<S5>/Read Parameter37'
  px4_internal_block_ParameterU_T obj_m;// '<S5>/Read Parameter36'
  px4_internal_block_ParameterU_T obj_o;// '<S5>/Read Parameter35'
  px4_internal_block_ParameterU_T obj_dc;// '<S5>/Read Parameter34'
  px4_internal_block_ParameterU_T obj_k;// '<S5>/Read Parameter33'
  px4_internal_block_ParameterU_T obj_l2;// '<S5>/Read Parameter32'
  px4_internal_block_ParameterU_T obj_i;// '<S5>/Read Parameter31'
  px4_internal_block_ParameterU_T obj_kt;// '<S5>/Read Parameter30'
  px4_internal_block_ParameterU_T obj_p;// '<S5>/Read Parameter29'
  px4_internal_block_ParameterU_T obj_dr;// '<S5>/Read Parameter28'
  px4_internal_block_ParameterU_T obj_b;// '<S5>/Read Parameter27'
  px4_internal_block_ParameterU_T obj_f3;// '<S5>/Read Parameter26'
  px4_internal_block_ParameterU_T obj_ja;// '<S5>/Read Parameter25'
  px4_internal_block_ParameterU_T obj_iv;// '<S5>/Read Parameter24'
  px4_internal_block_ParameterU_T obj_jm;// '<S5>/Read Parameter23'
  px4_internal_block_ParameterU_T obj_a;// '<S5>/Read Parameter22'
  px4_internal_block_ParameterU_T obj_hx;// '<S5>/Read Parameter21'
  px4_internal_block_ParameterU_T obj_c;// '<S5>/Read Parameter20'
  px4_internal_block_Publisher__T obj_pi;// '<S27>/SinkBlock'
  real_T Integrator_DSTATE;            // '<S205>/Integrator'
  real_T Integrator_DSTATE_a;          // '<S263>/Integrator'
  real_T Integrator_DSTATE_h;          // '<S320>/Integrator'
  real_T Integrator_DSTATE_i;          // '<S84>/Integrator'
  real_T Integrator_DSTATE_p;          // '<S142>/Integrator'
  real_T Integrator_DSTATE_o;          // '<S379>/Integrator'
  int8_T SwitchCase_ActiveSubsystem;   // '<S40>/Switch Case'
};

// Parameters (default storage)
struct P_UrbanConderController2_T_ {
  real_T ail_left_pos_deg[21];         // Variable: ail_left_pos_deg
                                          //  Referenced by: '<S1>/Left Aileron Angles'

  real_T ail_max;                      // Variable: ail_max
                                          //  Referenced by:
                                          //    '<S35>/Constant1'
                                          //    '<S36>/Constant1'
                                          //    '<S38>/Constant1'
                                          //    '<S41>/Constant1'
                                          //    '<S41>/Constant2'
                                          //    '<S161>/Constant1'
                                          //    '<S161>/Constant2'
                                          //    '<S339>/Constant1'
                                          //    '<S339>/Constant2'

  real_T ail_right_pos_deg[21];        // Variable: ail_right_pos_deg
                                          //  Referenced by: '<S1>/Right Aileron Angles'

  real_T ele_max;                      // Variable: ele_max
                                          //  Referenced by:
                                          //    '<S35>/Constant2'
                                          //    '<S36>/Constant2'
                                          //    '<S38>/Constant2'
                                          //    '<S44>/Constant'
                                          //    '<S44>/Constant5'
                                          //    '<S164>/Constant'
                                          //    '<S164>/Constant5'

  real_T ele_pos_deg[21];              // Variable: ele_pos_deg
                                          //  Referenced by: '<S1>/Elevator Angles'

  real_T flap_max;                     // Variable: flap_max
                                          //  Referenced by:
                                          //    '<S34>/Constant4'
                                          //    '<S35>/Constant4'
                                          //    '<S36>/Constant4'
                                          //    '<S37>/Constant4'
                                          //    '<S38>/Constant4'

  real_T phi_max;                      // Variable: phi_max
                                          //  Referenced by:
                                          //    '<S34>/Constant1'
                                          //    '<S37>/Constant1'

  real_T rud_max;                      // Variable: rud_max
                                          //  Referenced by:
                                          //    '<S1>/Constant4'
                                          //    '<S34>/Constant3'
                                          //    '<S35>/Constant3'
                                          //    '<S36>/Constant3'
                                          //    '<S37>/Constant3'
                                          //    '<S38>/Constant3'

  real_T servo_signal_neg[21];         // Variable: servo_signal_neg
                                          //  Referenced by: '<S1>/Actuator Signal1'

  real_T servo_signal_pos[21];         // Variable: servo_signal_pos
                                          //  Referenced by:
                                          //    '<S1>/Actuator Signal'
                                          //    '<S1>/Actuator Signal2'

  real_T theta_max;                    // Variable: theta_max
                                          //  Referenced by:
                                          //    '<S34>/Constant2'
                                          //    '<S37>/Constant2'

  real_T thrust_max;                   // Variable: thrust_max
                                          //  Referenced by:
                                          //    '<S1>/Constant1'
                                          //    '<S34>/Constant'
                                          //    '<S35>/Constant'
                                          //    '<S36>/Constant'
                                          //    '<S165>/Constant'

  real32_T K_p;                        // Variable: K_p
                                          //  Referenced by:
                                          //    '<S36>/Gain'
                                          //    '<S41>/kp'
                                          //    '<S161>/kp'

  real32_T K_q;                        // Variable: K_q
                                          //  Referenced by:
                                          //    '<S36>/Gain1'
                                          //    '<S44>/kq'
                                          //    '<S164>/kq'

  real_T PIbankanglecontroller_InitialCo;
                              // Mask Parameter: PIbankanglecontroller_InitialCo
                                 //  Referenced by: '<S379>/Integrator'

  real_T PIbankanglecontroller_Initial_p;
                              // Mask Parameter: PIbankanglecontroller_Initial_p
                                 //  Referenced by: '<S84>/Integrator'

  real_T PIpitchanglecontroller_InitialC;
                              // Mask Parameter: PIpitchanglecontroller_InitialC
                                 //  Referenced by: '<S142>/Integrator'

  real_T PIbankanglecontroller_Initial_k;
                              // Mask Parameter: PIbankanglecontroller_Initial_k
                                 //  Referenced by: '<S205>/Integrator'

  real_T PIpitchanglecontroller_Initia_f;
                              // Mask Parameter: PIpitchanglecontroller_Initia_f
                                 //  Referenced by: '<S263>/Integrator'

  real_T PIspeedcontroller_InitialCondit;
                              // Mask Parameter: PIspeedcontroller_InitialCondit
                                 //  Referenced by: '<S320>/Integrator'

  px4_Bus_fmr_log Constant_Value;      // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S26>/Constant'

  px4_Bus_sensor_gps Out1_Y0;          // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S21>/Out1'

  px4_Bus_sensor_gps Constant_Value_a; // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S20>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_c;  // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S33>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_e;// Computed Parameter: Constant_Value_e
                                               //  Referenced by: '<S32>/Constant'

  px4_Bus_failsafe_flags Out1_Y0_f;    // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S12>/Out1'

  px4_Bus_failsafe_flags Constant_Value_o;// Computed Parameter: Constant_Value_o
                                             //  Referenced by: '<S11>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S24>/Out1'

  px4_Bus_input_rc Constant_Value_p;   // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S23>/Constant'

  px4_Bus_home_position Out1_Y0_a;     // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_home_position Constant_Value_c;// Computed Parameter: Constant_Value_c
                                            //  Referenced by: '<S17>/Constant'

  px4_Bus_airspeed Out1_Y0_o;          // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S31>/Out1'

  px4_Bus_airspeed Constant_Value_m;   // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S28>/Constant'

  real_T Constant9_Value;              // Expression: 5
                                          //  Referenced by: '<S339>/Constant9'

  real_T Constant1_Value;              // Expression: -5
                                          //  Referenced by: '<S39>/Constant1'

  real_T Gain1_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<S340>/Gain1'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S379>/Integrator'

  real_T Constant11_Value;             // Expression: 5
                                          //  Referenced by: '<S339>/Constant11'

  real_T Constant_Value_pj;            // Expression: 0
                                          //  Referenced by: '<S39>/Constant'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S39>/Constant4'

  real_T Constant2_Value;              // Expression: -5
                                          //  Referenced by: '<S39>/Constant2'

  real_T Constant_Value_i;             // Expression: 1/250
                                          //  Referenced by: '<S339>/Constant'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S35>/Gain'

  real_T Gain_Gain_c;                  // Expression: -1
                                          //  Referenced by: '<S38>/Gain'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S36>/Gain2'

  real_T Constant9_Value_c;            // Expression: 5
                                          //  Referenced by: '<S41>/Constant9'

  real_T Gain1_Gain_g;                 // Expression: pi/180
                                          //  Referenced by: '<S42>/Gain1'

  real_T Gain1_Gain_gn;                // Expression: pi/180
                                          //  Referenced by: '<S45>/Gain1'

  real_T Integrator_gainval_a;       // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S84>/Integrator'

  real_T Constant11_Value_b;           // Expression: 5
                                          //  Referenced by: '<S41>/Constant11'

  real_T Constant_Value_j;             // Expression: 1/250
                                          //  Referenced by: '<S41>/Constant'

  real_T Gain1_Gain_i;                 // Expression: pi/180
                                          //  Referenced by: '<S43>/Gain1'

  real_T Gain1_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S34>/Gain1'

  real_T Gain1_Gain_h;                 // Expression: pi/180
                                          //  Referenced by: '<S103>/Gain1'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S142>/Integrator'

  real_T Constant4_Value_m;            // Expression: 3
                                          //  Referenced by: '<S44>/Constant4'

  real_T Constant6_Value;              // Expression: 3
                                          //  Referenced by: '<S44>/Constant6'

  real_T Constant1_Value_g;            // Expression: 1/250
                                          //  Referenced by: '<S44>/Constant1'

  real_T Constant9_Value_m;            // Expression: 5
                                          //  Referenced by: '<S161>/Constant9'

  real_T Gain1_Gain_a;                 // Expression: pi/180
                                          //  Referenced by: '<S163>/Gain1'

  real_T Gain1_Gain_c;                 // Expression: pi/180
                                          //  Referenced by: '<S166>/Gain1'

  real_T Integrator_gainval_j;       // Computed Parameter: Integrator_gainval_j
                                        //  Referenced by: '<S205>/Integrator'

  real_T Constant11_Value_g;           // Expression: 5
                                          //  Referenced by: '<S161>/Constant11'

  real_T Constant_Value_os;            // Expression: 1/250
                                          //  Referenced by: '<S161>/Constant'

  real_T Gain1_Gain_e;                 // Expression: pi/180
                                          //  Referenced by: '<S162>/Gain1'

  real_T Gain1_Gain_k;                 // Expression: -1
                                          //  Referenced by: '<S37>/Gain1'

  real_T Gain1_Gain_ia;                // Expression: pi/180
                                          //  Referenced by: '<S224>/Gain1'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S263>/Integrator'

  real_T Constant4_Value_d;            // Expression: 3
                                          //  Referenced by: '<S164>/Constant4'

  real_T Constant6_Value_b;            // Expression: 3
                                          //  Referenced by: '<S164>/Constant6'

  real_T Constant1_Value_m;            // Expression: 1/250
                                          //  Referenced by: '<S164>/Constant1'

  real_T Constant5_Value;              // Expression: 17
                                          //  Referenced by: '<S37>/Constant5'

  real_T Constant_Value_cs;            // Expression: 5
                                          //  Referenced by: '<S37>/Constant'

  real_T Integrator_gainval_d;       // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S320>/Integrator'

  real_T Constant2_Value_n;            // Expression: 0
                                          //  Referenced by: '<S165>/Constant2'

  real_T Constant4_Value_mx;           // Expression: 1/250
                                          //  Referenced by: '<S165>/Constant4'

  real_T Constant_Value_iy;            // Expression: 1
                                          //  Referenced by: '<S40>/Constant'

  real_T Constant7_Value;              // Expression: 970
                                          //  Referenced by: '<S6>/Constant7'

  real_T Gain7_Gain;                   // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain7'

  real_T Constant5_Value_f;            // Expression: 970
                                          //  Referenced by: '<S6>/Constant5'

  real_T Gain5_Gain;                   // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain5'

  real_T Constant6_Value_bo;           // Expression: 970
                                          //  Referenced by: '<S6>/Constant6'

  real_T Gain6_Gain;                   // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain6'

  real_T Constant4_Value_i;            // Expression: 970
                                          //  Referenced by: '<S6>/Constant4'

  real_T Gain4_Gain;                   // Expression: 0.001
                                          //  Referenced by: '<S6>/Gain4'

  real_T Constant3_Value;              // Expression: 1500
                                          //  Referenced by: '<S6>/Constant3'

  real_T Gain3_Gain;                   // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain3'

  real_T Gain8_Gain;                   // Expression: -1
                                          //  Referenced by: '<S6>/Gain8'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S6>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S6>/Saturation3'

  real_T Constant2_Value_j;            // Expression: 1500
                                          //  Referenced by: '<S6>/Constant2'

  real_T Gain2_Gain_d;                 // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain2'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S6>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S6>/Saturation2'

  real_T Constant1_Value_h;            // Expression: 1500
                                          //  Referenced by: '<S6>/Constant1'

  real_T Gain1_Gain_j;                 // Expression: 0.002
                                          //  Referenced by: '<S6>/Gain1'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S6>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S6>/Saturation1'

  real_T Constant_Value_l;             // Expression: 1000
                                          //  Referenced by: '<S6>/Constant'

  real_T Gain_Gain_g;                  // Expression: 0.001
                                          //  Referenced by: '<S6>/Gain'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S6>/Saturation'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S9>/Merge'

  real_T Saturation_UpperSat_d;        // Expression: 1
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation1_UpperSat_e;       // Expression: 1
                                          //  Referenced by: '<S1>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S1>/Saturation1'

  real_T Gain1_Gain_l;                 // Expression: -1
                                          //  Referenced by: '<S1>/Gain1'

  real_T Saturation5_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S1>/Saturation5'

  real_T Saturation5_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S1>/Saturation5'

  real_T Saturation2_UpperSat_o;       // Expression: 1
                                          //  Referenced by: '<S1>/Saturation2'

  real_T Saturation2_LowerSat_n;       // Expression: -1
                                          //  Referenced by: '<S1>/Saturation2'

  real_T Saturation3_UpperSat_c;       // Expression: 1
                                          //  Referenced by: '<S1>/Saturation3'

  real_T Saturation3_LowerSat_l;       // Expression: -1
                                          //  Referenced by: '<S1>/Saturation3'

  int64_T Gain1_Gain_o0;               // Computed Parameter: Gain1_Gain_o0
                                          //  Referenced by: '<S13>/Gain1'

  int64_T Gain1_Gain_af;               // Computed Parameter: Gain1_Gain_af
                                          //  Referenced by: '<S14>/Gain1'

  int32_T Gain2_Gain_p;                // Computed Parameter: Gain2_Gain_p
                                          //  Referenced by: '<S4>/Gain2'

  int32_T Gain_Gain_h;                 // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S4>/Gain'

  int32_T Gain1_Gain_eo;               // Computed Parameter: Gain1_Gain_eo
                                          //  Referenced by: '<S4>/Gain1'

  real32_T Constant1_Value_a;          // Computed Parameter: Constant1_Value_a
                                          //  Referenced by: '<S368>/Constant1'

  real32_T kp_Gain;                    // Computed Parameter: kp_Gain
                                          //  Referenced by: '<S339>/kp'

  real32_T Clamping_zero_Value;       // Computed Parameter: Clamping_zero_Value
                                         //  Referenced by: '<S368>/Clamping_zero'

  real32_T Constant1_Value_g0;         // Computed Parameter: Constant1_Value_g0
                                          //  Referenced by: '<S73>/Constant1'

  real32_T Constant1_Value_h2;         // Computed Parameter: Constant1_Value_h2
                                          //  Referenced by: '<S131>/Constant1'

  real32_T Clamping_zero_Value_e;   // Computed Parameter: Clamping_zero_Value_e
                                       //  Referenced by: '<S73>/Clamping_zero'

  real32_T Clamping_zero_Value_a;   // Computed Parameter: Clamping_zero_Value_a
                                       //  Referenced by: '<S131>/Clamping_zero'

  real32_T Constant1_Value_i;          // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S194>/Constant1'

  real32_T Constant1_Value_k;          // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S252>/Constant1'

  real32_T Constant1_Value_f;          // Computed Parameter: Constant1_Value_f
                                          //  Referenced by: '<S309>/Constant1'

  real32_T Clamping_zero_Value_j;   // Computed Parameter: Clamping_zero_Value_j
                                       //  Referenced by: '<S194>/Clamping_zero'

  real32_T Clamping_zero_Value_b;   // Computed Parameter: Clamping_zero_Value_b
                                       //  Referenced by: '<S252>/Clamping_zero'

  real32_T Clamping_zero_Value_d;   // Computed Parameter: Clamping_zero_Value_d
                                       //  Referenced by: '<S309>/Clamping_zero'

  int8_T Constant_Value_n;             // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S368>/Constant'

  int8_T Constant2_Value_b;            // Computed Parameter: Constant2_Value_b
                                          //  Referenced by: '<S368>/Constant2'

  int8_T Constant3_Value_e;            // Computed Parameter: Constant3_Value_e
                                          //  Referenced by: '<S368>/Constant3'

  int8_T Constant4_Value_b;            // Computed Parameter: Constant4_Value_b
                                          //  Referenced by: '<S368>/Constant4'

  int8_T Constant_Value_ex;            // Computed Parameter: Constant_Value_ex
                                          //  Referenced by: '<S73>/Constant'

  int8_T Constant2_Value_c;            // Computed Parameter: Constant2_Value_c
                                          //  Referenced by: '<S73>/Constant2'

  int8_T Constant3_Value_p;            // Computed Parameter: Constant3_Value_p
                                          //  Referenced by: '<S73>/Constant3'

  int8_T Constant4_Value_h;            // Computed Parameter: Constant4_Value_h
                                          //  Referenced by: '<S73>/Constant4'

  int8_T Constant_Value_jn;            // Computed Parameter: Constant_Value_jn
                                          //  Referenced by: '<S131>/Constant'

  int8_T Constant2_Value_m;            // Computed Parameter: Constant2_Value_m
                                          //  Referenced by: '<S131>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S131>/Constant3'

  int8_T Constant4_Value_ha;           // Computed Parameter: Constant4_Value_ha
                                          //  Referenced by: '<S131>/Constant4'

  int8_T Constant_Value_lx;            // Computed Parameter: Constant_Value_lx
                                          //  Referenced by: '<S194>/Constant'

  int8_T Constant2_Value_d;            // Computed Parameter: Constant2_Value_d
                                          //  Referenced by: '<S194>/Constant2'

  int8_T Constant3_Value_m;            // Computed Parameter: Constant3_Value_m
                                          //  Referenced by: '<S194>/Constant3'

  int8_T Constant4_Value_hz;           // Computed Parameter: Constant4_Value_hz
                                          //  Referenced by: '<S194>/Constant4'

  int8_T Constant_Value_ei;            // Computed Parameter: Constant_Value_ei
                                          //  Referenced by: '<S252>/Constant'

  int8_T Constant2_Value_f;            // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S252>/Constant2'

  int8_T Constant3_Value_f;            // Computed Parameter: Constant3_Value_f
                                          //  Referenced by: '<S252>/Constant3'

  int8_T Constant4_Value_a;            // Computed Parameter: Constant4_Value_a
                                          //  Referenced by: '<S252>/Constant4'

  int8_T Constant_Value_d;             // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S309>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S309>/Constant2'

  int8_T Constant3_Value_l;            // Computed Parameter: Constant3_Value_l
                                          //  Referenced by: '<S309>/Constant3'

  int8_T Constant4_Value_bb;           // Computed Parameter: Constant4_Value_bb
                                          //  Referenced by: '<S309>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_UrbanConderController_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_UrbanConderController2_T UrbanConderController2_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_UrbanConderController2_T UrbanConderController2_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_UrbanConderController2_T UrbanConderController2_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void UrbanConderController2_initialize(void);
  extern void UrbanConderController2_step(void);
  extern void UrbanConderController2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_UrbanConderControlle_T *const UrbanConderController2_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Constant5' : Unused code path elimination
//  Block '<S1>/Gain' : Unused code path elimination
//  Block '<S1>/Product5' : Unused code path elimination
//  Block '<S1>/Saturation4' : Unused code path elimination
//  Block '<Root>/Data Type Conversion6' : Unused code path elimination
//  Block '<Root>/Data Type Conversion7' : Unused code path elimination
//  Block '<S11>/NOT' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/Data Type Conversion2' : Unused code path elimination
//  Block '<S15>/Gain1' : Unused code path elimination
//  Block '<S16>/Gain1' : Unused code path elimination
//  Block '<S17>/NOT' : Unused code path elimination
//  Block '<S20>/NOT' : Unused code path elimination
//  Block '<S22>/Bitwise Operator' : Unused code path elimination
//  Block '<S22>/Data Type Conversion' : Unused code path elimination
//  Block '<S22>/Data Type Conversion1' : Unused code path elimination
//  Block '<S22>/Data Type Conversion2' : Unused code path elimination
//  Block '<S22>/Gain' : Unused code path elimination
//  Block '<S22>/Gain1' : Unused code path elimination
//  Block '<S23>/NOT' : Unused code path elimination
//  Block '<S28>/NOT' : Unused code path elimination
//  Block '<S32>/NOT' : Unused code path elimination
//  Block '<S29>/Signal Copy2' : Unused code path elimination
//  Block '<S92>/Data Type Duplicate' : Unused code path elimination
//  Block '<S92>/Data Type Propagation' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Propagation' : Unused code path elimination
//  Block '<S213>/Data Type Duplicate' : Unused code path elimination
//  Block '<S213>/Data Type Propagation' : Unused code path elimination
//  Block '<S271>/Data Type Duplicate' : Unused code path elimination
//  Block '<S271>/Data Type Propagation' : Unused code path elimination
//  Block '<S328>/Data Type Duplicate' : Unused code path elimination
//  Block '<S328>/Data Type Propagation' : Unused code path elimination
//  Block '<S387>/Data Type Duplicate' : Unused code path elimination
//  Block '<S387>/Data Type Propagation' : Unused code path elimination
//  Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion13' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S29>/Signal Copy' : Eliminate redundant signal conversion block
//  Block '<S29>/Signal Copy1' : Eliminate redundant signal conversion block


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'UrbanConderController2'
//  '<S1>'   : 'UrbanConderController2/Actuator Translation'
//  '<S2>'   : 'UrbanConderController2/Arm'
//  '<S3>'   : 'UrbanConderController2/Failsafe'
//  '<S4>'   : 'UrbanConderController2/GPS'
//  '<S5>'   : 'UrbanConderController2/Parameters'
//  '<S6>'   : 'UrbanConderController2/Radio'
//  '<S7>'   : 'UrbanConderController2/SD-card Logging'
//  '<S8>'   : 'UrbanConderController2/States'
//  '<S9>'   : 'UrbanConderController2/Steuerung//Regelung'
//  '<S10>'  : 'UrbanConderController2/Arm/MATLAB Function'
//  '<S11>'  : 'UrbanConderController2/Failsafe/PX4 uORB Read'
//  '<S12>'  : 'UrbanConderController2/Failsafe/PX4 uORB Read/Enabled Subsystem'
//  '<S13>'  : 'UrbanConderController2/GPS/Degrees to Radians'
//  '<S14>'  : 'UrbanConderController2/GPS/Degrees to Radians1'
//  '<S15>'  : 'UrbanConderController2/GPS/Degrees to Radians2'
//  '<S16>'  : 'UrbanConderController2/GPS/Degrees to Radians3'
//  '<S17>'  : 'UrbanConderController2/GPS/PX4 uORB Read'
//  '<S18>'  : 'UrbanConderController2/GPS/gps'
//  '<S19>'  : 'UrbanConderController2/GPS/PX4 uORB Read/Enabled Subsystem'
//  '<S20>'  : 'UrbanConderController2/GPS/gps/PX4 uORB Read'
//  '<S21>'  : 'UrbanConderController2/GPS/gps/PX4 uORB Read/Enabled Subsystem'
//  '<S22>'  : 'UrbanConderController2/Radio/Radio Control Transmitter'
//  '<S23>'  : 'UrbanConderController2/Radio/Radio Control Transmitter/PX4 uORB Read'
//  '<S24>'  : 'UrbanConderController2/Radio/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S25>'  : 'UrbanConderController2/SD-card Logging/PX4 ULog1'
//  '<S26>'  : 'UrbanConderController2/SD-card Logging/PX4 ULog1/PX4 uORB Message'
//  '<S27>'  : 'UrbanConderController2/SD-card Logging/PX4 ULog1/PX4_log_write'
//  '<S28>'  : 'UrbanConderController2/States/PX4 uORB Read'
//  '<S29>'  : 'UrbanConderController2/States/Vehicle Attitude'
//  '<S30>'  : 'UrbanConderController2/States/quat2eul'
//  '<S31>'  : 'UrbanConderController2/States/PX4 uORB Read/Enabled Subsystem'
//  '<S32>'  : 'UrbanConderController2/States/Vehicle Attitude/PX4 uORB Read'
//  '<S33>'  : 'UrbanConderController2/States/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S34>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller'
//  '<S35>'  : 'UrbanConderController2/Steuerung//Regelung/Manual'
//  '<S36>'  : 'UrbanConderController2/Steuerung//Regelung/SAS'
//  '<S37>'  : 'UrbanConderController2/Steuerung//Regelung/Speed controller '
//  '<S38>'  : 'UrbanConderController2/Steuerung//Regelung/Trimming'
//  '<S39>'  : 'UrbanConderController2/Steuerung//Regelung/failsafe'
//  '<S40>'  : 'UrbanConderController2/Steuerung//Regelung/flight mode selection'
//  '<S41>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller'
//  '<S42>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Degrees to Radians'
//  '<S43>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Degrees to Radians1'
//  '<S44>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller'
//  '<S45>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/Degrees to Radians2'
//  '<S46>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller'
//  '<S47>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Anti-windup'
//  '<S48>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/D Gain'
//  '<S49>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/External Derivative'
//  '<S50>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Filter'
//  '<S51>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Filter ICs'
//  '<S52>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/I Gain'
//  '<S53>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Ideal P Gain'
//  '<S54>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk'
//  '<S55>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Integrator'
//  '<S56>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Integrator ICs'
//  '<S57>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/N Copy'
//  '<S58>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/N Gain'
//  '<S59>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/P Copy'
//  '<S60>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Parallel P Gain'
//  '<S61>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Reset Signal'
//  '<S62>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Saturation'
//  '<S63>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Saturation Fdbk'
//  '<S64>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Sum'
//  '<S65>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Sum Fdbk'
//  '<S66>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tracking Mode'
//  '<S67>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tracking Mode Sum'
//  '<S68>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tsamp - Integral'
//  '<S69>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tsamp - Ngain'
//  '<S70>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/postSat Signal'
//  '<S71>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/preInt Signal'
//  '<S72>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/preSat Signal'
//  '<S73>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel'
//  '<S74>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S75>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S76>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S77>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/D Gain/Disabled'
//  '<S78>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/External Derivative/Disabled'
//  '<S79>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Filter/Disabled'
//  '<S80>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Filter ICs/Disabled'
//  '<S81>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/I Gain/External Parameters'
//  '<S82>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Ideal P Gain/Passthrough'
//  '<S83>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk/Disabled'
//  '<S84>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Integrator/Discrete'
//  '<S85>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Integrator ICs/Internal IC'
//  '<S86>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/N Copy/Disabled wSignal Specification'
//  '<S87>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/N Gain/Disabled'
//  '<S88>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/P Copy/Disabled'
//  '<S89>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Parallel P Gain/External Parameters'
//  '<S90>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Reset Signal/Disabled'
//  '<S91>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Saturation/External'
//  '<S92>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Saturation/External/Saturation Dynamic'
//  '<S93>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Saturation Fdbk/Disabled'
//  '<S94>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Sum/Sum_PI'
//  '<S95>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Sum Fdbk/Disabled'
//  '<S96>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tracking Mode/Disabled'
//  '<S97>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tracking Mode Sum/Passthrough'
//  '<S98>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tsamp - Integral/External Ts'
//  '<S99>'  : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/Tsamp - Ngain/Passthrough'
//  '<S100>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/postSat Signal/Forward_Path'
//  '<S101>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/preInt Signal/Internal PreInt'
//  '<S102>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Bank angle controller/PI bank angle controller/preSat Signal/Forward_Path'
//  '<S103>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/Degrees to Radians'
//  '<S104>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller'
//  '<S105>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Anti-windup'
//  '<S106>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/D Gain'
//  '<S107>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/External Derivative'
//  '<S108>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Filter'
//  '<S109>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Filter ICs'
//  '<S110>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/I Gain'
//  '<S111>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Ideal P Gain'
//  '<S112>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Ideal P Gain Fdbk'
//  '<S113>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Integrator'
//  '<S114>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Integrator ICs'
//  '<S115>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/N Copy'
//  '<S116>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/N Gain'
//  '<S117>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/P Copy'
//  '<S118>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Parallel P Gain'
//  '<S119>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Reset Signal'
//  '<S120>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Saturation'
//  '<S121>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Saturation Fdbk'
//  '<S122>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Sum'
//  '<S123>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Sum Fdbk'
//  '<S124>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tracking Mode'
//  '<S125>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tracking Mode Sum'
//  '<S126>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tsamp - Integral'
//  '<S127>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tsamp - Ngain'
//  '<S128>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/postSat Signal'
//  '<S129>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/preInt Signal'
//  '<S130>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/preSat Signal'
//  '<S131>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel'
//  '<S132>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S133>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S134>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S135>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/D Gain/Disabled'
//  '<S136>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/External Derivative/Disabled'
//  '<S137>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Filter/Disabled'
//  '<S138>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Filter ICs/Disabled'
//  '<S139>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/I Gain/External Parameters'
//  '<S140>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Ideal P Gain/Passthrough'
//  '<S141>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Integrator/Discrete'
//  '<S143>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Integrator ICs/Internal IC'
//  '<S144>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/N Copy/Disabled wSignal Specification'
//  '<S145>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/N Gain/Disabled'
//  '<S146>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/P Copy/Disabled'
//  '<S147>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Parallel P Gain/External Parameters'
//  '<S148>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Reset Signal/Disabled'
//  '<S149>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Saturation/External'
//  '<S150>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Saturation/External/Saturation Dynamic'
//  '<S151>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Saturation Fdbk/Disabled'
//  '<S152>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Sum/Sum_PI'
//  '<S153>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Sum Fdbk/Disabled'
//  '<S154>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tracking Mode/Disabled'
//  '<S155>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tracking Mode Sum/Passthrough'
//  '<S156>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tsamp - Integral/External Ts'
//  '<S157>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/Tsamp - Ngain/Passthrough'
//  '<S158>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/postSat Signal/Forward_Path'
//  '<S159>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/preInt Signal/Internal PreInt'
//  '<S160>' : 'UrbanConderController2/Steuerung//Regelung/Angle controller/Pitch angle controller/PI pitch angle controller/preSat Signal/Forward_Path'
//  '<S161>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller'
//  '<S162>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Degrees to Radians1'
//  '<S163>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Degrees to Radians2'
//  '<S164>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller'
//  '<S165>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller'
//  '<S166>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/Degrees to Radians2'
//  '<S167>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller'
//  '<S168>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Anti-windup'
//  '<S169>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/D Gain'
//  '<S170>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/External Derivative'
//  '<S171>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Filter'
//  '<S172>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Filter ICs'
//  '<S173>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/I Gain'
//  '<S174>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Ideal P Gain'
//  '<S175>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk'
//  '<S176>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Integrator'
//  '<S177>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Integrator ICs'
//  '<S178>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/N Copy'
//  '<S179>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/N Gain'
//  '<S180>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/P Copy'
//  '<S181>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Parallel P Gain'
//  '<S182>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Reset Signal'
//  '<S183>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Saturation'
//  '<S184>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Saturation Fdbk'
//  '<S185>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Sum'
//  '<S186>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Sum Fdbk'
//  '<S187>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tracking Mode'
//  '<S188>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tracking Mode Sum'
//  '<S189>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tsamp - Integral'
//  '<S190>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tsamp - Ngain'
//  '<S191>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/postSat Signal'
//  '<S192>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/preInt Signal'
//  '<S193>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/preSat Signal'
//  '<S194>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel'
//  '<S195>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S196>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S197>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S198>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/D Gain/Disabled'
//  '<S199>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/External Derivative/Disabled'
//  '<S200>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Filter/Disabled'
//  '<S201>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Filter ICs/Disabled'
//  '<S202>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/I Gain/External Parameters'
//  '<S203>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Ideal P Gain/Passthrough'
//  '<S204>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk/Disabled'
//  '<S205>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Integrator/Discrete'
//  '<S206>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Integrator ICs/Internal IC'
//  '<S207>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/N Copy/Disabled wSignal Specification'
//  '<S208>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/N Gain/Disabled'
//  '<S209>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/P Copy/Disabled'
//  '<S210>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Parallel P Gain/External Parameters'
//  '<S211>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Reset Signal/Disabled'
//  '<S212>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Saturation/External'
//  '<S213>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Saturation/External/Saturation Dynamic'
//  '<S214>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Saturation Fdbk/Disabled'
//  '<S215>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Sum/Sum_PI'
//  '<S216>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Sum Fdbk/Disabled'
//  '<S217>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tracking Mode/Disabled'
//  '<S218>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tracking Mode Sum/Passthrough'
//  '<S219>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tsamp - Integral/External Ts'
//  '<S220>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/Tsamp - Ngain/Passthrough'
//  '<S221>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/postSat Signal/Forward_Path'
//  '<S222>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/preInt Signal/Internal PreInt'
//  '<S223>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Bank angle controller/PI bank angle controller/preSat Signal/Forward_Path'
//  '<S224>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/Degrees to Radians'
//  '<S225>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller'
//  '<S226>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Anti-windup'
//  '<S227>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/D Gain'
//  '<S228>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/External Derivative'
//  '<S229>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Filter'
//  '<S230>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Filter ICs'
//  '<S231>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/I Gain'
//  '<S232>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Ideal P Gain'
//  '<S233>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Ideal P Gain Fdbk'
//  '<S234>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Integrator'
//  '<S235>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Integrator ICs'
//  '<S236>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/N Copy'
//  '<S237>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/N Gain'
//  '<S238>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/P Copy'
//  '<S239>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Parallel P Gain'
//  '<S240>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Reset Signal'
//  '<S241>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Saturation'
//  '<S242>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Saturation Fdbk'
//  '<S243>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Sum'
//  '<S244>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Sum Fdbk'
//  '<S245>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tracking Mode'
//  '<S246>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tracking Mode Sum'
//  '<S247>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tsamp - Integral'
//  '<S248>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tsamp - Ngain'
//  '<S249>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/postSat Signal'
//  '<S250>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/preInt Signal'
//  '<S251>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/preSat Signal'
//  '<S252>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel'
//  '<S253>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S254>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S255>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S256>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/D Gain/Disabled'
//  '<S257>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/External Derivative/Disabled'
//  '<S258>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Filter/Disabled'
//  '<S259>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Filter ICs/Disabled'
//  '<S260>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/I Gain/External Parameters'
//  '<S261>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Ideal P Gain/Passthrough'
//  '<S262>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Ideal P Gain Fdbk/Disabled'
//  '<S263>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Integrator/Discrete'
//  '<S264>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Integrator ICs/Internal IC'
//  '<S265>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/N Copy/Disabled wSignal Specification'
//  '<S266>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/N Gain/Disabled'
//  '<S267>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/P Copy/Disabled'
//  '<S268>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Parallel P Gain/External Parameters'
//  '<S269>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Reset Signal/Disabled'
//  '<S270>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Saturation/External'
//  '<S271>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Saturation/External/Saturation Dynamic'
//  '<S272>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Saturation Fdbk/Disabled'
//  '<S273>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Sum/Sum_PI'
//  '<S274>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Sum Fdbk/Disabled'
//  '<S275>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tracking Mode/Disabled'
//  '<S276>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tracking Mode Sum/Passthrough'
//  '<S277>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tsamp - Integral/External Ts'
//  '<S278>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/Tsamp - Ngain/Passthrough'
//  '<S279>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/postSat Signal/Forward_Path'
//  '<S280>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/preInt Signal/Internal PreInt'
//  '<S281>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Pitch angle controller/PI pitch angle controller/preSat Signal/Forward_Path'
//  '<S282>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller '
//  '<S283>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Anti-windup'
//  '<S284>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /D Gain'
//  '<S285>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /External Derivative'
//  '<S286>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Filter'
//  '<S287>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Filter ICs'
//  '<S288>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /I Gain'
//  '<S289>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Ideal P Gain'
//  '<S290>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Ideal P Gain Fdbk'
//  '<S291>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Integrator'
//  '<S292>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Integrator ICs'
//  '<S293>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /N Copy'
//  '<S294>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /N Gain'
//  '<S295>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /P Copy'
//  '<S296>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Parallel P Gain'
//  '<S297>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Reset Signal'
//  '<S298>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Saturation'
//  '<S299>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Saturation Fdbk'
//  '<S300>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Sum'
//  '<S301>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Sum Fdbk'
//  '<S302>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tracking Mode'
//  '<S303>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tracking Mode Sum'
//  '<S304>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tsamp - Integral'
//  '<S305>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tsamp - Ngain'
//  '<S306>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /postSat Signal'
//  '<S307>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /preInt Signal'
//  '<S308>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /preSat Signal'
//  '<S309>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Anti-windup/Disc. Clamping Parallel'
//  '<S310>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S311>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S312>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S313>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /D Gain/Disabled'
//  '<S314>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /External Derivative/Disabled'
//  '<S315>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Filter/Disabled'
//  '<S316>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Filter ICs/Disabled'
//  '<S317>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /I Gain/External Parameters'
//  '<S318>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Ideal P Gain/Passthrough'
//  '<S319>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Ideal P Gain Fdbk/Disabled'
//  '<S320>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Integrator/Discrete'
//  '<S321>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Integrator ICs/Internal IC'
//  '<S322>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /N Copy/Disabled wSignal Specification'
//  '<S323>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /N Gain/Disabled'
//  '<S324>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /P Copy/Disabled'
//  '<S325>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Parallel P Gain/External Parameters'
//  '<S326>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Reset Signal/Disabled'
//  '<S327>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Saturation/External'
//  '<S328>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Saturation/External/Saturation Dynamic'
//  '<S329>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Saturation Fdbk/Disabled'
//  '<S330>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Sum/Sum_PI'
//  '<S331>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Sum Fdbk/Disabled'
//  '<S332>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tracking Mode/Disabled'
//  '<S333>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tracking Mode Sum/Passthrough'
//  '<S334>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tsamp - Integral/External Ts'
//  '<S335>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /Tsamp - Ngain/Passthrough'
//  '<S336>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /postSat Signal/Forward_Path'
//  '<S337>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /preInt Signal/Internal PreInt'
//  '<S338>' : 'UrbanConderController2/Steuerung//Regelung/Speed controller /Speed controller/PI speed controller /preSat Signal/Forward_Path'
//  '<S339>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller'
//  '<S340>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Degrees to Radians'
//  '<S341>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller'
//  '<S342>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Anti-windup'
//  '<S343>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/D Gain'
//  '<S344>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/External Derivative'
//  '<S345>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Filter'
//  '<S346>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Filter ICs'
//  '<S347>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/I Gain'
//  '<S348>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Ideal P Gain'
//  '<S349>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk'
//  '<S350>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Integrator'
//  '<S351>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Integrator ICs'
//  '<S352>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/N Copy'
//  '<S353>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/N Gain'
//  '<S354>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/P Copy'
//  '<S355>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Parallel P Gain'
//  '<S356>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Reset Signal'
//  '<S357>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Saturation'
//  '<S358>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Saturation Fdbk'
//  '<S359>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Sum'
//  '<S360>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Sum Fdbk'
//  '<S361>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tracking Mode'
//  '<S362>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tracking Mode Sum'
//  '<S363>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tsamp - Integral'
//  '<S364>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tsamp - Ngain'
//  '<S365>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/postSat Signal'
//  '<S366>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/preInt Signal'
//  '<S367>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/preSat Signal'
//  '<S368>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel'
//  '<S369>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S370>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S371>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S372>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/D Gain/Disabled'
//  '<S373>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/External Derivative/Disabled'
//  '<S374>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Filter/Disabled'
//  '<S375>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Filter ICs/Disabled'
//  '<S376>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/I Gain/External Parameters'
//  '<S377>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Ideal P Gain/Passthrough'
//  '<S378>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Ideal P Gain Fdbk/Disabled'
//  '<S379>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Integrator/Discrete'
//  '<S380>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Integrator ICs/Internal IC'
//  '<S381>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/N Copy/Disabled wSignal Specification'
//  '<S382>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/N Gain/Disabled'
//  '<S383>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/P Copy/Disabled'
//  '<S384>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Parallel P Gain/External Parameters'
//  '<S385>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Reset Signal/Disabled'
//  '<S386>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Saturation/External'
//  '<S387>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Saturation/External/Saturation Dynamic'
//  '<S388>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Saturation Fdbk/Disabled'
//  '<S389>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Sum/Sum_PI'
//  '<S390>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Sum Fdbk/Disabled'
//  '<S391>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tracking Mode/Disabled'
//  '<S392>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tracking Mode Sum/Passthrough'
//  '<S393>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tsamp - Integral/External Ts'
//  '<S394>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/Tsamp - Ngain/Passthrough'
//  '<S395>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/postSat Signal/Forward_Path'
//  '<S396>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/preInt Signal/Internal PreInt'
//  '<S397>' : 'UrbanConderController2/Steuerung//Regelung/failsafe/Bank angle controller/PI bank angle controller/preSat Signal/Forward_Path'
//  '<S398>' : 'UrbanConderController2/Steuerung//Regelung/flight mode selection/flight mode'

#endif                                 // UrbanConderController2_h_

//
// File trailer for generated code.
//
// [EOF]
//
