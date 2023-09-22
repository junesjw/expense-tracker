#include "ExpenseTracker.h"
#include <iostream>
#include <fstream>
#include <sstream>

void ExpenseTracker::addTransaction(const Transaction& t) 
{
    transactions.push_back(t);
}

void ExpenseTracker::removeTransaction(int index) 
{
    if (index < 0 || index >= transactions.size()) 
    {
        std::cout << "Invalid index.\n";
        return;
    }
    transactions.erase(transactions.begin() + index);
}

void ExpenseTracker::editTransaction(int index, const Transaction& t) 
{
    if (index < 0 || index >= transactions.size()) 
    {
        std::cout << "Invalid index.\n";
        return;
    }
    transactions[index] = t;
}

void ExpenseTracker::viewSummary() const 
{
    double totalIncome = 0.0, totalExpense = 0.0;
    for (const auto& transaction : transactions) 
    {
        std::cout << "Amount: " << transaction.getAmount()
            << " Description: " << transaction.getDescription()
            << " Type: " << transaction.getType() 
            << " Category: " << transaction.getCategory() << "\n";
        if (transaction.getType() == "Income")
            totalIncome += transaction.getAmount();
        else
            totalExpense += transaction.getAmount();
    }
    std::cout << "Total Income: " << totalIncome << "\n";
    std::cout << "Total Expense: " << totalExpense << "\n";
}

void ExpenseTracker::saveToFile(const std::string& filename) const 
{
    std::ofstream outfile(filename);
    for (const auto& transaction : transactions) {
        outfile << transaction.toString() << std::endl; // Write each transaction to a new line
    }
    outfile.close();
}

void ExpenseTracker::loadFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (getline(ss, token, ',')) 
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 4) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }

        double amount = std::stod(tokens[0]);
        const std::string& description = tokens[1];
        const std::string& type = tokens[2];
        const std::string& category = tokens[3];

        Transaction t(amount, description, type, category);
        addTransaction(t);
    }

    file.close();
}