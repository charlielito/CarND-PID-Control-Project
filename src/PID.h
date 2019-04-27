#ifndef PID_H
#define PID_H

#include <stdlib.h> 
#include <iostream>


class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);



  /**
   * Calculate the total PID control command
   * @output The total PID control command
   */
  double control(double cte);

 private:
  /**
   * PID Errors
   */
  double current_error;
  double i_error;
  double d_error;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H