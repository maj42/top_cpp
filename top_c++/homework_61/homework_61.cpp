#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

struct Student {
	std::string name;
	std::string speciality;
	int class_;
};

void addStudent(Student& student, std::string filename) {
	std::ofstream os{ filename, std::ios::app };
	if (!os) {
		std::cerr << "No file";
		return;
	}
	os << student.name << ' ' << student.speciality << ' ' << student.class_ << std::endl;
	os.close();
}

void viewStudents(std::string filename) {
	std::ifstream is{ filename };
	if (!is) {
		std::cerr << "No file";
		return;
	}
	std::string name;
	std::string spec;
	int class_;
	while (is >> name >> spec >> class_) {
		std::cout << "Name: " << name << " Speciality: " << spec << " Class: " << class_ << std::endl;
	}
	is.close();
	remove(filename.c_str());
}

int main()
{
	const std::string filename = "students.txt";

	Student st1{ "Vasya", "Programmer", 3 };
	Student st2{ "Masha", "Designer", 4 };
	Student st3{ "John", "Manager", 1 };

	addStudent(st1, filename);
	addStudent(st2, filename);
	addStudent(st3, filename);

	viewStudents(filename);
}
