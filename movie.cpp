#include "movie.h"
using namespace std;

Movie::Movie(std::string category, std::string name, double price, int qty, std::string genre_, std::string rating_) :
Product(category, name, price, qty)
	{
		genre = genre_;
		rating = rating_;
	}
std::set<std::string> Movie::keywords()
{
	std::set<std::string> movieKey = parseStringToWords(genre);
	return movieKey;
}
bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
	if (keywords() == searchTerms)
	{
		return true;
	}
	return false;
}
std::string Movie::displayString()
{
	std::string dis = getName() + "\nGenre: " + genre + " Rating: " + rating + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left." + "\n";
	return dis;
}
void Movie::dump(std::ostream& os) const
{
	os << "movie" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << genre << "\n" << rating << endl;
}
~Movie()
{
	
}