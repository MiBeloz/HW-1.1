#include <iostream>
#include <fstream>

void printArr(const int* arr, const int size);
void moveRight(int* arr, const int size);
void moveLeft(int* arr, const int size);

int main() {
	setlocale(LC_ALL, "ru");

	std::string fileIn{ "in.txt" };
	std::string fileOut{ "out.txt" };
	std::fstream file;
	int* arrOne = nullptr;
	int* arrTwo = nullptr;
	int sizeArrOne{};
	int sizeArrTwo{};

	file.open(fileIn, std::fstream::in);
	if (file.is_open()) {
		file >> sizeArrOne;
		arrOne = new int[sizeArrOne];
		for (int i = 0; i < sizeArrOne; i++) {
			file >> arrOne[i];
		}

		file >> sizeArrTwo;
		arrTwo = new int[sizeArrTwo];
		for (int i = 0; i < sizeArrTwo; i++) {
			file >> arrTwo[i];
		}

		std::cout << "������ �� ����� 'in.txt' ������� ���������.\n" << std::endl;
	}
	else {
		std::cout << "������ �������� ����� 'in.txt' ��� ������ ������!" << std::endl;
		system("pause > nul");
		return 0;
	}
	file.close();

	std::cout << "������ ������� �1: " << sizeArrOne << std::endl;
	std::cout << "������ �1: ";
	printArr(arrOne, sizeArrOne);

	std::cout << "������ ������� �2: " << sizeArrTwo << std::endl;
	std::cout << "������ �2: ";
	printArr(arrTwo, sizeArrTwo);
	std::cout << std::endl;

	moveRight(arrTwo, sizeArrTwo);
	std::cout << "�������� ������� �1 �������� �����." << std::endl;
	moveLeft(arrOne, sizeArrOne);
	std::cout << "�������� ������� �2 �������� ������." << std::endl;
	std::cout << std::endl;

	std::cout << "������ ������� �2: " << sizeArrTwo << std::endl;
	std::cout << "������ �2 ����� ������ ��������� ������: ";
	printArr(arrTwo, sizeArrTwo);

	std::cout << "������ ������� �1: " << sizeArrOne << std::endl;
	std::cout << "������ �1 ����� ������ ��������� �����: ";
	printArr(arrOne, sizeArrOne);
	std::cout << std::endl;

	file.open(fileOut, std::fstream::out);
	if (file.is_open()) {
		file << sizeArrTwo << std::endl;
		for (int i = 0; i < sizeArrTwo; i++) {
			file << arrTwo[i] << " ";
		}
		file << std::endl;

		file << sizeArrOne << std::endl;
		for (int i = 0; i < sizeArrOne; i++) {
			file << arrOne[i] << " ";
		}
		file << std::endl;

		std::cout << "������ � ���� 'out.txt' ������� ��������." << std::endl;
	}
	else {
		std::cout << "������ �������� ����� ��� ������ 'out.txt'! ������ �� ����� ��������." << std::endl;
		system("pause > nul");
		return 0;
	}
	file.close();

	delete[] arrOne;
	delete[] arrTwo;
	arrOne = nullptr;
	arrTwo = nullptr;

	system("pause > nul");
	return 0;
}

void printArr(const int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


void moveRight(int* arr, const int size) {
	for (int i = size - 1, temp = arr[size - 1]; i >= 0; i--) {
		if (i == 0) {
			arr[i] = temp;
		}
		else {
			arr[i] = arr[i - 1];
		}
	}
}

void moveLeft(int* arr, const int size) {
	for (int i = 0, temp = arr[0]; i < size; i++) {
		if (i == (size - 1)) {
			arr[i] = temp;
		}
		else {
			arr[i] = arr[i + 1];
		}
	}
}