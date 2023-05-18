#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

typedef std::pair<char, int> p_ci;


int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	std::cout << "\tЧастота символов\n" << std::endl;

	std::string default_text{ "Hello world!!" };
	std::string in_text;
	std::cout << "Введите строку или 0(по умолчанию строка '" << default_text << "'):" << std::endl;
	std::getline(std::cin, in_text);
	if (in_text != "0") {
		default_text = in_text;
	}

	std::cout << "[IN]: " << default_text << std::endl << std::endl;
	std::cout << "[OUT]:" << std::endl;

	std::map<char, int> map;
	for (const auto& el : default_text) {
		auto it = map.find(el);
		if (it == map.end()) {
			map[el] = 1;
		}
		else {
			map[el] = it->second + 1;
			
		}
	}

	std::vector<p_ci> vector(map.begin(), map.end());

	std::sort(vector.begin(), vector.end(), [](const p_ci& lhs, const p_ci& rhs) {
		return lhs.second > rhs.second; });

	for (const auto& el : vector) {
		std::cout << el.first << ": " << el.second << std::endl;
	}

	system("pause > nul");
	return 0;
}