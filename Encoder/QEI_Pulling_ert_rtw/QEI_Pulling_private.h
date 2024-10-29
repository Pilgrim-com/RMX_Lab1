/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Pulling_private.h
 *
 * Code generated for Simulink model 'QEI_Pulling'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 00:27:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QEI_Pulling_private_h_
#define QEI_Pulling_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "QEI_Pulling.h"
#include "QEI_Pulling_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void QEI_Pulling_Encoder_Init(DW_Encoder_QEI_Pulling_T *localDW);
extern void QEI_Pulling_Encoder(B_Encoder_QEI_Pulling_T *localB,
  DW_Encoder_QEI_Pulling_T *localDW);
extern void QEI_Pulling_Encoder_Term(DW_Encoder_QEI_Pulling_T *localDW);

#endif                                 /* QEI_Pulling_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
