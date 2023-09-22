#include <vector>
#include "Transaction.h"

class ExpenseTracker
{
private:
	std::vector<Transaction> transactions;
public:
	void addTransaction(const Transaction& t);
	void removeTransaction(int index);
	void editTransaction(int index, const Transaction& t);
	void viewSummary() const;
	void saveToFile(const std::string& filename) const;
	void loadFromFile(const std::string& filename);
};