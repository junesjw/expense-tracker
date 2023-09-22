#include "Transaction.h"
#include <sstream>

Transaction::Transaction(double amount, const std::string& description, const std::string& type, const std::string& category)
    : amount(amount), description(description), type(type), category(category) {}

double Transaction::getAmount() const 
{
    return amount;
}

void Transaction::setAmount(double amt) 
{
    amount = amt;
}

std::string Transaction::getDescription() const 
{
    return description;
}

void Transaction::setDescription(const std::string& desc)
{
    description = desc;
}

std::string Transaction::getType() const 
{
    return type;
}

void Transaction::setType(const std::string& t) 
{
    type = t;
}


std::string Transaction::toString() const 
{
    std::ostringstream oss;
    oss << amount << "," << description << "," << type << "," << category;
    return oss.str();
}

Transaction Transaction::fromString(const std::string& str) 
{
    std::istringstream iss(str);
    double amount;
    std::string description, type, category;

    std::getline(iss, description, ',');
    std::getline(iss, type, ',');
    std::getline(iss, category, ',');
    iss >> amount;

    return Transaction(amount, description, type, category);
}