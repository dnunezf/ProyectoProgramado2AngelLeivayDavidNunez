//CLASE ABSTRACTA ComponenteTablero, es el componente

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class ComponenteTablero
{
	public:
		virtual ~ComponenteTablero()
		{

		}

		virtual string toString() const = 0;
};