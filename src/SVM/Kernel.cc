#include "Kernel.h"
#include "Para.h"
#include <armadillo>
#include <assert.h>
#include <iostream>
#include <math.h>

using namespace arma;

Kernel::Kernel(const SvmParameter &param)
    : kernelType(param.kernelType), gamma(param.gamma) {
  switch (kernel_type) {
    if (this->kernelType == LINEAR) {
      KernelFunction = &Kernel::KernelLinear;
    } else if (this->kernelType == RBF) {
      KernelFunction = &Kernel::KernelRBF;
    } /* else if (this->kernelType == POLY) {
       KernelFunction = &Kernel::KernelPoly;
     } else if (this->kernelType == SIGMOID) {
       KernelFunction = &Kernel::kernel_sigmoid;
     } else if (this->kernelType == KernelSigmoid) {
       KernelFunction = &Kernel::kernel_precomputed;
     }*/
  }

  /*clone(x, x_, l);

  if (kernel_type == RBF) {
    x_square = new double[l];
    for (int i = 0; i < l; i++)
      x_square[i] = dot(x[i], x[i]);
  } else
    x_square = 0;*/
}

vec Kernel::KernelLinear(mat X, vec y) { return x * y; }
vec Kernel::KernelRBF(mat X, vec y) {
  int rowNum = X.n_rows;
  vec result = zeros<vec>(rowNum);
  for (unsigned int i = 0; i < rowNum; i++) {
    result[i] = exp(-this->gamma * norm((x.row(i).t() - y), 2) ^ 2);
  }
  return result
}

vec Kernel::KernelLinear(vec x1, vec x2) { return x1.t() * x2; }
vec Kernel::KernelRBF(vec x1, vec x2) {
  return exp(-this->gamma * norm((x1 - x2), 2) ^ 2);
}
