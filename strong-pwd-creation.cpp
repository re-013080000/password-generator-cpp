#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

string generate(int len, string password) {
	string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,;:!?./§%µ£$*ù+=-#&";
	if (len == 0) {
		return password;
	}
	else {
		len -= 1;
		password += characters[rand() % 81];
		return generate(len, password);
	}
}

int main() {
	ofstream passwd;
	string password = "";
	int len;

	srand(time(NULL));
	system("cls");
	cout << "What length do you want your password? : ";
	cin >> len;
	cout << endl;
	password = generate(len, password);
	passwd.open("password.txt");  //export your password in a txt file
	passwd << password;
	passwd.close();
	cout << "Done." << endl << endl;
	return 0;
}
