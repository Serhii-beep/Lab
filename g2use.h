#pragma once
#include <fstream>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include "g2.h"


void processData(std::ifstream& input_file, std::ofstream& output_file); //Функція, яка викликає всі інші та є головною після main

void readData(std::list<Point>& points, std::ifstream& input_file);      //Функція зчитує екземпляр об'єкту з файлу

double calculateSquare(std::list<Point>& points);                        //Функція рахує площу многокутника 

void checkPoints(std::list<Point> points);                               //Функція перевіряє чи не повторюються точки та чи не є рядок пустим