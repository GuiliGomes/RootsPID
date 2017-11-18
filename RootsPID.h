/* ----------------------------------------------------------------------------

File:	RootsPID.h
Author:	Guilherme Gomes & Lorenzo Giordano
Date:	21/Oct/2016

Description:
  Two zeros two poles PID controller.


Constructor paramters:
 - dT: periodo de amostragem
 - Kp:
 - Ki:
 - Kd:

---------------------------------------------------------------------------- */

#ifndef __ROOTS_PID
#define __ROOTS_PID


class RootsPID {
	
	public:
	  RootsPID(float T, float Kp, float Ki, float Kd);
      float getU(float errork);
	  void setLimit(int value);
      void reset();
	  
	private:
	  float ek[3], uk[3], u, h1, h2, b0, b1, b2, a1, a2;
      int limit;
};

#endif
