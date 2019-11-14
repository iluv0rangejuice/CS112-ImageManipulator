#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int **allocateImage(int numRows, int numCols);
void saveImage(string filename, int **image, int numRows, int numCols);
int **readImage(string file, int& numRows, int& numCols);
void deallocateImage(int **image, int numRows, int numCols);
int **flipImage_vertical(int **image, int numRows, int numCols);
int **flipImage_horizontal(int **image, int numRows, int numCols);


int main(int argc, char *argv[])
{	
    //Variables
    int **image, **newImage, numRows, numCols, numRowsOut, numColsOut, i;

    //Read image in, allocate memory
    image = readImage(, numRows, numCols);
    if (!image)
    {
        // Image file was not found.
        return 1; 
    }
    i=3;

    // Handles multiple arguments
    while (i < argc)
    {
        // Flip
        if (strcmp(argv[i], "-flip") == 0)
        {
            //Flips the image
            image = flipImage_vertical(image, numRows, numCols);
            i+=1;
        }
        // Flop
        else if (strcmp(argv[i], "-flop") == 0)
        {
            //Flops the image
            image = flipImage_horizontal(image, numRows, numCols);
            i+=1;
        }
    }
    // Save image
    saveImage(argv[2], image, numRows, numCols);

    //Deallocate memory
    deallocateImage(image, numRows, numCols);

    //system("pause");
    cout << "Program ran without any issues." << endl;
    return 0;
}
// Allocates room in memory for array
int **allocateImage(int numRows, int numCols)
{
    int **result;
    result = new int*[numRows];
    for (int i = 0; i < numRows; i++)
        result[i] = new int[3 * numCols];
	return result;
    
}
// Saves the image file
void saveImage(string filename, int **image, int numRows, int numCols)
{
    ofstream outFile(filename);
    cout << "File " << filename << " successfully opened" << endl;
    outFile << "P3" << endl;
    outFile << numCols << " " << numRows << endl;
    outFile << "255" << endl;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            outFile << image[i][3 * j] << " " << image[i][3 * j + 1] 
                    << " " << image[i][3 * j + 2] << " ";
        }
    }
    outFile.close();
    cout << filename << " has been successfully closed" << endl;
    cout << "Saved " << filename << " to disk" << endl;
}
// Reads the image file
int **readImage(string filename, int& numRows, int& numCols)
{
    string fileType;
    int twoFiveFive, **image;
    ifstream inputFile(filename);

    if(!inputFile)
    {
        cout << "File not found." << endl;
        return 0;
    }

    inputFile >> fileType; // File name
    cout << "File " << filename << " successfully opened" << endl;
    inputFile >> numCols; // Number of columns
    inputFile >> numRows; // Number of rows
    inputFile >> twoFiveFive; // 255

    // Allocate memory for array
    image = allocateImage(numRows, numCols);

    // Fill array
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            inputFile >> image[i][3 * j];
            inputFile >> image[i][3 * j + 1];
            inputFile >> image[i][3 * j + 2];
        }
    }
    //Close file
    inputFile.close();
    cout << "File " << filename << " has been successfully closed" << endl;

return image;
}

// Deallocates memory
void deallocateImage(int **image, int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] image[i];
        delete[] image;
	cout << "Memory has been deleted" << endl;
	image = 0; 
    }
}

// This flips image
int **flipImage_vertical(int **image, int numRows, int numCols)
{
    // Allocate new array size of original
    int **tempArray = allocateImage(numRows, numCols); 
    int rows = numRows - 1;
    for(int i=0; i < numRows; i++)
    {
        for(int j=0; j < numCols; j++)
        {
            //Subtract i from amount of rows to flip image
            tempArray[i][3 * j] = image[rows-i][3 * j]; 
            tempArray[i][3 * j + 1] = image[rows-i][3 * j + 1];
            tempArray[i][3 * j + 2] = image[rows-i][3 * j + 2];
        }
    }
    cout << "Image flipped" << endl;
return tempArray;
}
//This flops image
int **flipImage_horizontal(int **image, int numRows, int numCols)
{
    int **tempArray = allocateImage(numRows, numCols);
    int cols = ((numCols*3)-1);
        for(int i=0; i < numRows; i++)
        {
            for(int j=0; j < numCols; j++)
            {
                //Subtract color value starting backwards from total number of columns to flop
                tempArray[i][3 * j] = image[i][(cols-(j*3+2))]; 
                tempArray[i][3 * j + 1] = image[i][(cols-(j*3+1))];
                tempArray[i][3 * j + 2] = image[i][(cols-(j*3))];
            }
        }
    cout << "Image has been flopped" << endl;
return tempArray;
}

