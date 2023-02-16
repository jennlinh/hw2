#include "datastore.h"

	void MyDataStore::addProduct(Product* p)
	{
		pair.insert()
		prodList.insert(p);
	}
	void MyDataStore::addUser(User* u)
	{
		userList.insert(u);
	}
	/* Results must be displayed to the user via the 
	displayProducts(vector<Product*>& hits); function provided 
	in amazon.cpp. Failure to use this function will result in 
	LARGE deductions since it will make our testing much harder. 
	
  Performs a search of products whose keywords match the given "terms"
  type 0 = AND search (intersection of results for each term) while
  type 1 = OR search (union of results for each term)
  */
	std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
	{
		std::vector<Product*> searches;
		if (type == 0) //intersections of results
		{
			std::set<Product*>::iterator itr;
  		for (itr = setIntersection(terms, prodList).begin(); itr != setIntersection(terms, prodList).end(); itr++)
			{
				searches.push_back(*itr);
			}
		}
		else if (type == 1) //union of results
		{
			std::set<Product*>::iterator itr;
  		for (itr = setUnion(terms, prodList).begin(); itr != setUnion(terms, prodList).end(); itr++)
			{
				searches.push_back(*itr);
			}
		}
		return searches;
	}
	void MyDataStore::dump(std::ostream& ofile)
	{
		std::set<Product*>::iterator itrP;
  	for (itrP = prodList.begin(); itrP != prodList.end(); itrP++)
		{
			*itrP->dump(ofile);
		}
		std::set<User*>::iterator itrU;
  	for (itrU = userList.begin(); itrU != userList.end(); itrU++)
		{
			*itrU->dump(ofile);
		}
	}
	std::set<User> getUserList()
	{
		return userList;
	}
	std::set<Product> getProdList()
	{
		return prodList;
	}