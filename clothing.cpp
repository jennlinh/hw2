#include "clothing.h"
using namespace std;

Clothing::Clothing(std::string category, std::string name, double price, int qty, std::string size_, std::string brand_) :
Product(category, name, price, qty)
{
	size = size_;
	brand = brand_;
}	
std::set<std::string> Clothing::keywords()
{
	std::set<std::string> clothingKey = parseStringToWords(brand);
	return clothingKey;
}
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
	if (keywords() == searchTerms)
	{
		return true;
	}
	return false;
}
std::string Clothing::displayString()
{
  std::string dis = getName() + "\nSize:" + size + " Brand: " + brand + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left.\n";
	return dis;
}
void Clothing::dump(std::ostream& os) const
{
	os << "clothing" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << size << "\n" << brand << endl;
}
~Clothing()
{

}