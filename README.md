# TSP-GA: Solving the Traveling Salesperson Problem using Genetic Algorithms

This project explores a solution to the classic Traveling Salesperson Problem (TSP) implemented in C, leveraging the power of Genetic Algorithms (GA).

## The Traveling Salesperson Problem (TSP)

The TSP is a well-known combinatorial optimization problem. Given a list of cities and the distances between each pair of cities, the challenge is to find the shortest possible route that visits each city exactly once and returns to the origin city.

Despite its simple description, finding the absolute optimal solution for the TSP is computationally very difficult (NP-hard) as the number of possible routes grows factorially with the number of cities. For a large number of cities, checking every single permutation becomes infeasible.

## Our Approach: Genetic Algorithms (GA)

This project employs a Genetic Algorithm, a metaheuristic inspired by the process of natural selection, to find a near-optimal solution to the TSP. GAs are particularly well-suited for optimization problems where the search space is vast and complex.

Here's how the GA is applied in this project:

1. **Representation:** A potential solution (a route visiting all cities) is represented as a "chromosome". In this case, a chromosome is an ordered list (permutation) of the cities.

2. **Population Initialization:** The algorithm starts by creating an initial population of random routes (chromosomes).

3. **Fitness Evaluation:** Each route in the population is evaluated based on a "fitness" function. For the TSP, the fitness is inversely related to the total length of the route – shorter routes are considered more "fit". This project calculates the total Euclidean distance for each route.

4. **Selection:** Routes are selected from the current population to become "parents" for the next generation. Fitter routes have a higher probability of being selected, mimicking the "survival of the fittest" principle. Various selection methods can be used (e.g., tournament selection, roulette wheel selection).

5. **Crossover (Recombination):** Selected parent routes are combined to create new "offspring" routes. Crossover operators (like ordered crossover or partially mapped crossover) are designed to inherit potentially good sub-sequences of cities from the parents while maintaining the validity of the route (visiting each city once).

6. **Mutation:** To maintain genetic diversity and prevent premature convergence to a suboptimal solution, random changes are introduced into some offspring routes. For the TSP, a common mutation operator is swapping two cities in the route sequence.

7. **Iteration:** The process of evaluation, selection, crossover, and mutation is repeated over many generations. With each generation, the overall fitness of the population tends to improve, leading towards better (shorter) routes.

8. **Termination:** The algorithm stops after a predefined number of generations or when the solution quality stops improving significantly.

The final result is the best route (chromosome) found throughout the evolutionary process.

## Implementation Details

* The core logic is implemented in C.
* City coordinates are read from simple text files.
* Distance calculations use the Euclidean distance formula.
* (Optional) The MLV library can be used for visualizing the cities and the best route found during the algorithm's execution.

## Project Structure

```text
pvc/
├── makefile           # Build configuration
├── pvc                # Executable (after build)
├── README.md          # This file
├── data/              # Input city data files (.txt)
│   ├── ...
├── inc/               # Header files (.h)
│   ├── calc.h
│   ├── file.h
│   ├── graphics.h
│   └── route.h
├── src/               # Source files (.c)
│   ├── calc.c
│   ├── file.c
│   ├── graphics.c
│   ├── main.c
│   └── route.c
└── sujet/             # Project-related documents
    ├── Sujet.pdf
    └── todo.md
```

## Future Work (TODO)

Based on `sujet/todo.md`:

* Implement robust termination criteria for the GA.
* Save the best found solution to an output file.
* Develop a user interface or command-line arguments for specifying input files and GA parameters (population size, mutation rate, generations, etc.).
* Add unit and integration tests.
* Enhance code documentation and comments.
* Implement more robust error handling.
* Explore performance optimizations.
* Experiment with different GA operators (selection, crossover, mutation) and parameter tuning.
