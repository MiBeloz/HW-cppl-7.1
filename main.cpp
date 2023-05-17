#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


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

	std::map<char, int> map_char;
	for (const auto& el : default_text) {
		auto it = map_char.find(el);
		if (it == map_char.end()) {
			map_char[el] = 1;
		}
		else {
			map_char[el] = it->second + 1;
			
		}
	}

	std::vector<std::pair<char, int>> vector_char(map_char.begin(), map_char.end());

	std::sort(vector_char.begin(), vector_char.end(), [](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {
		return lhs.second > rhs.second; });

	for (const auto& el : vector_char) {
		std::cout << el.first << ": " << el.second << std::endl;
	}

	system("pause > nul");
	return 0;
}