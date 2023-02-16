#include "product.h"
#include "util.h"

class Clothing : public Product {
public:
	Clothing(std::string category, std::string name, double price, int qty, std::string size_, std::string brand_);
	~Clothing();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

	std::string size;
	std::string brand;
};