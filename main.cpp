#include <iostream>
// ����� ����������� ���������� ��� ������ �� ��������.
#include <string>
#include <deque>
#include <vector>
#include <locale>

using namespace std;

int main()
{
	// ��������� ����������� ������ �� ��������� � ����������.
	setlocale(LC_ALL, "Russian");
	
	const char cname[10] = "�����";
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

	// �������������� ����������� ����� �����, ��� ����������� ������������� � GetLine()
	// ������� �� ������ 500-���� ����������������� ����� ������ �������� ������.
	wcin.ignore(500, '\n');
	
	wstring name;
	// ������ �� ������������ ������ ����� ������ � �������������� ���������� name
	getline(wcin, name);
	
	wstring surname;
	getline(wcin, surname);

	// ������������ ����� (���������� ���������� ����� � ����)
	wstring name_and_surname = name + L" " + surname;
	wcout << name << " " << surname << endl;
	wcout << name_and_surname << endl;
	// auto - �������������� ������������ ���� �� ������ �����.
	auto rstr = name_and_surname.rbegin();
	while (rstr != name_and_surname.rend())
	{
		wcout << *rstr++;
	}

	deque<int> deq = { 1, 2, 3, 5, 7 };

	// ���� foreach - ����� ������ ���������� ����������� - ������������� �� ����������
	for (int element : deq)
	{
		cout << element << endl;
	}

	// ���������.
	// ����������� ��� ����������� ������ ������ ����������, �������������� �������� ������ ������.

	cout << "Start interate..." << endl;
	// �������� �������� �� ������ ���������
	deque<int>::iterator iter = deq.begin();
	while(iter != deq.end())
	{
		// ����� �������� �� ������� ��������� ��������
		cout << *iter << endl;
		// ������� � ���������� ��������.
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
	students.push_back(L"������ ������ ���������");
	students.push_back(L"��������� ������ ���������");
	students.push_back(L"������� ��������� ���������");
	students.push_back(L"�������� ������ ���������");
	students.push_back(L"����� ������ ���������");
	students.push_back(L"�������� ������ ��������");
	students.push_back(L"�������� �������� ������������");
	students.push_back(L"���������� ������ ���������");
	students.push_back(L"������� ��������� ���������");
	students.push_back(L"������� ���� ����������");
	students.push_back(L"��������� ��������� �����������");
	students.push_back(L"������� ������ ���������");
	students.push_back(L"������ ������ ����������");
	students.push_back(L"������� ����� �������");
	students.push_back(L"�������� ������ ����������");
	students.push_back(L"������� ������ ��������");
	students.push_back(L"������� ������� ��������");
	students.push_back(L"������� ��������� �������������");

	// ������: ����� "���" �� "�������"

	// ������� ��� ������� �� ������� � ���� �������
	wstring haystack;
	for (wstring student : students)
	{
		haystack += student + L" ";
	}

	// ������ �������� ��� ������
	cout << "Enter surname: " << endl;
	wstring needle = L"�������";
	//getline(wcin, needle);

	// ����������� ����� �������� � ������, �������� ������
	auto index = haystack.find(needle);

	// ���������, ����� �� ��������� � ������
	if (index == wstring::npos)
	{
		cout << "Student not found" << endl;
	}
	else {
		auto student_iter = haystack.begin();
		// �������� ������ �� N �������� �����, ������ ������ ����� � ������ - ������� ���������
		student_iter += index;
		// �������� ������ ��� �� N �������� �����, ������ ������ ��������� �� ������ ����� ������
		student_iter += needle.length();
		// ������� ������ ����� ������
		student_iter += 1;
		cout << "Name: ";
		// ������ �������� ��� �� ��� ��� ���� �� ������ �� ��������.
		while (*student_iter != ' ')
		{
			wcout << *student_iter++;
		}
		cout << endl;
	}
	
	return 0;
}
