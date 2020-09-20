#include <iostream>
#include <fstream>

#include "parser.hpp"

//#define MAX_N 10

#define rowCount 12
#define colCount 12

int graph[rowCount][colCount];

struct state
{
    int row;
    int col;
};

using namespace std;
using namespace aria::csv;  //from parser.hpp

bool setGraph(string filepath)
{    
    fstream inputFile(filepath, fstream::in);                           //Check for input file
    if(!inputFile.is_open())
    {
        cout << "\"" << filepath << "\" This file does not exist\n";
        return false;
    }

    CsvParser parser(inputFile);
    parser.delimiter(',');

    int i=0;
    for (auto& row : parser)                //Reads graph
    {
        for(int j=0; j < colCount; j++)
        {
            graph[i][j] = stoi(row[j]);
        }
        i++;
    }

    inputFile.close();
    return true;
}

void showGraph()
{
    cout << "\nThe Input Hill.\n";
    cout << "Every integer denotes the height at that point.\n";
    cout << "Indices begin from 1.\n";

    for(int i=0; i<rowCount; i++)
    {
        for(int j=0; j < colCount; j++)
            (graph[i][j] == -1) ? cout << " \t" : cout << graph[i][j] << '\t';

        cout << endl;
    }
}

state hillClimb(state current)
{
    bool goal = false;

    while(!goal)
    {
        state past = current;   //Saving for later comparison

        int k=0;
        for(int row = current.row-1; row <= current.row+1; row++)       //Checks all immediate neighbors
        {
            for(int col = current.col-1; col <= current.col+1; col++)   //8 neighbors in total excluding self
            {
                if(graph[row][col] > graph[current.row][current.col])   //If neighbor is a higher state
                {
                    current = {row, col};                               //Change state
                    cout << "\nJumped to : " << current.row << ", " << current.col << "\n";    //Show where we jumped
                    cout << "New height : " << graph[current.row][current.col];
                }
            }
            cout << (!++k%3 ? '\n' : ' ');
        }

        if(past.row == current.row && past.col == current.col){
            goal = true;    //Goal is reached if no neighbor was jumped at.
            break;
        }
    }

    return current;
}

int main(int argc, char *argv[])
{
    if(!setGraph(argv[1]))
        exit(0);

    showGraph();

    int x = 1;
    int y = 1;

    if(argc == 4)
    {
        x = stoi(argv[2]);
        y = stoi(argv[3]);
    }
    state initial = {x,y};
    state endState = hillClimb(initial);

    cout << endl << endl;
    cout << "End State = " << endState.row << "," << endState.col << endl;
    cout << "Local Maxima = " << graph[endState.row][endState.col] << endl;
}