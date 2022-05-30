
#include "pch.h"
#include <iostream>
#include <string>
#include <cassert>
#include "template_class_of_container.h"
#include "definition_class_template_of_container.cpp"
using namespace std;


int main()
{
	int size = 0;//Size of the Container
	short ch = 0;
	bool entrance = true;
	while (entrance) {
		cout << " Menu" << endl;;
		cout << "0. QUIT" << endl;
		cout << "1. Create container" << endl;

		while (!(cin >> ch)) {
			cin.clear();//Cleaning of this stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//Checking this thread for a number
			break;
		}

		switch (ch) {
		case 0:
		{
			cout << "Goodbye!" << endl;
			entrance = false;
			break;
		}
		case 1:
		{
			cout << "Enter a size of the container: ";
			while (!(cin >> size)) {
				cin.clear();//Cleaning of this stream
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//Checking this thread for a number
				break;
			}

			try {

				Container_t <int> c2(size);

			}
			catch (const char *ex) {
				cout << ex << endl;
				//entrance = false;
				break;
			}

		}
		default:
		{
			cout << "Go again)!\n" << endl;
			break;
		}

		}

	}
}


