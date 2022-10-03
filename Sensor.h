#pragma once

#define LENGTH 2

class Light;
class Humidity;
class Pression;
class Temperature;

class Sensor {
public:
	Sensor();
	virtual ~Sensor() {
		delete[] specs;
	}

	Sensor(int type);
	Sensor(const Sensor& sensor);
	int getData();
	const char** getSpecifications();

protected :
	void setSpecifications(const char* spec1, const char* spec2 = "");
	void setData(int data);
	virtual int aleaGenVal() = 0;

private:
	int data;
	const char** specs;
};

