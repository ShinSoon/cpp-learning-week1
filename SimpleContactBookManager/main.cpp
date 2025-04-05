#include <iostream>
#include <string>
#include <vector>   // Although using fixed array, vector might be useful for temp storage or future expansion knowledge
#include <limits>   // Required for numeric_limits (used in input clearing)
#include <iomanip>  // Required for std::setw (optional, for better display formatting)

// [ ] Define a struct or class named Contact
struct Contact {
    std::string name;
    std::string phoneNumber;
};

// Function Prototypes (good practice to declare functions before main if defined after)
void displayContacts(const Contact contacts[], int size);
void addContact(Contact contacts[], int& size, int maxSize);

int main() {
    // [ ] In main(), declare a fixed-size array and tracking variables
    const int MAX_CONTACTS = 10; // Set the maximum size
    Contact contacts[MAX_CONTACTS]; // The array to hold contacts
    int currentSize = 0; // Track how many contacts are actually stored

    int choice;

    // [ ] In main(), create a simple loop-based menu:
    while (true) {
        std::cout << "\n--- Contact Book Menu ---" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        // Get user choice and perform basic validation
        std::cin >> choice;

        // Check if the input operation failed (e.g., user entered text)
        if (std::cin.fail()) {
            std::cout << "\n*** Invalid input. Please enter a number (1-3). ***" << std::endl;
            std::cin.clear(); // Clear the error flags
            // Discard the invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Go to the next iteration of the loop
        }

        // Consume the leftover newline character after reading the integer
        // This prevents issues with std::getline in addContact
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // [ ] Use a switch statement or if/else if to call functions
        switch (choice) {
            case 1:
                addContact(contacts, currentSize, MAX_CONTACTS);
                break;
            case 2:
                displayContacts(contacts, currentSize);
                break;
            case 3:
                std::cout << "\nExiting Contact Book. Goodbye!" << std::endl;
                return 0; // Exit the program successfully
            default:
                std::cout << "\n*** Invalid choice. Please enter 1, 2, or 3. ***" << std::endl;
                break;
        }
    }

    // This part is technically unreachable because the loop exits via 'return 0;'
    // but it's good practice for main to return 0 on successful completion.
    return 0;
}

// [ ] Implement a function void displayContacts(...)
/**
 * @brief Displays the details of all contacts currently stored in the array.
 *
 * @param contacts The array of Contact objects (passed as const as it's not modified).
 * @param size The current number of contacts stored in the array.
 */
void displayContacts(const Contact contacts[], int size) {
    std::cout << "\n--- Stored Contacts (" << size << "/" << 10 /* Hardcoded maxSize for display, could pass if needed */ << ") ---" << std::endl;
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

// [ ] Implement a function void addContact(...)
/**
 * @brief Adds a new contact to the array if space is available.
 *        Prompts the user for contact details.
 *
 * @param contacts The array of Contact objects.
 * @param size A reference to the current number of contacts (will be incremented).
 * @param maxSize The maximum capacity of the contacts array.
 */
void addContact(Contact contacts[], int& size, int maxSize) {
    std::cout << "\n--- Add New Contact ---" << std::endl;

    // Check if the array is full
    if (size >= maxSize) {
        std::cout << "*** Error: Contact book is full. Cannot add more contacts. ***" << std::endl;
        return; // Exit the function
    }

    // Create a temporary Contact object to store new data
    Contact newContact;

    // Prompt user for name
    std::cout << "Enter contact name: ";
    // Use std::getline to allow names with spaces.
    // std::ws consumes leading whitespace potentially left by previous std::cin >> choice
    // Note: We already used cin.ignore() in main, so std::ws might be redundant here,
    // but it's safer to include it or be aware of the potential issue.
    std::getline(std::cin >> std::ws, newContact.name);

    // Prompt user for phone number
    std::cout << "Enter phone number: ";
    std::getline(std::cin >> std::ws, newContact.phoneNumber);

    // Add the new contact to the array at the next available index
    contacts[size] = newContact;

    // Increment the size counter (modifies the original currentSize in main via reference)
    size++;

    std::cout << "*** Contact '" << newContact.name << "' added successfully. ***" << std::endl;
}
