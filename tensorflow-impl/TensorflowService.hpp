/*
 * TensorflowService.hpp
 *
 *  Created on: Jun 10, 2019
 *      Author: nanab
 */
#include <vector>
#include "LabeledData.hpp"
#include "../Query.hpp"

using namespace std;

#ifndef TENSORFLOW_IMPL_TENSORFLOWSERVICE_HPP_
#define TENSORFLOW_IMPL_TENSORFLOWSERVICE_HPP_

class TensorflowService {
	private:
		int computeLabelScoreByItemCount(int itemCount);

	public:
		vector<LabeledData> labelTrainingData(vector<Query> queries);
		void execute(vector<LabeledData> labeledData);
};



#endif /* TENSORFLOW_IMPL_TENSORFLOWSERVICE_HPP_ */
