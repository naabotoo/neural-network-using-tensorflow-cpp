#include "Query.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Query::Query(string text, int itemCount){
	queryText = text;
	queryItemCount = itemCount;
}

string Query::toString(){
	return "query text : " + this->queryText + " , item count : "+ to_string(this->queryItemCount); 
}