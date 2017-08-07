#ifndef MODEL_LINEARREGRESSION_H_
#define MODEL_LINEARREGRESSION_H_
#include <armadillo>

enum TrainingType {
  normalEquation,
  gradientDescent,
};

class LinearRegression {
  // First feature
  arma::mat x;

  // Target feature
  arma::vec y;

  // Vector for predication
  arma::vec theta;

public:
  // Model Trained or not
  bool trained;

  // Create a new instance from the given data set.
  LinearRegression(arma::mat &x, arma::vec &y);

  // Destructor
  ~LinearRegression();

  // Add other features
  void AddData(arma::mat &extraX, arma::vec &extraY);

  // Train the model
  void Train(TrainingType Type, double alpha = 0, unsigned int iters = 0);

  // Return number of example
  arma::uword ExampleNumber();

  // Predict y according to given x
  double Predict(arma::vec &x);

private:
  /**
   * Compute Cost Functions's Derivative
   */
  arma::vec CostDerivative();

  /**
   * Compute the hypothesis.
   */
  // static double h(double x, double theta[]);

  /**
   * Calculate the target feature from the other ones.
   */
  // static double *calculate_predictions(double x[], double theta[], int m);
  void NormalEquation();
  /**
   * Performs gradient descent to learn theta by taking num_items gradient steps
   * with learning rate alpha.
   */
  void GradientDescent(double alpha, unsigned int iters);
};

#endif
