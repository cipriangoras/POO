#pragma once
#include "Car.h"
#include "Weather.h"
class Volvo : public Car {
public:
    double GetFuelCapacity() const override { return 50.0; }
    double GetFuelConsumption() const override { return 8.0; }
    double GetAverageSpeed(Weather weather) const override {
        switch (weather) {
        case Weather::Rain: return 80.0;
        case Weather::Sunny: return 100.0;
        case Weather::Snow: return 60.0;
        }
        return 0; 
    }
};