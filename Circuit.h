#pragma once
#include "Weather.h"
#include <vector>
#include "Car.h"
#include <iostream>



class Circuit {
	Weather weather;
	double length;
	Car* cars[3];
public:
	Circuit() {
		length = 0;
		weather = Weather::Sunny;
		for (int i = 0; i < 3; ++i) {
			cars[i] = nullptr;
		}
	}
	void SetLength(double l) { length = l; };
	void setWeather(Weather w) { weather = w; };
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish() {

	}

	~Circuit()
	{
		delete[] cars;
	}
};