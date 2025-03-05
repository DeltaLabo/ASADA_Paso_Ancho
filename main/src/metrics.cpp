#include "metrics.h"

/**** Individual metrics ****/
AverageMetric_int16::AverageMetric_int16(int sampleFreq, int avgFreq) {
  length = sampleFreq / avgFreq + 5;
  counter = 0;
  array = (int16_t*)malloc(length * sizeof(int16_t));
  overflow = false;
}

void AverageMetric_int16::append(int16_t value) {
  array[counter] = value;
  counter++;
}

void AverageMetric_int16::calculate() {
  int64_t sum = 0;
  overflow = false;
  for (int i = 0; i < counter; i++) {
    // Check for overflow before adding the value
    if (sum > INT64_MAX - array[i]) {
      // Handle overflow
      overflow = true;
      sum = INT64_MAX;
      break;
    }
    sum += array[i];
  }
  avg = (float)sum / counter;
  counter = 0;
}

int16_t AverageMetric_int16::getResult() {
  return avg;
}

bool AverageMetric_int16::hasOverflowed() {
  return overflow;
}

AverageMetric_int32::AverageMetric_int32(int sampleFreq, int avgFreq) {
  length = sampleFreq / avgFreq + 5;
  counter = 0;
  array = (int32_t*)malloc(length * sizeof(int32_t));
  overflow = false;
}

void AverageMetric_int32::append(int32_t value) {
  array[counter] = value;
  counter++;
}

void AverageMetric_int32::calculate() {
  int64_t sum = 0;
  overflow = false;
  for (int i = 0; i < counter; i++) {
    // Check for overflow before adding the value
    if (sum > INT64_MAX - array[i]) {
      // Handle overflow
      overflow = true;
      sum = INT64_MAX;
      break;
    }
    sum += array[i];
  }
  avg = (float)sum / counter;
  counter = 0;
}

int32_t AverageMetric_int32::getResult() {
  return avg;
}

bool AverageMetric_int32::hasOverflowed() {
  return overflow;
}

MaxMetric_int16::MaxMetric_int16() {
  max = INT16_MIN;
}

void MaxMetric_int16::append(int16_t value) {
  if (value > max) {
    max = value;
  }
}

void MaxMetric_int16::calculate() {
  // No calculation needed for max
}

int16_t MaxMetric_int16::getResult() {
  return max;
}

MaxMetric_int32::MaxMetric_int32() {
  max = INT32_MIN;
}

void MaxMetric_int32::append(int32_t value) {
  if (value > max) {
    max = value;
  }
}

void MaxMetric_int32::calculate() {
  // No calculation needed for max
}

int32_t MaxMetric_int32::getResult() {
  return max;
}

MinMetric_int16::MinMetric_int16() {
  min = INT16_MAX;
}

void MinMetric_int16::append(int16_t value) {
  if (value < min) {
    min = value;
  }
}

void MinMetric_int16::calculate() {
  // No calculation needed for min
}

int16_t MinMetric_int16::getResult() {
  return min;
}

MinMetric_int32::MinMetric_int32() {
  min = INT32_MAX;
}

void MinMetric_int32::append(int32_t value) {
  if (value < min) {
    min = value;
  }
}

void MinMetric_int32::calculate() {
  // No calculation needed for min
}

int32_t MinMetric_int32::getResult() {
  return min;
}

/**** Manager class to calculate multiple metrics for a variable ****/
void MetricsManager_int16::addMetric(Metric16* metric) {
  metrics.push_back(metric);
}

void MetricsManager_int16::append(int16_t value) {
  for (auto& metric : metrics) {
    metric->append(value);
  }
}

void MetricsManager_int16::calculate() {
  for (auto& metric : metrics) {
    metric->calculate();
  }
}

int16_t MetricsManager_int16::getResult(int index) {
  return metrics[index]->getResult();
}

bool MetricsManager_int16::hasOverflowed(int index) {
  return metrics[index]->hasOverflowed();
}

void MetricsManager_int32::addMetric(Metric32* metric) {
  metrics.push_back(metric);
}

void MetricsManager_int32::append(int32_t value) {
  for (auto& metric : metrics) {
    metric->append(value);
  }
}

void MetricsManager_int32::calculate() {
  for (auto& metric : metrics) {
    metric->calculate();
  }
}

int32_t MetricsManager_int32::getResult(int index) {
  return metrics[index]->getResult();
}

bool MetricsManager_int32::hasOverflowed(int index) {
  return metrics[index]->hasOverflowed();
}