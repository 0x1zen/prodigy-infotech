#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    string email;

    Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(string name, string phoneNumber, string email) {
        Contact contact(name, phoneNumber, email);
        contacts.push_back(contact);
        cout << "Contact added successfully." << endl;
    }

    void viewContacts() {
        if (contacts.empty()) {
            cout << "No contacts found." << endl;
        } else {
            cout << "Contacts:" << endl;
            for (int i = 0; i < contacts.size(); ++i) {
                cout << i + 1 << ". Name: " << contacts[i].name << ", Phone: " << contacts[i].phoneNumber << ", Email: " << contacts[i].email << endl;
            }
        }
    }

    void editContact(int index, string name, string phoneNumber, string email) {
        if (index >= 0 && index < contacts.size()) {
            Contact &contact = contacts[index];
            contact.name = name;
            contact.phoneNumber = phoneNumber;
            contact.email = email;
            cout << "Contact updated successfully." << endl;
        } else {
            cout << "Invalid contact index." << endl;
        }
    }

    void deleteContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            cout << "Contact deleted successfully." << endl;
        } else {
            cout << "Invalid contact index." << endl;
        }
    }
};

int main() {
    ContactManager contactManager;

    while (true) {
        cout << "\nContact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, phoneNumber, email;
                cout << "Enter name: ";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter email: ";
                getline(cin, email);
                contactManager.addContact(name, phoneNumber, email);
                break;
            }
            case 2:
                contactManager.viewContacts();
                break;
            case 3: {
                int index;
                cout << "Enter the index of the contact to edit: ";
                cin >> index;
                string name, phoneNumber, email;
                cout << "Enter new name: ";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter new phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter new email: ";
                getline(cin, email);
                contactManager.editContact(index - 1, name, phoneNumber, email);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the contact to delete: ";
                cin >> index;
                contactManager.deleteContact(index - 1);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

return 0;
}