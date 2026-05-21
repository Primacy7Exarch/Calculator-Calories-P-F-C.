#include "Void's.h"


void Пациент(std::string& Назвищо)
{
	system("cls");
	std::cout << Назвищо << ", ";
}


void Сбросс_Ошибки(double& значение)
{
	while (!(std::cin >> значение)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "\033[A\033[K";
	}
	while (std::cin.get() != '\n');
} 