#include "Matrices.h" //Capitalization may cause error maybe?
namespace Matrices
//Very important, probably why I will get errors
{
Matrices::Matrix::Matrix(int _rows, int _cols) //Matrix has :: as the scope operator
{
    rows = _rows;
    cols = _cols;
    a.resize(rows); // resize the row, vector of vector, so outside vector is rows
    for (size_t i = 0; i < rows; i++)
    {
        a.at(i).resize(cols, 0); //Resize the vector columns and initializes values to 0
    }
}

///Add each corresponding element.
///usage:  c = a + b;
Matrices::Matrix operator+(const Matrices::Matrix& a, const Matrices::Matrix& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        throw runtime_error("Error: dimensions must agree");
    } // Dimensions Match, continue
    Matrix c(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            c(i,j) = a(i,j) + b(i,j);
        }
    }
    return c;
}

///Matrix multiply.  See description.
///usage:  c = a * b;
Matrices::Matrix operator*(const Matrices::Matrix& a, const Matrices::Matrix& b)
{
    if (a.getCols() != b.getRows())
    {
        throw runtime_error("Error: dimensions must agree");
    } // Dimensions Match, continue
    
    Matrix c(a.getRows(), b.getCols());
    double sum = 0;
    
    for (int k = 0; k < b.getCols(); k++)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            sum = 0;
            for (int j = 0; j < a.getCols(); j++)
            {
                sum = sum + a(i,j) * b(j,k);
            }
            c(i,k) = sum;
        }
    }
    
    return c;
}

///Matrix comparison.  See description.
///usage:  a == b
bool operator==(const Matrices::Matrix& a, const Matrices::Matrix& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        return false; // Dimensions must match
    }

    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            if (std::abs(a(i, j) - b(i, j)) >= 0.001)
            {
                return false; // At least one pair of elements not equal within tolerance
            }
        }
    }

    return true; // All elements are equal within tolerance
}

///Matrix comparison.  See description.
///usage:  a != b
bool operator!=(const Matrices::Matrix& a, const Matrices::Matrix& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        return true; // Dimensions must match
    }

    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            if (std::abs(a(i, j) - b(i, j)) >= 0.001)
            {
                return true; // At least one pair of elements not equal within tolerance
            }
        }
    }

    return false; // All elements are equal within tolerance
}

///Output matrix.
///Separate columns by ' ' and rows by '\n'
ostream& operator<<(ostream& os, const Matrices::Matrix& a)
{
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            os << setw(10) << a(i,j) << " ";
        }
        os << endl; //end of row
    }
    return os;
}

}
