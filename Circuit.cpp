#include "Circuit.h"
#include <iostream>

void Circuit::Race()
{
	for (int i = 0; i < 3; i++)
	{
		double time = length / cars[i]->GetAverageSpeed(weather);
		double fuelNeeded = time * cars[i]->GetFuelConsumption();
		if (fuelNeeded <= cars[i]->GetFuelCapacity()) {
			std::cout << "Masina"<< cars[i]<<  "a finisat in " << time << " ore.\n";
		}
		else {
			std::cout << "Masina nu a finisat din lipsa de combustibil.\n";
		}
	}
}
void Circuit::AddCar(Car* car)
{
	for (int i = 0; i < 3; ++i) {
		if (cars[i] == nullptr) {
			cars[i] = car;
			return;
		}
	}
	std::cout << "Could not add car, no space available\n";
}



