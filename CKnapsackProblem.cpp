#include "CKnapsackProblem.h"
#include <fstream>

CKnapsackProblem::CKnapsackProblem(int itemsCount, const vector<int>& values, const vector<int>& weights, int capacity)
	: itemsCount(itemsCount), values(values), weights(weights), capacity(capacity) 
{
	if (itemsCount <= 0 || values.size() != itemsCount || weights.size() != itemsCount || capacity < 1) 
	{
		throw invalid_argument("Invalid input data for knapsack problem");
	}
}

CKnapsackProblem::CKnapsackProblem(const string& fileName)
{
	ifstream file(fileName);

	if (!file.is_open() || !(file >> capacity))
	{
		file.close();
		throw invalid_argument("Invalid file data for knapsack problem");
	}

	int data;
	int i = 0;
	for(; file >> data; i++)
	{
		if (i % 2 == 0)
		{
			values.push_back(data);
		}
		else {
			weights.push_back(data);
		}
	}

	if (i % 2 == 1 || i == 0)
	{
		file.close();
		throw invalid_argument("Invalid file data for knapsack problem");
	}

	itemsCount = values.size();

	file.close();
}

CKnapsackProblem::CKnapsackProblem(const CKnapsackProblem& problem)
{
	itemsCount = problem.itemsCount;
	capacity = problem.capacity;
	values = problem.values;
	weights = problem.weights;
}

int CKnapsackProblem::evaluate(const std::vector<int>& genotype)
{
	int weight = 0;
	int value = 0;

	for (int item = 0; item < itemsCount; item++)
	{
		if (genotype[item] == 1)
		{
			weight += weights[item];
			value += values[item];
		}
	}

	if (weight > capacity) return -1;

	return value;
}
