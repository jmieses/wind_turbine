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

	/*Used the rule of three to avoid using a deleted dafault function. Implement the following: 
	copy constructor, overloaded assignment operator, and destructor. Once these are implemented 
	dafault member functions won't be created.*/

	// copy constructor
	WindSpeed(const WindSpeed&);

	// overloaded assignment operator
	WindSpeed& operator=(const WindSpeed);

	// Destructor
	~WindSpeed();
};

