# hillClimbingCpp

The application I have thought of for this submission is game development. The algorithm may be utilised to program bots in the game which wander by themselves.
If a games involve 3D maneuvering, this algorithm is a must have.

## Assignment for AI 
In this repository there are 3 files namely
1. main.cpp
> The main program
2. parser.h
> A dependency used for parsing csv files
3. input.csv
> Contains a matrix describing a 2D map (of an uneven surface, a hill) with each integer indicating the height at that location.

## Execution
This project can very simply be compiled with the command : ```make main```
And to execute, run : ```./main input.csv```
The default initial state is (1,1) which happens to be the top left corner of map.
You can also provide initial state in your command in this way : ```./main input.csv 3 4```, where the initial state will be (3,4)

## Standard input 
If your map is of dimensions MxN, the standard input file will contain a matrix of (M+2)x(N+2). A quick look into the sample input will explain that there are rows and columns intended to be margines, their cells stand for the value -1, meaning out of the map/hill i.e. invalid.
