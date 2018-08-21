
#include "Turbine.h"


Turbine::Turbine()
{
}

Turbine::Turbine(double new_rotor_radius){
	rotor_radius = new_rotor_radius;
}



Turbine::Turbine(double new_rotor_radius, double new_power_coefficient,
	double new_density, double new_average_wind_speed){

	rotor_radius = new_rotor_radius;
	power_coefficient = new_power_coefficient;
	wind_properties->setDensity(new_density);
	wind_properties->setWindSpeed(new_average_wind_speed);
}

Turbine::Turbine(double new_rotor_radius, double new_power_coefficient, WindSpeed& new_wind_properties){
	rotor_radius = new_rotor_radius;
	power_coefficient = new_power_coefficient;
	wind_properties = &new_wind_properties;
}

void Turbine::setRotorRadius(double new_rotor_radius){
	rotor_radius = new_rotor_radius;
}

double Turbine::getRotorRadius() const{
	return rotor_radius;
}

//WindSpeed Turbine::getWindProperties(){
//	return wind_properties;
//
//}

double Turbine::TurbinePower(){
	// Power = 0.5*density*Cp*pi*R^2*U^3
	std::cout << "this density: " << this->wind_properties->getDensity()<< std::endl;
	std::cout << "this wind: " <<  this->wind_properties->getWindSpeed() << std::endl;
	return 0.5*this->wind_properties->getDensity()*power_coefficient*PI*pow(rotor_radius, 2)*this->wind_properties->getWindSpeed();
}

Turbine::~Turbine()
{
}
