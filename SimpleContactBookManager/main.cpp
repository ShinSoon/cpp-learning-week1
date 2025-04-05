#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> // Required for std::setw

// Struct definition (same as before)
struct Contact {
    std::string name;
    std::string phoneNumber;
};

// --- Function Prototypes ---
void displayContacts(const Contact contacts[], int size);
void addContact(Contact contacts[], int& size, int maxSize);
// [ ] Add a new function prototype for findContactByName
void findContactByName(const Contact contacts[], int size); // New function prototype

int main() {
    const int MAX_CONTACTS = 10;
    Contact contacts[MAX_CONTACTS];
    int currentSize = 0;
    int choice;

    while (true) {
        std::cout << "\n--- Contact Book Menu ---" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        // [ ] Add a new option to your main menu loop
        std::cout << "3. Find Contact by Name" << std::endl; // New option
        std::cout << "4. Exit" << std::endl;                 // Renumbered Exit
        std::cout << "-------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "\n*** Invalid input. Please enter a number (1-4). ***" << std::endl; // Updated range
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

        switch (choice) {
            case 1:
                addContact(contacts, currentSize, MAX_CONTACTS);
                break;
            case 2:
                displayContacts(contacts, currentSize);
                break;
            // [ ] Add a case to call the search function
            case 3: // New case for search
                findContactByName(contacts, currentSize);
                break;
            case 4: // Renumbered case for Exit
                std::cout << "\nExiting Contact Book. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "\n*** Invalid choice. Please enter 1, 2, 3, or 4. ***" << std::endl; // Updated range
                break;
        }
    }

    return 0; // Should be unreachable
}

// displayContacts function (same as before)
void displayContacts(const Contact contacts[], int size) {
    std::cout << "\n--- Stored Contacts (" << size << "/" << 10 << ") ---" << std::endl;
    if (size == 0) {
        std::cout << "No contacts to display." << std::endl;
    } else {
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Phone Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << std::left << std::setw(20) << contacts[i].name
                      << std::setw(15) << contacts[i].phoneNumber << std::endl;
        }
    }
    std::cout << "-----------------------------------" << std::endl;
}

// addContact function (same as before)
void addContact(Contact contacts[], int& size, int maxSize) {
    std::cout << "\n--- Add New Contact ---" << std::endl;
    if (size >= maxSize) {
        std::cout << "*** Error: Contact book is full. Cannot add more contacts. ***" << std::endl;
        return;
    }
    Contact newContact;
    std::cout << "Enter contact name: ";
    std::getline(std::cin >> std::ws, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin >> std::ws, newContact.phoneNumber);
    contacts[size] = newContact;
    size++;
    std::cout << "*** Contact '" << newContact.name << "' added successfully. ***" << std::endl;
}


// [ ] Implement the new function void findContactByName(...)
/**
 * @brief Prompts the user for a name and searches for matching contacts.
 *        Prints the details of any contact found.
 *
 * @param contacts The array of Contact objects (const as it's not modified).
 * @param size The current number of contacts stored in the array.
 */
void findContactByName(const Contact contacts[], int size) {
    std::cout << "\n--- Find Contact by Name ---" << std::endl;
    if (size == 0) {
        std::cout << "No contacts stored yet to search." << std::endl;
        return;
    }

    std::string searchName;
    std::cout << "Enter the name to search for: ";
    std::getline(std::cin >> std::ws, searchName); // Read the name to search

    bool found = false; // Flag to track if any match is found

    std::cout << "\n--- Search Results ---" << std::endl;
    for (int i = 0; i < size; ++i) {
        // Simple case-sensitive string comparison
        if (contacts[i].name == searchName) {
            if (!found) { // Print header only once when the first match is found
                 std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Phone Number" << std::endl;
                 std::cout << "-----------------------------------" << std::endl;
            }
            std::cout << std::left << std::setw(20) << contacts[i].name
                      << std::setw(15) << contacts[i].phoneNumber << std::endl;
            found = true; // Set flag to true as we found at least one match
        }
    }

    if (!found) {
        std::cout << "Contact '" << searchName << "' not found." << std::endl;
    } else {
         std::cout << "-----------------------------------" << std::endl; // Footer if found
    }

}
