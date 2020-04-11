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
	std::string route_to_input_file;                                 //���� �� �������� �����
	std::string route_to_output_file;                                //���� �� ��������� �����
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
	std::cout << "�������� ������������ " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " �i�i������\n";
	return 0;
}


void aboutPerson() 
{
	std::cout << "����������� ������\n�������� ����� �-15\n����� ����i�\n���i���: 66\n";
	std::cout << "� ��i����� ����i ���������� ������ ������i ���� �������i ��� ��� ����� ����i�, �� ������� ���� ������i� ����i�\n";
	std::cout << "������� ��������� ����� � ���������� ����� �����\n";
	std::cout << "���������, 12 43 23 56 ����������, �� ���� ��i ������� � ������������ (12, 43) �� (23, 56)\n";
}


void inputRoute(std::string& rtif, std::string& rtof) 
{
	std::ifstream temp;
	do
	{
		std::cout << "����i�� ���� �� ����� � ������ ��� �����������:\n";
		std::getline(std::cin, rtif);
		temp.open(rtif);
	} while (!temp.is_open() && rtif.size() != 0);                     //���� ���������� �� ��� ���� �� �����, �� ���� ����������� ����� ���� ������
	temp.close();
	std::cout << "����i�� ���� �� �����, � ���� ����i��� ������� ���������� ������ ��������:\n";
	std::getline(std::cin, rtof);
	if (rtof.size() == 0) { rtof = "out.txt"; }                         //���� ������� ������� ����� �� ���������� ���� out.txt
}