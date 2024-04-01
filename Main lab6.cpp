#include "Weather.h"
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "MercedesBenz.h"
#include "Circuit.h"
#include <iostream>


int main()
{
	Volvo volvo;
	Mercedes mercedes;
	BMW bmw;

	Circuit c1;
	c1.SetLength(100);
	c1.AddCar(&volvo);
	c1.AddCar(&mercedes);
	c1.AddCar(&bmw);

	c1.Race();


}


