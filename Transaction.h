#pragma once
#include <string>

class Transaction
{
private:
	double amount;
	std::string description;
	std::string type;
	std::string category;
public:
	Transaction(double amount, const std::string& description, const std::string& type, const std::string& category);
	const std::string& getCategory() const { return category; }
	void setCategory(const std::string& category) { this->category = category; }
	double getAmount() const;
	void setAmount(double amt);
	std::string getDescription() const;
	void setDescription(const std::string& desc);
	std::string getType() const;
	void setType(const std::string& t);
	std::string toString() const;
	static Transaction fromString(const std::string& str);
};