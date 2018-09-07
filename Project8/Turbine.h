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

public:
	WindSpeed* wind; // avoid error c2280

	Turbine();
	Turbine(double, double);
	Turbine(double, double, WindSpeed&);
	void setRotorRadius(double);
	void setWindProperties(WindSpeed);
	const double getRotorRadius() const;
	const double TurbinePower() const;

	WindSpeed getWindProperties();
	~Turbine();
};

