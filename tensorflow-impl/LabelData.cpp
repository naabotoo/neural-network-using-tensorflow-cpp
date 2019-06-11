/*
 * LabelData.cpp
 *
 *  Created on: Jun 10, 2019
 *      Author: nanab
 */

#include "LabeledData.hpp"

LabeledData::LabeledData(string query, int score){
	this->query = query;
	this->score = score;
}

string LabeledData::getQuery(){
	return this->query;
}

int LabeledData::getScore(){
	return this->score;
}
