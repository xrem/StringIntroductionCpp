#include <iostream>
// Часть стандартной библиотеки для работы со строками.
#include <string>
#include <deque>
#include <vector>
#include <locale>

using namespace std;

int main()
{
	// Подключаю возможность работы со строчками с кириллицей.
	setlocale(LC_ALL, "Russian");
	
	const char cname[10] = "Роман";
	cout << cname << " " << cname << endl;

	
	for(int i = 0; ; i++)
	{
		if (cname[i] == 0)
		{
			cout << "String length: " << i << endl;
			break;
		}
	}

	string wrapper_name = cname;
	cout << "String length: " << wrapper_name.length() << endl;

	int number;
	cin >> number;

	// Подготавливаем стандартный поток ввода, для дальнейшего использования в GetLine()
	// Удаляем из первых 500-байт пользовотельского ввода символ перевода строки.
	wcin.ignore(500, '\n');
	
	wstring name;
	// Читаем из стандартного потока ввода строку и инициализируем переменную name
	getline(wcin, name);
	
	wstring surname;
	getline(wcin, surname);

	// Конкатенация строк (склеивание нескольких строк в одну)
	wstring name_and_surname = name + L" " + surname;
	wcout << name << " " << surname << endl;
	wcout << name_and_surname << endl;
	// auto - автоматическое определенние типа по правой части.
	auto rstr = name_and_surname.rbegin();
	while (rstr != name_and_surname.rend())
	{
		wcout << *rstr++;
	}

	deque<int> deq = { 1, 2, 3, 5, 7 };

	// Цикл foreach - обход нашего контейнера поэлементно - итерированиие по контейнеру
	for (int element : deq)
	{
		cout << element << endl;
	}

	// Итераторы.
	// Специальный тип объявленный внутри класса контейнера, предоставлящий механизм обхода памяти.

	cout << "Start interate..." << endl;
	// Объявлям итератор на начало коллекции
	deque<int>::iterator iter = deq.begin();
	while(iter != deq.end())
	{
		// Вывод значения на которое указывает итератор
		cout << *iter << endl;
		// Переход к следующему элементу.
		iter++;
	}
	cout << "End interate" << endl;

	cout << "Start reserve interate..." << endl;
	deque<int>::reverse_iterator reserve_iter = deq.rbegin();
	while (reserve_iter != deq.rend())
	{
		cout << *reserve_iter << endl;
		reserve_iter++;
	}
	cout << "End reserve interate" << endl;

	vector<wstring> students;
	students.push_back(L"Апокин Леонид Денисович");
	students.push_back(L"Валуйский Даниил Романович");
	students.push_back(L"Ванслов Александр Андреевич");
	students.push_back(L"Дрекалов Никита Сергеевич");
	students.push_back(L"Жуков Никита Сергеевич");
	students.push_back(L"Ивасенко Андрей Павлович");
	students.push_back(L"Кузнецов Владимир Владимирович");
	students.push_back(L"Кушнаренко Никита Сергеевич");
	students.push_back(L"Логинов Александр Сергеевич");
	students.push_back(L"Новиков Глеб Евгеньевич");
	students.push_back(L"Подашевко Анастасия Димитриевна");
	students.push_back(L"Путилин Никита Захарович");
	students.push_back(L"Сагиев Ильвир Русланович");
	students.push_back(L"Тарасов Роман Юрьевич");
	students.push_back(L"Тимофеев Кирилл Дмитриевич");
	students.push_back(L"Федоров Никита Игоревич");
	students.push_back(L"Федоров Тимофей Павлович");
	students.push_back(L"Ходжаев Абдужалол Абдужаборович");

	// Задача: Найти "Имя" по "Фамилии"

	// Собрали все строчки из массива в одну большую
	wstring haystack;
	for (wstring student : students)
	{
		haystack += student + L" ";
	}

	// Задали параметр для поиска
	cout << "Enter surname: " << endl;
	wstring needle = L"Новиков";
	//getline(wcin, needle);

	// Осуществили поиск подстоки в строке, получили индекс
	auto index = haystack.find(needle);

	// Проверили, нашли ли подстроку в строке
	if (index == wstring::npos)
	{
		cout << "Student not found" << endl;
	}
	else {
		auto student_iter = haystack.begin();
		// Сдвинули строку на N символов вперёд, теперь первое слово в строке - искомая подстрока
		student_iter += index;
		// Сдвинули строку ещё на N символов вперёд, теперь строка указывает на пробел перед именем
		student_iter += needle.length();
		// Удалили пробел перед именем
		student_iter += 1;
		cout << "Name: ";
		// Начали выводить имя до тех пор пока не дойдем до отчества.
		while (*student_iter != ' ')
		{
			wcout << *student_iter++;
		}
		cout << endl;
	}
	
	return 0;
}
