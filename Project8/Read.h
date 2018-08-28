#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Read
{
private:
	std::ifstream readFile;
	std::string file;

protected:



public:
	std::vector<double> data1, data2;
	std::vector < std::string> date_time;

	Read();
	Read(std::string file);
	Read(const Read&);

	std::vector<std::string> * ReadStoreDateTimeData();

	void ReadStoreData();
	void ReadPrintData();

	const std::vector<double>& getData1() const;
	const std::vector<double>& getData2() const;
	const std::vector<std::string>& getDateTime() const;
	const int getStringIndex(std::string,std::string) const;

	

	~Read();
};

