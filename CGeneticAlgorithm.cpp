#include "CGeneticAlgorithm.h"
#include <algorithm>
#include <random>

CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem& problem, int popSize, double crossProb, double mutProb, int iterationsCount)
	: problem(problem), popSize(popSize), crossProb(crossProb), mutProb(mutProb), iterationsCount(iterationsCount)
{
	if (iterationsCount < 1 || popSize < 1)
	{
		throw invalid_argument("Invalid input data for genetic algorithm");
	}

	for (int i = 0; i < popSize; i++)
	{
		CIndividual newInd(problem.itemsCount);
		bestSolution = max(bestSolution, newInd.evaluate(problem));
		population.push_back(newInd);
	}
}

void CGeneticAlgorithm::run()
{
	bestSolution = -1;
	for (int iter = 1; iter <= iterationsCount; iter++)
	{
		int localBest = -1;
		auto oldPop = population;
		for (int i = 0; i < popSize; i++)
		{
			if (((double) rand() / RAND_MAX) < crossProb)
			{
				int crossWith = rand() % popSize;

				if (crossWith == i) crossWith = (crossWith + 1) % popSize;

				population[i].crossover(oldPop[crossWith]);
			}
		}

		for (auto& ind : population)
		{
			ind.mutate(mutProb);
			localBest = max(ind.evaluate(problem), localBest);
		}

		bestSolution = max(bestSolution, localBest);

		//std::cout << "Population " << iter << " best : " << localBest << endl;
	}
}

int CGeneticAlgorithm::getBestSolution()
{
	return bestSolution;
}