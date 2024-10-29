/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Pulling.c
 *
 * Code generated for Simulink model 'QEI_Pulling'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 01:58:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QEI_Pulling.h"
#include "QEI_Pulling_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "QEI_Pulling_private.h"

/* Block signals (default storage) */
B_QEI_Pulling_T QEI_Pulling_B;

/* Block states (default storage) */
DW_QEI_Pulling_T QEI_Pulling_DW;

/* Real-time model */
static RT_MODEL_QEI_Pulling_T QEI_Pulling_M_;
RT_MODEL_QEI_Pulling_T *const QEI_Pulling_M = &QEI_Pulling_M_;

/* Forward declaration for local functions */
static void QEI_Pulling_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void QEI_Pulling_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void QEI_Pulling_step(void)
{
  /* MATLABSystem: '<Root>/Encoder1' */
  QEI_Pulling_B.X2 = getTimerCounterValueForG4(QEI_Pulling_DW.obj.TimerHandle,
    false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  QEI_Pulling_B.unwrappedPosition = QEI_Pulling_B.X2;

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
  QEI_Pulling_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  QEI_Pulling_M->Sizes.checksums[0] = (700354475U);
  QEI_Pulling_M->Sizes.checksums[1] = (554233582U);
  QEI_Pulling_M->Sizes.checksums[2] = (2817220893U);
  QEI_Pulling_M->Sizes.checksums[3] = (3111840786U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    QEI_Pulling_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QEI_Pulling_M->extModeInfo,
      &QEI_Pulling_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QEI_Pulling_M->extModeInfo,
                        QEI_Pulling_M->Sizes.checksums);
    rteiSetTPtr(QEI_Pulling_M->extModeInfo, rtmGetTPtr(QEI_Pulling_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  QEI_Pulling_DW.obj.isInitialized = 0;
  QEI_Pulling_DW.obj.matlabCodegenIsDeleted = false;
  QEI_Pulling_SystemCore_setup(&QEI_Pulling_DW.obj);
}

/* Model terminate function */
void QEI_Pulling_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!QEI_Pulling_DW.obj.matlabCodegenIsDeleted) {
    QEI_Pulling_DW.obj.matlabCodegenIsDeleted = true;
    if ((QEI_Pulling_DW.obj.isInitialized == 1) &&
        QEI_Pulling_DW.obj.isSetupComplete) {
      disableCounter(QEI_Pulling_DW.obj.TimerHandle);
      disableTimerInterrupts(QEI_Pulling_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_Pulling_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_Pulling_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
