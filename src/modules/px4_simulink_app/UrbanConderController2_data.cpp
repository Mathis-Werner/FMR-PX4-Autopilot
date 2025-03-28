//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: UrbanConderController2_data.cpp
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
#include "UrbanConderController2.h"

// Block parameters (default storage)
P_UrbanConderController2_T UrbanConderController2_P = {
  // Variable: ail_left_pos_deg
  //  Referenced by: '<S1>/Left Aileron Angles'

  { -28.3, -26.0, -23.2, -20.4, -17.5, -14.8, -11.8, -8.6, -5.7, -2.5, 0.0, 2.6,
    5.1, 7.8, 10.4, 12.6, 14.8, 17.1, 18.9, 20.8, 23.1 },

  // Variable: ail_max
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

  25.0,

  // Variable: ail_right_pos_deg
  //  Referenced by: '<S1>/Right Aileron Angles'

  { -25.6, -23.8, -21.4, -19.1, -16.8, -14.3, -11.5, -8.1, -5.9, -2.7, 0.0, 3.3,
    5.7, 8.9, 11.8, 14.6, 18.3, 20.1, 22.4, 24.2, 26.4 },

  // Variable: ele_max
  //  Referenced by:
  //    '<S35>/Constant2'
  //    '<S36>/Constant2'
  //    '<S38>/Constant2'
  //    '<S44>/Constant'
  //    '<S44>/Constant5'
  //    '<S164>/Constant'
  //    '<S164>/Constant5'

  20.0,

  // Variable: ele_pos_deg
  //  Referenced by: '<S1>/Elevator Angles'

  { -26.1, -24.2, -21.8, -19.5, -16.7, -14.2, -11.3, -8.4, -5.5, -2.6, 0.0, 3.3,
    6.3, 9.4, 12.4, 15.3, 17.9, 20.6, 23.0, 25.7, 28.0 },

  // Variable: flap_max
  //  Referenced by:
  //    '<S34>/Constant4'
  //    '<S35>/Constant4'
  //    '<S36>/Constant4'
  //    '<S37>/Constant4'
  //    '<S38>/Constant4'

  30.0,

  // Variable: phi_max
  //  Referenced by:
  //    '<S34>/Constant1'
  //    '<S37>/Constant1'

  30.0,

  // Variable: rud_max
  //  Referenced by:
  //    '<S1>/Constant4'
  //    '<S34>/Constant3'
  //    '<S35>/Constant3'
  //    '<S36>/Constant3'
  //    '<S37>/Constant3'
  //    '<S38>/Constant3'

  26.0,

  // Variable: servo_signal_neg
  //  Referenced by: '<S1>/Actuator Signal1'

  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2,
    0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  // Variable: servo_signal_pos
  //  Referenced by:
  //    '<S1>/Actuator Signal'
  //    '<S1>/Actuator Signal2'

  { 1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0, -0.1, -0.2, -0.3,
    -0.4, -0.5, -0.6, -0.7, -0.8, -0.9, -1.0 },

  // Variable: theta_max
  //  Referenced by:
  //    '<S34>/Constant2'
  //    '<S37>/Constant2'

  15.0,

  // Variable: thrust_max
  //  Referenced by:
  //    '<S1>/Constant1'
  //    '<S34>/Constant'
  //    '<S35>/Constant'
  //    '<S36>/Constant'
  //    '<S165>/Constant'

  2.5,

  // Variable: K_p
  //  Referenced by:
  //    '<S36>/Gain'
  //    '<S41>/kp'
  //    '<S161>/kp'

  -5.0F,

  // Variable: K_q
  //  Referenced by:
  //    '<S36>/Gain1'
  //    '<S44>/kq'
  //    '<S164>/kq'

  -5.0F,

  // Mask Parameter: PIbankanglecontroller_InitialCo
  //  Referenced by: '<S379>/Integrator'

  0.0,

  // Mask Parameter: PIbankanglecontroller_Initial_p
  //  Referenced by: '<S84>/Integrator'

  0.0,

  // Mask Parameter: PIpitchanglecontroller_InitialC
  //  Referenced by: '<S142>/Integrator'

  0.0,

  // Mask Parameter: PIbankanglecontroller_Initial_k
  //  Referenced by: '<S205>/Integrator'

  0.0,

  // Mask Parameter: PIpitchanglecontroller_Initia_f
  //  Referenced by: '<S263>/Integrator'

  0.0,

  // Mask Parameter: PIspeedcontroller_InitialCondit
  //  Referenced by: '<S320>/Integrator'

  0.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S26>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // sig1
    0.0,                               // sig2
    0.0,                               // sig3
    0.0,                               // sig4
    0.0,                               // sig5
    0.0,                               // sig6
    0.0,                               // sig7
    0.0,                               // sig8
    0.0,                               // sig9
    0.0,                               // sig10
    0.0,                               // sig11
    0.0,                               // sig12
    0.0,                               // sig13
    0.0,                               // sig14
    0.0,                               // sig15
    0.0,                               // sig16
    0.0,                               // sig17
    0.0,                               // sig18
    0.0,                               // sig19
    0.0                                // sig20
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S21>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // time_utc_usec
    0U,                                // device_id
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0.0F,                              // heading_accuracy
    0.0F,                              // rtcm_injection_rate
    0U,                                // automatic_gain_control
    0U,                                // fix_type
    0U,                                // jamming_state
    0U,                                // spoofing_state
    false,                             // vel_ned_valid
    0U,                                // satellites_used
    0U,                                // selected_rtcm_instance

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S20>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // time_utc_usec
    0U,                                // device_id
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0.0F,                              // heading_accuracy
    0.0F,                              // rtcm_injection_rate
    0U,                                // automatic_gain_control
    0U,                                // fix_type
    0U,                                // jamming_state
    0U,                                // spoofing_state
    false,                             // vel_ned_valid
    0U,                                // satellites_used
    0U,                                // selected_rtcm_instance

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S33>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S32>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S12>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // mode_req_angular_velocity
    0U,                                // mode_req_attitude
    0U,                                // mode_req_local_alt
    0U,                                // mode_req_local_position
    0U,                                // mode_req_local_position_relaxed
    0U,                                // mode_req_global_position
    0U,                                // mode_req_mission
    0U,                                // mode_req_offboard_signal
    0U,                                // mode_req_home_position
    0U,                             // mode_req_wind_and_flight_time_compliance
    0U,                                // mode_req_prevent_arming
    0U,                                // mode_req_manual_control
    0U,                                // mode_req_other
    false,                             // angular_velocity_invalid
    false,                             // attitude_invalid
    false,                             // local_altitude_invalid
    false,                             // local_position_invalid
    false,                             // local_position_invalid_relaxed
    false,                             // local_velocity_invalid
    false,                             // global_position_invalid
    false,                             // auto_mission_missing
    false,                             // offboard_control_signal_lost
    false,                             // home_position_invalid
    false,                             // manual_control_signal_lost
    false,                             // gcs_connection_lost
    0U,                                // battery_warning
    false,                             // battery_low_remaining_time
    false,                             // battery_unhealthy
    false,                             // primary_geofence_breached
    false,                             // mission_failure
    false,                             // vtol_fixed_wing_system_failure
    false,                             // wind_limit_exceeded
    false,                             // flight_time_limit_exceeded
    false,                             // local_position_accuracy_low
    false,                             // fd_critical_failure
    false,                             // fd_esc_arming_failure
    false,                             // fd_imbalanced_prop
    false,                             // fd_motor_failure

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S11>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // mode_req_angular_velocity
    0U,                                // mode_req_attitude
    0U,                                // mode_req_local_alt
    0U,                                // mode_req_local_position
    0U,                                // mode_req_local_position_relaxed
    0U,                                // mode_req_global_position
    0U,                                // mode_req_mission
    0U,                                // mode_req_offboard_signal
    0U,                                // mode_req_home_position
    0U,                             // mode_req_wind_and_flight_time_compliance
    0U,                                // mode_req_prevent_arming
    0U,                                // mode_req_manual_control
    0U,                                // mode_req_other
    false,                             // angular_velocity_invalid
    false,                             // attitude_invalid
    false,                             // local_altitude_invalid
    false,                             // local_position_invalid
    false,                             // local_position_invalid_relaxed
    false,                             // local_velocity_invalid
    false,                             // global_position_invalid
    false,                             // auto_mission_missing
    false,                             // offboard_control_signal_lost
    false,                             // home_position_invalid
    false,                             // manual_control_signal_lost
    false,                             // gcs_connection_lost
    0U,                                // battery_warning
    false,                             // battery_low_remaining_time
    false,                             // battery_unhealthy
    false,                             // primary_geofence_breached
    false,                             // mission_failure
    false,                             // vtol_fixed_wing_system_failure
    false,                             // wind_limit_exceeded
    false,                             // flight_time_limit_exceeded
    false,                             // local_position_accuracy_low
    false,                             // fd_critical_failure
    false,                             // fd_esc_arming_failure
    false,                             // fd_imbalanced_prop
    false,                             // fd_motor_failure

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S24>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S23>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S19>/Out1'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S17>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S31>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S28>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Expression: 5
  //  Referenced by: '<S339>/Constant9'

  5.0,

  // Expression: -5
  //  Referenced by: '<S39>/Constant1'

  -5.0,

  // Expression: pi/180
  //  Referenced by: '<S340>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S379>/Integrator'

  1.0,

  // Expression: 5
  //  Referenced by: '<S339>/Constant11'

  5.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant4'

  0.0,

  // Expression: -5
  //  Referenced by: '<S39>/Constant2'

  -5.0,

  // Expression: 1/250
  //  Referenced by: '<S339>/Constant'

  0.004,

  // Expression: -1
  //  Referenced by: '<S35>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S36>/Gain2'

  -1.0,

  // Expression: 5
  //  Referenced by: '<S41>/Constant9'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S42>/Gain1'

  0.017453292519943295,

  // Expression: pi/180
  //  Referenced by: '<S45>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S84>/Integrator'

  1.0,

  // Expression: 5
  //  Referenced by: '<S41>/Constant11'

  5.0,

  // Expression: 1/250
  //  Referenced by: '<S41>/Constant'

  0.004,

  // Expression: pi/180
  //  Referenced by: '<S43>/Gain1'

  0.017453292519943295,

  // Expression: -1
  //  Referenced by: '<S34>/Gain1'

  -1.0,

  // Expression: pi/180
  //  Referenced by: '<S103>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: '<S142>/Integrator'

  1.0,

  // Expression: 3
  //  Referenced by: '<S44>/Constant4'

  3.0,

  // Expression: 3
  //  Referenced by: '<S44>/Constant6'

  3.0,

  // Expression: 1/250
  //  Referenced by: '<S44>/Constant1'

  0.004,

  // Expression: 5
  //  Referenced by: '<S161>/Constant9'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S163>/Gain1'

  0.017453292519943295,

  // Expression: pi/180
  //  Referenced by: '<S166>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_j
  //  Referenced by: '<S205>/Integrator'

  1.0,

  // Expression: 5
  //  Referenced by: '<S161>/Constant11'

  5.0,

  // Expression: 1/250
  //  Referenced by: '<S161>/Constant'

  0.004,

  // Expression: pi/180
  //  Referenced by: '<S162>/Gain1'

  0.017453292519943295,

  // Expression: -1
  //  Referenced by: '<S37>/Gain1'

  -1.0,

  // Expression: pi/180
  //  Referenced by: '<S224>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S263>/Integrator'

  1.0,

  // Expression: 3
  //  Referenced by: '<S164>/Constant4'

  3.0,

  // Expression: 3
  //  Referenced by: '<S164>/Constant6'

  3.0,

  // Expression: 1/250
  //  Referenced by: '<S164>/Constant1'

  0.004,

  // Expression: 17
  //  Referenced by: '<S37>/Constant5'

  17.0,

  // Expression: 5
  //  Referenced by: '<S37>/Constant'

  5.0,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S320>/Integrator'

  1.0,

  // Expression: 0
  //  Referenced by: '<S165>/Constant2'

  0.0,

  // Expression: 1/250
  //  Referenced by: '<S165>/Constant4'

  0.004,

  // Expression: 1
  //  Referenced by: '<S40>/Constant'

  1.0,

  // Expression: 970
  //  Referenced by: '<S6>/Constant7'

  970.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain7'

  0.002,

  // Expression: 970
  //  Referenced by: '<S6>/Constant5'

  970.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain5'

  0.002,

  // Expression: 970
  //  Referenced by: '<S6>/Constant6'

  970.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain6'

  0.002,

  // Expression: 970
  //  Referenced by: '<S6>/Constant4'

  970.0,

  // Expression: 0.001
  //  Referenced by: '<S6>/Gain4'

  0.001,

  // Expression: 1500
  //  Referenced by: '<S6>/Constant3'

  1500.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain3'

  0.002,

  // Expression: -1
  //  Referenced by: '<S6>/Gain8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S6>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Saturation3'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S6>/Constant2'

  1500.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain2'

  0.002,

  // Expression: 1
  //  Referenced by: '<S6>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Saturation2'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S6>/Constant1'

  1500.0,

  // Expression: 0.002
  //  Referenced by: '<S6>/Gain1'

  0.002,

  // Expression: 1
  //  Referenced by: '<S6>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S6>/Saturation1'

  -1.0,

  // Expression: 1000
  //  Referenced by: '<S6>/Constant'

  1000.0,

  // Expression: 0.001
  //  Referenced by: '<S6>/Gain'

  0.001,

  // Expression: 1
  //  Referenced by: '<S6>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S6>/Saturation'

  0.0,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<S9>/Merge'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Saturation1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S1>/Saturation5'

  1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Saturation5'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S1>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Saturation2'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S1>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Saturation3'

  -1.0,

  // Computed Parameter: Gain1_Gain_o0
  //  Referenced by: '<S13>/Gain1'

  (314410566756820LL),

  // Computed Parameter: Gain1_Gain_af
  //  Referenced by: '<S14>/Gain1'

  (314410566756820LL),

  // Computed Parameter: Gain2_Gain_p
  //  Referenced by: '<S4>/Gain2'

  1099511628,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S4>/Gain'

  1801439851,

  // Computed Parameter: Gain1_Gain_eo
  //  Referenced by: '<S4>/Gain1'

  1801439851,

  // Computed Parameter: Constant1_Value_a
  //  Referenced by: '<S368>/Constant1'

  0.0F,

  // Computed Parameter: kp_Gain
  //  Referenced by: '<S339>/kp'

  -3.0F,

  // Computed Parameter: Clamping_zero_Value
  //  Referenced by: '<S368>/Clamping_zero'

  0.0F,

  // Computed Parameter: Constant1_Value_g0
  //  Referenced by: '<S73>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_h2
  //  Referenced by: '<S131>/Constant1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_e
  //  Referenced by: '<S73>/Clamping_zero'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_a
  //  Referenced by: '<S131>/Clamping_zero'

  0.0F,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S194>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_k
  //  Referenced by: '<S252>/Constant1'

  0.0F,

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S309>/Constant1'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_j
  //  Referenced by: '<S194>/Clamping_zero'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_b
  //  Referenced by: '<S252>/Clamping_zero'

  0.0F,

  // Computed Parameter: Clamping_zero_Value_d
  //  Referenced by: '<S309>/Clamping_zero'

  0.0F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S368>/Constant'

  1,

  // Computed Parameter: Constant2_Value_b
  //  Referenced by: '<S368>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_e
  //  Referenced by: '<S368>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_b
  //  Referenced by: '<S368>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_ex
  //  Referenced by: '<S73>/Constant'

  1,

  // Computed Parameter: Constant2_Value_c
  //  Referenced by: '<S73>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_p
  //  Referenced by: '<S73>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_h
  //  Referenced by: '<S73>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_jn
  //  Referenced by: '<S131>/Constant'

  1,

  // Computed Parameter: Constant2_Value_m
  //  Referenced by: '<S131>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_k
  //  Referenced by: '<S131>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_ha
  //  Referenced by: '<S131>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_lx
  //  Referenced by: '<S194>/Constant'

  1,

  // Computed Parameter: Constant2_Value_d
  //  Referenced by: '<S194>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_m
  //  Referenced by: '<S194>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_hz
  //  Referenced by: '<S194>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_ei
  //  Referenced by: '<S252>/Constant'

  1,

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S252>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_f
  //  Referenced by: '<S252>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_a
  //  Referenced by: '<S252>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S309>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S309>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_l
  //  Referenced by: '<S309>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_bb
  //  Referenced by: '<S309>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
