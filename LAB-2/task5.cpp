#include <iostream>
using namespace std;

int main() 
{
	int** A = new int*[3];
	 for(int i=0;i<3;i++)
	 {
	 	A[i]= new int[3];
	 }
	
	int** B = new int*[3];
	 for(int i=0;i<3;i++)
	 {
	 	B[i]= new int[3];
	 }
	 
	 		 
	cout<<"enter elements for the matrix A: \n";
	 for(int i=0;i<3;i++)
	 {
	 	cout<<"for row "<<i+1<<endl;
	 	for(int j=0;j<3;j++)
	 	{
	 		cin>>A[i][j];
		}
	 }
	 
	cout<<"enter elements for the matrix B: \n";
	 for(int i=0;i<3;i++)
	 {
	 	cout<<"for row "<<i+1<<endl;
	 	for(int j=0;j<3;j++)
	 	{
	 		cin>>B[i][j];
		}
	 }
	 
	cout<<"addition of two matrices: \n";
	
	for(int i=0;i<3;i++)
	 {
	 	for(int j=0;j<3;j++)
	 	{
	 		cout<<A[i][j]+B[i][j]<<" ";
		}
		cout<<endl;
	 }
	 
	 	cout<<"\nsubtraction of two matrices: \n";
	 
	for(int i=0;i<3;i++)
	 {
	 	for(int j=0;j<3;j++)
	 	{
	 		cout<<A[i][j]-B[i][j]<<" ";
		}
		cout<<endl;
	 }
	 
	for(int i=0;i<3;i++)
	delete[] A[i];
	
	delete[] A;
	
	for(int i=0;i<3;i++)
	delete[] B[i];
	 
	delete[] B;	 
}
