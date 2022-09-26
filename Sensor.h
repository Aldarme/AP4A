#pragma once

class Light;
class Humidity;
class Pression;
class Temperature;

class Sensor {
public:
	Sensor();
	virtual ~Sensor() {

	}
	Sensor(int type);
	Sensor(const Sensor& sensor);
	int getData();
	void setData(int data);
	void write();
protected:
	int aleaGenVal();

private:
	int data;
};

