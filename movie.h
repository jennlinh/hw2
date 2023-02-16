#include "product.h"
#include "util.h"

class Movie : public Product {
public:
	Movie(std::string category, std::string name, double price, int qty, std::string author_, std::string isbn_);
	~Movie();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

	std::string genre;
	std::string rating;
};