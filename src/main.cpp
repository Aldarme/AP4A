/**
 * @author Timothe Watteau
 * @file main.cpp
 * @date 25/09/2022
 * @brief main file
 */

#include "Server.hpp"

int main()
{
	Server server;
	float t, h, l, p;
	t = 0;
	h = 0;
	l = 0;
	p = 0;
	server.consoleWrite(t, h, l, p);
  return 0;
}