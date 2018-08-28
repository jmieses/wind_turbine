#include "WindSpeed.h"


WindSpeed::WindSpeed()
{
	density = 0;
	average_wind_speed = 0;
	read = new Read();
}

WindSpeed::WindSpeed(double new_density, double new_average_wind_speed){
	density = new_density;
	average_wind_speed = new_average_wind_speed;
}

WindSpeed::WindSpeed(const double& new_density,  Read& new_read){
	density = new_density;
	read = &new_read;  // shallow copy 
}

void WindSpeed::setDensity(double new_density){
	density = new_density;
}

void WindSpeed::setWindSpeed(double new_average_wind_speed){
	average_wind_speed = new_average_wind_speed;
}

double WindSpeed::getDensity() const{
	return density;
}

double WindSpeed::getWindSpeed() const{
	return average_wind_speed;
}

void WindSpeed::averageWind(int first, int last){
	const std::vector<double>&  wind_speed = read->getData1();
	std::cout << read->getData1().size() << std::endl;
	//const std::vector<double>&  wind_direction = read.getData2();
	double sum = 0;
	for (int i = first; i < last; i++){
		sum += wind_speed[i];
	}
	average_wind_speed = sum / abs((double)last - (double)first);
}

/* Definition of the rule of three. Copy constructor, overloaded assignment operator, destructor. 
Check comment at WindSpeed.h file for reference. */

// copy constructor

WindSpeed::WindSpeed(const WindSpeed& w){
	this->density = w.density;
	this->average_wind_speed = w.average_wind_speed;
	read = new Read();
	
	std::copy(w.read->data1.begin(), w.read->data1.end(), this->read->data1.begin());
	std::copy(w.read->data2.begin(), w.read->data2.end(), this->read->data2.begin());
	std::copy(w.read->date_time.begin(), w.read->date_time.end(), this->read->date_time.begin());
	
}

// overloaded operator assignment

WindSpeed& WindSpeed:: operator=(const WindSpeed w){

	if (this == &w){
		return *this;
	}
	this->density = w.density;
	this->average_wind_speed = w.average_wind_speed;

	std::copy(w.read->data1.begin(), w.read->data1.end(), this->read->data1.begin());
	std::copy(w.read->data2.begin(), w.read->data2.end(), this->read->data2.begin());
	std::copy(w.read->date_time.begin(), w.read->date_time.end(), this->read->date_time.begin());

	return *this;
}
WindSpeed::~WindSpeed()
{
	delete read;
}
