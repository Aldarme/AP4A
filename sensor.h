#pragma once
#include <iostream>
#include <string>
using namespace std;

class sensor
{
private :
	float donnees;
public:
	sensor();
	~sensor();
	float getData();
	void setdata();
protected :
	float aleaGenVal();
	   
};