/*
 * MLPackImpl.hpp
 *
 *  Created on: Jun 12, 2019
 *      Author: nanab
 */

#ifndef MLPACK_IMPL_MLPACKIMPL_HPP_
#define MLPACK_IMPL_MLPACKIMPL_HPP_

#include <vector>
#include "../tensorflow-impl/LabeledData.hpp"

class MLPackImpl {
	private:
		vector<LabeledData> labeledData;
	public:
		MLPackImpl(vector<LabeledData> labeledDate);
		void generateTrainingDataResourceFile();
};


#endif /* MLPACK_IMPL_MLPACKIMPL_HPP_ */
