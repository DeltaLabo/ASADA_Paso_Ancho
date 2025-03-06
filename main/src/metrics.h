#ifndef METRICS_H
#define METRICS_H

#define AVG_METRIC 0
#define MAX_METRIC 1
#define MIN_METRIC 2

#include <Arduino.h>
#include <vector>

class Metric_int16 {
  public:
    virtual void append(int16_t value) = 0;
    virtual void calculate() = 0;
    virtual int16_t getResult() = 0;
    virtual bool hasOverflowed() = 0;
};

class Metric_int32 {
  public:
    virtual void append(int32_t value) = 0;
    virtual void calculate() = 0;
    virtual int32_t getResult() = 0;
    virtual bool hasOverflowed() = 0;
};

class AverageMetric_int16 : public Metric_int16 {
  private:
    int counter;
    int length;
    int16_t* array;
    int16_t avg;
    bool overflow;

  public:
    AverageMetric_int16(int sampleFreq, int avgFreq);
    void append(int16_t value) override;
    void calculate() override;
    int16_t getResult() override;
    bool hasOverflowed() override;
};

class AverageMetric_int32 : public Metric_int32 {
  private:
    int counter;
    int length;
    int32_t* array;
    int32_t avg;
    bool overflow;

  public:
    AverageMetric_int32(int sampleFreq, int avgFreq);
    void append(int32_t value) override;
    void calculate() override;
    int32_t getResult() override;
    bool hasOverflowed() override;
};

class MaxMetric_int16 : public Metric_int16 {
  private:
    int16_t max;

  public:
    MaxMetric_int16();
    void append(int16_t value) override;
    void calculate() override;
    int16_t getResult() override;
    bool hasOverflowed() override { return false; }
};

class MaxMetric_int32 : public Metric_int32 {
  private:
    int32_t max;

  public:
    MaxMetric_int32();
    void append(int32_t value) override;
    void calculate() override;
    int32_t getResult() override;
    bool hasOverflowed() override { return false; }
};

class MinMetric_int16 : public Metric_int16 {
  private:
    int16_t min;

  public:
    MinMetric_int16();
    void append(int16_t value) override;
    void calculate() override;
    int16_t getResult() override;
    bool hasOverflowed() override { return false; }
};

class MinMetric_int32 : public Metric_int32 {
  private:
    int32_t min;

  public:
    MinMetric_int32();
    void append(int32_t value) override;
    void calculate() override;
    int32_t getResult() override;
    bool hasOverflowed() override { return false; }
};

class MetricsManager_int16 {
  private:
    std::vector<Metric_int16*> metrics;

  public:
    void addMetric(Metric_int16* metric);
    void append(int16_t value);
    void calculate();
    int16_t getResult(int index);
    bool hasOverflowed(int index);
};

class MetricsManager_int32 {
  private:
    std::vector<Metric_int32*> metrics;

  public:
    void addMetric(Metric_int32* metric);
    void append(int32_t value);
    void calculate();
    int32_t getResult(int index);
    bool hasOverflowed(int index);
};

#endif // METRICS_H