#pragma once
namespace DivideTwoIntegers {
	int DivideTwoIntegersMethod1(int dividend, int divisor) {
    // Calculate sign of divisor i.e.,
    // sign will be negative only iff
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
    // Update both divisor and
    // dividend positive
    dividend = abs(dividend);
    divisor = abs(divisor);                                                   
 
    // Initialize the quotient
    int quotient = 0;
    while (dividend >= divisor) {
      dividend -= divisor;
      ++quotient;
    }
    // Return the value of quotient with the appropriate sign.
    return quotient * sign;
	} ;

  int DivideTwoIntegersMethod2(long long dividend, long long divisor){  
    // Calculate sign of divisor i.e.,
    // sign will be negative only iff
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((dividend < 0) ^
                (divisor < 0)) ? -1 : 1;
 
    // remove sign of operands
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    // Initialize the quotient
    long long quotient = 0, temp = 0;
 
    // test down from the highest bit and
    // accumulate the tentative value for
    // valid bit
    for (int i = 31; i >= 0; --i) {
 
      if (temp + (divisor << i) <= dividend) {
        temp += divisor << i;
        quotient |= 1LL << i;
      }
    }
    //if the sign value computed earlier is -1 then negate the value of quotient
    if(sign==-1) quotient=-quotient;
     
    return quotient;
  }
}
