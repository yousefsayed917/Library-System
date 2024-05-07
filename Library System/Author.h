#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Author {
	string name, email;
public:
	Author() {}
	Author(string name, string email) {
		this->name = name;
		this->email = email;
	}
	void setAuthorname(string name) {
		this->name = name;
	}
	void setAuthorEmail(string email) {
		this->email = email;
	}
	string getAuthorName() {
		return name;
	}
	string getAuthorEmail() {
		return email;
	}
};

