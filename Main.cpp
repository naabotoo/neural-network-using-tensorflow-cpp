#include <iostream>
#include <string>
#include "Query.hpp"
#include "ReadQueryManager.hpp"
#include "tensorflow-impl/TensorflowService.hpp"

using namespace std;

int main(){

	string resourceFile = "training_data.json";

	ReadQueryManager readQueryManager(resourceFile);
	vector<Query> queries = readQueryManager.getQueries();

	cout << "no. of queries found : "<< queries.size() << endl;

	if(queries.size() > 0){

		TensorflowService tensorflowService;
		vector<LabeledData> labeledData = tensorflowService.labelTrainingData(queries);

		int labeledDataSize = labeledData.size();
		cout << "no. labeled data size : "<< labeledDataSize << endl;

		tensorflowService.execute(labeledData);

	}

	return 0;
}
