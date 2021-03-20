#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool LoggedIn() {
	string username, password;
	string us, ps;

	cout << "Enter your username :" << endl;
	cin >> username;

	cout << "Enter your password :" << endl;
	cin >> password;

	ifstream read("data.txt");
	getline(read, us);
	getline(read, ps);


	if (us == username && ps == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;
	string username, password;

	cout << "1- Register \n 2- Login" << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "Enter your username :" << endl;
		cin >> username;

		cout << "Enter your password :" << endl;
		cin >> password;

		ofstream out_file;
		out_file.open("data.txt");

		out_file << username << endl << password;
		out_file.close();

		main();
	}
	else if (choice == 2)
	{
		bool status = LoggedIn();

		if (!status)
		{
			cout << "False login" << endl;
			system("PAUSE");
			return(0);
		}
		else
		{
			cout << "Successfully LoggedIn" << endl;
			system("PAUSE");
			return 1;
		}
	}
}