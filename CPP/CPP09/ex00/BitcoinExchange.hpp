
#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

void	storeData(std::map<std::string, double> &dataMap);
int		check_date(std::string date);
int		check_value(double value);
void	processInput(std::string filename, std::map<std::string, double> &map);