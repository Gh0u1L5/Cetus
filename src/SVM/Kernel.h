#ifndef MODEL_SUPPORTVECTORMACHINE_KERNEL_H_
#define MODEL_SUPPORTVECTORMACHINE_KERNEL_H_
#include "Para.h"
#include <armadillo>

enum KernelType { LINEAR, POLY, RBF, SIGMOID, PRECOMPUTED }; /* kernel_type */

class Kernel {
public:
  Kernel(int l, svm_node *const *x, const SvmParameter &param);
  ~Kernel();

  // static double k_function();

  // Function Pointer
  double (Kernel::*kernel_function)(int i, int j) const;
  // svm_parameter
  const KernelType kernelType;
  const int degree;
  const double gamma;
  const double coef0;

  // linear: u'*v
  // polynomial: (gamma*u'*v + coef0)^degree
  // radial basis function: exp(-gamma*|u-v|^2)
  // sigmoid: tanh(gamma*u'*v + coef0)
  // precomputed kernel (kernel values in training_set_file)
  double KernelLinear(arma::mat x, arma::vec y) const { return x * y; }
};

#endif
