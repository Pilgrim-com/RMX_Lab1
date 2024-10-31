/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Pulling.c
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

#include "QEI_Pulling.h"
#include "rtwtypes.h"
#include "coder_posix_time.h"
#include "QEI_Pulling_private.h"

/* Block signals (default storage) */
B_QEI_Pulling_T QEI_Pulling_B;

/* Block states (default storage) */
DW_QEI_Pulling_T QEI_Pulling_DW;

/* Real-time model */
static RT_MODEL_QEI_Pulling_T QEI_Pulling_M_;
RT_MODEL_QEI_Pulling_T *const QEI_Pulling_M = &QEI_Pulling_M_;

/* Forward declaration for local functions */
static void QEI_Pulling_tic(real_T *tstart_tv_sec, real_T *tstart_tv_nsec);
static real_T QEI_Pulling_toc(real_T tstart_tv_sec, real_T tstart_tv_nsec);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void QEI_Pulling_tic(real_T *tstart_tv_sec, real_T *tstart_tv_nsec)
{
  coderTimespec origTimespec;
  if (!QEI_Pulling_DW.freq_not_empty) {
    QEI_Pulling_DW.freq_not_empty = true;
    coderInitTimeFunctions(&QEI_Pulling_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, QEI_Pulling_DW.freq);
  *tstart_tv_sec = origTimespec.tv_sec;
  *tstart_tv_nsec = origTimespec.tv_nsec;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T QEI_Pulling_toc(real_T tstart_tv_sec, real_T tstart_tv_nsec)
{
  coderTimespec origTimespec;
  if (!QEI_Pulling_DW.freq_not_empty) {
    QEI_Pulling_DW.freq_not_empty = true;
    coderInitTimeFunctions(&QEI_Pulling_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, QEI_Pulling_DW.freq);
  return (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec
    - tstart_tv_sec);
}

/* Model step function */
void QEI_Pulling_step(void)
{
  real_T currentTime;
  int32_T B;
  int32_T currentA;
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S5>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S5>/Digital Port Read' */
  QEI_Pulling_B.DigitalPortRead_e = ((pinReadLoc & 8192U) != 0U);

  /* MATLABSystem: '<S7>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S7>/Digital Port Read' */
  QEI_Pulling_B.DigitalPortRead = ((pinReadLoc & 16384U) != 0U);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  currentA = QEI_Pulling_B.DigitalPortRead_e;
  B = QEI_Pulling_B.DigitalPortRead;
  if ((!QEI_Pulling_DW.lastA_not_empty) || (!QEI_Pulling_DW.count_not_empty) ||
      (!QEI_Pulling_DW.lastCount_not_empty) ||
      (!QEI_Pulling_DW.lastTime_not_empty)) {
    QEI_Pulling_DW.lastA = 0.0;
    QEI_Pulling_DW.lastA_not_empty = true;
    QEI_Pulling_DW.count = 0.0;
    QEI_Pulling_DW.count_not_empty = true;
    QEI_Pulling_DW.lastCount = 0.0;
    QEI_Pulling_DW.lastCount_not_empty = true;
    QEI_Pulling_tic(&QEI_Pulling_DW.lastTime.tv_sec,
                    &QEI_Pulling_DW.lastTime.tv_nsec);
    QEI_Pulling_DW.lastTime_not_empty = true;
  }

  if ((QEI_Pulling_DW.lastA == 0.0) && (currentA == 1)) {
    if (B == 0) {
      QEI_Pulling_DW.count++;
    } else {
      QEI_Pulling_DW.count--;
    }
  }

  currentTime = QEI_Pulling_toc(QEI_Pulling_DW.lastTime.tv_sec,
    QEI_Pulling_DW.lastTime.tv_nsec);
  if (currentTime > 0.0) {
    QEI_Pulling_B.velocity = (QEI_Pulling_DW.count - QEI_Pulling_DW.lastCount) /
      currentTime;
  } else {
    QEI_Pulling_B.velocity = 0.0;
  }

  QEI_Pulling_DW.lastA = currentA;
  QEI_Pulling_DW.lastCount = QEI_Pulling_DW.count;
  QEI_Pulling_tic(&QEI_Pulling_DW.lastTime.tv_sec,
                  &QEI_Pulling_DW.lastTime.tv_nsec);
  QEI_Pulling_B.position = QEI_Pulling_DW.count;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  /* Gain: '<Root>/Gain' */
  QEI_Pulling_B.Polling_X1_Position = 0.26179938779914941 *
    QEI_Pulling_B.position;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  QEI_Pulling_M->Timing.taskTime0 =
    ((time_T)(++QEI_Pulling_M->Timing.clockTick0)) *
    QEI_Pulling_M->Timing.stepSize0;
}

/* Model initialize function */
void QEI_Pulling_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(QEI_Pulling_M, -1);
  QEI_Pulling_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  QEI_Pulling_M->Sizes.checksums[0] = (54567027U);
  QEI_Pulling_M->Sizes.checksums[1] = (1278915740U);
  QEI_Pulling_M->Sizes.checksums[2] = (4189197377U);
  QEI_Pulling_M->Sizes.checksums[3] = (3276512109U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    QEI_Pulling_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QEI_Pulling_M->extModeInfo,
      &QEI_Pulling_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QEI_Pulling_M->extModeInfo,
                        QEI_Pulling_M->Sizes.checksums);
    rteiSetTPtr(QEI_Pulling_M->extModeInfo, rtmGetTPtr(QEI_Pulling_M));
  }
}

/* Model terminate function */
void QEI_Pulling_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
