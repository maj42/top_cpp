#include <iostream>

using namespace std;

union Var {
	int signedInt;
	unsigned unsignedInt;
};

struct Animal {
	string specName;
	string specClass;
	string name;
	string voice;

	Animal(string spN, string spCl, string name, string voice = "I can't talk right now") : specName(spN), specClass(spCl), name(name), voice(voice) {}

	void print() {
		cout << name << ":\n\tSpecies name: " << specName << "\n\tSpecies Class: " << specClass << "\n\n";
	}

	void talk() {
		cout << name << " says: " << voice << "\n\n";
	}
};

int main()
{
	//task1 Union
	Var variable{-10};
	cout << "Signed: " << variable.signedInt << "\nUnsigned: " << variable.unsignedInt << "\n\n";
	
	//task2 Struct
	Animal cat{ "Felis Catus", "Mammalia", "Vasya", "Meow" };
	Animal dog{ "Canis lupus familiaris", "Mammalia", "Rex", "Woof" };
	Animal platypus{ "Ornithorhynchus anatinus", "Mammalia", "Perry" };

	cat.print();
	cat.talk();
	dog.print();
	dog.talk();
	platypus.print();
	platypus.talk();

}
