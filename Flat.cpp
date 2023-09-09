#include "Flat.h"
#include "GetSquare.h"

Flat::Flat()
	: _street("")
	, _numberHouse("")
	, _numberFlat("")
	, _price(0)
	, _square(0)
	, _getSquare(new GetSquareInMetres(_square)){}

Flat::Flat(std::string street, std::string numberHouse, std::string numberFlat, double price, double square)
	: _street(street)
	, _numberHouse(numberHouse)
	, _numberFlat(numberFlat)
	, _price(price)
	, _square(square)
	, _getSquare(new GetSquareInMetres(_square)) {}

Flat::Flat(std::string street)
	: Flat(street, "", "", 0.0f, 0.0f){}

Flat::Flat(std::string street, std::string numberHouse)
	: Flat(street, numberHouse, "", 0.0f, 0.0f) {}

Flat::Flat(std::string street, std::string numberHouse, std::string numberFlat)
	: Flat(street, numberHouse, numberFlat, 0.0f, 0.0f){}

Flat::Flat(std::string street, std::string numberHouse, std::string numberFlat, double price)
	: Flat(street, numberHouse, numberFlat, price, 0.0f) {}

Flat::~Flat() {
	if (_getSquare)
		delete _getSquare;
}

Flat::Flat(const Flat& f) : Flat(f._street, f._numberHouse, f._numberFlat, f._price, f._square)
{
	_getSquare = new GetSquareInMetres(f._square); 
}

Flat& Flat::operator=(const Flat& f)
{
	if (this == &f)
		return *this;
	this->_street = f._street;
	this->_numberHouse = f._numberHouse;
	this->_numberFlat = f._numberFlat;
	this->_price = f._price;
	this->_square = f._square;
	if (this->_getSquare)
		delete _getSquare;
	this->_getSquare = f._getSquare;
	return *this;
}

bool Flat::operator==(const Flat& f)
{
	if (_square == f._square)
		return true;
	return false;
}

bool Flat::operator>(const Flat& f)
{
	if (_square > f._square)
		return true;
	return false;
}

bool Flat::operator<(const Flat& f)
{
	if (_square < f._square)
		return true;
	return false;
}

std::string Flat::GetStreet()
{
	return _street;
}

std::string Flat::GetNumberHouse()
{
	return _numberHouse;
}

std::string Flat::GetNumberFlat()
{
	return _numberFlat;
}

double Flat::GetPrice()
{
	return _price;
}

double Flat::GetSquare_() {
	return _getSquare->Square();
}

void Flat::SetGetSquareIn(GetSquare* getSquare) {
	if(_getSquare)
		delete _getSquare;
	_getSquare = getSquare;
}

void Flat::ShowFlat()
{
	std::cout << "Адрес: " << _street << ", " << _numberHouse << "/" << _numberFlat << ".\n";
	std::cout << "Цена: "; 
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	std::cout << _price;
	std::cout << ", " << "площадь: "; 
	std::cout.precision(2); 
	std::cout << _square << "\n";
}