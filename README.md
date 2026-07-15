# philosophers

## What is this?
A concurrency simulation built from scratch as part of the CODAM 
(42 Network) curriculum. Based on the classic Dining Philosophers 
problem by Edsger Dijkstra.

## How it works
A number of philosophers sit at a table with one fork between each 
pair. They alternate between eating, thinking and sleeping. Each 
philosopher needs two forks to eat. The challenge is to ensure no 
philosopher starves while avoiding deadlocks and data races.

## What it includes
- main.c — entry point and setup
- inc/ — header files
- src/ — source files containing thread management, mutex handling, 
  simulation monitoring and philosopher lifecycle logic

## What I learned
How threads and mutexes work in C, how to prevent deadlocks and 
race conditions, and how to manage shared resources safely across 
multiple concurrent processes.

## Usage
```bash
make
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
The last argument is optional. Example:
```bash
./philo 5 800 200 200
```
5 philosophers, die if not eaten within 800ms, eat for 200ms, sleep for 200ms.

## Personal note
One of the most challenging projects in the curriculum — debugging 
concurrency issues is a completely different kind of problem to 
anything else. You can't always reproduce the bug, which makes 
it frustrating.
