#include "g2use.h"


void processData(std::ifstream& input_file, std::ofstream& output_file)
{
	std::list<Point> points;
	while (!input_file.eof())
	{
		readData(points, input_file);
		try {
			checkPoints(points);
			output_file << "�����: " << calculateSquare(points) << "\n";
		}
		catch (char)
		{
			output_file << "�� ������� ���������� ����� ����� ���� �i���i��� �����\n";
		}
		catch (int)
		{
			output_file << "���� �������� ��i ����� � ���������� ������������(�� �� ����� � �������)\n";

		}
	}
}


void readData(std::list<Point>& points, std::ifstream& input_file)
{
	if(!points.empty()) { points.clear(); }
	double x, y;
	input_file >> x >> y;
	points.push_back({ x, y });
	auto it = points.begin();
	do
	{
		input_file >> x >> y;
		points.push_back({ x, y });
	} while (!(((*it).getX() == x) && ((*it).getY() == y)));    //�����, � ��� ���������� ��� � �� � � ��������� � ������� ���������
}

double calculateSquare(std::list<Point>& points)
{
	if(points.size() <= 3 || points.size() > 10000) 
	{
		/*�������, ���� ����� ����� ���� 2 ��� ����� 10000, ������� � ���� �������, �� ����� �� ����� 10000*/
		throw 'A';     
	}
	
	double square = 0;
	for (auto it = points.begin(); it != points.end(); ++it) 
	{
		/*����� �������� �� �������� �����(� ����� ���� ����� ������� �������)*/
		++it;
		if (it == points.end()) { break; }
		--it;
		square += (*it).getX() * (*(++it)).getY();
		--it;
	}
	auto it = points.begin();
	++it;
	for(it; it != points.end(); ++it) 
	{
		/*� ����� ���� �������� ����� ������� �������*/
		++it;
		if(it == points.end()) 
		{
			std::advance(it, -2);
			auto temp = points.begin();
			square -= (*temp).getX() * (*it).getY();
			break;
		}
		--it;
		square -= (*it).getX() * (*(--it)).getY();
		++it;
	}
	square = fabs(square) / 2;  //� ���� �� ������� ������� �����
	return square;
}

void checkPoints(std::list<Point> points)
{
	if(!points.empty()) { points.pop_back(); }
	for(auto x : points) 
	{
		if(std::count(points.begin(), points.end(), x) > 1) 
		{
			throw 0;
		}
	}
}
					
