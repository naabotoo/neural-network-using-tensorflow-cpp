#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>

using namespace std;

class Query {
	private:
		string queryText;
		int queryItemCount;

	public:
		Query(string text, int itemCount);
		int getItemCount(){ return queryItemCount; }
		string getText(){ return queryText; }
		string toString();
};

#endif
