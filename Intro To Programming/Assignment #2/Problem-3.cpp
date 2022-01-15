/*-----------------------------------
Name: Abhinaba Chakraborty
Roll number: cs2109
Date: 15.01.2022
Program description: Write a C++ program for developing matrix class which can handle integer matrices of different
dimensions. Now overload the operator +, -, and ==, such that if M1 and M2 are the objects of the
class matrix, then M1+M2, M1-M2, M1==M2 behaves as addition, multiplication, and comparison of
the two matrices. 
------------------------------------*/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
class matrix{
private:
	vector<vi> M;
	bool indexBound(int i,int j,int R,int C){
		return i<0 or i>=R or j<0 or j>=C;
	}
	bool equalSize(int R,int C){
		return R==(int)M.size() and C==(int)M[0].size();
	}
	void ERROR_MSG(string s=""){
		cout<<"Error: Size is not compatible "<<s<<endl;
	}
public:
	matrix()=delete;
	matrix(int rows,int cols){
		M.resize(rows);
		for(int i=0;i<rows;++i){
			M[i].resize(cols);
		}
	}
	void setElemenet(int i,int j,int value){
		if(indexBound(i,j,M.size(),M[0].size())){
			printf("Matrix index of bound");
			exit(0);
		}else{
			M[i][j]=value;
		}
	}
	void printMatrix(){
		for(int i=0;i<(int)M.size();++i){
			for(int j=0;j<(int)M[i].size();++j){
				printf("%d ",M[i][j]);
			}printf("\n");
		}
	}
	matrix operator +(matrix X){
		if(equalSize(X.M.size(),X.M[0].size())){
			matrix R(X.M.size(),X.M[0].size());
			for(int i=0;i<(int)X.M.size();++i){
				for(int j=0;j<(int)X.M[0].size();++j){
					R.M[i][j]=this->M[i][j]+X.M[i][j];
				}
			}
			return R;
		}else{
			matrix R(0,0);
			ERROR_MSG("for addition");
			return R;
		}
	}
	
	matrix operator -(matrix X){
		if(equalSize(X.M.size(),X.M[0].size())){
			matrix R(X.M.size(),X.M[0].size());
			for(int i=0;i<(int)X.M.size();++i){
				for(int j=0;j<(int)X.M[0].size();++j){
					R.M[i][j]=this->M[i][j]-X.M[i][j];
				}
			}
			return R;
		}else{
			matrix R(0,0);
			ERROR_MSG("for substraction");
			return R;
		}
	}
	
	bool operator ==(matrix X){
		if(equalSize(X.M.size(),X.M[0].size())){
			for(int i=0;i<(int)M.size();++i){
				for(int j=0;j<(int)M[i].size();++j){
					if(M[i][j]!=X.M[i][j]){
						return false;
					}
				}
			}return true;
		}else{
			ERROR_MSG("for equality checking");
			return false;
		}
	}
};	
int main()
{
	printf("MATRIX 1\n");
	printf("Enter number of rows and cols:\n");
	int R1,C1;scanf("%d %d",&R1,&C1);
	matrix M1(R1,C1);
	for(int i=0;i<R1;++i){
		for(int j=0;j<C1;++j){
			int a;scanf("%d",&a);
			M1.setElemenet(i,j,a);
		}
	}
	printf("MATRIX 2\n");
	printf("Enter number of rows and cols:\n");
	int R2,C2;scanf("%d %d",&R2,&C2);
	matrix M2(R2,C2);
	for(int i=0;i<R2;++i){
		for(int j=0;j<C2;++j){
			int a;scanf("%d",&a);
			M2.setElemenet(i,j,a);
		}
	}
	
	int option;
	printf("1. Addition, 2. Substration, 3. Equal");
	scanf("%d",&option);
	if(option==1){
		matrix R=M1+M2;
		R.printMatrix();
	}else if(option==2){
		matrix R=M1-M2;
		R.printMatrix();
	}else if(option==3){
		bool f=(M1==M2);
		if(f)printf("\nEQUAL MATRIX");
		else printf("\nNOT EQUAL MATRIX");
	}else{
		printf("\nInvalid Option");
	}
	//int rows,cols;cin>>rows>>cols;
	//matrix X(rows,cols);
	//matrix R(rows,cols);
	//for(int i=0;i<rows;++i){
		//for(int j=0;j<cols;++j){
			//int a;scanf("%d",&a);
			//X.setElemenet(i,j,a);
		//}
	//}
	//for(int i=0;i<rows;++i){
		//for(int j=0;j<cols;++j){
			//int a;scanf("%d",&a);
			//R.setElemenet(i,j,a);
		//}
	//}
	//matrix C=X*R;
	//C.printMatrix();
}
