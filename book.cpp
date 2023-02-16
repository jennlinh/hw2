#include "book.h"
using namespace std;

	Book::Book(std::string category, std::string name, double price, int qty, std::string author_, std::string isbn_) :
	Product(category, name, price, qty)
	{
		author = author_;
		isbn = isbn_;
	}
	std::set<std::string> Book::keywords()
	{
		std::set<std::string> bookKey = parseStringToWords(author);
		bookKey.insert(isbn);
		return bookKey;
	}
	bool Book::isMatch(std::vector<std::string>& searchTerms) const
	{
		if (keywords() == searchTerms)
		{
			return true;
		}
		return false;
	}
	std::string Book::displayString()
	{
		std::string dis = getName() + "\n Author: " + author + " ISBN: " + isbn + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left." + "\n";
		return dis;
	}
	void Book::dump(std::ostream& os) const
	{
		os << "book" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << isbn << "\n" << author << endl;
	}
	~Book()
	{
		
	}