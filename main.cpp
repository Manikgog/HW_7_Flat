/*
Для вывода площади квартиры применён паттерн "Стратегия" 
*/
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Flat.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	

	Flat f1("Энгельса", "36", "419/3", 5000000.1f, 20.0f);
	Flat f3("Энгельса", "36", "421", 5100000.1f, 20.0f);
	Flat f4("Энгельса", "36", "422", 5100000.1f, 25.0f);
	
	// Проверка правильности выполнения перегруженной операции присвоения
	Flat f2 = f1;
	assert(f2.GetNumberFlat() == f1.GetNumberFlat());
	assert(f2.GetNumberHouse() == f1.GetNumberHouse());
	assert(f2.GetStreet() == f1.GetStreet());
	assert(f2.GetPrice() == f1.GetPrice());
	
	std::cout << "Square in metres - " << f1.GetSquare_() << std::endl;
	f1.SetGetSquareIn(new GetSquareInFeet(f1.GetSquare_()));				// установка объекта для вычисления площади в квадратных футах
	std::cout << "Square in feet - " << f1.GetSquare_() << std::endl;

	f2.ShowFlat();
	
	// Проверка равенства площадей квартир
	assert((f3 == f1) == 1);

	// Проверка неравенства цены
	assert((f3 < f4) == 1);
	assert((f4 > f2) == 1);
	assert((f3 > f1) == 0);


	return 0;
}
