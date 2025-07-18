#ifndef SENSORPAGE_H
#define SENSORPAGE_H
#include "page.h"
class SensorPage:public Page{
public:
    SensorPage();
    const std::string& getContent() const override;
private:
    float mTemperature;
    float mPressure;
    float mHumidity;
};

#endif