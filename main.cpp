#include "Matrix.h"
#include <iostream>
#include <ctime>
using namespace std;
int main() {
    //seed rand() with the current time
    srand (time(0));
    int numMatrices;
    cout << "\nWelcome."<< "\nHow many random 3x3 matrices would you like to generate? ";
    cin >> numMatrices;
    cout << "Generating "<< numMatrices << " matrices with an upper bound of 100\n\n";
    Matrix *matrices = new Matrix[numMatrices];

    int selection;
    while(selection != 4){
        //display menu
        cout << "\n\n1. Print a list of all the Matrices\n" << "2. Perform some random matrix multiplication\n";
        cout << "3. Check to see if 2 matrices are equal\n" << "4. Exit\n";
        cout << "Make a selection(1-4): ";
        cin >> selection;
        switch(selection){
            case 1:
                {
                    for(int i = 0; i < numMatrices; i++){
                        cout<< "Matrix #" << i+1 << "\n";
                        matrices[i].toString();
                    }
                }
                break;
            case 2:
                {
                    int numToMutiply;
                    cout << "\nHow many random matrices do you want to perform mutiplication on?(Min is 2, Max is 10)\n";
                    cin >> numToMutiply;
                    //random indexes for the base calculation
                    int startingMatrix = rand() % numMatrices;
                    int secondMatrix = rand() % numMatrices;
                    cout << "\nMatrix #" << startingMatrix + 1 << "\n"; matrices[startingMatrix].toString();
                    cout << "Mutiplied By Matrix #" << secondMatrix + 1 << "\n"; matrices[secondMatrix].toString();
                    //store result as a new matrix
                    Matrix result = matrices[startingMatrix] * matrices[secondMatrix];
                    //print result
                    cout << "The result of the mutiplication is: \n"; result.toString();
                    //perform addition mutiplication
                    for(int i = 0; i < numToMutiply -1; i++){
                        cout << "-----------Calculation #" << i + 2<<"-----------";
                        int randomMatrix = rand() % numMatrices;
                        cout << "\nRandom matrix #" << randomMatrix << " will be used for the next operation.  This is the matrix\n";
                        matrices[randomMatrix].toString();
                        result = result * matrices[randomMatrix];
                        cout<<"The result after we perform mutiplication on the previous calculation\n";
                        result.toString();
                    }
                }
                break;
            case 3:
                {
                int matrix1, matrix2;
                cout << "Enter the number of the starting matrix to check if equal: \n";
                cin >> matrix1;
                cout << "Enter the number of the second matrix to check if equal: \n";
                cin >> matrix2;
                if(matrix1 == matrix2){
                    cout<< "They are equal!\n";
                }
                else{
                    cout << "They are not equal.\n";
                }
                }
                break;
            case 4:
                cout<<"\n\nExiting....";
                break;
            default:
                cout <<"\n Invalid Selection";
                break;
                
        }
    }
    return 0;
}
