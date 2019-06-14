/*
 * MLPackImpl.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: nanab
 */

#include "MLPackImpl.hpp"
#include <mlpack/core.hpp>
#include <mlpack/methods/ann/layer/layer.hpp>
#include <mlpack/methods/ann/loss_functions/mean_squared_error.hpp>
#include <mlpack/methods/ann/ffn.hpp>
#include <mlpack/core/data/load_impl.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

using namespace std;
using namespace mlpack;
using namespace arma;

MLPackImpl::MLPackImpl(vector<LabeledData> labeledData){
	this->labeledData = labeledData;
}

void MLPackImpl::generateTrainingDataResourceFile(){
	cout << "about to generate training data to file" << endl;
	arma::mat dataset;
	arma::Mat<size_t> labels;


}

