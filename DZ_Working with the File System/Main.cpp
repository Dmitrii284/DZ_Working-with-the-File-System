#include <iostream>
#include <fstream>
#include<string>

bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;					
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	in.close();
	return false;
}
	

bool overwrite(std::string file_path, std::string str1);

int main() {
	setlocale(LC_ALL, "Rus");
	//Task 1
	std::ofstream out;
	out.open("file.txt", std::ios::app);
	if (out.is_open()) {
		std::string input;
		do{
		std::cout << "Введите строку: ";
		std::getline(std::cin, input);		
		out << input << "\n";		
		} while (input != "end");		
	}
	else
		std::cout << "Ошибка открытия файла1\n";
	out.close();

	std::ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str)) {
			std::cout << str << std::endl;
		}
	}	
	else
		std::cout << "Ошибка открытия файла2 \n";
	in.close();
	remove("file.txt");

	//Task 2
	
	std::string path = "file2.txt";
	std::cout << "Начальное содержимое файла №2: \n";	
	print_file(path);		
		std::cout << "Введите текст -> ";
		std::string str2;
		std::getline(std::cin, str2);
		overwrite(path, str2);
		std::cout << "Конечное содержимое файла №2: \n";
		print_file(path);

	return 0;
}

bool overwrite( std::string file_path, std::string str1) {
	
	std::ofstream file;
	file.open(file_path, std::ios::out);
	if(file.is_open()) {		
		file << str1 << "\n";
		std::cout << std::endl;
		file.close();
		return true;
	}
	else 
		std::cout << "Ошибка открытия файла.\n";
		file.close();
		return false;	
}

	