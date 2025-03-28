//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: UrbanConderController2.cpp
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
#include "UrbanConderController2_types.h"
#include "UrbanConderController2_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "rt_defines.h"

// Block signals (default storage)
B_UrbanConderController2_T UrbanConderController2_B;

// Block states (default storage)
DW_UrbanConderController2_T UrbanConderController2_DW;

// Real-time model
RT_MODEL_UrbanConderControlle_T UrbanConderController2_M_ =
  RT_MODEL_UrbanConderControlle_T();
RT_MODEL_UrbanConderControlle_T *const UrbanConderController2_M =
  &UrbanConderController2_M_;

// Forward declaration for local functions
static void UrbanCon_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  // Binary Search
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

void mul_wide_s64(int64_T in0, int64_T in1, uint64_T *ptrOutBitsHi, uint64_T
                  *ptrOutBitsLo)
{
  uint64_T absIn0;
  uint64_T absIn1;
  uint64_T in0Hi;
  uint64_T in0Lo;
  uint64_T in1Hi;
  uint64_T productHiLo;
  uint64_T productLoHi;
  absIn0 = in0 < 0LL ? ~static_cast<uint64_T>(in0) + 1ULL : static_cast<uint64_T>
    (in0);
  absIn1 = in1 < 0LL ? ~static_cast<uint64_T>(in1) + 1ULL : static_cast<uint64_T>
    (in1);
  in0Hi = absIn0 >> 32ULL;
  in0Lo = absIn0 & 4294967295ULL;
  in1Hi = absIn1 >> 32ULL;
  absIn0 = absIn1 & 4294967295ULL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0ULL;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 32ULL) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1ULL;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 32ULL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 32ULL) + (productHiLo >> 32ULL)) + in0Hi * in1Hi) +
    absIn1;
  if (static_cast<int32_T>((in0 != 0LL) && ((in1 != 0LL) && ((in0 > 0LL) != (in1
          > 0LL))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0ULL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int64_T mul_s64_loSR_sat(int64_T a, int64_T b, uint64_T aShift)
{
  int64_T result;
  uint64_T u64_chi;
  uint64_T u64_clo;
  mul_wide_s64(a, b, &u64_chi, &u64_clo);
  u64_clo = u64_chi << /*MW:OvBitwiseOk*/ (64ULL - aShift) | u64_clo >> aShift;
  u64_chi = static_cast<uint64_T>(static_cast<int64_T>(u64_chi) >> aShift);
  if ((static_cast<int64_T>(u64_chi) > 0LL) || ((u64_chi == 0ULL) && (u64_clo >=
        9223372036854775808ULL))) {
    result = MAX_int64_T;
  } else if ((static_cast<int64_T>(u64_chi) < -1LL) || ((static_cast<int64_T>
               (u64_chi) == -1LL) && (u64_clo < 9223372036854775808ULL))) {
    result = MIN_int64_T;
  } else {
    result = static_cast<int64_T>(u64_clo);
  }

  return result;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

static void UrbanCon_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidServoIdx[0] = true;
  obj->ValidServoIdx[1] = true;
  obj->ValidServoIdx[2] = true;
  obj->ValidServoIdx[3] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function
void UrbanConderController2_step(void)
{
  int32_T i;
  real32_T ParamStep;
  real32_T ParamStep_0;
  real32_T ParamStep_1;
  real32_T rtb_DataTypeConversion2_p_tmp;
  real32_T rtb_Sum_f;
  real32_T rtb_phi;
  real32_T rtb_phi_tmp;
  real32_T rtb_phi_tmp_0;
  real32_T rtb_phi_tmp_1;
  real32_T rtb_phi_tmp_2;
  real32_T rtb_theta;
  uint32_T rtb_ElevatorAngles_o1;
  int8_T rtPrevAction;
  int8_T tmp;
  boolean_T b_varargout_1;

  // MATLABSystem: '<S23>/SourceBlock'
  b_varargout_1 = uORB_read_step(UrbanConderController2_DW.obj_j.orbMetadataObj,
    &UrbanConderController2_DW.obj_j.eventStructObj,
    &UrbanConderController2_B.r3, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S24>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S24>/In1'
    UrbanConderController2_B.In1_i = UrbanConderController2_B.r3;
  }

  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // MATLABSystem: '<S11>/SourceBlock'
  b_varargout_1 = uORB_read_step(UrbanConderController2_DW.obj_hn.orbMetadataObj,
    &UrbanConderController2_DW.obj_hn.eventStructObj,
    &UrbanConderController2_B.r2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Start for MATLABSystem: '<S11>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    UrbanConderController2_B.In1_m = UrbanConderController2_B.r2;
  }

  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'

  // Rounding: '<S6>/Round1' incorporates:
  //   Constant: '<S6>/Constant5'
  //   Gain: '<S6>/Gain5'
  //   Sum: '<S6>/Sum5'

  UrbanConderController2_B.Modeswitch1 = rt_roundd_snf((static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[5]) -
    UrbanConderController2_P.Constant5_Value_f) *
    UrbanConderController2_P.Gain5_Gain);

  // Rounding: '<S6>/Round2' incorporates:
  //   Constant: '<S6>/Constant6'
  //   Gain: '<S6>/Gain6'
  //   Sum: '<S6>/Sum6'

  UrbanConderController2_B.Modeswitch2 = rt_roundd_snf((static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[6]) -
    UrbanConderController2_P.Constant6_Value_bo) *
    UrbanConderController2_P.Gain6_Gain);

  // MATLABSystem: '<S32>/SourceBlock'
  b_varargout_1 = uORB_read_step(UrbanConderController2_DW.obj_f.orbMetadataObj,
    &UrbanConderController2_DW.obj_f.eventStructObj,
    &UrbanConderController2_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  // Start for MATLABSystem: '<S32>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S33>/In1'
    UrbanConderController2_B.In1_g = UrbanConderController2_B.r1;
  }

  // End of Outputs for SubSystem: '<S32>/Enabled Subsystem'

  // MATLAB Function: '<S8>/quat2eul'
  rtb_phi_tmp = UrbanConderController2_B.In1_g.q[0] *
    UrbanConderController2_B.In1_g.q[0];
  rtb_phi_tmp_0 = UrbanConderController2_B.In1_g.q[1] *
    UrbanConderController2_B.In1_g.q[1];
  rtb_phi_tmp_1 = UrbanConderController2_B.In1_g.q[2] *
    UrbanConderController2_B.In1_g.q[2];
  rtb_phi_tmp_2 = UrbanConderController2_B.In1_g.q[3] *
    UrbanConderController2_B.In1_g.q[3];
  rtb_phi = rt_atan2f_snf((UrbanConderController2_B.In1_g.q[0] *
    UrbanConderController2_B.In1_g.q[1] + UrbanConderController2_B.In1_g.q[2] *
    UrbanConderController2_B.In1_g.q[3]) * 2.0F, ((rtb_phi_tmp - rtb_phi_tmp_0)
    - rtb_phi_tmp_1) + rtb_phi_tmp_2);
  rtb_theta = static_cast<real32_T>(asin(static_cast<real_T>
    ((UrbanConderController2_B.In1_g.q[1] * UrbanConderController2_B.In1_g.q[3]
      - UrbanConderController2_B.In1_g.q[0] * UrbanConderController2_B.In1_g.q[2])
     * -2.0F)));

  // MATLABSystem: '<S5>/Read Parameter35'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_o.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter34'
  MW_Param_Step(UrbanConderController2_DW.obj_dc.MW_PARAMHANDLE, MW_SINGLE,
                &UrbanConderController2_B.ParamStep_c);

  // MATLABSystem: '<S5>/Read Parameter33'
  MW_Param_Step(UrbanConderController2_DW.obj_k.MW_PARAMHANDLE, MW_SINGLE,
                &UrbanConderController2_B.ParamStep_c);

  // MATLABSystem: '<S5>/Read Parameter32'
  MW_Param_Step(UrbanConderController2_DW.obj_l2.MW_PARAMHANDLE, MW_SINGLE,
                &UrbanConderController2_B.ParamStep_c);

  // MATLABSystem: '<S5>/Read Parameter31'
  MW_Param_Step(UrbanConderController2_DW.obj_i.MW_PARAMHANDLE, MW_SINGLE,
                &UrbanConderController2_B.ParamStep_c);

  // MATLABSystem: '<S5>/Read Parameter30'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_kt.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_c);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter29'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_k);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter28'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_dr.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_cx);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_cx = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter27'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_b);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_b = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter26'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_f3.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_p);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_p = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter25'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_ja.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_cv);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_cv = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter24'
  MW_Param_Step(UrbanConderController2_DW.obj_iv.MW_PARAMHANDLE, MW_SINGLE,
                &UrbanConderController2_B.ParamStep_f);

  // MATLABSystem: '<S5>/Read Parameter37'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_lj.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_f);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_f = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter36'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_m.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_g);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_g = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter23'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_jm.MW_PARAMHANDLE,
    MW_SINGLE, &UrbanConderController2_B.ParamStep_g1);
  if (b_varargout_1) {
    UrbanConderController2_B.ParamStep_g1 = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter22'
  MW_Param_Step(UrbanConderController2_DW.obj_a.MW_PARAMHANDLE, MW_SINGLE,
                &ParamStep);

  // MATLABSystem: '<S5>/Read Parameter4'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter20'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_c.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // MATLABSystem: '<S5>/Read Parameter21'
  b_varargout_1 = MW_Param_Step(UrbanConderController2_DW.obj_hx.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_1);
  if (b_varargout_1) {
    ParamStep_1 = 0.0F;
  }

  // Rounding: '<S6>/Round' incorporates:
  //   Constant: '<S6>/Constant4'
  //   Gain: '<S6>/Gain4'
  //   Sum: '<S6>/Sum4'

  UrbanConderController2_B.Flapswitch = rt_roundd_snf((static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[4]) -
    UrbanConderController2_P.Constant4_Value_i) *
    UrbanConderController2_P.Gain4_Gain);

  // Gain: '<S6>/Gain8' incorporates:
  //   Constant: '<S6>/Constant3'
  //   Gain: '<S6>/Gain3'
  //   Sum: '<S6>/Sum3'

  UrbanConderController2_B.Yawcmd = (static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[3]) -
    UrbanConderController2_P.Constant3_Value) *
    UrbanConderController2_P.Gain3_Gain * UrbanConderController2_P.Gain8_Gain;

  // Saturate: '<S6>/Saturation3'
  if (UrbanConderController2_B.Yawcmd >
      UrbanConderController2_P.Saturation3_UpperSat) {
    UrbanConderController2_B.Yawcmd =
      UrbanConderController2_P.Saturation3_UpperSat;
  } else if (UrbanConderController2_B.Yawcmd <
             UrbanConderController2_P.Saturation3_LowerSat) {
    UrbanConderController2_B.Yawcmd =
      UrbanConderController2_P.Saturation3_LowerSat;
  }

  // End of Saturate: '<S6>/Saturation3'

  // Gain: '<S6>/Gain2' incorporates:
  //   Constant: '<S6>/Constant2'
  //   Sum: '<S6>/Sum2'

  UrbanConderController2_B.Pitchcmd = (static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[2]) -
    UrbanConderController2_P.Constant2_Value_j) *
    UrbanConderController2_P.Gain2_Gain_d;

  // Saturate: '<S6>/Saturation2'
  if (UrbanConderController2_B.Pitchcmd >
      UrbanConderController2_P.Saturation2_UpperSat) {
    UrbanConderController2_B.Pitchcmd =
      UrbanConderController2_P.Saturation2_UpperSat;
  } else if (UrbanConderController2_B.Pitchcmd <
             UrbanConderController2_P.Saturation2_LowerSat) {
    UrbanConderController2_B.Pitchcmd =
      UrbanConderController2_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S6>/Saturation2'

  // Gain: '<S6>/Gain1' incorporates:
  //   Constant: '<S6>/Constant1'
  //   Sum: '<S6>/Sum1'

  UrbanConderController2_B.Rollcmd = (static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[1]) -
    UrbanConderController2_P.Constant1_Value_h) *
    UrbanConderController2_P.Gain1_Gain_j;

  // Saturate: '<S6>/Saturation1'
  if (UrbanConderController2_B.Rollcmd >
      UrbanConderController2_P.Saturation1_UpperSat) {
    UrbanConderController2_B.Rollcmd =
      UrbanConderController2_P.Saturation1_UpperSat;
  } else if (UrbanConderController2_B.Rollcmd <
             UrbanConderController2_P.Saturation1_LowerSat) {
    UrbanConderController2_B.Rollcmd =
      UrbanConderController2_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S6>/Saturation1'

  // Gain: '<S6>/Gain' incorporates:
  //   Constant: '<S6>/Constant'
  //   Sum: '<S6>/Sum'

  UrbanConderController2_B.Throttlecmd = (static_cast<real_T>
    (UrbanConderController2_B.In1_i.values[0]) -
    UrbanConderController2_P.Constant_Value_l) *
    UrbanConderController2_P.Gain_Gain_g;

  // Saturate: '<S6>/Saturation'
  if (UrbanConderController2_B.Throttlecmd >
      UrbanConderController2_P.Saturation_UpperSat) {
    UrbanConderController2_B.Throttlecmd =
      UrbanConderController2_P.Saturation_UpperSat;
  } else if (UrbanConderController2_B.Throttlecmd <
             UrbanConderController2_P.Saturation_LowerSat) {
    UrbanConderController2_B.Throttlecmd =
      UrbanConderController2_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S6>/Saturation'

  // MATLABSystem: '<S28>/SourceBlock'
  b_varargout_1 = uORB_read_step(UrbanConderController2_DW.obj_ff.orbMetadataObj,
    &UrbanConderController2_DW.obj_ff.eventStructObj,
    &UrbanConderController2_B.r5, false, 1.0);

  // Outputs for Enabled SubSystem: '<S28>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  // Start for MATLABSystem: '<S28>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S31>/In1'
    UrbanConderController2_B.In1_a = UrbanConderController2_B.r5;
  }

  // End of Outputs for SubSystem: '<S28>/Enabled Subsystem'

  // SwitchCase: '<S40>/Switch Case'
  rtPrevAction = UrbanConderController2_DW.SwitchCase_ActiveSubsystem;
  UrbanConderController2_DW.SwitchCase_ActiveSubsystem = -1;

  // Switch: '<S40>/Switch' incorporates:
  //   Constant: '<S40>/Constant'
  //   MATLAB Function: '<S40>/flight mode'

  if (UrbanConderController2_B.In1_m.manual_control_signal_lost) {
    UrbanConderController2_B.DataTypeConversion1 =
      UrbanConderController2_P.Constant_Value_iy;
  } else if ((UrbanConderController2_B.Modeswitch1 == 1.0) &&
             (UrbanConderController2_B.Modeswitch2 == 0.0)) {
    // MATLAB Function: '<S40>/flight mode'
    UrbanConderController2_B.DataTypeConversion1 = 3.0;
  } else if ((UrbanConderController2_B.Modeswitch1 == 2.0) &&
             (UrbanConderController2_B.Modeswitch2 == 0.0)) {
    // MATLAB Function: '<S40>/flight mode'
    UrbanConderController2_B.DataTypeConversion1 = 4.0;
  } else if ((UrbanConderController2_B.Modeswitch1 == 0.0) &&
             (UrbanConderController2_B.Modeswitch2 == 1.0)) {
    // MATLAB Function: '<S40>/flight mode'
    UrbanConderController2_B.DataTypeConversion1 = 5.0;
  } else if ((UrbanConderController2_B.Modeswitch1 == 0.0) &&
             (UrbanConderController2_B.Modeswitch2 == 2.0)) {
    // MATLAB Function: '<S40>/flight mode'
    UrbanConderController2_B.DataTypeConversion1 = 6.0;
  } else {
    UrbanConderController2_B.DataTypeConversion1 = 2.0;
  }

  // SwitchCase: '<S40>/Switch Case' incorporates:
  //   Switch: '<S40>/Switch'

  if (UrbanConderController2_B.DataTypeConversion1 < 0.0) {
    UrbanConderController2_B.DataTypeConversion1 = ceil
      (UrbanConderController2_B.DataTypeConversion1);
  } else {
    UrbanConderController2_B.DataTypeConversion1 = floor
      (UrbanConderController2_B.DataTypeConversion1);
  }

  if (rtIsNaN(UrbanConderController2_B.DataTypeConversion1) || rtIsInf
      (UrbanConderController2_B.DataTypeConversion1)) {
    UrbanConderController2_B.DataTypeConversion1 = 0.0;
  } else {
    UrbanConderController2_B.DataTypeConversion1 = fmod
      (UrbanConderController2_B.DataTypeConversion1, 4.294967296E+9);
  }

  switch (UrbanConderController2_B.DataTypeConversion1 < 0.0 ? -static_cast<
          int32_T>(static_cast<uint32_T>
                   (-UrbanConderController2_B.DataTypeConversion1)) :
          static_cast<int32_T>(static_cast<uint32_T>
           (UrbanConderController2_B.DataTypeConversion1))) {
   case 1:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case 2:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   case 3:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 2;
    break;

   case 4:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 3;
    break;

   case 5:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 4;
    break;

   case 6:
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = 5;
    break;
  }

  switch (UrbanConderController2_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (UrbanConderController2_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S9>/failsafe' incorporates:
      //   ActionPort: '<S39>/Action Port'

      // InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
      //   DiscreteIntegrator: '<S379>/Integrator'

      UrbanConderController2_DW.Integrator_DSTATE_o =
        UrbanConderController2_P.PIbankanglecontroller_InitialCo;

      // End of InitializeConditions for SubSystem: '<S9>/failsafe'
    }

    // Outputs for IfAction SubSystem: '<S9>/failsafe' incorporates:
    //   ActionPort: '<S39>/Action Port'

    // DataTypeConversion: '<S339>/Data Type Conversion1' incorporates:
    //   Constant: '<S339>/Constant2'
    //   Constant: '<S339>/Constant9'
    //   Sum: '<S339>/Add2'

    UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
      (UrbanConderController2_P.ail_max -
       UrbanConderController2_P.Constant9_Value);

    // Sum: '<S339>/Sum1' incorporates:
    //   Constant: '<S39>/Constant1'
    //   Gain: '<S340>/Gain1'

    UrbanConderController2_B.Flapswitch = UrbanConderController2_P.Gain1_Gain *
      UrbanConderController2_P.Constant1_Value - rtb_phi;

    // Sum: '<S389>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion27'
    //   DiscreteIntegrator: '<S379>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter27'
    //   Product: '<S384>/PProd Out'
    //
    UrbanConderController2_B.ParamStep_cv = static_cast<real32_T>
      (static_cast<real32_T>(UrbanConderController2_B.Flapswitch *
        UrbanConderController2_B.ParamStep_b) +
       UrbanConderController2_DW.Integrator_DSTATE_o);

    // DataTypeConversion: '<S339>/Data Type Conversion2' incorporates:
    //   Constant: '<S339>/Constant1'
    //   Constant: '<S339>/Constant11'
    //   Sum: '<S339>/Add3'

    UrbanConderController2_B.ParamStep_f = static_cast<real32_T>
      (UrbanConderController2_P.Constant11_Value -
       UrbanConderController2_P.ail_max);

    // Merge: '<S9>/Merge' incorporates:
    //   Constant: '<S39>/Constant'
    //   SignalConversion generated from: '<S39>/Failsafe cmds'

    UrbanConderController2_B.Merge[0] =
      UrbanConderController2_P.Constant_Value_pj;

    // Switch: '<S387>/Switch2' incorporates:
    //   RelationalOperator: '<S387>/LowerRelop1'
    //   RelationalOperator: '<S387>/UpperRelop'
    //   Switch: '<S387>/Switch'

    if (UrbanConderController2_B.ParamStep_cv >
        UrbanConderController2_B.ParamStep_p) {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_p;
    } else if (UrbanConderController2_B.ParamStep_cv <
               UrbanConderController2_B.ParamStep_f) {
      // Switch: '<S387>/Switch' incorporates:
      //   DataTypeConversion: '<S339>/Data Type Conversion2'

      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_f;
    } else {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_cv;
    }

    // Merge: '<S9>/Merge' incorporates:
    //   Constant: '<S39>/Constant2'
    //   Constant: '<S39>/Constant4'
    //   DataTypeConversion: '<S339>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   Gain: '<S339>/kp'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   SignalConversion generated from: '<S39>/Failsafe cmds'
    //   Sum: '<S339>/Sum'
    //   Sum: '<S339>/Sum3'
    //   Sum: '<S39>/Sum'
    //   Switch: '<S387>/Switch2'
    //
    UrbanConderController2_B.Merge[1] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_b - UrbanConderController2_P.kp_Gain *
       UrbanConderController2_B.In1_g.angular_velocity[0]) + ParamStep_0;
    UrbanConderController2_B.Merge[2] = ParamStep +
      UrbanConderController2_P.Constant2_Value;
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.ParamStep_g1;
    UrbanConderController2_B.Merge[4] = UrbanConderController2_P.Constant4_Value;

    // Switch: '<S371>/Switch' incorporates:
    //   RelationalOperator: '<S371>/u_GTE_up'

    if (!(UrbanConderController2_B.ParamStep_cv >=
          UrbanConderController2_B.ParamStep_p)) {
      // Switch: '<S371>/Switch1' incorporates:
      //   DataTypeConversion: '<S339>/Data Type Conversion2'
      //   RelationalOperator: '<S371>/u_GT_lo'

      if (UrbanConderController2_B.ParamStep_cv >
          UrbanConderController2_B.ParamStep_f) {
        UrbanConderController2_B.ParamStep_p =
          UrbanConderController2_B.ParamStep_cv;
      } else {
        UrbanConderController2_B.ParamStep_p =
          UrbanConderController2_B.ParamStep_f;
      }

      // End of Switch: '<S371>/Switch1'
    }

    // End of Switch: '<S371>/Switch'

    // Sum: '<S371>/Diff'
    UrbanConderController2_B.ParamStep_p = UrbanConderController2_B.ParamStep_cv
      - UrbanConderController2_B.ParamStep_p;

    // Product: '<S376>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion28'
    //   MATLABSystem: '<S5>/Read Parameter28'
    //
    UrbanConderController2_B.ParamStep_g1 = static_cast<real32_T>
      (UrbanConderController2_B.Flapswitch *
       UrbanConderController2_B.ParamStep_cx);

    // Switch: '<S368>/Switch1' incorporates:
    //   Constant: '<S368>/Clamping_zero'
    //   Constant: '<S368>/Constant'
    //   Constant: '<S368>/Constant2'
    //   RelationalOperator: '<S368>/fix for DT propagation issue'

    if (UrbanConderController2_B.ParamStep_p >
        UrbanConderController2_P.Clamping_zero_Value) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_n;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_b;
    }

    // Switch: '<S368>/Switch2' incorporates:
    //   Constant: '<S368>/Clamping_zero'
    //   Constant: '<S368>/Constant3'
    //   Constant: '<S368>/Constant4'
    //   RelationalOperator: '<S368>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_g1 >
        UrbanConderController2_P.Clamping_zero_Value) {
      tmp = UrbanConderController2_P.Constant3_Value_e;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_b;
    }

    // Switch: '<S368>/Switch' incorporates:
    //   Constant: '<S368>/Clamping_zero'
    //   Constant: '<S368>/Constant1'
    //   Logic: '<S368>/AND3'
    //   RelationalOperator: '<S368>/Equal1'
    //   RelationalOperator: '<S368>/Relational Operator'
    //   Switch: '<S368>/Switch1'
    //   Switch: '<S368>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value !=
         UrbanConderController2_B.ParamStep_p) && (rtPrevAction == tmp)) {
      UrbanConderController2_B.ParamStep_g1 =
        UrbanConderController2_P.Constant1_Value_a;
    }

    // Update for DiscreteIntegrator: '<S379>/Integrator' incorporates:
    //   Constant: '<S339>/Constant'
    //   Product: '<S393>/Uintegral*Ts Prod Out'
    //   Switch: '<S368>/Switch'

    UrbanConderController2_DW.Integrator_DSTATE_o +=
      UrbanConderController2_B.ParamStep_g1 *
      UrbanConderController2_P.Constant_Value_i *
      UrbanConderController2_P.Integrator_gainval;

    // End of Outputs for SubSystem: '<S9>/failsafe'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S9>/Manual' incorporates:
    //   ActionPort: '<S35>/Action Port'

    // Product: '<S35>/Product' incorporates:
    //   Constant: '<S35>/Constant'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[0] = UrbanConderController2_B.Throttlecmd *
      UrbanConderController2_P.thrust_max;

    // Sum: '<S35>/Sum' incorporates:
    //   Constant: '<S35>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   Gain: '<S35>/Gain'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   Merge: '<S9>/Merge'
    //   Product: '<S35>/Product1'
    //
    UrbanConderController2_B.Merge[1] = UrbanConderController2_P.Gain_Gain *
      UrbanConderController2_P.ail_max * UrbanConderController2_B.Rollcmd +
      ParamStep_0;

    // Sum: '<S35>/Sum1' incorporates:
    //   Constant: '<S35>/Constant2'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   Merge: '<S9>/Merge'
    //   Product: '<S35>/Product2'
    //
    UrbanConderController2_B.Merge[2] = UrbanConderController2_B.Pitchcmd *
      UrbanConderController2_P.ele_max + ParamStep;

    // Sum: '<S35>/Sum2' incorporates:
    //   Constant: '<S35>/Constant3'
    //   DataTypeConversion: '<S5>/Data Type Conversion23'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   Merge: '<S9>/Merge'
    //   Product: '<S35>/Product3'
    //
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.Yawcmd *
      UrbanConderController2_P.rud_max + UrbanConderController2_B.ParamStep_g1;

    // Product: '<S35>/Product4' incorporates:
    //   Constant: '<S35>/Constant4'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[4] = UrbanConderController2_B.Flapswitch *
      UrbanConderController2_P.flap_max;

    // End of Outputs for SubSystem: '<S9>/Manual'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S9>/Trimming' incorporates:
    //   ActionPort: '<S38>/Action Port'

    // Merge: '<S9>/Merge' incorporates:
    //   Constant: '<S38>/Constant1'
    //   Constant: '<S38>/Constant2'
    //   Constant: '<S38>/Constant3'
    //   Constant: '<S38>/Constant4'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   DataTypeConversion: '<S5>/Data Type Conversion23'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   Gain: '<S38>/Gain'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   MATLABSystem: '<S5>/Read Parameter21'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   Product: '<S38>/Product1'
    //   Product: '<S38>/Product2'
    //   Product: '<S38>/Product3'
    //   Product: '<S38>/Product4'
    //   SignalConversion generated from: '<S38>/Manual cmds'
    //   Sum: '<S38>/Sum'
    //   Sum: '<S38>/Sum1'
    //   Sum: '<S38>/Sum2'
    //
    UrbanConderController2_B.Merge[0] = ParamStep_1;
    UrbanConderController2_B.Merge[1] = UrbanConderController2_P.Gain_Gain_c *
      UrbanConderController2_P.ail_max * UrbanConderController2_B.Rollcmd +
      ParamStep_0;
    UrbanConderController2_B.Merge[2] = UrbanConderController2_B.Pitchcmd *
      UrbanConderController2_P.ele_max + ParamStep;
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.Yawcmd *
      UrbanConderController2_P.rud_max + UrbanConderController2_B.ParamStep_g1;
    UrbanConderController2_B.Merge[4] = UrbanConderController2_B.Flapswitch *
      UrbanConderController2_P.flap_max;

    // End of Outputs for SubSystem: '<S9>/Trimming'
    break;

   case 3:
    // Outputs for IfAction SubSystem: '<S9>/SAS' incorporates:
    //   ActionPort: '<S36>/Action Port'

    // Product: '<S36>/Product' incorporates:
    //   Constant: '<S36>/Constant'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[0] = UrbanConderController2_B.Throttlecmd *
      UrbanConderController2_P.thrust_max;

    // Sum: '<S36>/Sum' incorporates:
    //   Constant: '<S36>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   Gain: '<S36>/Gain'
    //   Gain: '<S36>/Gain2'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   Merge: '<S9>/Merge'
    //   Product: '<S36>/Product1'
    //   Sum: '<S36>/Sum4'
    //
    UrbanConderController2_B.Merge[1] = (UrbanConderController2_P.Gain2_Gain *
      UrbanConderController2_P.ail_max * UrbanConderController2_B.Rollcmd -
      UrbanConderController2_P.K_p *
      UrbanConderController2_B.In1_g.angular_velocity[0]) + ParamStep_0;

    // Sum: '<S36>/Sum1' incorporates:
    //   Constant: '<S36>/Constant2'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   Gain: '<S36>/Gain1'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   Merge: '<S9>/Merge'
    //   Product: '<S36>/Product2'
    //   Sum: '<S36>/Sum3'
    //
    UrbanConderController2_B.Merge[2] = (UrbanConderController2_B.Pitchcmd *
      UrbanConderController2_P.ele_max - UrbanConderController2_P.K_q *
      UrbanConderController2_B.In1_g.angular_velocity[1]) + ParamStep;

    // Sum: '<S36>/Sum2' incorporates:
    //   Constant: '<S36>/Constant3'
    //   DataTypeConversion: '<S5>/Data Type Conversion23'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   Merge: '<S9>/Merge'
    //   Product: '<S36>/Product3'
    //
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.Yawcmd *
      UrbanConderController2_P.rud_max + UrbanConderController2_B.ParamStep_g1;

    // Product: '<S36>/Product4' incorporates:
    //   Constant: '<S36>/Constant4'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[4] = UrbanConderController2_B.Flapswitch *
      UrbanConderController2_P.flap_max;

    // End of Outputs for SubSystem: '<S9>/SAS'
    break;

   case 4:
    if (UrbanConderController2_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S9>/Angle controller' incorporates:
      //   ActionPort: '<S34>/Action Port'

      // InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
      //   DiscreteIntegrator: '<S142>/Integrator'
      //   DiscreteIntegrator: '<S84>/Integrator'

      UrbanConderController2_DW.Integrator_DSTATE_i =
        UrbanConderController2_P.PIbankanglecontroller_Initial_p;
      UrbanConderController2_DW.Integrator_DSTATE_p =
        UrbanConderController2_P.PIpitchanglecontroller_InitialC;

      // End of InitializeConditions for SubSystem: '<S9>/Angle controller'
    }

    // Outputs for IfAction SubSystem: '<S9>/Angle controller' incorporates:
    //   ActionPort: '<S34>/Action Port'

    // DataTypeConversion: '<S41>/Data Type Conversion1' incorporates:
    //   Constant: '<S41>/Constant2'
    //   Constant: '<S41>/Constant9'
    //   Sum: '<S41>/Add2'

    ParamStep_1 = static_cast<real32_T>(UrbanConderController2_P.ail_max -
      UrbanConderController2_P.Constant9_Value_c);

    // Sum: '<S41>/Sum1' incorporates:
    //   Constant: '<S34>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion36'
    //   Gain: '<S42>/Gain1'
    //   Gain: '<S45>/Gain1'
    //   MATLABSystem: '<S5>/Read Parameter36'
    //   Product: '<S34>/Product2'
    //   Sum: '<S41>/Sum2'
    //
    UrbanConderController2_B.DataTypeConversion1 =
      (UrbanConderController2_P.Gain1_Gain_g * UrbanConderController2_P.phi_max *
       UrbanConderController2_B.Rollcmd + UrbanConderController2_P.Gain1_Gain_gn
       * UrbanConderController2_B.ParamStep_g) - rtb_phi;

    // Sum: '<S94>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion27'
    //   DiscreteIntegrator: '<S84>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter27'
    //   Product: '<S89>/PProd Out'
    //
    rtb_Sum_f = static_cast<real32_T>(static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_b) +
      UrbanConderController2_DW.Integrator_DSTATE_i);

    // DataTypeConversion: '<S41>/Data Type Conversion2' incorporates:
    //   Constant: '<S41>/Constant1'
    //   Constant: '<S41>/Constant11'
    //   Sum: '<S41>/Add3'

    UrbanConderController2_B.ParamStep_c = static_cast<real32_T>
      (UrbanConderController2_P.Constant11_Value_b -
       UrbanConderController2_P.ail_max);

    // Switch: '<S92>/Switch2' incorporates:
    //   RelationalOperator: '<S92>/LowerRelop1'
    //   RelationalOperator: '<S92>/UpperRelop'
    //   Switch: '<S92>/Switch'

    if (rtb_Sum_f > ParamStep_1) {
      UrbanConderController2_B.ParamStep_b = ParamStep_1;
    } else if (rtb_Sum_f < UrbanConderController2_B.ParamStep_c) {
      // Switch: '<S92>/Switch' incorporates:
      //   DataTypeConversion: '<S41>/Data Type Conversion2'

      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_c;
    } else {
      UrbanConderController2_B.ParamStep_b = rtb_Sum_f;
    }

    // Sum: '<S41>/Sum' incorporates:
    //   DataTypeConversion: '<S41>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   Gain: '<S41>/kp'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   Merge: '<S9>/Merge'
    //   Sum: '<S41>/Sum3'
    //   Switch: '<S92>/Switch2'
    //
    UrbanConderController2_B.Merge[1] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_b - UrbanConderController2_P.K_p *
       UrbanConderController2_B.In1_g.angular_velocity[0]) + ParamStep_0;

    // Switch: '<S76>/Switch' incorporates:
    //   RelationalOperator: '<S76>/u_GTE_up'

    if (!(rtb_Sum_f >= ParamStep_1)) {
      // Switch: '<S76>/Switch1' incorporates:
      //   DataTypeConversion: '<S41>/Data Type Conversion2'
      //   RelationalOperator: '<S76>/u_GT_lo'

      if (rtb_Sum_f > UrbanConderController2_B.ParamStep_c) {
        ParamStep_1 = rtb_Sum_f;
      } else {
        ParamStep_1 = UrbanConderController2_B.ParamStep_c;
      }

      // End of Switch: '<S76>/Switch1'
    }

    // End of Switch: '<S76>/Switch'

    // Sum: '<S76>/Diff'
    ParamStep_1 = rtb_Sum_f - ParamStep_1;

    // Product: '<S81>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion28'
    //   MATLABSystem: '<S5>/Read Parameter28'
    //
    UrbanConderController2_B.ParamStep_cx = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_cx);

    // Switch: '<S73>/Switch1' incorporates:
    //   Constant: '<S73>/Clamping_zero'
    //   Constant: '<S73>/Constant'
    //   Constant: '<S73>/Constant2'
    //   RelationalOperator: '<S73>/fix for DT propagation issue'

    if (ParamStep_1 > UrbanConderController2_P.Clamping_zero_Value_e) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_ex;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_c;
    }

    // Switch: '<S73>/Switch2' incorporates:
    //   Constant: '<S73>/Clamping_zero'
    //   Constant: '<S73>/Constant3'
    //   Constant: '<S73>/Constant4'
    //   RelationalOperator: '<S73>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_cx >
        UrbanConderController2_P.Clamping_zero_Value_e) {
      tmp = UrbanConderController2_P.Constant3_Value_p;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_h;
    }

    // Switch: '<S73>/Switch' incorporates:
    //   Constant: '<S73>/Clamping_zero'
    //   Constant: '<S73>/Constant1'
    //   Logic: '<S73>/AND3'
    //   RelationalOperator: '<S73>/Equal1'
    //   RelationalOperator: '<S73>/Relational Operator'
    //   Switch: '<S73>/Switch1'
    //   Switch: '<S73>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value_e != ParamStep_1) &&
        (rtPrevAction == tmp)) {
      ParamStep_0 = UrbanConderController2_P.Constant1_Value_g0;
    } else {
      ParamStep_0 = UrbanConderController2_B.ParamStep_cx;
    }

    // End of Switch: '<S73>/Switch'

    // Sum: '<S44>/Sum' incorporates:
    //   Constant: '<S34>/Constant2'
    //   DataTypeConversion: '<S5>/Data Type Conversion37'
    //   Gain: '<S103>/Gain1'
    //   Gain: '<S34>/Gain1'
    //   Gain: '<S43>/Gain1'
    //   MATLABSystem: '<S5>/Read Parameter37'
    //   Product: '<S34>/Product3'
    //   Sum: '<S44>/Sum3'
    //
    UrbanConderController2_B.DataTypeConversion1 =
      (UrbanConderController2_P.Gain1_Gain_i *
       UrbanConderController2_P.theta_max *
       UrbanConderController2_P.Gain1_Gain_o * UrbanConderController2_B.Pitchcmd
       + UrbanConderController2_P.Gain1_Gain_h *
       UrbanConderController2_B.ParamStep_f) - rtb_theta;

    // Product: '<S139>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion26'
    //   MATLABSystem: '<S5>/Read Parameter26'
    //
    UrbanConderController2_B.ParamStep_cx = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_p);

    // Sum: '<S152>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion25'
    //   DiscreteIntegrator: '<S142>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter25'
    //   Product: '<S147>/PProd Out'
    //
    UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
      (static_cast<real32_T>(UrbanConderController2_B.DataTypeConversion1 *
        UrbanConderController2_B.ParamStep_cv) +
       UrbanConderController2_DW.Integrator_DSTATE_p);

    // DataTypeConversion: '<S44>/Data Type Conversion2' incorporates:
    //   Constant: '<S44>/Constant'
    //   Constant: '<S44>/Constant4'
    //   Sum: '<S44>/Add'

    UrbanConderController2_B.ParamStep_cv = static_cast<real32_T>
      (UrbanConderController2_P.ele_max -
       UrbanConderController2_P.Constant4_Value_m);

    // Sum: '<S44>/Add1' incorporates:
    //   Constant: '<S44>/Constant5'
    //   Constant: '<S44>/Constant6'

    UrbanConderController2_B.DataTypeConversion1 =
      UrbanConderController2_P.Constant6_Value -
      UrbanConderController2_P.ele_max;

    // Switch: '<S134>/Switch' incorporates:
    //   DataTypeConversion: '<S44>/Data Type Conversion'
    //   RelationalOperator: '<S134>/u_GTE_up'
    //   RelationalOperator: '<S134>/u_GT_lo'
    //   Sum: '<S44>/Add1'
    //   Switch: '<S134>/Switch1'

    if (UrbanConderController2_B.ParamStep_p >=
        UrbanConderController2_B.ParamStep_cv) {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_cv;
    } else if (UrbanConderController2_B.ParamStep_p > static_cast<real32_T>
               (UrbanConderController2_B.DataTypeConversion1)) {
      // Switch: '<S134>/Switch1'
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_p;
    } else {
      UrbanConderController2_B.ParamStep_b = static_cast<real32_T>
        (UrbanConderController2_B.DataTypeConversion1);
    }

    // Sum: '<S134>/Diff' incorporates:
    //   Switch: '<S134>/Switch'

    ParamStep_1 = UrbanConderController2_B.ParamStep_p -
      UrbanConderController2_B.ParamStep_b;

    // Switch: '<S150>/Switch2' incorporates:
    //   RelationalOperator: '<S150>/LowerRelop1'

    if (!(UrbanConderController2_B.ParamStep_p >
          UrbanConderController2_B.ParamStep_cv)) {
      // Switch: '<S150>/Switch' incorporates:
      //   DataTypeConversion: '<S44>/Data Type Conversion'
      //   RelationalOperator: '<S150>/UpperRelop'
      //   Sum: '<S44>/Add1'

      if (UrbanConderController2_B.ParamStep_p < static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1)) {
        UrbanConderController2_B.ParamStep_cv = static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1);
      } else {
        UrbanConderController2_B.ParamStep_cv =
          UrbanConderController2_B.ParamStep_p;
      }

      // End of Switch: '<S150>/Switch'
    }

    // End of Switch: '<S150>/Switch2'

    // Sum: '<S44>/Sum1' incorporates:
    //   DataTypeConversion: '<S44>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   Gain: '<S44>/kq'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   Merge: '<S9>/Merge'
    //   Sum: '<S44>/Sum2'
    //
    UrbanConderController2_B.Merge[2] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_cv - UrbanConderController2_P.K_q *
       UrbanConderController2_B.In1_g.angular_velocity[1]) + ParamStep;

    // Product: '<S34>/Product1' incorporates:
    //   Constant: '<S34>/Constant'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[0] = UrbanConderController2_B.Throttlecmd *
      UrbanConderController2_P.thrust_max;

    // Sum: '<S34>/Sum' incorporates:
    //   Constant: '<S34>/Constant3'
    //   DataTypeConversion: '<S5>/Data Type Conversion23'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   Merge: '<S9>/Merge'
    //   Product: '<S34>/Product4'
    //
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.Yawcmd *
      UrbanConderController2_P.rud_max + UrbanConderController2_B.ParamStep_g1;

    // Product: '<S34>/Product5' incorporates:
    //   Constant: '<S34>/Constant4'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[4] = UrbanConderController2_B.Flapswitch *
      UrbanConderController2_P.flap_max;

    // Update for DiscreteIntegrator: '<S84>/Integrator' incorporates:
    //   Constant: '<S41>/Constant'
    //   Product: '<S98>/Uintegral*Ts Prod Out'

    UrbanConderController2_DW.Integrator_DSTATE_i += ParamStep_0 *
      UrbanConderController2_P.Constant_Value_j *
      UrbanConderController2_P.Integrator_gainval_a;

    // Switch: '<S131>/Switch1' incorporates:
    //   Constant: '<S131>/Clamping_zero'
    //   Constant: '<S131>/Constant'
    //   Constant: '<S131>/Constant2'
    //   RelationalOperator: '<S131>/fix for DT propagation issue'

    if (ParamStep_1 > UrbanConderController2_P.Clamping_zero_Value_a) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_jn;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_m;
    }

    // Switch: '<S131>/Switch2' incorporates:
    //   Constant: '<S131>/Clamping_zero'
    //   Constant: '<S131>/Constant3'
    //   Constant: '<S131>/Constant4'
    //   RelationalOperator: '<S131>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_cx >
        UrbanConderController2_P.Clamping_zero_Value_a) {
      tmp = UrbanConderController2_P.Constant3_Value_k;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_ha;
    }

    // Switch: '<S131>/Switch' incorporates:
    //   Constant: '<S131>/Clamping_zero'
    //   Constant: '<S131>/Constant1'
    //   Logic: '<S131>/AND3'
    //   RelationalOperator: '<S131>/Equal1'
    //   RelationalOperator: '<S131>/Relational Operator'
    //   Switch: '<S131>/Switch1'
    //   Switch: '<S131>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value_a != ParamStep_1) &&
        (rtPrevAction == tmp)) {
      UrbanConderController2_B.ParamStep_cx =
        UrbanConderController2_P.Constant1_Value_h2;
    }

    // Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
    //   Constant: '<S44>/Constant1'
    //   Product: '<S156>/Uintegral*Ts Prod Out'
    //   Switch: '<S131>/Switch'

    UrbanConderController2_DW.Integrator_DSTATE_p +=
      UrbanConderController2_B.ParamStep_cx *
      UrbanConderController2_P.Constant1_Value_g *
      UrbanConderController2_P.Integrator_gainval_f;

    // End of Outputs for SubSystem: '<S9>/Angle controller'
    break;

   case 5:
    if (UrbanConderController2_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S9>/Speed controller ' incorporates:
      //   ActionPort: '<S37>/Action Port'

      // InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
      //   DiscreteIntegrator: '<S205>/Integrator'
      //   DiscreteIntegrator: '<S263>/Integrator'
      //   DiscreteIntegrator: '<S320>/Integrator'

      UrbanConderController2_DW.Integrator_DSTATE =
        UrbanConderController2_P.PIbankanglecontroller_Initial_k;
      UrbanConderController2_DW.Integrator_DSTATE_a =
        UrbanConderController2_P.PIpitchanglecontroller_Initia_f;
      UrbanConderController2_DW.Integrator_DSTATE_h =
        UrbanConderController2_P.PIspeedcontroller_InitialCondit;

      // End of InitializeConditions for SubSystem: '<S9>/Speed controller '
    }

    // Outputs for IfAction SubSystem: '<S9>/Speed controller ' incorporates:
    //   ActionPort: '<S37>/Action Port'

    // DataTypeConversion: '<S161>/Data Type Conversion1' incorporates:
    //   Constant: '<S161>/Constant2'
    //   Constant: '<S161>/Constant9'
    //   Sum: '<S161>/Add2'

    rtb_Sum_f = static_cast<real32_T>(UrbanConderController2_P.ail_max -
      UrbanConderController2_P.Constant9_Value_m);

    // Sum: '<S161>/Sum1' incorporates:
    //   Constant: '<S37>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion36'
    //   Gain: '<S163>/Gain1'
    //   Gain: '<S166>/Gain1'
    //   MATLABSystem: '<S5>/Read Parameter36'
    //   Product: '<S37>/Product4'
    //   Sum: '<S161>/Sum2'
    //
    UrbanConderController2_B.DataTypeConversion1 =
      (UrbanConderController2_P.Gain1_Gain_a * UrbanConderController2_P.phi_max *
       UrbanConderController2_B.Rollcmd + UrbanConderController2_P.Gain1_Gain_c *
       UrbanConderController2_B.ParamStep_g) - rtb_phi;

    // Sum: '<S215>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion27'
    //   DiscreteIntegrator: '<S205>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter27'
    //   Product: '<S210>/PProd Out'
    //
    UrbanConderController2_B.ParamStep_g = static_cast<real32_T>
      (static_cast<real32_T>(UrbanConderController2_B.DataTypeConversion1 *
        UrbanConderController2_B.ParamStep_b) +
       UrbanConderController2_DW.Integrator_DSTATE);

    // DataTypeConversion: '<S161>/Data Type Conversion2' incorporates:
    //   Constant: '<S161>/Constant1'
    //   Constant: '<S161>/Constant11'
    //   Sum: '<S161>/Add3'

    rtb_DataTypeConversion2_p_tmp = static_cast<real32_T>
      (UrbanConderController2_P.Constant11_Value_g -
       UrbanConderController2_P.ail_max);

    // Switch: '<S213>/Switch2' incorporates:
    //   RelationalOperator: '<S213>/LowerRelop1'
    //   RelationalOperator: '<S213>/UpperRelop'
    //   Switch: '<S213>/Switch'

    if (UrbanConderController2_B.ParamStep_g > rtb_Sum_f) {
      UrbanConderController2_B.ParamStep_b = rtb_Sum_f;
    } else if (UrbanConderController2_B.ParamStep_g <
               rtb_DataTypeConversion2_p_tmp) {
      // Switch: '<S213>/Switch' incorporates:
      //   DataTypeConversion: '<S161>/Data Type Conversion2'

      UrbanConderController2_B.ParamStep_b = rtb_DataTypeConversion2_p_tmp;
    } else {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_g;
    }

    // Sum: '<S161>/Sum' incorporates:
    //   DataTypeConversion: '<S161>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion20'
    //   Gain: '<S161>/kp'
    //   MATLABSystem: '<S5>/Read Parameter20'
    //   Merge: '<S9>/Merge'
    //   Sum: '<S161>/Sum3'
    //   Switch: '<S213>/Switch2'
    //
    UrbanConderController2_B.Merge[1] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_b - UrbanConderController2_P.K_p *
       UrbanConderController2_B.In1_g.angular_velocity[0]) + ParamStep_0;

    // Switch: '<S197>/Switch' incorporates:
    //   RelationalOperator: '<S197>/u_GTE_up'

    if (!(UrbanConderController2_B.ParamStep_g >= rtb_Sum_f)) {
      // Switch: '<S197>/Switch1' incorporates:
      //   DataTypeConversion: '<S161>/Data Type Conversion2'
      //   RelationalOperator: '<S197>/u_GT_lo'

      if (UrbanConderController2_B.ParamStep_g > rtb_DataTypeConversion2_p_tmp)
      {
        rtb_Sum_f = UrbanConderController2_B.ParamStep_g;
      } else {
        rtb_Sum_f = rtb_DataTypeConversion2_p_tmp;
      }

      // End of Switch: '<S197>/Switch1'
    }

    // End of Switch: '<S197>/Switch'

    // Sum: '<S197>/Diff'
    rtb_Sum_f = UrbanConderController2_B.ParamStep_g - rtb_Sum_f;

    // Product: '<S202>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion28'
    //   MATLABSystem: '<S5>/Read Parameter28'
    //
    UrbanConderController2_B.ParamStep_cx = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_cx);

    // Switch: '<S194>/Switch1' incorporates:
    //   Constant: '<S194>/Clamping_zero'
    //   Constant: '<S194>/Constant'
    //   Constant: '<S194>/Constant2'
    //   RelationalOperator: '<S194>/fix for DT propagation issue'

    if (rtb_Sum_f > UrbanConderController2_P.Clamping_zero_Value_j) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_lx;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_d;
    }

    // Switch: '<S194>/Switch2' incorporates:
    //   Constant: '<S194>/Clamping_zero'
    //   Constant: '<S194>/Constant3'
    //   Constant: '<S194>/Constant4'
    //   RelationalOperator: '<S194>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_cx >
        UrbanConderController2_P.Clamping_zero_Value_j) {
      tmp = UrbanConderController2_P.Constant3_Value_m;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_hz;
    }

    // Switch: '<S194>/Switch' incorporates:
    //   Constant: '<S194>/Clamping_zero'
    //   Constant: '<S194>/Constant1'
    //   Logic: '<S194>/AND3'
    //   RelationalOperator: '<S194>/Equal1'
    //   RelationalOperator: '<S194>/Relational Operator'
    //   Switch: '<S194>/Switch1'
    //   Switch: '<S194>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value_j != rtb_Sum_f) &&
        (rtPrevAction == tmp)) {
      ParamStep_0 = UrbanConderController2_P.Constant1_Value_i;
    } else {
      ParamStep_0 = UrbanConderController2_B.ParamStep_cx;
    }

    // End of Switch: '<S194>/Switch'

    // Sum: '<S164>/Sum' incorporates:
    //   Constant: '<S37>/Constant2'
    //   DataTypeConversion: '<S5>/Data Type Conversion37'
    //   Gain: '<S162>/Gain1'
    //   Gain: '<S224>/Gain1'
    //   Gain: '<S37>/Gain1'
    //   MATLABSystem: '<S5>/Read Parameter37'
    //   Product: '<S37>/Product5'
    //   Sum: '<S164>/Sum3'
    //
    UrbanConderController2_B.DataTypeConversion1 =
      (UrbanConderController2_P.Gain1_Gain_e *
       UrbanConderController2_P.theta_max *
       UrbanConderController2_P.Gain1_Gain_k * UrbanConderController2_B.Pitchcmd
       + UrbanConderController2_P.Gain1_Gain_ia *
       UrbanConderController2_B.ParamStep_f) - rtb_theta;

    // Product: '<S260>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion26'
    //   MATLABSystem: '<S5>/Read Parameter26'
    //
    UrbanConderController2_B.ParamStep_cx = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_p);

    // Sum: '<S273>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion25'
    //   DiscreteIntegrator: '<S263>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter25'
    //   Product: '<S268>/PProd Out'
    //
    UrbanConderController2_B.ParamStep_f = static_cast<real32_T>
      (static_cast<real32_T>(UrbanConderController2_B.DataTypeConversion1 *
        UrbanConderController2_B.ParamStep_cv) +
       UrbanConderController2_DW.Integrator_DSTATE_a);

    // DataTypeConversion: '<S164>/Data Type Conversion2' incorporates:
    //   Constant: '<S164>/Constant'
    //   Constant: '<S164>/Constant4'
    //   Sum: '<S164>/Add'

    UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
      (UrbanConderController2_P.ele_max -
       UrbanConderController2_P.Constant4_Value_d);

    // Sum: '<S164>/Add1' incorporates:
    //   Constant: '<S164>/Constant5'
    //   Constant: '<S164>/Constant6'

    UrbanConderController2_B.DataTypeConversion1 =
      UrbanConderController2_P.Constant6_Value_b -
      UrbanConderController2_P.ele_max;

    // Switch: '<S255>/Switch' incorporates:
    //   DataTypeConversion: '<S164>/Data Type Conversion'
    //   RelationalOperator: '<S255>/u_GTE_up'
    //   RelationalOperator: '<S255>/u_GT_lo'
    //   Sum: '<S164>/Add1'
    //   Switch: '<S255>/Switch1'

    if (UrbanConderController2_B.ParamStep_f >=
        UrbanConderController2_B.ParamStep_p) {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_p;
    } else if (UrbanConderController2_B.ParamStep_f > static_cast<real32_T>
               (UrbanConderController2_B.DataTypeConversion1)) {
      // Switch: '<S255>/Switch1'
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_f;
    } else {
      UrbanConderController2_B.ParamStep_b = static_cast<real32_T>
        (UrbanConderController2_B.DataTypeConversion1);
    }

    // Sum: '<S255>/Diff' incorporates:
    //   Switch: '<S255>/Switch'

    rtb_Sum_f = UrbanConderController2_B.ParamStep_f -
      UrbanConderController2_B.ParamStep_b;

    // Switch: '<S252>/Switch1' incorporates:
    //   Constant: '<S252>/Clamping_zero'
    //   Constant: '<S252>/Constant'
    //   Constant: '<S252>/Constant2'
    //   RelationalOperator: '<S252>/fix for DT propagation issue'

    if (rtb_Sum_f > UrbanConderController2_P.Clamping_zero_Value_b) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_ei;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_f;
    }

    // Switch: '<S252>/Switch2' incorporates:
    //   Constant: '<S252>/Clamping_zero'
    //   Constant: '<S252>/Constant3'
    //   Constant: '<S252>/Constant4'
    //   RelationalOperator: '<S252>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_cx >
        UrbanConderController2_P.Clamping_zero_Value_b) {
      tmp = UrbanConderController2_P.Constant3_Value_f;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_a;
    }

    // Switch: '<S252>/Switch' incorporates:
    //   Constant: '<S252>/Clamping_zero'
    //   Constant: '<S252>/Constant1'
    //   Logic: '<S252>/AND3'
    //   RelationalOperator: '<S252>/Equal1'
    //   RelationalOperator: '<S252>/Relational Operator'
    //   Switch: '<S252>/Switch1'
    //   Switch: '<S252>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value_b != rtb_Sum_f) &&
        (rtPrevAction == tmp)) {
      UrbanConderController2_B.ParamStep_cv =
        UrbanConderController2_P.Constant1_Value_k;
    } else {
      UrbanConderController2_B.ParamStep_cv =
        UrbanConderController2_B.ParamStep_cx;
    }

    // End of Switch: '<S252>/Switch'

    // Switch: '<S271>/Switch2' incorporates:
    //   RelationalOperator: '<S271>/LowerRelop1'

    if (!(UrbanConderController2_B.ParamStep_f >
          UrbanConderController2_B.ParamStep_p)) {
      // Switch: '<S271>/Switch' incorporates:
      //   DataTypeConversion: '<S164>/Data Type Conversion'
      //   RelationalOperator: '<S271>/UpperRelop'
      //   Sum: '<S164>/Add1'

      if (UrbanConderController2_B.ParamStep_f < static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1)) {
        UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1);
      } else {
        UrbanConderController2_B.ParamStep_p =
          UrbanConderController2_B.ParamStep_f;
      }

      // End of Switch: '<S271>/Switch'
    }

    // End of Switch: '<S271>/Switch2'

    // Sum: '<S164>/Sum1' incorporates:
    //   DataTypeConversion: '<S164>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   Gain: '<S164>/kq'
    //   MATLABSystem: '<S5>/Read Parameter4'
    //   Merge: '<S9>/Merge'
    //   Sum: '<S164>/Sum2'
    //
    UrbanConderController2_B.Merge[2] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_p - UrbanConderController2_P.K_q *
       UrbanConderController2_B.In1_g.angular_velocity[1]) + ParamStep;

    // Sum: '<S165>/Sum' incorporates:
    //   Constant: '<S37>/Constant'
    //   Constant: '<S37>/Constant5'
    //   Product: '<S37>/Product3'
    //   Sum: '<S37>/Sum'

    UrbanConderController2_B.DataTypeConversion1 =
      (UrbanConderController2_B.Throttlecmd *
       UrbanConderController2_P.Constant_Value_cs +
       UrbanConderController2_P.Constant5_Value) -
      UrbanConderController2_B.In1_a.true_airspeed_m_s;

    // Product: '<S317>/IProd Out' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion30'
    //   MATLABSystem: '<S5>/Read Parameter30'
    //
    UrbanConderController2_B.ParamStep_cx = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_c);

    // Sum: '<S330>/Sum' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion29'
    //   DiscreteIntegrator: '<S320>/Integrator'
    //   MATLABSystem: '<S5>/Read Parameter29'
    //   Product: '<S325>/PProd Out'
    //
    ParamStep = static_cast<real32_T>(static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1 *
       UrbanConderController2_B.ParamStep_k) +
      UrbanConderController2_DW.Integrator_DSTATE_h);

    // DataTypeConversion: '<S165>/Data Type Conversion' incorporates:
    //   Constant: '<S165>/Constant'
    //   DataTypeConversion: '<S5>/Data Type Conversion21'
    //   MATLABSystem: '<S5>/Read Parameter21'
    //   Sum: '<S165>/Sum1'
    //
    UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
      (UrbanConderController2_P.thrust_max - ParamStep_1);

    // Sum: '<S165>/Sum2' incorporates:
    //   Constant: '<S165>/Constant2'
    //   DataTypeConversion: '<S5>/Data Type Conversion21'
    //   MATLABSystem: '<S5>/Read Parameter21'
    //
    UrbanConderController2_B.DataTypeConversion1 =
      UrbanConderController2_P.Constant2_Value_n - ParamStep_1;

    // Switch: '<S312>/Switch' incorporates:
    //   DataTypeConversion: '<S165>/Data Type Conversion1'
    //   RelationalOperator: '<S312>/u_GTE_up'
    //   RelationalOperator: '<S312>/u_GT_lo'
    //   Sum: '<S165>/Sum2'
    //   Switch: '<S312>/Switch1'

    if (ParamStep >= UrbanConderController2_B.ParamStep_p) {
      UrbanConderController2_B.ParamStep_b =
        UrbanConderController2_B.ParamStep_p;
    } else if (ParamStep > static_cast<real32_T>
               (UrbanConderController2_B.DataTypeConversion1)) {
      // Switch: '<S312>/Switch1'
      UrbanConderController2_B.ParamStep_b = ParamStep;
    } else {
      UrbanConderController2_B.ParamStep_b = static_cast<real32_T>
        (UrbanConderController2_B.DataTypeConversion1);
    }

    // Sum: '<S312>/Diff' incorporates:
    //   Switch: '<S312>/Switch'

    rtb_Sum_f = ParamStep - UrbanConderController2_B.ParamStep_b;

    // Switch: '<S328>/Switch2' incorporates:
    //   RelationalOperator: '<S328>/LowerRelop1'

    if (!(ParamStep > UrbanConderController2_B.ParamStep_p)) {
      // Switch: '<S328>/Switch' incorporates:
      //   DataTypeConversion: '<S165>/Data Type Conversion1'
      //   RelationalOperator: '<S328>/UpperRelop'
      //   Sum: '<S165>/Sum2'

      if (ParamStep < static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1)) {
        UrbanConderController2_B.ParamStep_p = static_cast<real32_T>
          (UrbanConderController2_B.DataTypeConversion1);
      } else {
        UrbanConderController2_B.ParamStep_p = ParamStep;
      }

      // End of Switch: '<S328>/Switch'
    }

    // End of Switch: '<S328>/Switch2'

    // Sum: '<S165>/Sum3' incorporates:
    //   DataTypeConversion: '<S165>/Data Type Conversion2'
    //   DataTypeConversion: '<S5>/Data Type Conversion21'
    //   MATLABSystem: '<S5>/Read Parameter21'
    //   Merge: '<S9>/Merge'
    //
    UrbanConderController2_B.Merge[0] = static_cast<real_T>
      (UrbanConderController2_B.ParamStep_p) + ParamStep_1;

    // Sum: '<S37>/Sum1' incorporates:
    //   Constant: '<S37>/Constant3'
    //   DataTypeConversion: '<S5>/Data Type Conversion23'
    //   MATLABSystem: '<S5>/Read Parameter23'
    //   Merge: '<S9>/Merge'
    //   Product: '<S37>/Product6'
    //
    UrbanConderController2_B.Merge[3] = UrbanConderController2_B.Yawcmd *
      UrbanConderController2_P.rud_max + UrbanConderController2_B.ParamStep_g1;

    // Product: '<S37>/Product7' incorporates:
    //   Constant: '<S37>/Constant4'
    //   Merge: '<S9>/Merge'

    UrbanConderController2_B.Merge[4] = UrbanConderController2_B.Flapswitch *
      UrbanConderController2_P.flap_max;

    // Update for DiscreteIntegrator: '<S205>/Integrator' incorporates:
    //   Constant: '<S161>/Constant'
    //   Product: '<S219>/Uintegral*Ts Prod Out'

    UrbanConderController2_DW.Integrator_DSTATE += ParamStep_0 *
      UrbanConderController2_P.Constant_Value_os *
      UrbanConderController2_P.Integrator_gainval_j;

    // Update for DiscreteIntegrator: '<S263>/Integrator' incorporates:
    //   Constant: '<S164>/Constant1'
    //   Product: '<S277>/Uintegral*Ts Prod Out'

    UrbanConderController2_DW.Integrator_DSTATE_a +=
      UrbanConderController2_B.ParamStep_cv *
      UrbanConderController2_P.Constant1_Value_m *
      UrbanConderController2_P.Integrator_gainval_g;

    // Switch: '<S309>/Switch1' incorporates:
    //   Constant: '<S309>/Clamping_zero'
    //   Constant: '<S309>/Constant'
    //   Constant: '<S309>/Constant2'
    //   RelationalOperator: '<S309>/fix for DT propagation issue'

    if (rtb_Sum_f > UrbanConderController2_P.Clamping_zero_Value_d) {
      rtPrevAction = UrbanConderController2_P.Constant_Value_d;
    } else {
      rtPrevAction = UrbanConderController2_P.Constant2_Value_e;
    }

    // Switch: '<S309>/Switch2' incorporates:
    //   Constant: '<S309>/Clamping_zero'
    //   Constant: '<S309>/Constant3'
    //   Constant: '<S309>/Constant4'
    //   RelationalOperator: '<S309>/fix for DT propagation issue1'

    if (UrbanConderController2_B.ParamStep_cx >
        UrbanConderController2_P.Clamping_zero_Value_d) {
      tmp = UrbanConderController2_P.Constant3_Value_l;
    } else {
      tmp = UrbanConderController2_P.Constant4_Value_bb;
    }

    // Switch: '<S309>/Switch' incorporates:
    //   Constant: '<S309>/Clamping_zero'
    //   Constant: '<S309>/Constant1'
    //   Logic: '<S309>/AND3'
    //   RelationalOperator: '<S309>/Equal1'
    //   RelationalOperator: '<S309>/Relational Operator'
    //   Switch: '<S309>/Switch1'
    //   Switch: '<S309>/Switch2'

    if ((UrbanConderController2_P.Clamping_zero_Value_d != rtb_Sum_f) &&
        (rtPrevAction == tmp)) {
      UrbanConderController2_B.ParamStep_cx =
        UrbanConderController2_P.Constant1_Value_f;
    }

    // Update for DiscreteIntegrator: '<S320>/Integrator' incorporates:
    //   Constant: '<S165>/Constant4'
    //   Product: '<S334>/Uintegral*Ts Prod Out'
    //   Switch: '<S309>/Switch'

    UrbanConderController2_DW.Integrator_DSTATE_h +=
      UrbanConderController2_B.ParamStep_cx *
      UrbanConderController2_P.Constant4_Value_mx *
      UrbanConderController2_P.Integrator_gainval_d;

    // End of Outputs for SubSystem: '<S9>/Speed controller '
    break;
  }

  // Product: '<S1>/Product1' incorporates:
  //   Constant: '<S1>/Constant1'

  UrbanConderController2_B.Flapswitch = 1.0 /
    UrbanConderController2_P.thrust_max * UrbanConderController2_B.Merge[0];

  // Saturate: '<S1>/Saturation'
  if (UrbanConderController2_B.Flapswitch >
      UrbanConderController2_P.Saturation_UpperSat_d) {
    UrbanConderController2_B.Flapswitch =
      UrbanConderController2_P.Saturation_UpperSat_d;
  } else if (UrbanConderController2_B.Flapswitch <
             UrbanConderController2_P.Saturation_LowerSat_g) {
    UrbanConderController2_B.Flapswitch =
      UrbanConderController2_P.Saturation_LowerSat_g;
  }

  // End of Saturate: '<S1>/Saturation'

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  UrbanConderController2_B.ParamStep_g1 = static_cast<real32_T>
    (UrbanConderController2_B.Flapswitch);

  // PreLookup: '<S1>/Right Aileron Angles'
  rtb_ElevatorAngles_o1 = plook_binx(UrbanConderController2_B.Merge[1],
    UrbanConderController2_P.ail_right_pos_deg, 20U,
    &UrbanConderController2_B.Flapswitch);

  // Interpolation_n-D: '<S1>/Actuator Signal2'
  UrbanConderController2_B.DataTypeConversion1 = intrp1d_l_pw
    (rtb_ElevatorAngles_o1, UrbanConderController2_B.Flapswitch,
     UrbanConderController2_P.servo_signal_pos);

  // Gain: '<S1>/Gain1'
  UrbanConderController2_B.Flapswitch = UrbanConderController2_P.Gain1_Gain_l *
    UrbanConderController2_B.Merge[1];

  // PreLookup: '<S1>/Left Aileron Angles'
  rtb_ElevatorAngles_o1 = plook_binx(UrbanConderController2_B.Flapswitch,
    UrbanConderController2_P.ail_left_pos_deg, 20U,
    &UrbanConderController2_B.Flapswitch);

  // Interpolation_n-D: '<S1>/Actuator Signal1'
  UrbanConderController2_B.Flapswitch = intrp1d_l_pw(rtb_ElevatorAngles_o1,
    UrbanConderController2_B.Flapswitch,
    UrbanConderController2_P.servo_signal_neg);

  // Saturate: '<S1>/Saturation5'
  if (UrbanConderController2_B.Flapswitch >
      UrbanConderController2_P.Saturation5_UpperSat) {
    UrbanConderController2_B.Flapswitch =
      UrbanConderController2_P.Saturation5_UpperSat;
  } else if (UrbanConderController2_B.Flapswitch <
             UrbanConderController2_P.Saturation5_LowerSat) {
    UrbanConderController2_B.Flapswitch =
      UrbanConderController2_P.Saturation5_LowerSat;
  }

  // End of Saturate: '<S1>/Saturation5'

  // DataTypeConversion: '<Root>/Data Type Conversion3'
  ParamStep = static_cast<real32_T>(UrbanConderController2_B.Flapswitch);

  // PreLookup: '<S1>/Elevator Angles'
  rtb_ElevatorAngles_o1 = plook_binx(UrbanConderController2_B.Merge[2],
    UrbanConderController2_P.ele_pos_deg, 20U,
    &UrbanConderController2_B.Flapswitch);

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (i = 0; i < 12; i++) {
    UrbanConderController2_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    UrbanConderController2_B.servoValues[i] = (rtNaNF);
  }

  UrbanConderController2_B.motorValues[0] =
    UrbanConderController2_B.ParamStep_g1;

  // Saturate: '<S1>/Saturation1'
  if (UrbanConderController2_B.DataTypeConversion1 >
      UrbanConderController2_P.Saturation1_UpperSat_e) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion2'

    UrbanConderController2_B.servoValues[0] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation1_UpperSat_e);
  } else if (UrbanConderController2_B.DataTypeConversion1 <
             UrbanConderController2_P.Saturation1_LowerSat_g) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion2'

    UrbanConderController2_B.servoValues[0] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation1_LowerSat_g);
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion2'

    UrbanConderController2_B.servoValues[0] = static_cast<real32_T>
      (UrbanConderController2_B.DataTypeConversion1);
  }

  // End of Saturate: '<S1>/Saturation1'

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  UrbanConderController2_B.servoValues[1] = ParamStep;

  // Interpolation_n-D: '<S1>/Actuator Signal'
  UrbanConderController2_B.Flapswitch = intrp1d_l_pw(rtb_ElevatorAngles_o1,
    UrbanConderController2_B.Flapswitch,
    UrbanConderController2_P.servo_signal_pos);

  // Saturate: '<S1>/Saturation2'
  if (UrbanConderController2_B.Flapswitch >
      UrbanConderController2_P.Saturation2_UpperSat_o) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion4'

    UrbanConderController2_B.servoValues[2] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation2_UpperSat_o);
  } else if (UrbanConderController2_B.Flapswitch <
             UrbanConderController2_P.Saturation2_LowerSat_n) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion4'

    UrbanConderController2_B.servoValues[2] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation2_LowerSat_n);
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion4'

    UrbanConderController2_B.servoValues[2] = static_cast<real32_T>
      (UrbanConderController2_B.Flapswitch);
  }

  // End of Saturate: '<S1>/Saturation2'

  // Product: '<S1>/Product4' incorporates:
  //   Constant: '<S1>/Constant4'

  UrbanConderController2_B.Flapswitch = 1.0 / UrbanConderController2_P.rud_max *
    UrbanConderController2_B.Merge[3];

  // Saturate: '<S1>/Saturation3'
  if (UrbanConderController2_B.Flapswitch >
      UrbanConderController2_P.Saturation3_UpperSat_c) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion5'

    UrbanConderController2_B.servoValues[3] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation3_UpperSat_c);
  } else if (UrbanConderController2_B.Flapswitch <
             UrbanConderController2_P.Saturation3_LowerSat_l) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion5'

    UrbanConderController2_B.servoValues[3] = static_cast<real32_T>
      (UrbanConderController2_P.Saturation3_LowerSat_l);
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion5'

    UrbanConderController2_B.servoValues[3] = static_cast<real32_T>
      (UrbanConderController2_B.Flapswitch);
  }

  // End of Saturate: '<S1>/Saturation3'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<S6>/Constant7'
  //   Gain: '<S6>/Gain7'
  //   MATLAB Function: '<S2>/MATLAB Function'
  //   Rounding: '<S6>/Round3'
  //   Sum: '<S6>/Sum7'

  MW_actuators_set(!(rt_roundd_snf(UrbanConderController2_P.Gain7_Gain * (
    static_cast<real_T>(UrbanConderController2_B.In1_i.values[7]) -
    UrbanConderController2_P.Constant7_Value)) == 0.0),
                   &UrbanConderController2_B.motorValues[0],
                   &UrbanConderController2_B.servoValues[0]);

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S25>/PX4 Timestamp'

  UrbanConderController2_B.BusAssignment.timestamp = hrt_absolute_time();

  // MATLABSystem: '<S20>/SourceBlock'
  b_varargout_1 = uORB_read_step(UrbanConderController2_DW.obj_h.orbMetadataObj,
    &UrbanConderController2_DW.obj_h.eventStructObj, &UrbanConderController2_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S21>/Enable'

  // Start for MATLABSystem: '<S20>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S21>/In1'
    UrbanConderController2_B.In1 = UrbanConderController2_B.r;
  }

  // End of Outputs for SubSystem: '<S20>/Enabled Subsystem'

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion3'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   DataTypeConversion: '<S7>/Data Type Conversion'
  //   DataTypeConversion: '<S7>/Data Type Conversion10'
  //   DataTypeConversion: '<S7>/Data Type Conversion7'
  //   DataTypeConversion: '<S7>/Data Type Conversion8'
  //   Gain: '<S13>/Gain1'
  //   Gain: '<S14>/Gain1'
  //   Gain: '<S4>/Gain'
  //   Gain: '<S4>/Gain1'
  //   Gain: '<S4>/Gain2'
  //   MATLAB Function: '<S8>/quat2eul'
  //   MATLABSystem: '<S5>/Read Parameter35'
  //
  UrbanConderController2_B.BusAssignment.sig1 =
    UrbanConderController2_B.Throttlecmd;
  UrbanConderController2_B.BusAssignment.sig2 = UrbanConderController2_B.Rollcmd;
  UrbanConderController2_B.BusAssignment.sig3 =
    UrbanConderController2_B.Pitchcmd;
  UrbanConderController2_B.BusAssignment.sig4 = UrbanConderController2_B.Yawcmd;
  UrbanConderController2_B.BusAssignment.sig5 =
    UrbanConderController2_B.Modeswitch1;
  UrbanConderController2_B.BusAssignment.sig6 =
    UrbanConderController2_B.Modeswitch2;
  UrbanConderController2_B.BusAssignment.sig7 = rtb_phi;
  UrbanConderController2_B.BusAssignment.sig8 = rtb_theta;
  UrbanConderController2_B.BusAssignment.sig9 = rt_atan2f_snf
    ((UrbanConderController2_B.In1_g.q[1] * UrbanConderController2_B.In1_g.q[2]
      + UrbanConderController2_B.In1_g.q[0] * UrbanConderController2_B.In1_g.q[3])
     * 2.0F, ((rtb_phi_tmp + rtb_phi_tmp_0) - rtb_phi_tmp_1) - rtb_phi_tmp_2);
  UrbanConderController2_B.BusAssignment.sig10 =
    UrbanConderController2_B.In1_a.true_airspeed_m_s;
  UrbanConderController2_B.BusAssignment.sig11 = static_cast<real_T>
    (mul_s64_loSR_sat(UrbanConderController2_P.Gain1_Gain_o0,
                      static_cast<int64_T>(UrbanConderController2_P.Gain_Gain_h)
                      * UrbanConderController2_B.In1.lat, 54ULL)) *
    5.5511151231257827E-17;
  UrbanConderController2_B.BusAssignment.sig12 = static_cast<real_T>
    (mul_s64_loSR_sat(UrbanConderController2_P.Gain1_Gain_af,
                      static_cast<int64_T>
                      (UrbanConderController2_P.Gain1_Gain_eo) *
                      UrbanConderController2_B.In1.lon, 54ULL)) *
    5.5511151231257827E-17;
  UrbanConderController2_B.BusAssignment.sig13 = static_cast<real_T>(
    static_cast<int64_T>(UrbanConderController2_P.Gain2_Gain_p) *
    UrbanConderController2_B.In1.alt) * 9.0949470177292824E-13;
  UrbanConderController2_B.BusAssignment.sig14 =
    UrbanConderController2_B.In1_m.manual_control_signal_lost;
  UrbanConderController2_B.BusAssignment.sig15 =
    UrbanConderController2_B.ParamStep;
  UrbanConderController2_B.BusAssignment.sig16 = 0.0;
  UrbanConderController2_B.BusAssignment.sig17 = 0.0;
  UrbanConderController2_B.BusAssignment.sig18 = 0.0;
  UrbanConderController2_B.BusAssignment.sig19 = 0.0;
  UrbanConderController2_B.BusAssignment.sig20 = 0.0;

  // MATLABSystem: '<S27>/SinkBlock' incorporates:
  //   BusAssignment: '<S25>/Bus Assignment'

  uORB_write_step(UrbanConderController2_DW.obj_pi.orbMetadataObj,
                  &UrbanConderController2_DW.obj_pi.orbAdvertiseObj,
                  &UrbanConderController2_B.BusAssignment);

  // MATLABSystem: '<S17>/SourceBlock'
  uORB_read_step(UrbanConderController2_DW.obj_l.orbMetadataObj,
                 &UrbanConderController2_DW.obj_l.eventStructObj,
                 &UrbanConderController2_B.r4, false, 1.0);
}

// Model initialize function
void UrbanConderController2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[15] = "AA_ALT_REF_MSL";
    static const char_T ParameterNameStr_0[10] = "AA_I_HEAD";
    static const char_T ParameterNameStr_1[10] = "AA_P_HEAD";
    static const char_T ParameterNameStr_2[9] = "AA_I_ALT";
    static const char_T ParameterNameStr_3[9] = "AA_P_ALT";
    static const char_T ParameterNameStr_4[7] = "AA_I_V";
    static const char_T ParameterNameStr_5[7] = "AA_P_V";
    static const char_T ParameterNameStr_6[10] = "AA_I_BANK";
    static const char_T ParameterNameStr_7[10] = "AA_P_BANK";
    static const char_T ParameterNameStr_8[11] = "AA_I_PITCH";
    static const char_T ParameterNameStr_9[11] = "AA_P_PITCH";
    static const char_T ParameterNameStr_a[14] = "AA_YAW_DAMPER";
    static const char_T ParameterNameStr_b[14] = "AA_PITCH_TRIM";
    static const char_T ParameterNameStr_c[13] = "AA_BANK_TRIM";
    static const char_T ParameterNameStr_d[12] = "AA_RUD_TRIM";
    static const char_T ParameterNameStr_e[17] = "AA_ELE_TRIM_FLAP";
    static const char_T ParameterNameStr_f[12] = "AA_ELE_TRIM";
    static const char_T ParameterNameStr_g[12] = "AA_AIL_TRIM";
    static const char_T ParameterNameStr_h[15] = "AA_THRUST_TRIM";
    int32_T i;

    // Start for SwitchCase: '<S40>/Switch Case'
    UrbanConderController2_DW.SwitchCase_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S24>/In1' incorporates:
    //   Outport: '<S24>/Out1'

    UrbanConderController2_B.In1_i = UrbanConderController2_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
    //   Outport: '<S12>/Out1'

    UrbanConderController2_B.In1_m = UrbanConderController2_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S33>/In1' incorporates:
    //   Outport: '<S33>/Out1'

    UrbanConderController2_B.In1_g = UrbanConderController2_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S28>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S31>/In1' incorporates:
    //   Outport: '<S31>/Out1'

    UrbanConderController2_B.In1_a = UrbanConderController2_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S28>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S9>/failsafe'
    // InitializeConditions for DiscreteIntegrator: '<S379>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE_o =
      UrbanConderController2_P.PIbankanglecontroller_InitialCo;

    // End of SystemInitialize for SubSystem: '<S9>/failsafe'

    // SystemInitialize for IfAction SubSystem: '<S9>/Angle controller'
    // InitializeConditions for DiscreteIntegrator: '<S84>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE_i =
      UrbanConderController2_P.PIbankanglecontroller_Initial_p;

    // InitializeConditions for DiscreteIntegrator: '<S142>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE_p =
      UrbanConderController2_P.PIpitchanglecontroller_InitialC;

    // End of SystemInitialize for SubSystem: '<S9>/Angle controller'

    // SystemInitialize for IfAction SubSystem: '<S9>/Speed controller '
    // InitializeConditions for DiscreteIntegrator: '<S205>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE =
      UrbanConderController2_P.PIbankanglecontroller_Initial_k;

    // InitializeConditions for DiscreteIntegrator: '<S263>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE_a =
      UrbanConderController2_P.PIpitchanglecontroller_Initia_f;

    // InitializeConditions for DiscreteIntegrator: '<S320>/Integrator'
    UrbanConderController2_DW.Integrator_DSTATE_h =
      UrbanConderController2_P.PIspeedcontroller_InitialCondit;

    // End of SystemInitialize for SubSystem: '<S9>/Speed controller '
    for (i = 0; i < 5; i++) {
      // SystemInitialize for Merge: '<S9>/Merge'
      UrbanConderController2_B.Merge[i] =
        UrbanConderController2_P.Merge_InitialOutput;
    }

    // SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S21>/In1' incorporates:
    //   Outport: '<S21>/Out1'

    UrbanConderController2_B.In1 = UrbanConderController2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem'

    // Start for MATLABSystem: '<S23>/SourceBlock'
    UrbanConderController2_DW.obj_j.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_j.isInitialized = 1;
    UrbanConderController2_DW.obj_j.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(UrbanConderController2_DW.obj_j.orbMetadataObj,
                         &UrbanConderController2_DW.obj_j.eventStructObj);
    UrbanConderController2_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/SourceBlock'
    UrbanConderController2_DW.obj_hn.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_hn.isInitialized = 1;
    UrbanConderController2_DW.obj_hn.orbMetadataObj = ORB_ID(failsafe_flags);
    uORB_read_initialize(UrbanConderController2_DW.obj_hn.orbMetadataObj,
                         &UrbanConderController2_DW.obj_hn.eventStructObj);
    UrbanConderController2_DW.obj_hn.isSetupComplete = true;

    // Start for MATLABSystem: '<S32>/SourceBlock'
    UrbanConderController2_DW.obj_f.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_f.isInitialized = 1;
    UrbanConderController2_DW.obj_f.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(UrbanConderController2_DW.obj_f.orbMetadataObj,
                         &UrbanConderController2_DW.obj_f.eventStructObj);
    UrbanConderController2_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter35'
    UrbanConderController2_DW.obj_o.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_o.isInitialized = 1;
    UrbanConderController2_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, 4.0);
    UrbanConderController2_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter34'
    UrbanConderController2_DW.obj_dc.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_dc.isInitialized = 1;
    UrbanConderController2_DW.obj_dc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 4.0);
    UrbanConderController2_DW.obj_dc.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter33'
    UrbanConderController2_DW.obj_k.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_k.isInitialized = 1;
    UrbanConderController2_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, 4.0);
    UrbanConderController2_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter32'
    UrbanConderController2_DW.obj_l2.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_l2.isInitialized = 1;
    UrbanConderController2_DW.obj_l2.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 4.0);
    UrbanConderController2_DW.obj_l2.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter31'
    UrbanConderController2_DW.obj_i.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_i.isInitialized = 1;
    UrbanConderController2_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 4.0);
    UrbanConderController2_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter30'
    UrbanConderController2_DW.obj_kt.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_kt.isInitialized = 1;
    UrbanConderController2_DW.obj_kt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 4.0);
    UrbanConderController2_DW.obj_kt.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter29'
    UrbanConderController2_DW.obj_p.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_p.isInitialized = 1;
    UrbanConderController2_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 4.0);
    UrbanConderController2_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter28'
    UrbanConderController2_DW.obj_dr.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_dr.isInitialized = 1;
    UrbanConderController2_DW.obj_dr.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, 4.0);
    UrbanConderController2_DW.obj_dr.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter27'
    UrbanConderController2_DW.obj_b.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_b.isInitialized = 1;
    UrbanConderController2_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, 4.0);
    UrbanConderController2_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter26'
    UrbanConderController2_DW.obj_f3.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_f3.isInitialized = 1;
    UrbanConderController2_DW.obj_f3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 4.0);
    UrbanConderController2_DW.obj_f3.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter25'
    UrbanConderController2_DW.obj_ja.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_ja.isInitialized = 1;
    UrbanConderController2_DW.obj_ja.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 4.0);
    UrbanConderController2_DW.obj_ja.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter24'
    UrbanConderController2_DW.obj_iv.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_iv.isInitialized = 1;
    UrbanConderController2_DW.obj_iv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 4.0);
    UrbanConderController2_DW.obj_iv.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter37'
    UrbanConderController2_DW.obj_lj.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_lj.isInitialized = 1;
    UrbanConderController2_DW.obj_lj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 4.0);
    UrbanConderController2_DW.obj_lj.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter36'
    UrbanConderController2_DW.obj_m.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_m.isInitialized = 1;
    UrbanConderController2_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 4.0);
    UrbanConderController2_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter23'
    UrbanConderController2_DW.obj_jm.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_jm.isInitialized = 1;
    UrbanConderController2_DW.obj_jm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 4.0);
    UrbanConderController2_DW.obj_jm.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter22'
    UrbanConderController2_DW.obj_a.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_a.isInitialized = 1;
    UrbanConderController2_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 4.0);
    UrbanConderController2_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter4'
    UrbanConderController2_DW.obj_d.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_d.isInitialized = 1;
    UrbanConderController2_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 4.0);
    UrbanConderController2_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter20'
    UrbanConderController2_DW.obj_c.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_c.isInitialized = 1;
    UrbanConderController2_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 4.0);
    UrbanConderController2_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/Read Parameter21'
    UrbanConderController2_DW.obj_hx.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_hx.isInitialized = 1;
    UrbanConderController2_DW.obj_hx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, 4.0);
    UrbanConderController2_DW.obj_hx.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/SourceBlock'
    UrbanConderController2_DW.obj_ff.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_ff.isInitialized = 1;
    UrbanConderController2_DW.obj_ff.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(UrbanConderController2_DW.obj_ff.orbMetadataObj,
                         &UrbanConderController2_DW.obj_ff.eventStructObj);
    UrbanConderController2_DW.obj_ff.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      UrbanConderController2_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      UrbanConderController2_DW.obj.ValidServoIdx[i] = false;
    }

    UrbanConderController2_DW.obj.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj.isSetupComplete = false;
    UrbanConderController2_DW.obj.isInitialized = 1;
    UrbanCon_PX4Actuators_setupImpl(&UrbanConderController2_DW.obj);
    UrbanConderController2_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S25>/PX4 Timestamp'
    UrbanConderController2_DW.obj_n.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_n.isInitialized = 1;
    UrbanConderController2_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S20>/SourceBlock'
    UrbanConderController2_DW.obj_h.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_h.isInitialized = 1;
    UrbanConderController2_DW.obj_h.orbMetadataObj = ORB_ID(vehicle_gps_position);
    uORB_read_initialize(UrbanConderController2_DW.obj_h.orbMetadataObj,
                         &UrbanConderController2_DW.obj_h.eventStructObj);
    UrbanConderController2_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S27>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    UrbanConderController2_DW.obj_pi.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_pi.isInitialized = 1;
    UrbanConderController2_DW.obj_pi.orbMetadataObj = ORB_ID(fmr_log);
    uORB_write_initialize(UrbanConderController2_DW.obj_pi.orbMetadataObj,
                          &UrbanConderController2_DW.obj_pi.orbAdvertiseObj,
                          &UrbanConderController2_B.BusAssignment, 1);
    UrbanConderController2_DW.obj_pi.isSetupComplete = true;

    // Start for MATLABSystem: '<S17>/SourceBlock'
    UrbanConderController2_DW.obj_l.matlabCodegenIsDeleted = false;
    UrbanConderController2_DW.obj_l.isInitialized = 1;
    UrbanConderController2_DW.obj_l.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(UrbanConderController2_DW.obj_l.orbMetadataObj,
                         &UrbanConderController2_DW.obj_l.eventStructObj);
    UrbanConderController2_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void UrbanConderController2_terminate(void)
{
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!UrbanConderController2_DW.obj_j.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_j.isInitialized == 1) &&
        UrbanConderController2_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!UrbanConderController2_DW.obj_hn.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_hn.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_hn.isInitialized == 1) &&
        UrbanConderController2_DW.obj_hn.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_hn.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'

  // Terminate for MATLABSystem: '<S32>/SourceBlock'
  if (!UrbanConderController2_DW.obj_f.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_f.isInitialized == 1) &&
        UrbanConderController2_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/Read Parameter35'
  if (!UrbanConderController2_DW.obj_o.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter35'

  // Terminate for MATLABSystem: '<S5>/Read Parameter34'
  if (!UrbanConderController2_DW.obj_dc.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_dc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter34'

  // Terminate for MATLABSystem: '<S5>/Read Parameter33'
  if (!UrbanConderController2_DW.obj_k.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter33'

  // Terminate for MATLABSystem: '<S5>/Read Parameter32'
  if (!UrbanConderController2_DW.obj_l2.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_l2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter32'

  // Terminate for MATLABSystem: '<S5>/Read Parameter31'
  if (!UrbanConderController2_DW.obj_i.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter31'

  // Terminate for MATLABSystem: '<S5>/Read Parameter30'
  if (!UrbanConderController2_DW.obj_kt.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_kt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter30'

  // Terminate for MATLABSystem: '<S5>/Read Parameter29'
  if (!UrbanConderController2_DW.obj_p.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter29'

  // Terminate for MATLABSystem: '<S5>/Read Parameter28'
  if (!UrbanConderController2_DW.obj_dr.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_dr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter28'

  // Terminate for MATLABSystem: '<S5>/Read Parameter27'
  if (!UrbanConderController2_DW.obj_b.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter27'

  // Terminate for MATLABSystem: '<S5>/Read Parameter26'
  if (!UrbanConderController2_DW.obj_f3.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_f3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter26'

  // Terminate for MATLABSystem: '<S5>/Read Parameter25'
  if (!UrbanConderController2_DW.obj_ja.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_ja.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter25'

  // Terminate for MATLABSystem: '<S5>/Read Parameter24'
  if (!UrbanConderController2_DW.obj_iv.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_iv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter24'

  // Terminate for MATLABSystem: '<S5>/Read Parameter37'
  if (!UrbanConderController2_DW.obj_lj.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_lj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter37'

  // Terminate for MATLABSystem: '<S5>/Read Parameter36'
  if (!UrbanConderController2_DW.obj_m.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter36'

  // Terminate for MATLABSystem: '<S5>/Read Parameter23'
  if (!UrbanConderController2_DW.obj_jm.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_jm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter23'

  // Terminate for MATLABSystem: '<S5>/Read Parameter22'
  if (!UrbanConderController2_DW.obj_a.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter22'

  // Terminate for MATLABSystem: '<S5>/Read Parameter4'
  if (!UrbanConderController2_DW.obj_d.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter4'

  // Terminate for MATLABSystem: '<S5>/Read Parameter20'
  if (!UrbanConderController2_DW.obj_c.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter20'

  // Terminate for MATLABSystem: '<S5>/Read Parameter21'
  if (!UrbanConderController2_DW.obj_hx.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_hx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/Read Parameter21'

  // Terminate for MATLABSystem: '<S28>/SourceBlock'
  if (!UrbanConderController2_DW.obj_ff.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_ff.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_ff.isInitialized == 1) &&
        UrbanConderController2_DW.obj_ff.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_ff.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S28>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!UrbanConderController2_DW.obj.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj.isInitialized == 1) &&
        UrbanConderController2_DW.obj.isSetupComplete) {
      for (int32_T i = 0; i < 12; i++) {
        UrbanConderController2_B.motorValues_m[i] = (rtNaNF);
      }

      for (int32_T i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (int32_T i = 0; i < 12; i++) {
        if (UrbanConderController2_DW.obj.ValidMotorIdx[i]) {
          UrbanConderController2_B.motorValues_m[i] = 0.0F;
        }
      }

      for (int32_T i = 0; i < 8; i++) {
        if (UrbanConderController2_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &UrbanConderController2_B.motorValues_m[0],
                       &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'

  // Terminate for MATLABSystem: '<S25>/PX4 Timestamp'
  if (!UrbanConderController2_DW.obj_n.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S25>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S20>/SourceBlock'
  if (!UrbanConderController2_DW.obj_h.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_h.isInitialized == 1) &&
        UrbanConderController2_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S20>/SourceBlock'

  // Terminate for MATLABSystem: '<S27>/SinkBlock'
  if (!UrbanConderController2_DW.obj_pi.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_pi.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_pi.isInitialized == 1) &&
        UrbanConderController2_DW.obj_pi.isSetupComplete) {
      uORB_write_terminate(&UrbanConderController2_DW.obj_pi.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S27>/SinkBlock'

  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!UrbanConderController2_DW.obj_l.matlabCodegenIsDeleted) {
    UrbanConderController2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((UrbanConderController2_DW.obj_l.isInitialized == 1) &&
        UrbanConderController2_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&UrbanConderController2_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'
}

const char_T* RT_MODEL_UrbanConderControlle_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_UrbanConderControlle_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
