#include "CIndividual.h"
#include <random>

CIndividual::CIndividual(int itemsCount) : itemsCount(itemsCount)
{
	for (int i = 0; i < itemsCount; i++)
	{
		genotype.push_back(rand() % 2);
	}
}

int CIndividual::evaluate(CKnapsackProblem& problem)
{
	return problem.evaluate(genotype);
}

void CIndividual::mutate(double mutProb)
{
	for (int i = 0; i < itemsCount; i++)
	{
		if (((double)rand() / RAND_MAX) < mutProb)
		{
			genotype[i] = 1 - genotype[i];
		}
	}
}


void CIndividual::crossover(CIndividual& other)
{
	int crossPoint = rand() % itemsCount;

	for (int i = 0; i <= crossPoint; i++)
	{
		genotype[i] = other.genotype[i];
	}
}