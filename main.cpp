#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> // replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
#include "HelperFunctions.h"
#include "FileHelpers.h"
#include "PpmDocument.hpp"
using namespace std;



int main(int argc, char* argv[])
{ 
    int item (127);
    //catching a_file
    vector <string> data = readFile("bunny.ppm");
    for (int i = 3; i<data.size(); i++)
    {
        //reading into a_file
        istringstream line {data [i]};
        while (line.good() == true)
        {
            //changing bunny.ppm into an int
            int int_bunny = stoi ("bunny.ppm");
            
            //setting new index [j] & changing int
            for(int j = 0; j<data.size(); j++)
            {
                //if x > 255 -> 255 || if x < 255 -> 0
                if (data.size() > 127)
                {
                    item = 255;
                }
                else if (data.size() < 127)
                {
                    item = 0;
                }
                                
            }
            string to_string("bunny.ppm");
        }
    cout << "bunny.ppm" << endl;
    }
return 0;
}