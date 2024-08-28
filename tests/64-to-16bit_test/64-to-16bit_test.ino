#include <Arduino.h>
#include <fp64lib.h>
#include <stdint.h>

// Scale factor for two decimal places
#define SCALE_FACTOR "100.0"

// Maximum values that can represented in 16 and 32 bits with 2 decimal places
#define DEC16_MAX "327.67"
#define DEC16_MIN "-327.68"
#define DEC32_MAX "21474836.47"
#define DEC32_MIN "-21474836.48"

void setup() {
  Serial.begin(9600);
  delay(50);

  // put your setup code here, to run once:
  float64_t number = fp64_atof("0.0");
  int32_t output;
  int code = truncateDoubleto32bits(number, output);
  Serial.println(code);
  Serial.println(output);
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Truncate 64-bit double to 16 bits
int truncateDoubleto16bits(float64_t input, int16_t &output){
  // Check for overflow or underflow
  // if input > DEC16MAX
  if (fp64_compare(input, fp64_atof(DEC16_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT16_MAX;
    // Error code 1: Overflow
    return 1;
  }
  // if input < DEC16MIN
  else if (fp64_compare(input, fp64_atof(DEC16_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT16_MIN;
    // Error code 2: Underflow
    return 2;
  }
  else {
    // Scale, then cast to int16
    output = fp64_to_int16(fp64_mul(input, fp64_atof(SCALE_FACTOR)));
    // No error
    return 0;
  }
}

// Truncate 64-bit double to 32 bits
int truncateDoubleto32bits(float64_t input, int32_t &output){
  // Check for overflow or underflow
  // if input > DEC32MAX
  if (fp64_compare(input, fp64_atof(DEC32_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT32_MAX;
    // Error code 1: Overflow
    return 1;
  }
  // if input < DEC32MIN
  else if (fp64_compare(input, fp64_atof(DEC32_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT32_MIN;
    // Error code 2: Underflow
    return 2;
  }
  else {
    // Scale, then cast to int16
    output = fp64_to_int32(fp64_mul(input, fp64_atof(SCALE_FACTOR)));

    // Re-check for over/underflow in the sign bit, since fp64_compare doesn't work properly with
    // numbers slightly greater/smaller than DEC32_MAX/MIN

    // If the signs match
    if (fp64_signbit(output) == fp64_signbit(input)){
      // No error
      return 0;
    }

    // If the signs don't match, there was an error
    else {
      // If the input had a negative sign
      if (fp64_signbit(input) != 0){
        // If the input was -0.0, special case
        if (fp64_compare(fp64_abs(input), fp64_atof("0.0")) == 0) {
          // Remove the sign, the truncation is then complete
          output = fp64_atof("0.0");
          // No error
          return 0;
        }
        // If the input was a negative number
        else {
          // Output the largest possible value to minimize the error
          output = INT32_MIN;
          // Error code 2: Underflow
          return 2;
        }
      }
      // If the input had a "positive" sign
      else {
        // Output the largest possible value to minimize the error
        output = INT32_MAX;
        // Error code 1: Overflow
        return 1;
      }
    }
  }
}