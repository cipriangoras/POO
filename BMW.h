#pragma once
#include "Car.h"
#include "Weather.h"

class BMW :public Car
{
public:
    double GetFuelCapacity() const override { return 40.0; }
    double GetFuelConsumption() const override { return 7.0; }
    double GetAverageSpeed(Weather weather) const override {
        switch (weather) {
        case Weather::Rain: return 90.0;
        case Weather::Sunny: return 110.0;
        case Weather::Snow: return 50.0;
        }
        return 0;
    }
};