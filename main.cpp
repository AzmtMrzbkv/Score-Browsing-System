#include "project.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
	// read input file
	Project Grade;
	Grade.readfile();

	int command;
	cout << "1. Login\n2. Student info\n3. Score Rank\n4. Score statistics\n9. Logout\n0. Terminate" << endl;
	for (;;)
	{
		cout << "Select the command: ";
		cin >> command;

		switch (command)
		{
		case 0:
			exit(0);
		case 1:
			Grade.login();
			break;
		case 2:
			Grade.studentinfo();
			break;
		case 3:
			Grade.scorerank();
			break;
		case 4:
			Grade.scorestatistic();
			break;
		case 5:
			Grade.alldata();
			break;
		case 6:
			Grade.modifyinfo();
			break;
		case 7:
			Grade.addstudent();
			break;
		case 9:
			Grade.logout();
			break;
		default:
			cout << "Wrong command." << endl;
		}
	}
}
