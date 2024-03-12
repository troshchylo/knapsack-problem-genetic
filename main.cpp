#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"

int main()
{
	srand(time(NULL));
	CKnapsackProblem problem("b.txt");
	CGeneticAlgorithm alg(problem, 300, 0.7, 0.05, 100);
	alg.run();
	cout << "Best solution: " << alg.getBestSolution() << endl;


	CKnapsackProblem problem2("a.txt");
	CGeneticAlgorithm alg2(problem2, 50, 0.6, 0.1, 100);
	alg2.run();
	cout << "Best solution: " << alg2.getBestSolution() << endl;
	return 0;
}