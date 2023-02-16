#include "datastore.h"

class MyDataStore : public DataStore{
public:
	void addProduct(Product* p);
	void addUser(User* u);
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	void dump(std::ostream& ofile);
protected:
	std::set<User*> userList;
	std::set<Product*> prodList;
	std::map<std::set<Product*>, std::set<std::string>> pair;
	// make a map of keywords to products
};