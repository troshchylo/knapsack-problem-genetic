#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem(int itemsCount, const vector<int>& values, const vector<int>& weights, int capacity);
	CKnapsackProblem(const string& fileName);
	CKnapsackProblem(const CKnapsackProblem& problem);
	int evaluate(const vector<int>& genotype);
	friend class CGeneticAlgorithm;
private:
	int itemsCount;
	int capacity;
	vector<int> values;
	vector<int> weights;
};