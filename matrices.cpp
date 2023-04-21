#include <iostream>
#include <fstream>
#define MAXROWS 10
#define MAXCOLS 10

using namespace std;


class Matrix
{
    private:
        int rows,cols;
        float data[MAXROWS][MAXCOLS];
        bool test_stochastic(void)
        {
            if(rows != cols)
            {
                return false;
            }
            else
            {
                float test[rows] = {0};
                for(int i = 0; i<rows; i++)
                {
                    for(int k = 0; k<cols; k++)
                    {
                        test[i] += data[i][k]; 
                    }
                }
                int size = sizeof(test)/sizeof(test[0]);
                for(int j = 0; j<size;j++)
                {
                    if(test[j] != 1) {return false;}; 
                }
                return true;
            }
        };
    public:
        Matrix()
        {
            this-> rows = 0;
            this-> cols = 0;
        };

        Matrix(float neWdata[MAXROWS][MAXROWS], int neWrows, int neWcols) // bence burayı double pointerla yapmamız gerkeiyor ama neyse
        {
            rows = neWrows;
            cols = neWcols;
            
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    data[i][k] = neWdata[i][k];
                }
            }
        };

        void print(void) 
        {
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    cout<< data[i][k] << " ";
                }
                cout<<endl;
            }
            test_stochastic();
        };

        Matrix operator+(const Matrix& rightMatrix)
        {
            int neWrows = rows;
            int neWcols = cols;
            float neWdata[MAXROWS][MAXCOLS];
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    neWdata[i][k] = data[i][k] + rightMatrix.data[i][k];
                }
            }
            return Matrix(neWdata,neWrows,neWcols);
        };

        Matrix operator+(float scalar_value)
        {
            int neWrows = rows;
            int neWcols = cols;
            float neWdata[MAXROWS][MAXCOLS];
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    neWdata[i][k] = data[i][k] + scalar_value;
                }
            }
            return Matrix(neWdata,neWrows,neWcols);
        };

        void operator++(void)
        {
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    data[i][k]=data[i][k]+1;
                }
            }
        }; 

        void operator+=(const Matrix &)
        {
            for(int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    data[i][k] += data[i][k];
                }
            }
        };
};

int main()
{

    Matrix Mat[20]; // Declare an array of Matrix objects (named Mat). (Maximum array size 20) //
    ifstream infile("matrices.txt");
    int i = 0;
    while (infile) {
        int rows, cols;
        infile >> rows >> cols;
        float data[MAXROWS][MAXCOLS];
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                infile >> data[j][k];
            }
        }
        Mat[i] = Matrix(data, rows, cols);
        i++;
        if (i >= 20) {
            break;
        }
    }
    infile.close();

    Matrix Result1,Result2;

    Result1 = Mat[0] + Mat[2];
    Result1.print();

    Result2 = Mat[4] + 70;
    Result2.print();

    ++Mat[2];
    
    Mat[3] += Mat[1];

    for (int l = 0; l < i; l++)
    {
        Mat[l].print();
    }
    

    return 0;
}