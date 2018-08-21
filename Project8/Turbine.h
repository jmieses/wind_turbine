#pragma once
#include <math.h>
#include "Read.h"
#include "WindSpeed.h"
#define PI 3.14159265358979323846

class Turbine : public WindSpeed
{
private:
	double rotor_radius;
	double power_coefficient;
	WindSpeed* wind_properties; // avoid error c2280
public:
	Turbine();
	Turbine(double);
	Turbine(double, double, WindSpeed&);
	Turbine(double, double, double, double);
	void setRotorRadius(double);
	void setWindProperties(WindSpeed);
	double getRotorRadius() const;
	double TurbinePower();

	WindSpeed getWindProperties();
	~Turbine();
};

