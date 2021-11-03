#ifndef RIR_GENERATOR_CORE_H
#define RIR_GENERATOR_CORE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void computeRIR(double* imp, double c, double fs, double* rr, int nMicrophones, int nSamples, double* ss, double* LL, double* beta, char microphone_type, int nOrder, double* microphone_angle, int isHighPassFilter);
void conv_(const double* input, int len_in, double* kernel, int len_k, double* output);
#ifdef __cplusplus
}
#endif

#endif
