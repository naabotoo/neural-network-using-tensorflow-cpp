#include "ReadQueryManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstring>
#include <unordered_set>
#include <map>
#include "json/json.h"

using namespace std;

ReadQueryManager::ReadQueryManager(string resourceFile) {
	readResourceFile = resourceFile;
	initiateResourceFile();
}

void ReadQueryManager::initiateResourceFile() {
	cout << "about to get queries from file : " << this->readResourceFile
			<< endl;

	if (!this->readResourceFile.empty()) {
		ifstream ifs(readResourceFile);

		try {
			Json::Reader reader;
			Json::Value value;

			bool parseSuccess = reader.parse(ifs, value, true);

			if (parseSuccess) {
				int size = value.size();

				cout << "no. of training data found : "<< size << endl;


				if(size > 0){
					unordered_set<string> uniqueQueries;

					map<string, Json::Int64> queryToCountMap;

					for(Json::Value::ArrayIndex i = 0; i < size; i++){

						Json::Value queryValue = value[i]["query"];
						Json::Int64 countValue = value[i]["noOfItems"].asInt64();

						string query = this->jsonStringToString(queryValue);

						if(uniqueQueries.find(query) == uniqueQueries.end()){
							uniqueQueries.insert(query);
						}

						if(queryToCountMap.find(query) == queryToCountMap.end()){
							queryToCountMap.insert(pair<string, Json::Int64>(query, countValue));
						} else {
							Json::Int64 existingCount = queryToCountMap.at(query);
							Json::Int64 incomingCount = existingCount + countValue;
							queryToCountMap.insert(pair<string, Json::Int64>(query, incomingCount));
						}
					}

					if(queryToCountMap.size() > 0){

						map<string, Json::Int64>::iterator itr;

						for(itr = queryToCountMap.begin(); itr != queryToCountMap.end(); ++itr){
							string query = itr->first;
							Json::Int64 count = itr->second;

							Query queryData(query, count);
							this->readQueries.push_back(queryData);
						}

					}
				}
			}

		} catch (exception& ex) {
			cout << "Exception occurred in getting queries : " << ex.what() << endl;
		}

		ifs.close();
	}
}

string ReadQueryManager::jsonStringToString(Json::Value jsonString){
	Json::FastWriter fastWriter;
	return fastWriter.write(jsonString);
}

