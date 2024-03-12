#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(CKnapsackProblem& problem, int popSize, double crossProb, double mutProb, int iterationsCount);
	void run();
	int getBestSolution();
private:
	CKnapsackProblem& problem;
	vector<CIndividual> population;
	int bestSolution = -1;
	int iterationsCount;
	int popSize;
	double crossProb;
	double mutProb;
};