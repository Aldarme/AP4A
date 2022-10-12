/**
 * @file Package.cpp
 * @author Loric Ravassard
 * @brief regroupe toutes les données dans un packet pour pouvoir les exploiter
 * @version 1
 * @date 2022-10-05
 */

#include "Package.hpp"
#include <string>
#include <vector>
#include <iostream>

Package& Package::operator=(const Package& other_p)
{
  m_allData = other_p.m_allData;
  return *this;
}

void Package::addMeasure(std::string date_p, std::string name_p, int val_p, std::string unit_p)
{
  data temp;
  temp.date = date_p;
  temp.name = name_p;
  temp.value = val_p;
  temp.unit = unit_p;
  m_allData.push_back(temp);
}

void Package::clear()
{
  m_allData.clear();
}

std::vector<data> Package::getVector() const
{
  return m_allData;
}