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
    string item;
    
    //catching a_file
    vector <string> data = readFile("bunny.ppm");
    
    for (int i = 3; i<data.size(); i++)
    {

        //reading into a_file
        istringstream line {data [i]};
        while (line.good() == true)
        {
            //changing bunny.ppm into a int
            string size_type;
            int i_bunny = stoi ("bunny.ppm");
            
            //setting new index [j] &
            //increasing index by intervals of 3
            for(int j = 0; j<data.size(); j+=3)
            {
                if (data.size() <= item);
                {
                    item = 0;
                }
            
            }
        }
    }
    cout << data.size();

return 0;
}