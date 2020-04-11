#pragma once
#include <fstream>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include "g2.h"


void processData(std::ifstream& input_file, std::ofstream& output_file); //�������, ��� ������� �� ���� �� � �������� ���� main

void readData(std::list<Point>& points, std::ifstream& input_file);      //������� ����� ��������� ��'���� � �����

double calculateSquare(std::list<Point>& points);                        //������� ���� ����� ������������ 

void checkPoints(std::list<Point> points);                               //������� �������� �� �� ������������ ����� �� �� �� � ����� ������