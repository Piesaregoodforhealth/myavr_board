#include "sensorpage.h"
SensorPage::SensorPage(){
    mTemperature = 0;
    mPressure = 0;
    mHumidity = 0;
    mContent = "defualt page content";
}
const std::string& SensorPage::getContent() const{

    static std::string html = "<h1>Sensor data</h1>";
    html += "<p>Temperature= </a></p>"+std::to_string(mTemperature);
    html += "<p>Pressure= </a></p>"+std::to_string(mPressure);    
    html += "<p>Humidity= </a></p>"+std::to_string(mHumidity);   
    return html;
}