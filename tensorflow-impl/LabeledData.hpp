/*
 * LabeledData.hpp
 *
 *  Created on: Jun 10, 2019
 *      Author: nanab
 */

#ifndef TENSORFLOW_IMPL_LABELEDDATA_HPP_
#define TENSORFLOW_IMPL_LABELEDDATA_HPP_

#include <iostream>
#include <string>

using namespace std;

class LabeledData {
	private:
		string query;
		int score;

	public:
		LabeledData(string query, int score);
		string getQuery();
		int getScore();
};



#endif /* TENSORFLOW_IMPL_LABELEDDATA_HPP_ */
