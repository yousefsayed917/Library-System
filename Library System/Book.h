#pragma once
#include <iostream>
#include "Author.h"
using namespace std;
class Book {
	int id;
	string title;
	Author writer;
	bool isborrowed=false;
public:
	Book() {
		this->id = 0;
	}
	Book(int id ,string title, Author writer) {
		this->id = id;
		this->title = title;
		this->writer = writer;
	}
	void setid(int id) {
		this->id = id;
	}
	void settitle(string title) {
		this->title = title;
	}
	void setAuthor(Author writer) {
		this->writer = writer;
	}
	void setisborrowed(bool isborrowed) {
		this->isborrowed = isborrowed;
	}
	int getid() {
		return this->id;
	}
	string gettitle() {
		return this->title;
	}
	Author getWriter() {
		return writer;
	}
	bool getisborrowed() {
		return this->isborrowed;
	}
	void DisplayBook() {
		cout << "Book Title : " << gettitle() << endl;
		cout << "Book Id : " << getid() << endl;
		cout << "Author Name : " << getWriter().getAuthorName() << endl;
		cout << "Author Email : " << getWriter().getAuthorEmail() << endl;
	}
};