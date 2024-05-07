#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;
int main()
{Library l("Egypt_library");
	int opt
	;
	if (l.libraryOptions()) {
		do {
			cout << "[1] menu\t\t[0] Exit\n";
			cout << "..::Enter the Choice: ";
			cin >> opt;
			switch (opt)
			{
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				if (!l.libraryOptions()) {
					exit(0);
				}
				break;
			default:
				cout << "Invalid choise!" << endl;
				break;
			}
		} while (opt == 1);
	}
	else {
		exit(0);
	}
}
