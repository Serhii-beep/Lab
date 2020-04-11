#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <chrono>
#include "g2use.h"


void aboutPerson();
void inputRoute(std::string& rrtif, std::string& rtof);


int main() 
{
	setlocale(LC_ALL, "ukr");
	aboutPerson();
	std::string route_to_input_file;                                 //Шлях до вхідного файлу
	std::string route_to_output_file;                                //Шлях до вихідного файлу
	inputRoute(route_to_input_file, route_to_output_file);
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open(route_to_input_file);
	out_file.open(route_to_output_file, std::ofstream::app);
	processData(in_file, out_file);
	in_file.close();
	out_file.close();
	std::chrono::steady_clock::time_point finish = std::chrono::high_resolution_clock::now();
	std::cout << "Програма виконувалась " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " мiлiсекунд\n";
	return 0;
}


void aboutPerson() 
{
	std::cout << "Лабораторна робота\nСтудента групи К-15\nПешка Сергiя\nВарiант: 66\n";
	std::cout << "У вхiдному файлi координати вершин повиннi бути записанi без ком через пробiл, не повинно бути порожнiх рядкiв\n";
	std::cout << "Ознакою закінчення рядка є повторення першої точки\n";
	std::cout << "Наприклад, 12 43 23 56 означатиме, що дано двi вершини з координатами (12, 43) та (23, 56)\n";
}


void inputRoute(std::string& rtif, std::string& rtof) 
{
	std::ifstream temp;
	do
	{
		std::cout << "Введiть шлях до файлу з даними про многокутник:\n";
		std::getline(std::cin, rtif);
		temp.open(rtif);
	} while (!temp.is_open() && rtif.size() != 0);                     //Якщо користувач не ввів шлях до файлу, то йому пропонується знову його ввести
	temp.close();
	std::cout << "Введiть шлях до файлу, в який потрiбно вивести результати роботи програми:\n";
	std::getline(std::cin, rtof);
	if (rtof.size() == 0) { rtof = "out.txt"; }                         //Якщо введено порожній рядок то створиться файл out.txt
}