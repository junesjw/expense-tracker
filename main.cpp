#include "ExpenseTracker.h"
#include <iostream>
#include <limits>

double getUserInputAmount()
{
    double amount;
    while (true)
    {
        std::cout << "Enter amount: ";
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0)
        {
            std::cin.clear(); // Reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Amount must be a positive number. Please enter again.\n";
        }
        else
        {
            std::cin.ignore(); // To clear the input buffer of newline character
            return amount;
        }
    }
}

std::string getUserInputDescription()
{
    std::string description;
    do 
    {
        std::cout << "Enter description: ";
        std::getline(std::cin, description);
        if (description.empty())
            std::cout << "Description cannot be empty. Please enter again.\n";
    } while (description.empty());
    return description;
}

std::string getUserInputType()
{
    std::string type;
    do 
    {
        std::cout << "Enter type (Income/Expense): ";
        std::getline(std::cin, type);
        if (type != "Income" && type != "Expense")
            std::cout << "Invalid type entered. Please enter either 'Income' or 'Expense'.\n";
    } while (type != "Income" && type != "Expense");
    return type;
}

std::string getUserInputCategory()
{
    std::string category;
    do 
    {
        std::cout << "Enter category: ";
        std::getline(std::cin, category);
        if (category.empty())
            std::cout << "Category cannot be empty. Please enter again.\n";
    } while (category.empty());
    return category;
}

int getUserInputIndex(const std::string& prompt)
{
    int index;
    while (true)
    {
        std::cout << prompt;
        std::cin >> index;

        if (std::cin.fail() || index < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please enter a non-negative integer.\n";
        }
        else
        {
            std::cin.ignore();
            return index;
        }
    }
}

void addTransaction(ExpenseTracker& tracker)
{
    double amount = getUserInputAmount();
    std::string description = getUserInputDescription();
    std::string type = getUserInputType();
    std::string category = getUserInputCategory();

    Transaction t(amount, description, type, category);
    tracker.addTransaction(t);
}


void removeTransaction(ExpenseTracker& tracker)
{
    int index = getUserInputIndex("Enter the index of the transaction to remove: ");

    tracker.removeTransaction(index);
}

void editTransaction(ExpenseTracker& tracker)
{
    int index = getUserInputIndex("Enter the index of the transaction to edit: ");

    double amount = getUserInputAmount();
    std::string description = getUserInputDescription();
    std::string type = getUserInputType();
    std::string category = getUserInputCategory();

    Transaction t(amount, description, type, category);
    tracker.editTransaction(index, t);
}

int main() 
{
    ExpenseTracker tracker;
    int choice;
    do 
    {
        std::cout << "1. Add Transaction\n";
        std::cout << "2. Remove Transaction\n";
        std::cout << "3. Edit Transaction\n";
        std::cout << "4. View Summary\n";
        std::cout << "5. Save Transactions to File\n";
        std::cout << "6. Load Transactions from File\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) 
        {
        case 1:
            addTransaction(tracker);
            break;
        case 2:
            removeTransaction(tracker);
            break;
        case 3:
            editTransaction(tracker);
            break;
        case 4:
            tracker.viewSummary();
            break;
        case 5:
            std::cout << "Saving Transactions to File...\n";
            tracker.saveToFile("transactions.txt");
            break;
        case 6:
            std::cout << "Loading Transactions from File...\n";
            tracker.loadFromFile("transactions.txt");
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 7);

    return 0;
}