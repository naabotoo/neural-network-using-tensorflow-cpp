/*
 * ReadQueryManager.hpp
 *
 *  Created on: Jun 4, 2019
 *      Author: nanab
 */

#ifndef READQUERYMANAGER_HPP_
#define READQUERYMANAGER_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "Query.hpp"
#include "json/json.h"

using namespace std;

class ReadQueryManager {
	private:
		string readResourceFile;
		vector<Query> readQueries;
		string jsonStringToString(Json::Value jsonString);

	public:
		ReadQueryManager(string resourceFile);
		vector<Query> getQueries(){ return readQueries; };
		void initiateResourceFile();
};


#endif /* READQUERYMANAGER_HPP_ */
