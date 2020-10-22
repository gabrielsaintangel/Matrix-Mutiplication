class Matrix{
    public:
        //default constructor, blank matrix
        Matrix();
        void toString();
        Matrix operator * (const Matrix &m2);
        bool operator == (const Matrix& m2);
        void clearMatrix();

    private:
        long long int matrix[3][3];
};