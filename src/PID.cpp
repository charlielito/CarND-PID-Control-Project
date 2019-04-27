#include "PID.h"


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

  current_error = 0;
  i_error = 0;

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

}

double PID::control(double cte){
  d_error = cte - current_error;
  current_error = cte;
  
 
  // integral error only if has not exploded
  //if abs(self.Ki * self.integral) < 100:
  //    self.integral += self.error

  // Only sum if i_error has not exploded
  // std::cout<<i_error<<Ki*i_error<<std::endl;
  // if (abs(Ki*i_error) < 10)  
  //   i_error += cte;
 
  double value = -Kp * cte - Kd * d_error - Ki * i_error;

  return value;
}

