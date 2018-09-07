#include "Read.h"


Read::Read()
{
}

Read::Read(std::string new_file){
	file = new_file;
	readFile.open("../test/" + file);
	if (!readFile.is_open()){
		std::cout << "File could not be opened \n";
	}
}

//Read::Read(const Read& new_read){
//	file = new_read.file;
//	data1 = new_read.data1;
//	data2 = new_read.data2;
//	date_time = new_read.date_time;
//}

void Read::ReadStoreData(){
	// check that file is opened
	// read date, time, and data from file separated by ','

	if (readFile.is_open()){
		double temp1, temp2;
		std::string date, time, str_dummy;

		getline(readFile, str_dummy); // get rid of first line

		if (!data1.empty()){
			data1.clear();
		}
		else if (!data2.empty())
		{
			data2.clear();
		}
		// store the data into map data1, data2;
		while (!readFile.eof()){
			getline(readFile, date, ',');
			getline(readFile, time, ',');
			getline(readFile, str_dummy, ',');
			temp1 = stof(str_dummy);
			readFile >> temp2;

			date_time.push_back(date + ',' + time);
			data1.push_back(temp1);
			data2.push_back(temp2);
		}
	}
	else {
		std::cout << "File could not be open" << std::endl;
	}
}

void Read::ReadPrintData(){
	{
		// Display data on the console.
		for (const auto &it : date_time){
			std::cout << it << std::endl;
		}


	}
}

const std::string Read::getFileName() const{
	return file;
}

const std::vector<double>& Read::getData1() const{
	return data1;
}

const std::vector<double>& Read::getData2() const{
	return data2;
}

const std::vector<std::string>& Read::getDateTime() const{
	return date_time;
}

const int Read::getStringIndex(std::string date, std::string time) const {
	// get the index that represent the date and time 
	/*std::vector<std::string>::const_iterator date_it = std::find(date_time.cbegin(), date_time.cend(), date + ',' + time);
	return std::distance(date_time.cbegin(), date_it);*/
	int i = 0;
	while (('\n' + date + ',' + time) != date_time.at(i)){
		i++;
		if (i > date_time.size()) break;
	}
	return i;
}

// Rule of three definition

// copy constructor
Read::Read(const Read& r){

	// resize the vector containers data1, data2, date_time
	// so the iterator does not go out  of range
	if (!this->data1.empty()){

		size_t n = r.data1.size();
		this->data1.resize(n);
		this->data2.resize(n);
		this->date_time.resize(n);
	}

	std::cout << "Read Copy constructor called " << std::endl;
	if (!this->data1.empty()){
		std::copy(r.file.begin(), r.file.end() - 1, this->file.begin());
		std::copy(r.data1.begin(), r.data1.end() - 1, this->data1.begin());
		std::copy(r.data2.begin(), r.data2.end() - 1, this->data2.begin());
		std::copy(r.date_time.begin(), r.date_time.end() - 1, this->date_time.begin());
	}
	system("pause");
}

// overloaded assignment operator
Read& Read::operator=(const Read r){
	// check if the two objects have the same data. 
	// if same data return this object.
	if (this == &r){
		return *this;
	}
	std::copy(r.file.begin(), r.file.end(), this->file.begin());
	std::copy(r.data1.begin(), r.data1.end(), this->data1.begin());
	std::copy(r.data2.begin(), r.data2.end(), this->data2.begin());
	std::copy(r.date_time.begin(), r.date_time.end(), this->date_time.begin());

	return *this;
}

Read::~Read()
{
}
