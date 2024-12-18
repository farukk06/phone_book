#include <iostream>
#include <clocale>
#include <string>

using namespace std;

string addition_person();
unsigned long long addition_telephone();

const int MAX = 1000;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int operation;
	int sayac_person = 0;
	int sayac_telephone = 0;
	string person[MAX];
	unsigned long long telephone[MAX] ;
	
	cout << "**************  PHONE BOOK  **************\n\n\n";
	
	while (true)
	{
		cout << "Please choose a operation which you want: " << endl;
		cout << "1 = Add person." << endl;
		cout << "2 = Edit person." << endl;
		cout << "3 = Delete person." << endl;
		cout << "4 = Show all person." << endl;
		cout << "5 = Exit the program." << endl << endl;
		cout << "Operation: ";
		cin >> operation;
		cout << endl;

		if (!(1 <= operation && operation <= 5))
		{
			cout << "Please choose a operation between 1 to 5 !!!" << endl << endl;
			continue;
		}
		if (operation == 5)
		{
			cout << "Leaving from program..." << endl;
			break;
		}
		else if (operation == 1)
		{
			person[sayac_person] = addition_person();
			telephone[sayac_telephone] = addition_telephone();
			sayac_person++;
			sayac_telephone++;
			cout << endl;
		}
		else if (operation == 2)
		{
			int b;
			cout << "Whose information do you want to change ? : ";
			cin >> b;
			if (b<0 || b>sayac_person)
			{
				cout << "Invalid person index!" << endl << endl;
				continue;
			}
			else if (b >= 1 && b <= sayac_person)
			{
				person[b - 1] = addition_person();
				telephone[b - 1] = addition_telephone();
				cout << endl;
			}
			else if (b == 1)
			{
				cout << "You changed " << b << "st person..." << endl << endl;
			}
			else if (b == 2)
			{
				cout << "You changed " << b << "nd person..." << endl << endl;
			}
			else if (b == 3)
			{
				cout << "You changed " << b << "rd person..." << endl << endl;
			}
			else
			{
				cout << "You changed " << b << "th person..." << endl << endl;
			}
			
		}
		else if (operation == 3)
		{
			int c;
			cout << "Whose informations do you want to delete ? : ";
			cin >> c;
			if (c <= 0 || c > sayac_person)
			{
				cout << "Invalid person index!" << endl;
				continue;
			}

			for (int i = c - 1; i < sayac_person - 1; i++)
			{
				person[i] = person[i + 1];
				telephone[i] = telephone[i + 1];
			}
			sayac_person--;
			sayac_telephone--;
			cout << endl;
			if (c == 1)
			{
				cout << "You deleted " << c << "st person..." << endl << endl;
			}
			else if (c == 2)
			{
				cout << "You deleted " << c << "nd person..." << endl << endl;
			}
			else if (c == 3)
			{
				cout << "You deleted " << c << "rd person..." << endl << endl;
			}
			else
			{
				cout << "You deleted " << c << "th person..." << endl << endl;
			}
		}
		else if (operation == 4)
		{
			
			while (true)
			{
				for (int i = 0;i < sayac_person;i++)
				{
					cout << i + 1 << ".kisi : " << person[i] << "  ---->  " << "0" << telephone[i] << endl << endl;
				}
				break;
			}
		}
		
	}
}

string addition_person()
{
	string name;
	string surname;
	string a;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter name: ";
	getline(cin, name);
	
	cout << "Enter surname: ";
	getline(cin, surname);
	a = name + " " + surname;

	return a;
}

unsigned long long addition_telephone()
{
	unsigned long long telephone;
	cout << "Enter telephone number: ";
	cin >> telephone;

	return telephone;
}
