#include "product.h"
#include "util.cpp"

class Book : public Product {
public:
	Book(std::string category, std::string name, double price, int qty, std::string author_, std::string isbn_);
	~Book();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

	std::string author;
	std::string isbn;
};