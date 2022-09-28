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

protected :
	void setData(int data);
	virtual int aleaGenVal() = 0;

private:
	int data;
};

