//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: UrbanConderController2_types.h
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
#ifndef UrbanConderController2_types_h_
#define UrbanConderController2_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/fmr_log.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/vehicle_odometry.h>
#ifndef struct_d_px4_internal_block_SampleTi_T
#define struct_d_px4_internal_block_SampleTi_T

struct d_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_d_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

// Custom Type definition for MATLABSystem: '<S5>/Read Parameter4'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterU_T
#define struct_px4_internal_block_ParameterU_T

struct px4_internal_block_ParameterU_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif                                // struct_px4_internal_block_ParameterU_T

#ifndef struct_px4_internal_block_getPX4Abso_T
#define struct_px4_internal_block_getPX4Abso_T

struct px4_internal_block_getPX4Abso_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
};

#endif                                // struct_px4_internal_block_getPX4Abso_T

#ifndef struct_px4_internal_block_Publisher__T
#define struct_px4_internal_block_Publisher__T

struct px4_internal_block_Publisher__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Publisher__T

#ifndef struct_px4_internal_block_PX4Actuato_T
#define struct_px4_internal_block_PX4Actuato_T

struct px4_internal_block_PX4Actuato_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint8_T QSize;
  boolean_T ValidMotorIdx[12];
  boolean_T ValidServoIdx[8];
};

#endif                                // struct_px4_internal_block_PX4Actuato_T

// Parameters (default storage)
typedef struct P_UrbanConderController2_T_ P_UrbanConderController2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_UrbanConderController_T RT_MODEL_UrbanConderControlle_T;

#endif                                 // UrbanConderController2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
