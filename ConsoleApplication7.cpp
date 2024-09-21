
					//PROJECT PHONES
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Contanct {
	string firstname;
	string lastname;
	string phonenumber;//βαζουμε string στο τηλεφωνο γιατι ειναι μεγαλος αριθμος και μπορει να δημιουργησει
						//bugs αν βαλουμε για variable int
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
//Χρησιμοποιώντας το const string& αντί για απλά string, 
//αποφεύγουμε τον περιττό αντίγραφο της συμβολοσειράς κατά την κλήση της συνάρτησης. 
//Αυτό σημαίνει ότι περνάμε μια αναφορά στη συμβολοσειρά αντί για την ίδια την συμβολοσειρά.
//Αυτό εξοικονομεί χρόνο εκτέλεσης και μνήμης, ειδικά όταν οι συμβολοσειρές είναι μεγάλες.
//Τελος χρησιμοποιουμε το const κανουμε το ορισμα αναγνωσιμο μονο για αναγνωση με αποτελεσμα να αποφυγουμε bugs 
	
	for (auto it = contacts.begin(); it != contacts.end(); ++it) {//Η for δειχνει στο πρωτο στοιχειο του 
		//vector με ονομασια it μεχρι και το τελευταιο στοιχειο του πινακα

		if (it->firstname == firstname && it->lastname == lastname) {
			contacts.erase(it); //Η συναρτηση erase(it) διαγραφει τα στοιχεια απο το vector it.
		
			cout << "Contact deleted." << endl;
			
			return;
		}
	}
	cout << "Contact not found." << endl;

}



//Εδώ, το auto& δημιουργεί μια αναφορά για κάθε στοιχείο του numbers.
//Η μεταβλητή number δεν είναι αντίγραφο, αλλά αναφορά στο πραγματικό στοιχείο μέσα στο numbers. 
// Οποιαδήποτε τροποποίηση γίνεται μέσω της αναφοράς number επηρεάζει απευθείας τα στοιχεία του numbers.

void display(const vector<Contanct>& contacts) {
	
	for (const auto& contact : contacts) {		//Η εντολή auto στην C++ χρησιμοποιείται
		                     //για την αυτόματη ανίχνευση του τύπου μιας μεταβλητής από τον μεταγλωττιστή.
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

	vector<Contanct>contacts;	//contacts ειναι η ονομασια του vector που χρησιμοποιει την κλαση Contancts
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