#ifndef _FLAT_H_
#define _FLAT_H_

#include <string>
#include <iostream>
#include <iomanip>

#include "GetSquare.h"

class Flat
{
private:
	std::string _street;
	std::string _numberHouse;
	std::string _numberFlat;
	double _price;
	double _square;
	GetSquare* _getSquare;

public:
	


	Flat();
	Flat(std::string street, std::string numberHouse, std::string numberFlat, double price, double square);
	Flat(std::string street);
	Flat(std::string street, std::string numberHouse);
	Flat(std::string street, std::string numberHouse, std::string numberFlat);
	Flat(std::string street, std::string numberHouse, std::string numberFlat, double price);
	~Flat();
	Flat(const Flat& f);
	Flat& operator=(const Flat& f);
	bool operator==(const Flat& f);
	bool operator>(const Flat& f);
	bool operator<(const Flat& f);
	std::string GetStreet();
	std::string GetNumberHouse();
	std::string GetNumberFlat();
	double GetPrice();
	double GetSquare_();
	void SetGetSquareIn(GetSquare* getSquare);
	void ShowFlat();
};

#endif // !_FLAT_H_

