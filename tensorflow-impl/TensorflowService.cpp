/*
 * Tensorflow.cpp
 *
 *  Created on: Jun 10, 2019
 *      Author: nanab
 */


#include <iostream>
#include <vector>
#include "TensorflowService.hpp"

using namespace std;

vector<LabeledData> TensorflowService::labelTrainingData(vector<Query> queries){
	vector<LabeledData> labeledData;

	if(queries.size() > 0){
		for(vector<Query>::iterator itr = queries.begin(); itr != queries.end(); ++itr){
			Query query = *itr;

			string text = query.getText();

			int count = query.getItemCount();
			int labelScore = this->computeLabelScoreByItemCount(count);

			LabeledData scoredLabel(text, labelScore);

			labeledData.push_back(scoredLabel);
		}
	}

	return labeledData;
}

int TensorflowService::computeLabelScoreByItemCount(int itemCount){
	int answer = 0;

	if(itemCount > 0){

		if(itemCount == 0){
			answer = 0;
		}

		if(itemCount > 0 && itemCount < 10){
			answer = 1;
		}

		if(itemCount >= 10 && itemCount < 20){
			answer = 2;
		}

		if(itemCount >= 20 && itemCount < 30){
			answer = 3;
		}

		if(itemCount >= 30 && itemCount < 40){
			answer = 4;
		}

		if(itemCount >= 40 && itemCount < 50){
			answer = 5;
		}

		if(itemCount >= 50 && itemCount < 60){
			answer = 6;
		}

		if(itemCount >= 60 && itemCount < 70){
			answer = 7;
		}

		if(itemCount >= 80 && itemCount < 90){
			answer = 8;
		}

		if(itemCount >= 90){
			answer = 9;
		}
	}
	return answer;
}

void TensorflowService::execute(vector<LabeledData> labeledData){
	int size = labeledData.size();

	if(size > 0){
		cout << "about to beginning data training on : "<< size << " records." << endl;

	}
}

