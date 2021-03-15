#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<bits/stdc++.h>
#define N 10
using namespace std;
void PrintOperationsList();

void FindDeterminant();
void GetCofactor(int mat[N][N], int temp[N][N], int p, int q, int n);
int DeterminantOfMatrix(int mat[N][N], int n);

void AddMatrices();

void SubtractMatrices();

void MultiplyTwoMatices();
void Multiply(int r1,int c1,int mat1[][N],int r2,int c2,int mat2[][N]);

void PowerOfMatrix();
void Power(int n,int n1,int mat1[][N],int mat2[][N]);

void  AdjointOfMatrix();
void Adjoint(int mat1[N][N],int mat2[N][N],int n,int flag=0);

void InverseOfMatrix();

void LUDecompositionOfMatrix();
void LUDecomposition(int mat[][N], int n);

int main()
{
    int n;
    system("CLS");/*To clear console*/
    PrintOperationsList();/*Prints List of Operations that we can  perform*/
    cout<<"Enter the number corresponding to the function you want to perform: ";
    cin>>n;/*To select an operation to perform*/

    switch(n)/*To perform the selected operation*/
    {
    case 1: FindDeterminant();/*Finds the Determinant*/
        break;
    case 2: AddMatrices();/*Adds Matrices*/
        break;
    case 3: SubtractMatrices();/*Subtracts Matrices*/
        break;
    case 4: MultiplyTwoMatices();/*Multiplies two Matrices*/
        break;
    case 5: PowerOfMatrix();/*Finds Powers of Matrix*/
        break;
    case 6: AdjointOfMatrix();/*Finds Adjoint of Matrix*/
        break;
    case 7: InverseOfMatrix();/*Finds Inverse of Matrix*/
        break;
    case 8: LUDecompositionOfMatrix();/*Finds LU-Decomposition of Matrix*/
        break;
    case 0:
        exit(0);
    }

    return 0;
}

void PrintOperationsList()/*Definition of the Function to print list of operations*/
{
   cout<<"*HERE IS A LIST OF OPERATIONS YOU CAN PERFORM*\n\n";
   cout<<"1. DETERMINANT OF A MATRIX\n";
   cout<<"2. ADDITION OF  MATRICES\n";
   cout<<"3. SUBTRACTION OF  MATRICES\n";
   cout<<"4. MULTIPLICATION OF TWO MATRICES\n";
   cout<<"5. POWERS OF A MATRIX\n";
   cout<<"6. ADJOINT OF A MATRIX\n";
   cout<<"7. INVERSE OF A MATRIX\n";
   cout<<"8. LU DECOMPOSITION OF A MATRIX\n";
   cout<<"0. EXIT\n\n";
}

void FindDeterminant()/*Definition of function to find determinant*/
{
    int n=0,row=0,col=0,mat[N][N]={0},i=0,j=0,flag=0;
    system("CLS");
    cout<<"Enter size of square matrix: ";
    cin>>n;/*Takes size of square matrix*/
    system("CLS");

    for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
    {
        for(j=0;j<n;j++)
        {
            cout<<"Input Time!!!\n\n";
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                {
                    cout<<"\t"<<mat[row][col]<<setw(4);
                }
                cout<<"\n";
            }
            cout<<"\nEnter the value of element M"<<i+1<<j+1<<": ";
            cin>>mat[i][j];
            system("CLS");
        }

    }

    cout<<"Matrix You Entered is: \n\n";
    for(row=0;row<n;row++)/*This loops will display the entered matrix*/
    {
        for(col=0;col<n;col++)
        {
            cout<<"\t"<<mat[row][col]<<setw(4);
        }
        cout<<"\n";
    }
    cout<<"\n The value of Determinant= "<<DeterminantOfMatrix(mat,n);
    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
        FindDeterminant();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void GetCofactor(int mat[N][N], int temp[N][N], int p, int q, int n)/*Function to get cofactor of mat[p][q] in temp[][]*/
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int DeterminantOfMatrix(int mat[N][N], int n)/* Recursive function for finding determinant of matrix.n is current dimension of mat[][]. */
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];

    int temp[N][N]; // To store cofactors

    int sign = 1;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        GetCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * DeterminantOfMatrix(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

void AddMatrices()/*Definition of function to add matrices*/
{
    int number=0,n=0,m=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,k=0,flag=0;
    static int x;
    system("CLS");
    cout<<"How many Matrix you want to add: "; cin>>number;/*Takes number of matrix you want to add*/
    cout<<"Enter size of matrix:\n";
    cout<<"\tEnter number rows that you want: "; cin>>n;/*Takes size of row of matrix*/
    cout<<"\tEnter number columns that you want: "; cin>>m;/*Takes size of column of matrix*/
    system("CLS");

    for(k=0,x=0;k<number;k++,x++)
    {
        for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
        {
            for(j=0;j<m;j++)
            {
                cout<<"Input Time!!!\n\n";
                for(row=0;row<n;row++)
                {
                    for(col=0;col<m;col++)
                    {
                        cout<<"\t"<<mat1[row][col]<<setw(4);
                    }
                    cout<<"\n";
                }
                cout<<"\nEnter the value of Matrix"<<x+1<<" element M"<<i+1<<j+1<<": ";
                cin>>mat1[i][j];
                mat2[i][j]+=mat1[i][j];/*Add each element of the matrix to the  other*/
                system("CLS");
            }
        }
        for(row=0;row<n;row++)/*To  re-initialize the mat1 to zero*/
        {
            for(col=0;col<m;col++)
            {
                mat1[row][col]=0;
            }
        }
    }

    cout<<"Final  Answer: \n\n";
    for(row=0;row<n;row++)/*This loops will display the final matrix after addition*/
    {
        for(col=0;col<m;col++)
        {
            cout<<"\t"<<mat2[row][col]<<setw(4);
        }
        cout<<"\n";
    }

    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
        AddMatrices();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void SubtractMatrices()/*Definition of function to subtract matrices*/
{
    int number=0,n=0,m=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,k=0,flag=0;
    static int x;
    system("CLS");
    cout<<"How many Matrix you want to subtract: "; cin>>number;/*Takes number of matrix you want to add*/
    cout<<"Enter size of matrix:\n";
    cout<<"\tEnter number rows that you want: "; cin>>n;/*Takes size of row of matrix*/
    cout<<"\tEnter number columns that you want: "; cin>>m;/*Takes size of column of matrix*/
    system("CLS");

    for(k=0,x=0;k<number;k++,x++)
    {
        for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
        {
            for(j=0;j<m;j++)
            {
                cout<<"Input Time!!!\n\n";
                for(row=0;row<n;row++)
                {
                    for(col=0;col<m;col++)
                    {
                        cout<<"\t"<<mat1[row][col]<<setw(4);
                    }
                    cout<<"\n";
                }
                cout<<"\nEnter the value of Matrix"<<x+1<<" element M"<<i+1<<j+1<<": ";
                cin>>mat1[i][j];
                if(x==0){mat2[i][j]=mat1[i][j];}/*Storing the values in other matrix for further operations*/
                else{mat2[i][j]-=mat1[i][j];}/*Subtracting each element from the first*/
                system("CLS");
            }
        }
        for(row=0;row<n;row++)/*To  re-initialize the mat1 to zero*/
        {
            for(col=0;col<m;col++)
            {
                mat1[row][col]=0;
            }
        }
    }

    cout<<"Final  Answer: \n\n";
    for(row=0;row<n;row++)/*This loops will display the final matrix after addition*/
    {
        for(col=0;col<m;col++)
        {
            cout<<"\t"<<mat2[row][col]<<setw(4);
        }
        cout<<"\n";
    }

    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
        SubtractMatrices();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }

}

void MultiplyTwoMatices()/*Definition of  function to multiply two matrices*/
{
    int r1=0,c1=0,r2=0,c2=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,k=0,flag=0;
    system("CLS");
    cout<<"Enter size of matrix1:\n";
    cout<<"\tEnter number rows that you want: "; cin>>r1;/*Takes size of row of matrix1*/
    cout<<"\tEnter number columns that you want: "; cin>>c1;/*Takes size of column of matrix1*/
    cout<<"\nEnter size of matrix1:\n";
    cout<<"\tEnter number rows that you want: "; cin>>r2;/*Takes size of row of matrix2*/
    cout<<"\tEnter number columns that you want: "; cin>>c2;/*Takes size of column of matrix2*/
    if(c1!=r2)
    {
        cout<<"MATHEMATICALLY NOT DEFINED";
        cout<<"\n Press 1: To restart the operation.";
        cout<<"\n Press 2: To perform any other operation.";
        cout<<"\n Press 0: Exit.\n";
        cin>>flag;
        if(flag==1)/*Restarts the function*/
        {
            MultiplyTwoMatices();
        }
        else if(flag==2)/*Restarts main Function*/
        {
            main();
        }
        else/*Exit*/
        {
            exit(0);
        }
    }
    system("CLS");

        for(i=0;i<r1;i++)/*This collection loops will take the input of all values of the matrix1*/
        {
            for(j=0;j<c1;j++)
            {
                cout<<"Input Time!!!\n\n";
                for(row=0;row<r1;row++)
                {
                    for(col=0;col<c1;col++)
                    {
                        cout<<"\t"<<mat1[row][col]<<setw(4);
                    }
                    cout<<"\n";
                }
                cout<<"\nEnter the value of Matrix1 element M"<<i+1<<j+1<<": ";
                cin>>mat1[i][j];
                system("CLS");
            }
        }

        for(i=0;i<r2;i++)/*This collection loops will take the input of all values of the matrix2*/
        {
            for(j=0;j<c2;j++)
            {
                cout<<"Input Time!!!\n\n";
                for(row=0;row<r2;row++)
                {
                    for(col=0;col<c2;col++)
                    {
                        cout<<"\t"<<mat2[row][col]<<setw(4);
                    }
                    cout<<"\n";
                }
                cout<<"\nEnter the value of Matrix2 element M"<<i+1<<j+1<<": ";
                cin>>mat2[i][j];
                system("CLS");
            }
        }
        Multiply(r1,c1,mat1,r2,c2,mat2);

        cout<<"\n Press 1: To perform the same operation.";
        cout<<"\n Press 2: To perform any other operation.";
        cout<<"\n Press 0: Exit.\n";
        cin>>flag;
        if(flag==1)/*Restarts the Same function*/
        {
            MultiplyTwoMatices();
        }
        else if(flag==2)/*Restarts main Function*/
        {
            main();
        }
        else/*Exit*/
        {
            exit(0);
        }
}

void Multiply(int r1,int c1,int mat1[][N],int r2,int c2,int mat2[][N])/*Take the matrices and multiply them*/
{
	int x, i, j;
	int res[r1][c2];/*Result will be stored in it*/
	for(i=0;i<r1;i++)/*Multiplication of the matrices*/
	{
		for(j=0;j<c2;j++)
		{
			res[i][j]=0;
			for(x=0;x<c2;x++)
			{
				res[i][j] += mat1[i][x]*mat2[x][j];
			}
		}
	}

	cout<<"Final  Answer: \n\n";
	for(i=0;i<r1;i++)/*Prints final answer*/
	{
		for(j=0;j<c2;j++)
		{
			cout<<"\t"<<res[i][j]<<setw(4);
		}
		cout << "\n";
	}
}

void PowerOfMatrix()/*Definition of function to find powers of matrix*/
{
    int n=0,n1=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,flag=0;
    system("CLS");
    cout<<"Enter size of square matrix: ";
    cin>>n;/*Takes size of square matrix*/
    cout<<"Enter the positive integral power of the matrix that you want find: ";
    cin>>n1;/*Takes the value of power*/
    system("CLS");
    if(n1<0)
    {
        cout<<"I said positive.\n";
        cout<<"\n Press 1: To restart the operation.";
        cout<<"\n Press 2: To perform any other operation.";
        cout<<"\n Press 0: Exit.\n";
        cin>>flag;
        if(flag==1)/*Restarts the function*/
        {
           PowerOfMatrix();
        }
        else if(flag==2)/*Restarts main Function*/
        {
            main();
        }
        else/*Exit*/
        {
            exit(0);
        }
    }

    for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
    {
        for(j=0;j<n;j++)
        {
            cout<<"Input Time!!!\n\n";
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                {
                    cout<<"\t"<<mat1[row][col]<<setw(4);
                }
                cout<<"\n";
            }
            cout<<"\nEnter the value of element M"<<i+1<<j+1<<": ";
            cin>>mat1[i][j];
            mat2[i][j]=mat1[i][j];/*Making a copy of original Matrix*/
            system("CLS");
        }
    }
    if(n1==0)
    {
        cout<<"Final Answer:\n";
        for(row=0;row<n;row++)/*This loops will display the answer. Here answer is identity matrix as the power is zero*/
        {
            for(col=0;col<n;col++)
            {
                if(row==col)
                {
                    cout<<"\t1"<<setw(4);
                }
                else
                {
                    cout<<"\t0"<<setw(4);
                }
            }
            cout<<"\n";
        }
    }

    else if(n1==1)
    {
        cout<<"Final Answer:\n";
        for(row=0;row<n;row++)/*This loops will display the  matrix itself as power is one*/
        {
            for(col=0;col<n;col++)
            {
                cout<<"\t"<<mat1[row][col]<<setw(4);
             }
            cout<<"\n";
        }
    }

    else
    {
        Power(n,n1-1,mat1,mat2);/*Finding Powers of the Matrix*/
    }

    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
        PowerOfMatrix();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void Power(int n,int n1,int mat1[][N],int mat2[][N])/*Function to calculate the power of the Matrix*/
{
	int x=0,i=0,j=0,k=0;
	int res[n][n]={0};/*Result will be stored in it*/
	for(k=0;k<n1;k++)
	{
        for(i=0;i<n;i++)/*Power of the matrices*/
        {
            for(j=0;j<n;j++)
            {
                res[i][j]=0;
                for(x=0;x<n;x++)
                {
                    res[i][j] += mat1[i][x]*mat2[x][j];
                }
            }
        }
        for(i=0;i<n;i++)/*Will copy the resultant matrix into matrix 1 for further calculation*/
        {
            for(j=0;j<n;j++)
            {
               mat1[i][j]=res[i][j];
            }
        }
	}

	cout<<"Final  Answer: \n\n";
	for(i=0;i<n;i++)/*Prints final answer*/
	{
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<res[i][j]<<setw(4);
		}
		cout << "\n";
	}
}

void AdjointOfMatrix()/*Definition of function to find adjoint of the Matrix*/
{
    int n=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,flag=0;
    system("CLS");
    cout<<"Enter size of square matrix: ";
    cin>>n;/*Takes size of square matrix*/
    system("CLS");

    for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
    {
        for(j=0;j<n;j++)
        {
            cout<<"Input Time!!!\n\n";
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                {
                    cout<<"\t"<<mat1[row][col]<<setw(4);
                }
                cout<<"\n";
            }
            cout<<"\nEnter the value of element M"<<i+1<<j+1<<": ";
            cin>>mat1[i][j];
            system("CLS");
        }

    }

    cout<<"Matrix You Entered is: \n\n";
    for(row=0;row<n;row++)/*This loops will display the entered matrix*/
    {
        for(col=0;col<n;col++)
        {
            cout<<"\t"<<mat1[row][col]<<setw(4);
        }
        cout<<"\n";
    }

    Adjoint(mat1,mat2,n);

    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
       AdjointOfMatrix();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void Adjoint(int mat1[N][N],int mat2[N][N],int n,int flag)/*Function to get Adjoint of the Matrix.*/
{
    if (n == 1)
    {
        mat2[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of mat1[][]
    int sign = 1, temp[N][N];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            // Get cofactor of A[i][j]
            GetCofactor(mat1, temp, i, j, n);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            mat2[j][i] = (sign)*(DeterminantOfMatrix(temp, n-1));
        }
    }

    if(flag==0)
    {
        cout<<"\n\nAdjoint of the Matrix is: \n\n";
        for(int row=0;row<n;row++)/*This loops will display the entered matrix*/
        {
            for(int col=0;col<n;col++)
            {
                cout<<"\t"<<mat2[row][col]<<setw(4);
            }
            cout<<"\n";
        }
    }
}

void InverseOfMatrix()/*Definition of Function to find Inverse of a Matrix*/
{
    int n=0,row=0,col=0,mat1[N][N]={0},mat2[N][N]={0},i=0,j=0,flag=0,det=0;
    float inv[N][N]={0};
    system("CLS");
    cout<<"Enter size of square matrix: ";
    cin>>n;/*Takes size of square matrix*/
    system("CLS");

    for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
    {
        for(j=0;j<n;j++)
        {
            cout<<"Input Time!!!\n\n";
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                {
                    cout<<"\t"<<mat1[row][col]<<setw(4);
                }
                cout<<"\n";
            }
            cout<<"\nEnter the value of element M"<<i+1<<j+1<<": ";
            cin>>mat1[i][j];
            system("CLS");
        }
    }

    det=DeterminantOfMatrix(mat1,n);
    if(det==0)
    {
        cout<<"\nSingular matrix, can't find its inverse";
        cout<<"\n Press 1: To restart the operation.";
        cout<<"\n Press 2: To perform any other operation.";
        cout<<"\n Press 0: Exit.\n";
        cin>>flag;
        if(flag==1)/*Restarts the function*/
        {
            InverseOfMatrix();
        }
        else if(flag==2)/*Restarts main Function*/
        {
            main();
        }
        else/*Exit*/
        {
            exit(0);
        }
    }

    cout<<"Matrix You Entered is: \n\n";
    for(row=0;row<n;row++)/*This loops will display the entered matrix*/
    {
        for(col=0;col<n;col++)
        {
            cout<<"\t"<<mat1[row][col]<<setw(4);
        }
        cout<<"\n";
    }

    Adjoint(mat1,mat2,n,1);

    cout<<"Inverse of the Matrix: \n\n";
    for(row=0;row<n;row++)/*This loops will display the answer*/
    {
        for(col=0;col<n;col++)
        {
            inv[row][col]=mat2[row][col]/float(det);
            cout<<"\t"<<inv[row][col]<<setw(4);
        }
        cout<<"\n";
    }


    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
       InverseOfMatrix();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void LUDecompositionOfMatrix()/*Definition Of Function to find LU-Decomposition of Matrix*/
{
    int n=0,row=0,col=0,mat[N][N]={0},i=0,j=0,flag=0,det=0;
    system("CLS");
    cout<<"Enter size of square matrix: ";
    cin>>n;/*Takes size of square matrix*/
    system("CLS");

    for(i=0;i<n;i++)/*This collection loops will take the input of all values of the matrix*/
    {
        for(j=0;j<n;j++)
        {
            cout<<"Input Time!!!\n\n";
            for(row=0;row<n;row++)
            {
                for(col=0;col<n;col++)
                {
                    cout<<"\t"<<mat[row][col]<<setw(4);
                }
                cout<<"\n";
            }
            cout<<"\nEnter the value of element M"<<i+1<<j+1<<": ";
            cin>>mat[i][j];
            system("CLS");
        }

    }

    det=DeterminantOfMatrix(mat,n);
    if(det==0)
    {
        cout<<"\n Determinant of the Matrix is zero. LU-Decomposition not possible.";
        cout<<"\n Press 1: To restart the operation.";
        cout<<"\n Press 2: To perform any other operation.";
        cout<<"\n Press 0: Exit.\n";
        cin>>flag;
        if(flag==1)/*Restarts the function*/
        {
            LUDecompositionOfMatrix();
        }
        else if(flag==2)/*Restarts main Function*/
        {
            main();
        }
        else/*Exit*/
        {
            exit(0);
        }
    }

    cout<<"Matrix You Entered is: \n\n";
    for(row=0;row<n;row++)/*This loops will display the entered matrix*/
    {
        for(col=0;col<n;col++)
        {
            cout<<"\t"<<mat[row][col]<<setw(4);
        }
        cout<<"\n";
    }

    cout<<"\n\n";
    LUDecomposition(mat,n);
    cout<<"\n Press 1: To perform the same operation.";
    cout<<"\n Press 2: To perform any other operation.";
    cout<<"\n Press 0: Exit.\n";
    cin>>flag;
    if(flag==1)/*Restarts the Same function*/
    {
        LUDecompositionOfMatrix();
    }
    else if(flag==2)/*Restarts main Function*/
    {
        main();
    }
    else/*Exit*/
    {
        exit(0);
    }
}

void LUDecomposition(int mat[][N], int n)/*Decomposes Matrix into Lower  and  Upper Triangular form.*/
{
    float lower[n][n], upper[n][n];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    for (int i = 0; i < n; i++) /*This loops will decompose matrix into upper and lower triangular Matrix*/
    {
        for (int k = i; k < n; k++)/*Upper  Triangular*/
        {
            int sum = 0;/*Summation of L(i, j) * U(j, k)*/
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
            upper[i][k] = mat[i][k] - sum;/* Evaluating U(i, k)*/
        }

        for (int k = i; k < n; k++)/* Lower Triangular*/
        {
            if (i == k)
                lower[i][i] = 1; /*Diagonal as 1*/
            else
            {
                int sum = 0; /*Summation of L(k, j) * U(j, i)*/
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];/*Evaluating L(k, i)*/
            }
        }
    }

    cout << setw(6) << "\tLower Triangular"
         << setw(24) << "\t\tUpper Triangular" << endl;

    // Displaying the result :
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)/*Lower*/
        {
              cout << setw(6) << lower[i][j] << "\t";
        }
        cout << "\t";

        for (int j = 0; j < n; j++)/*Upper*/
        {
            cout << setw(6) << upper[i][j] << "\t";
        }
        cout << endl;
    }
}

