#pragma once
#include <iostream>
#include <List>
#include <iterator>
#include "Book.h"
using namespace std;
class Library {
	string name;
	list <Book> books;
	list<Book> ::iterator it;
public:
	Library(string name) {
		this->name = name;
	}
	void addnewbook(Book b) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == b.getid()) {
				cout << " this book id is already \n";
				return;
			}
		}
		books.push_back(b);
		cout << " the book is added successfully \n";
		cout << endl;
	}
	void UpdateSpecificBook(int id, string newtitle, Author newWriter) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == id) {
				it->settitle(newtitle);
				it->setAuthor(newWriter);
				return;
			}
		}
		cout << " This book does not exist in the library \n";
		cout << endl;
	}
	void RemoveAnExistBook(int id) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == id) {
				books.erase(it);
				cout << "this book is deleted successfully \n";
				cout << endl;
				return;
			}
		}
		cout << " This book does not exist in the library \n";
		cout << endl;
	}
	void BorrowBook(int id) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == id) {
				if (it->getisborrowed()) {
					cout << "this book is unavailable \n";
					cout << endl;
					return;
				}
				else {
					cout << "this book is available and borrowed successfully \n";
					cout << endl;
					it->setisborrowed(true);
					return;
				}
			}
		}
		cout << " This book does not exist in the library \n";
		cout << endl;
	}
	void SearchBook(int id) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == id) {
				it->DisplayBook();
				cout << endl;
				return;
			}
		}
		cout << " This book does not exist in the library \n";
		cout << endl;
		return;
	}
	void ReturnBook(int id) {
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->getid() == id && it->getisborrowed() == true) {
				cout << "this book is returned successfully \n";
				it->setisborrowed(false);
				return;
			}
		}
		cout << "this book does not borrowed \n";
		cout << endl;
	}
	void DisplayBooks() {
		for (it = books.begin(); it != books.end(); ++it) {
			it->DisplayBook();
			cout << "=======================" << endl;
		}
	}
	void DisplayMenu() {
		cout << " enter 1 to add a book \n"
			" enter 2 to update specific book by id \n"
			" enter 3 to remove an existing book by id \n"
			" enter 4 to borrow book by id \n"
			" enter 5 to search book by id \n"
			" enter 6 to return book by id \n"
			" enter 7 to  displaying all books \n"
			" enter 8 to exit \n" << endl;
	}
	bool libraryOptions() {
		DisplayMenu();
		int x;
		cout << " your choice is : ";
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			string title, name, email;
			Author writer;
			int id;
			cout << "enter id \n";
			cin >> id;
			cout << "enter title \n";
			cin >> title;
			cout << "enter author name \n";
			cin >> name;
			writer.setAuthorname(name);
			cout << "enter author Email \n";
			cin >> email;
			writer.setAuthorEmail(email);
			Book b(id, title, writer);
			addnewbook(b);
			return true;
			break;
		}
		case 2: {
			system("cls");
			int id;
			string newtitle;
			Author writer;
			string name, email;
			cout << "enter id of book to update this book \n";
			cin >> id;
			cout << "enter new title \n";
			cin >> newtitle;
			cout << "enter author name \n";
			cin >> name;
			writer.setAuthorname(name);
			cout << "enter author Email \n";
			cin >> email;
			writer.setAuthorEmail(email);
			UpdateSpecificBook(id, newtitle, writer);
			return true;
			break;
		}
		case 3: {
			system("cls");
			cout << "enter id of book to remove this book \n";
			int id;
			cin >> id;
			RemoveAnExistBook(id);
			return true;
			break;
		}
		case 4: {
			system("cls");
			cout << "enter id of book to borrow this book \n";
			int id;
			cin >> id;
			BorrowBook(id);
			return true;
			break;
		}
		case 5: {
			system("cls");
			cout << "enter id of book to search about this book \n";
			int id;
			cin >> id;
			SearchBook(id);
			return true;
			break;
		}
		case 6: {
			system("cls");
			cout << "enter id of book to return this book \n";
			int id;
			cin >> id;
			ReturnBook(id);
			return true;
			break;
		}
		case 7: {
			system("cls");
			DisplayBooks();
			return true;
			break;
		}
		case 8: {
			return false;
			break;
		}
		default: {
			return true;
		}
		}
	}
};