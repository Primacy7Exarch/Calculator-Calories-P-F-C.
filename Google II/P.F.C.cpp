#include "P.F.C.h"
#include <limits>

extern std::vector<Patient> database;


void ВыключитьВводВстроке()
{
	HANDLE ВыключитьВвод = GetStdHandle(STD_INPUT_HANDLE);
	DWORD СтарыеНастройки = 0;
	GetConsoleMode(ВыключитьВвод, &СтарыеНастройки);
	SetConsoleMode(ВыключитьВвод, СтарыеНастройки & ~ENABLE_ECHO_INPUT);

	std::cin.get();

	SetConsoleMode(ВыключитьВвод, СтарыеНастройки);
}

void РасчётPFC(const Patient& Client)
{

	СкрытьКурсорВвода(true);

	system("cls");
	std::cout << "Расчёт для Пациента: " << Client.Назвищо << std::endl;
	double Калории = (10 * 70) - (5 * Client.Возраст) + 5;
	double Белки = 140;
	double Жиры = 70;
	double Углеводы = 200;
	std::cout << "Рекомендации по КБЖУ: " << std::endl;
	std::cout << "Калории " << Калории << std::endl;
	std::cout << "Белки " << Белки << std::endl;
	std::cout << "Жиры " << Жиры << std::endl;
	std::cout << "Углеводы " << Углеводы << std::endl;
	
	std::cout << "\nНажмите Enter, чтобы продолжить..." << std::endl;

	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	ВыключитьВводВстроке();

	system("cls");
}

void ПодсчётPFCУПациента()
{
	СкрытьКурсорВвода(false);
	int ВыборПациента;
	std::cout << "Выберите Пациента, чтобы посмотреть для него сколько надо Белков, Жиров, Углеводов." << std::endl;
	std::cin >> ВыборПациента;

	if (ВыборПациента >= 0 && ВыборПациента < database.size())
	{
		РасчётPFC(database[ВыборПациента]);
	}
}