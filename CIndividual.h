#pragma once
#include <iostream>
#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual
{
public:
	CIndividual(int itemsCount);
	int evaluate(CKnapsackProblem& problem);
	void mutate(double mutProb);
	void crossover(CIndividual& other);
private:
	int itemsCount;
	vector<int> genotype;
};