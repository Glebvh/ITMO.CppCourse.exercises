#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Person {

public:

	virtual ~Person() {}
	virtual string info() const = 0;

};


class Collegue: public Person {

public:

	Collegue(string firstName , string secondName, string email, int phone) {

		this->firstName = firstName;
		this->secondName = secondName;
		this->email = email;
		this->phone = phone;

	}

	string info() const override {

		return "Collegue: " + secondName + " " + firstName + " " + email + " " + to_string(phone);

	}

private:

	string firstName;
	string secondName;
	string email;
	int phone;

};

class Friend : public Person {

public:

	Friend(string firstName, string nickName, int phone) {

		this->firstName = firstName;
		this->nickName = nickName;
		this->phone = phone;

	}

	string info() const override {

		return "Friend: " + firstName + " \"" + nickName + "\" " + to_string(phone);

	}


private:

	string firstName;
	string nickName;
	int phone;

};


int main() {

	vector<Person*> person;
	
	person.push_back(new Collegue("John", "Doe", "john@doe.com", 777));
	person.push_back(new Friend("Mark", "First", 999));

	string file = "info.txt";
	ofstream fout(file, ios::app);

	for (auto p : person)
		fout << p->info() << std::endl;

	fout.close();
	
}