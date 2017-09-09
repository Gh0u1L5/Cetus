#ifndef MODEL_SUPPORTVECTORMACHINE_SOLVER_H_
#define MODEL_SUPPORTVECTORMACHINE_SOLVER_H_
#include "Kernel.h"
#include "Para.h"
#include <armadillo>
double tol = 1.0e-3;

class SmoSolver {
public:
  SmoSolver(arma::mat &x, arma::vec &y, double regPar = 1.0, Kernel *kernel= new Kernel(LINEAR))
      : x{x}, y{y}, C{regPar}, kernel{kernel} {};
  ~SmoSolver(){};
  Kernel *kernel;
  arma::vec theta;
  // First feature
  arma::mat &x;
  bool trained;

  // Target feature
  // Elements in y have to be either 1 or 0
  arma::vec &y;
  int ExampleNum();
  int Train();
  double Predict(arma::vec &x);

private:
  int TakeStep(int i1, int i2);
  int ExamineExample(int i2);

  double C;
  double b;
  double eps = 1.0e-7;
  double SvmOutputOnPoint(int i);
  double KernelCal(int i1, int i2, bool onlyKernel);
  arma::vec lagrangeMultiplier;
  arma::vec errorCache;
};

#endif
