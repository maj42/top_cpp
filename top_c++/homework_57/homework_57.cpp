#include <iostream>
#include <vector>

class Dynosaur {
	std::string name;
	int age;
public:
	Dynosaur(std::string name, int age) : name(name), age(age) {}
	virtual ~Dynosaur() {};

	std::string getName() const {
		return name;
	}

	void setName(std::string newName) {
		name = newName;
	}

	int getAge() const {
		return age;
	}

	void setAge(int newAge) {
		age = newAge;
	}

	virtual void move() const = 0;
	virtual void sound() const = 0;
};

class Triceratops : virtual public Dynosaur {
public:
	Triceratops(std::string name, int age) : Dynosaur(name, age) {}

	~Triceratops() override {}
	
	void move() const override {
		std::cout << "Triceratops " << this->getName() << " is walking" << std::endl;
	}

	void sound() const override {
		std::cout << "Hello, I'm triceratops " << this->getName() << ", I'm " << this->getAge() << std::endl;
	}
};

class Archaeopteryx : virtual public Dynosaur {
public:
	Archaeopteryx(std::string name, int age) : Dynosaur(name, age) {}
	
	~Archaeopteryx() override {}
	
	void move() const override {
		std::cout << "Archaeopteryx " << this->getName() << " is flying" << std::endl;
	}

	void sound() const override {
		std::cout << "Hello, I'm Archaeopteryx " << this->getName() << ", I'm " << this->getAge() << std::endl;
	}
};

class DynosaurManager {
	std::vector<Dynosaur*> dynoVec;
public:
	DynosaurManager() : dynoVec{} {}
	~DynosaurManager() {
		for (Dynosaur* dyno : dynoVec) dyno->~Dynosaur();
	}
	void addTryceratops(std::string name, int age) {
		dynoVec.push_back(new Triceratops{ name, age });
	}

	void addArchaeopteryx(std::string name, int age) {
		dynoVec.push_back(new Archaeopteryx{ name, age });
	}

	void ShowAllDino() {
		for (Dynosaur* dyno : dynoVec) {
			dyno->move();
			dyno->sound();
			std::cout << std::string(40, '-') << std::endl;
		}
	}
};

int main()
{
	DynosaurManager dynoManager;
	dynoManager.addTryceratops("Vasya", 150);
	dynoManager.addArchaeopteryx("Jora", 145);
	dynoManager.ShowAllDino();
}
