#pragma once
#include "Car.h"
#include "Weather.h"
class Mercedes : public Car {
public:
    double GetFuelCapacity() const override { return 55.0; }
    double GetFuelConsumption() const override { return 6.0; }
    double GetAverageSpeed(Weather weather) const override {
        switch (weather) {
        case Weather::Rain: return 70.0;
        case Weather::Sunny: return 90.0;
        case Weather::Snow: return 55.0;
        }
        return 0;
    }
};