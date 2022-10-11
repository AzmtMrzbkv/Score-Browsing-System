#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;
struct Info
{
	string idlist[20], pwlist[20];
	double HW1[20], HW2[20], PJ1[20], PJ2[20];
	int loginfail[20]; // login fail count (default: 0)
};

class Project
{
private:
	string userid;
	Info info;
	int studentnum = 11;
	const string adminid = "admin";
	const string adminpw = "unisteee";

public:
	// read input file. Each data is saved in structure Info.
	void readfile()
	{
		ifstream inFile("input.txt");
		string line;

		if (inFile.is_open())
		{
			for (int i = 0; i < studentnum; i++)
			{
				getline(inFile, line) >> info.idlist[i] >> info.pwlist[i] >> info.HW1[i] >> info.HW2[i] >> info.PJ1[i] >> info.PJ2[i];
			}
		}
		inFile.close();
		for (int i = 0; i < studentnum; i++)
		{
			info.loginfail[i] = 0;
		}
	}

	// command 1
	void login()
	{
		if (userid.compare("") != 0)
		{
			cout << "You've already logged in." << endl;
			return;
		}

		string id, pw;
		cout << "Student name: ";
		cin >> id;
		cout << "Password: ";
		cin >> pw;

		if (id.compare(adminid) == 0)
		{
			if (pw.compare(adminpw) == 0)
			{
				cout << "Login Success." << endl;
				userid = id;
				cout << "[Admin Command]\n5. All data\n6. Modify info\n7. Add student" << endl;
			}
			else
				cout << "Login Fail." << endl;

			return;
		}

		for (int i = 0; i < studentnum; i++)
		{
			if (info.idlist[i].compare(id) == 0)
			{

				// after 3 failed logins even correct password shouldn't work
				if (info.loginfail[i] > 3)
				{
					cout << "Please contact administrator and reset your password." << endl;
					cout << "Login Fail." << endl;
					return;
				}

				if (info.pwlist[i].compare(pw) == 0)
				{
					cout << "Login Success." << endl;
					userid = id;
					// info.loginfail[i] = 0;
				}
				else
				{
					info.loginfail[i]++;
					if (info.loginfail[i] > 3)
						cout << "Please contact administrator and reset your password." << endl;
					cout << "Login Fail." << endl;
				}
				return;
			}
		}

		cout << "Login Fail." << endl;
	};

	// command 2
	void studentinfo()
	{
		if (userid.compare("") == 0)
		{
			cout << "Please login first." << endl;
			return;
		}

		for (int i = 0; i < studentnum; i++)
		{
			if (info.idlist[i].compare(userid) == 0)
			{
				cout << "Name: " << info.idlist[i] << endl;
				cout << "Homework: " << info.HW1[i] << " " << info.HW2[i] << endl;
				cout << "Project: " << info.PJ1[i] << " " << info.PJ2[i] << endl;
				break;
			}
		}
	};

	// command 3
	void scorerank()
	{
		if (userid.compare("") == 0)
		{
			cout << "Please login first." << endl;
			return;
		}

		cout << "Your rank is..." << endl;
		for (int i = 0; i < studentnum; i++)
		{
			if (userid.compare(info.idlist[i]) == 0)
			{
				// rank for HWs
				double scoreHW1 = info.HW1[i];
				double scoreHW2 = info.HW2[i];
				double scorePJ1 = info.PJ1[i];
				double scorePJ2 = info.PJ2[i];

				// rank for HW1
				double sorted_HW1[20];
				memcpy(sorted_HW1, info.HW1, studentnum * sizeof(double));
				sort(sorted_HW1, 0, studentnum - 1);
				for (int j = 0; j < studentnum; j++)
				{
					if (sorted_HW1[j] == scoreHW1)
					{
						cout << "HW1: " << j + 1 << endl;
						break;
					}
				}

				// rank for HW2
				double sorted_HW2[20];
				memcpy(sorted_HW2, info.HW2, studentnum * sizeof(double));
				sort(sorted_HW2, 0, studentnum - 1);
				for (int j = 0; j < studentnum; j++)
				{
					if (sorted_HW2[j] == scoreHW2)
					{
						cout << "HW2: " << j + 1 << endl;
						break;
					}
				}

				// rank for PJ1
				double sorted_PJ1[20];
				memcpy(sorted_PJ1, info.PJ1, studentnum * sizeof(double));
				sort(sorted_PJ1, 0, studentnum - 1);
				for (int j = 0; j < studentnum; j++)
				{
					if (sorted_PJ1[j] == scorePJ1)
					{
						cout << "Project1: " << j + 1 << endl;
						break;
					}
				}

				// rank for PJ2
				double sorted_PJ2[20];
				memcpy(sorted_PJ2, info.PJ2, studentnum * sizeof(double));
				sort(sorted_PJ2, 0, studentnum - 1);
				for (int j = 0; j < studentnum; j++)
				{
					if (sorted_PJ2[j] == scorePJ2)
					{
						cout << "Project2: " << j + 1 << endl;
						break;
					}
				}

				return;
			}
		}
	};

	// command 4
	void scorestatistic()
	{
		cout << "Average scores and median scores are..." << endl;

		double average = 0, median;
		for (int i = 0; i < studentnum; i++)
			average += info.HW1[i];
		average /= studentnum;
		if (studentnum % 2 == 0)
			median = (info.HW1[studentnum / 2] + info.HW1[studentnum / 2 + 1]) / 2;
		else
			median = info.HW1[studentnum / 2];
		cout << "HW1: " << average << ", " << median << endl;

		average = 0;
		for (int i = 0; i < studentnum; i++)
			average += info.HW2[i];
		average /= studentnum;
		if (studentnum % 2 == 0)
			median = (info.HW2[studentnum / 2] + info.HW2[studentnum / 2 + 1]) / 2;
		else
			median = info.HW2[studentnum / 2];
		cout << "HW2: " << average << ", " << median << endl;

		average = 0;
		for (int i = 0; i < studentnum; i++)
			average += info.PJ1[i];
		average /= studentnum;
		if (studentnum % 2 == 0)
			median = (info.PJ1[studentnum / 2] + info.PJ1[studentnum / 2 + 1]) / 2;
		else
			median = info.PJ1[studentnum / 2];
		cout << "Project1: " << average << ", " << median << endl;

		average = 0;
		for (int i = 0; i < studentnum; i++)
			average += info.PJ2[i];
		average /= studentnum;
		if (studentnum % 2 == 0)
			median = (info.PJ2[studentnum / 2] + info.PJ2[studentnum / 2 + 1]) / 2;
		else
			median = info.PJ2[studentnum / 2];
		cout << "Project2: " << average << ", " << median << endl;
	};

	// command 5
	void alldata()
	{
		if (userid.compare(adminid) != 0)
		{
			cout << "You do not have authority." << endl;
			return;
		}

		cout << "All data:" << endl;
		for (int i = 0; i < studentnum; i++)
			cout << info.idlist[i] << ": " << info.HW1[i] << " " << info.HW2[i] << " " << info.PJ1[i] << " " << info.PJ2[i] << endl;
	};

	// command 6
	void modifyinfo()
	{
		if (userid.compare(adminid) != 0)
		{
			cout << "You do not have authority." << endl;
			return;
		}

		cout << "Whose information are you going to modify?: ";
		string name, inf;
		cin >> name;
		cout << "What information are you going to modify?(password, HW1, HW2, PJ1, PJ2): ";
		cin >> inf;

		if (inf.compare("password") == 0)
		{
			cout << "Enter new password: ";
			string pass;
			cin >> pass;

			// check password for validity => must include: uppercase, lowercase, numbers, and punctuation characters.
			int check = 0x00000000;
			for (char c : pass)
			{
				if (c >= 0x41 && c <= 0x5A)
					check |= 0x11000000;
				if (c >= 0x61 && c <= 0x7A)
					check |= 0x00110000;
				if (c >= 0x30 && c <= 0x39)
					check |= 0x00001100;
				if ((c >= 0x21 && c <= 0x2F) || (c >= 0x3A && c <= 0x40) || (c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E))
					check |= 0x00000011;
			}

			if (check != 0x11111111)
			{
				cout << "Wrong password." << endl;
				return;
			}

			for (int i = 0; i < studentnum; i++)
			{
				if (info.idlist[i].compare(name) == 0)
				{
					info.pwlist[i] = pass;
					info.loginfail[i] = 0;
					cout << "Change complete." << endl;
					return;
				}
			}
		}

		if (inf.compare("HW1") == 0)
		{
			cout << "Enter new score: ";
			float sc;
			cin >> sc;

			if (sc > 20 || sc < 0)
			{
				cout << "Wrong input." << endl;
				return;
			}

			for (int i = 0; i < studentnum; i++)
			{
				if (name == info.idlist[i])
				{
					info.HW1[i] = sc;
					cout << "Change complete." << endl;
					return;
				}
			}
		}

		if (inf.compare("HW2") == 0)
		{
			cout << "Enter new score: ";
			float sc;
			cin >> sc;

			if (sc > 30 || sc < 0)
			{
				cout << "Wrong input." << endl;
				return;
			}

			for (int i = 0; i < studentnum; i++)
			{
				if (name == info.idlist[i])
				{
					info.HW2[i] = sc;
					cout << "Change complete." << endl;
					return;
				}
			}
		}

		if (inf.compare("PJ1") == 0)
		{
			cout << "Enter new score: ";
			float sc;
			cin >> sc;

			if (sc > 100 || sc < 0)
			{
				cout << "Wrong input." << endl;
				return;
			}

			for (int i = 0; i < studentnum; i++)
			{
				if (name == info.idlist[i])
				{
					info.PJ1[i] = sc;
					cout << "Change complete." << endl;
					return;
				}
			}
		}

		if (inf.compare("PJ2") == 0)
		{
			cout << "Enter new score: ";
			float sc;
			cin >> sc;

			if (sc > 100 || sc < 0)
			{
				cout << "Wrong input." << endl;
				return;
			}

			for (int i = 0; i < studentnum; i++)
			{
				if (name == info.idlist[i])
				{
					info.PJ2[i] = sc;
					cout << "Change complete." << endl;
					return;
				}
			}
		}
	};

	// command 7
	void addstudent()
	{
		if (userid.compare(adminid) != 0)
		{
			cout << "You do not have authority." << endl;
			return;
		}

		string name, pass;
		cout << "Student name: ";
		cin >> name;
		cout << "Password: ";
		cin >> pass;

		double sHW1, sHW2, sPJ1, sPJ2;
		cout << "HW1 score: ";
		cin >> sHW1;
		if (sHW1 > 20 || sHW1 < 0)
			sHW1 = 0;

		cout << "HW2 score: ";
		cin >> sHW2;
		if (sHW2 > 30 || sHW2 < 0)
			sHW2 = 0;

		cout << "PJ1 score: ";
		cin >> sPJ1;
		if (sPJ1 > 100 || sPJ1 < 0)
			sPJ1 = 0;

		cout << "PJ2 score: ";
		cin >> sPJ2;
		if (sPJ2 > 100 || sPJ2 < 0)
			sPJ2 = 0;

		info.idlist[studentnum] = name;
		info.pwlist[studentnum] = pass;
		info.HW1[studentnum] = sHW1;
		info.HW2[studentnum] = sHW2;
		info.PJ1[studentnum] = sPJ1;
		info.PJ2[studentnum] = sPJ2;
		studentnum++;
	};

	// command 9
	void logout()
	{
		if (userid.compare("") == 0)
		{
			cout << "You are not login." << endl;
			return;
		}

		userid = "";
		cout << "Logout complete." << endl;
	};

private:
	// sort an array in descending order
	void sort(double *arr, int l, int r)
	{
		if (l >= r)
			return;

		int s = l + 1;
		for (int i = l + 1; i <= r; i++)
		{
			if (arr[i] > arr[l])
			{
				swap(arr[i], arr[s]);
				s++;
			}
		}

		swap(arr[s - 1], arr[l]);

		sort(arr, l, s - 2);
		sort(arr, s, r);
	};
};
#endif