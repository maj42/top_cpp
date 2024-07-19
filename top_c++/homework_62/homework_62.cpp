//Создайте приложение для работы автосалона.
//Необходимохранить информацию о продаваемых автомобилях(название, год выпуска, объем двигателя, цену).
//Реализуйте:
//простой интерфейс для добавления данных,
//удаления данных,
//отображения данных,
//сортировке данных по различным
//параметрам, поиску данных по различным параметрам.
//
//
//При реализации используйте контейнеры

#include <iostream>
#include <vector>
#include <algorithm>

struct Car {
	std::string name;
	int year;
	float engVolume;
	int price;

	Car(std::string name, int year, float engVolume, int price) : name(name), year(year), engVolume(engVolume), price(price) {}

	bool operator==(const Car& other) const {
		return (name == other.name && year == other.year && engVolume == other.engVolume && price == other.price);
	}
};

std::ostream& operator<<(std::ostream& os, Car car) {
	os << "Car name: " << car.name << "\n\tYear: " << car.year << "\n\tEngine volume: " << car.engVolume << "\n\tPrice: " << car.price << "\n\n";
	return os;
}

class Dealership {
	std::vector<Car> cars;

public:
	Dealership& addCar(Car car) {
		cars.push_back(car);
		return *this;
	}

	Dealership& addCar(std::string name, int year, float engVolume, int price) {
		cars.push_back(Car{name, year, engVolume, price});
		return *this;
	}

	Dealership& removeCar(std::string carName, int year) {
		for (Car car : cars) {
			if (car.name == carName && car.year == year) cars.erase(std::find(cars.begin(), cars.end(), car));
		}
		return *this;
	}

	Dealership& removeCar(std::string carName) {
		for (Car car : cars) {
			if (car.name == carName) cars.erase(std::find(cars.begin(), cars.end(), car));
		}
		return *this;
	}

	Dealership& showCars() {
		std::cout << "Here are my cars:\n";
		for (Car car : cars) {
			std::cout << car;
		}
		return *this;
	}

	Dealership& sort(std::string sortBy) {
		if (sortBy == "year") {
			std::cout << "Sorting by year" << std::endl;
			std::sort(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {return car1.year < car2.year; });
		}
		else if (sortBy == "engine") {
			std::cout << "Sorting by engine volume" << std::endl;
			std::sort(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {return car1.engVolume < car2.engVolume; });
		}
		else if (sortBy == "price") {
			std::cout << "Sorting by price" << std::endl;
			std::sort(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {return car1.price < car2.price; });
		}
		else {
			std::cout << "Sorting by name" << std::endl;
			std::sort(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {return car1.name < car2.name; });
		}
		return *this;
	}

	Dealership& searchByName(std::string search) {
		if (std::find_if(cars.begin(), cars.end(), [search](const Car& car) { return car.name == search; }) == cars.end()) {
			std::cout << "I have no such car" << std::endl;
			return *this;
		}
		std::cout << "Searching " << search << ":" << std::endl;
		auto it = cars.begin();
		while (true) {
			it = std::find_if(it, cars.end(), [search](const Car& car) { return car.name == search; });
			if (it != cars.end()) {
				std::cout << *it++;
			}
			else break;
		}
		return *this;
	}

	Dealership& searchByYear(int search) {
		if (std::find_if(cars.begin(), cars.end(), [search](const Car& car) { return car.year == search; }) == cars.end()) {
			std::cout << "I have no such car" << std::endl;
			return *this;
		}
		std::cout << "Searching " << search << " year cars:" << std::endl;
		auto it = cars.begin();
		while (true) {
			it = std::find_if(it, cars.end(), [search](const Car& car) { return car.year == search; });
			if (it != cars.end()) {
				std::cout << *it++;
			}
			else break;
		}
		return *this;
	}

	Dealership& searchByEng(float search) {
		if (std::find_if(cars.begin(), cars.end(), [search](const Car& car) { return car.engVolume == search; }) == cars.end()) {
			std::cout << "I have no such car" << std::endl;
			return *this;
		}
		std::cout << "Searching " << search << " engine volume cars:" << std::endl;
		auto it = cars.begin();
		while (true) {
			it = std::find_if(it, cars.end(), [search](const Car& car) { return car.engVolume == search; });
			if (it != cars.end()) {
				std::cout << *it++;
			}
			else break;
		}
		return *this;
	}

	Dealership& searchByPrice(int search) {
		if (std::find_if(cars.begin(), cars.end(), [search](const Car& car) { return car.price <= search; }) == cars.end()) {
			std::cout << "I have no such car" << std::endl;
			return *this;
		}
		std::cout << "Searching " << search << " or cheaper:" << std::endl;
		auto it = cars.begin();
		while (true) {
			it = std::find_if(it, cars.end(), [search](const Car& car) { return car.price <= search; });
			if (it != cars.end()) {
				std::cout << *it++;
			}
			else break;
		}
		return *this;
	}
};

int main()
{
	Dealership baryga;
	baryga.addCar("Toyota Yaris", 2004, 1.6, 300000);
	baryga.addCar("Ford Focus", 2017, 1.6, 1300000);
	baryga.addCar("Volkswagen Passat", 2012, 1.8, 1730000);
	baryga.addCar("Toyota Yaris", 2010, 1.8, 600000);
	baryga.addCar("Hyundai Getz", 2008, 1.4, 500000);

	baryga.showCars();

	baryga.sort("year");
	baryga.showCars();

	baryga.sort("engine");
	baryga.showCars();

	baryga.sort("price");
	baryga.showCars();

	baryga.sort("as;dklfa;sl");
	baryga.showCars();

	baryga.searchByName("Toyota Corolla");
	baryga.searchByName("Toyota Yaris");
	baryga.searchByYear(2010);
	baryga.searchByEng(1.6);
	baryga.searchByPrice(1000000);

	baryga.removeCar("Ford Focus");
	baryga.removeCar("Toyota Yaris", 2004);

	baryga.showCars();
}
