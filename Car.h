#pragma once
#include "Weather.h"
class Car {
public:
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather weather) const = 0;
};