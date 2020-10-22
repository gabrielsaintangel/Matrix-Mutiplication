#include "Matrix.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//default constructor, blank matrix of 0s
Matrix::Matrix()
{
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
           matrix[i][j] = rand() % 25;
        }
    }
}
//overlaoded constructor, generates random with upper bound of matrixRange


//toString method for the matrix
void Matrix::toString(){
    for(int i = 0; i < 3; i++){
        cout << "[" << matrix[i][0] << "] " << "[" << matrix[i][1] << "] " << "[" << matrix[i][2] << "]\n";
    }
    cout << "\n\n";
}

void Matrix::clearMatrix(){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
    }
}

//overloaded *
Matrix Matrix::operator* (const Matrix &m2)
{
    //delcare return instance of Matrix
    Matrix m1;
    m1.clearMatrix();

    //matrix mutiplication
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            for (int u = 0; u < 3; u++)
                m1.matrix[i][j] += (this->matrix[i][u] * m2.matrix[u][j]);
    }
    return m1;
}

//overloaded ==
bool Matrix::operator== (const Matrix &m2){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if(matrix[i][j] != m2.matrix[i][j]){
                return false;
            } 
        }
    return true;
}