#pragma once
#include "Read.h"

class WindSpeed : public Read
{
	double density;
	double average_wind_speed;
	Read* read; // avoid error c2280
public:
	WindSpeed();
	WindSpeed(double, double);
	WindSpeed(const double&,  Read&);
	void setDensity(double);
	void setWindSpeed(double);
	double getDensity() const;
	double getWindSpeed() const;
	void averageWind(int, int);

	~WindSpeed();
};

