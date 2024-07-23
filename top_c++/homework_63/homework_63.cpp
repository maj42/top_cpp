//Удалите из unordered_map элементы, которые делятся на 2, и выведите ключи этих элементов.

#include <iostream>
#include <unordered_map>

void deleteEvenKeys(std::unordered_map<int, int>& map) {
	auto iter = map.begin();
	while (iter != map.end()) {
		iter = std::find_if(iter, map.end(), [](const std::pair<int, int>& pair) { return !(pair.second % 2); });
		std::cout << "Deleting " << (*iter).first << std::endl;
		auto deleteIter = iter++;
		map.erase(deleteIter);
	}
}

int main()
{
	std::unordered_map<int, int> dict{
		std::make_pair(0, 10),
		std::make_pair(1, 21),
		std::make_pair(2, 30),
		std::make_pair(3, 41),
		std::make_pair(4, 50),
		std::make_pair(5, 61),
		std::make_pair(6, 70),
		std::make_pair(7, 81),
		std::make_pair(8, 90)
	};
	deleteEvenKeys(dict);
}
