#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> // Required for std::setw

// Base class with virtual function
class Entry {
public:
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Entry() = default;

    // Virtual method to print details
    virtual void printDetails() const {
        std::cout << "Base Entry (no details available)" << std::endl;
    }
};

// Contact class now derives from Entry
class Contact : public Entry {
public:
    std::string name;
    std::string phoneNumber;

    // Override the printDetails method
    void printDetails() const override {
        std::cout << std::left << std::setw(20) << name
                  << std::setw(15) << phoneNumber << std::endl;
    }
};

// --- Function Prototypes ---
void displayContacts(const std::vector<Contact>& contacts);
void addContact(std::vector<Contact>& contacts);
void findContactByName(const std::vector<Contact>& contacts);

int main() {
    // Changed from fixed array to vector
    std::vector<Contact> contacts;
    int choice;

    while (true) {
        std::cout << "\n--- Contact Book Menu ---" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Find Contact by Name" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "\n*** Invalid input. Please enter a number (1-4). ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                findContactByName(contacts);
                break;
            case 4:
                std::cout << "\nExiting Contact Book. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "\n*** Invalid choice. Please enter 1, 2, 3, or 4. ***" << std::endl;
                break;
        }
    }

    return 0; // Should be unreachable
}

// Updated displayContacts function to use vector and virtual function
void displayContacts(const std::vector<Contact>& contacts) {
    std::cout << "\n--- Stored Contacts (" << contacts.size() << ") ---" << std::endl;
    if (contacts.empty()) {
        std::cout << "No contacts to display." << std::endl;
    } else {
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Phone Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        for (const auto& contact : contacts) {
            contact.printDetails(); // Using the virtual function
        }
    }
    std::cout << "-----------------------------------" << std::endl;
}

// Updated addContact function to use vector
void addContact(std::vector<Contact>& contacts) {
    std::cout << "\n--- Add New Contact ---" << std::endl;
    Contact newContact;
    std::cout << "Enter contact name: ";
    std::getline(std::cin >> std::ws, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin >> std::ws, newContact.phoneNumber);
    contacts.push_back(newContact);
    std::cout << "*** Contact '" << newContact.name << "' added successfully. ***" << std::endl;
}

// Updated findContactByName function to use vector and virtual function
void findContactByName(const std::vector<Contact>& contacts) {
    std::cout << "\n--- Find Contact by Name ---" << std::endl;
    if (contacts.empty()) {
        std::cout << "No contacts stored yet to search." << std::endl;
        return;
    }

    std::string searchName;
    std::cout << "Enter the name to search for: ";
    std::getline(std::cin >> std::ws, searchName); // Read the name to search

    bool found = false; // Flag to track if any match is found

    std::cout << "\n--- Search Results ---" << std::endl;
    for (const auto& contact : contacts) {
        // Simple case-sensitive string comparison
        if (contact.name == searchName) {
            if (!found) { // Print header only once when the first match is found
                 std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Phone Number" << std::endl;
                 std::cout << "-----------------------------------" << std::endl;
            }
            contact.printDetails(); // Using the virtual function
            found = true; // Set flag to true as we found at least one match
        }
    }

    if (!found) {
        std::cout << "Contact '" << searchName << "' not found." << std::endl;
    } else {
        std::cout << "-----------------------------------" << std::endl; // Footer if found
    }
}
