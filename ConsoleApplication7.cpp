
					//PROJECT PHONES
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Contanct {
	string firstname;
	string lastname;
	string phonenumber;//������� string ��� �������� ����� ����� ������� ������� ��� ������ �� ������������
						//bugs �� ������� ��� variable int
	string email;
};


void addContact(vector<Contanct>& contacts) {
	Contanct newContact;
	
	cout << "Enter First Name" << endl;
	cin >> newContact.firstname;
	
	cout << "Enter Last Name" << endl;
	cin >> newContact.lastname;

	cout << "Enter phonenumber" << endl;
	cin >> newContact.phonenumber;

	cout << "Enter email" << endl;
	cin >> newContact.email;

	contacts.push_back(newContact);
}





void DeleteContacts(vector<Contanct>& contacts,const string& firstname,const string& lastname) {
//��������������� �� const string& ���� ��� ���� string, 
//����������� ��� ������� ��������� ��� ������������� ���� ��� ����� ��� ����������. 
//���� �������� ��� ������� ��� ������� ��� ������������ ���� ��� ��� ���� ��� ������������.
//���� ����������� ����� ��������� ��� ������, ������ ���� �� ������������� ����� �������.
//����� �������������� �� const ������� �� ������ ���������� ���� ��� �������� �� ���������� �� ���������� bugs 
	
	for (auto it = contacts.begin(); it != contacts.end(); ++it) {//� for ������� ��� ����� �������� ��� 
		//vector �� �������� it ����� ��� �� ��������� �������� ��� ������

		if (it->firstname == firstname && it->lastname == lastname) {
			contacts.erase(it); //� ��������� erase(it) ��������� �� �������� ��� �� vector it.
		
			cout << "Contact deleted." << endl;
			
			return;
		}
	}
	cout << "Contact not found." << endl;

}



//���, �� auto& ���������� ��� ������� ��� ���� �������� ��� numbers.
//� ��������� number ��� ����� ���������, ���� ������� ��� ���������� �������� ���� ��� numbers. 
// ����������� ����������� ������� ���� ��� �������� number ��������� ��������� �� �������� ��� numbers.

void display(const vector<Contanct>& contacts) {
	
	for (const auto& contact : contacts) {		//� ������ auto ���� C++ ���������������
		                     //��� ��� �������� ��������� ��� ����� ���� ���������� ��� ��� �������������.
		cout << "Name:" << contact.firstname << " " << contact.lastname << endl;
		cout << "phonenumber:" << contact.phonenumber << endl;
		cout << "email" << contact.email << endl;
		cout << "_____________________________" << endl;

	}
}


void searchContacts(const vector<Contanct>& contacts, const string& firstname, const string& lastname) {
	
	for (const auto& contact : contacts) {
		if (contact.firstname == firstname && contact.lastname == lastname) {
			cout << "Name:" << contact.firstname << " " << contact.lastname << endl;
			cout << "phonenumber:" << contact.phonenumber << endl;
			cout << "email:" << contact.email << endl;
			return;
		}
	}
	cout << "Not found" << endl;

}


int main() {

	vector<Contanct>contacts;	//contacts ����� � �������� ��� vector ��� ������������ ��� ����� Contancts
	string firstname, lastname;

	string name;
	cout << "hello user please enter your name:";
	cin >> name;
	cout << "Welcome back " << name << endl;

	int choice;

		
	do {
		cout << "1.Add Contact" << endl;
		cout << "2.Display Contacts" << endl;
		cout << "3.Delete Contact" << endl;
		cout << "4.Search Contact" << endl;
		cout << "5.EXIT" << endl;
		cout << "Enter your choice:" << endl;

		do {
			cin >> choice;
		} while (choice < 1 || choice > 5);



			switch (choice) {
			case 1:
				addContact(contacts);
				break;

			case 2:
				display(contacts);
				break;

			case 3:
				cout << "Enter first name of the contact to delete" << endl;
				cin >> firstname;
				cout << "Enter last name of the contact to delete" << endl;
				cin >> lastname;

				DeleteContacts(contacts, firstname, lastname);

			case 4:
				cout << "Enter first name of the contact to search" << endl;
				cin >> firstname;
				cout << "Enter last name of the contact to search" << endl;
				cin >> lastname;

				searchContacts(contacts, firstname, lastname);
			}

		
		}while (choice != 5);
	
	cout << "Good bye " << name << endl;





	return 0;
}