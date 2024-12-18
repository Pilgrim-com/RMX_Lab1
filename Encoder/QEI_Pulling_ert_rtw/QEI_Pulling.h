/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Pulling.h
 *
 * Code generated for Simulink model 'QEI_Pulling'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 07:14:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QEI_Pulling_h_
#define QEI_Pulling_h_
#ifndef QEI_Pulling_COMMON_INCLUDES_
#define QEI_Pulling_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "coder_posix_time.h"
#include "main.h"
#endif                                 /* QEI_Pulling_COMMON_INCLUDES_ */

#include "QEI_Pulling_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Polling_X1_Position;          /* '<Root>/Gain' */
  real_T position;                     /* '<Root>/MATLAB Function' */
  real_T velocity;                     /* '<Root>/MATLAB Function' */
  boolean_T DigitalPortRead;           /* '<S7>/Digital Port Read' */
  boolean_T DigitalPortRead_e;         /* '<S5>/Digital Port Read' */
} B_QEI_Pulling_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  sdAmwXbnJnEmimT0NaJRtAD_QEI_P_T lastTime;/* '<Root>/MATLAB Function' */
  real_T lastA;                        /* '<Root>/MATLAB Function' */
  real_T count;                        /* '<Root>/MATLAB Function' */
  real_T lastCount;                    /* '<Root>/MATLAB Function' */
  real_T freq;                         /* '<Root>/MATLAB Function' */
  boolean_T lastA_not_empty;           /* '<Root>/MATLAB Function' */
  boolean_T count_not_empty;           /* '<Root>/MATLAB Function' */
  boolean_T lastCount_not_empty;       /* '<Root>/MATLAB Function' */
  boolean_T lastTime_not_empty;        /* '<Root>/MATLAB Function' */
  boolean_T freq_not_empty;            /* '<Root>/MATLAB Function' */
} DW_QEI_Pulling_T;

/* Real-time Model Data Structure */
struct tag_RTM_QEI_Pulling_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_QEI_Pulling_T QEI_Pulling_B;

/* Block states (default storage) */
extern DW_QEI_Pulling_T QEI_Pulling_DW;

/* Model entry point functions */
extern void QEI_Pulling_initialize(void);
extern void QEI_Pulling_step(void);
extern void QEI_Pulling_terminate(void);

/* Real-time Model object */
extern RT_MODEL_QEI_Pulling_T *const QEI_Pulling_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'QEI_Pulling'
 * '<S1>'   : 'QEI_Pulling/Digital Port Read3'
 * '<S2>'   : 'QEI_Pulling/Digital Port Read4'
 * '<S3>'   : 'QEI_Pulling/MATLAB Function'
 * '<S4>'   : 'QEI_Pulling/Digital Port Read3/ECSoC'
 * '<S5>'   : 'QEI_Pulling/Digital Port Read3/ECSoC/ECSimCodegen'
 * '<S6>'   : 'QEI_Pulling/Digital Port Read4/ECSoC'
 * '<S7>'   : 'QEI_Pulling/Digital Port Read4/ECSoC/ECSimCodegen'
 */
#endif                                 /* QEI_Pulling_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
