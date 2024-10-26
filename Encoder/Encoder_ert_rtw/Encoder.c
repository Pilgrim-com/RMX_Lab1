/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder.c
 *
 * Code generated for Simulink model 'Encoder'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Oct 26 15:08:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder.h"
#include "Encoder_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "Encoder_private.h"

/* Block signals (default storage) */
B_Encoder_T Encoder_B;

/* Block states (default storage) */
DW_Encoder_T Encoder_DW;

/* Real-time model */
static RT_MODEL_Encoder_T Encoder_M_;
RT_MODEL_Encoder_T *const Encoder_M = &Encoder_M_;

/* Forward declaration for local functions */
static void Encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Encoder_step(void)
{
  /* MATLABSystem: '<Root>/Encoder' */
  Encoder_B.COUNT = getTimerCounterValueForG4(Encoder_DW.obj.TimerHandle, false,
    NULL);

  /* MATLABSystem: '<Root>/Encoder' */
  Encoder_B.Encoder_o2 = ouputDirectionOfCounter(Encoder_DW.obj.TimerHandle);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_M->Timing.taskTime0 =
    ((time_T)(++Encoder_M->Timing.clockTick0)) * Encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void Encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Encoder_M, -1);
  Encoder_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Encoder_M->Sizes.checksums[0] = (1838802939U);
  Encoder_M->Sizes.checksums[1] = (1383450138U);
  Encoder_M->Sizes.checksums[2] = (1182130130U);
  Encoder_M->Sizes.checksums[3] = (461959959U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_M->extModeInfo,
      &Encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_M->extModeInfo, Encoder_M->Sizes.checksums);
    rteiSetTPtr(Encoder_M->extModeInfo, rtmGetTPtr(Encoder_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder' */
  Encoder_DW.obj.isInitialized = 0;
  Encoder_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_SystemCore_setup(&Encoder_DW.obj);
}

/* Model terminate function */
void Encoder_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!Encoder_DW.obj.matlabCodegenIsDeleted) {
    Encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((Encoder_DW.obj.isInitialized == 1) && Encoder_DW.obj.isSetupComplete) {
      disableCounter(Encoder_DW.obj.TimerHandle);
      disableTimerInterrupts(Encoder_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(Encoder_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
