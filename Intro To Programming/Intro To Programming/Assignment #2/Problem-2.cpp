/*
 * Name: Abhinaba Chakraborty
 * Roll No: cs2109
 * Date: 15.1.2021
 * Program Description: Define an abstract class named Shape having the following members:
 i) height as protected data member,
 ii) width as protected data member,
 iii) two public member functions for setting the height and width, respectively,
 iv) computeArea() as a pure virtual function
Derive two other classes, namely Rectangle and Triangle, from the base class Shape and define the
computeArea() function for these. Now apply the concept of runtime polymorphism while
computing the area for Rectangle and Triangle objects, named R and T, respectively.
 */
 
#include<bits/stdc++.h>
using namespace std;
class Shape{
protected:
	double height,width;
public:
	//Shape()=delete;
	void setWidth(double w){
		this->width=w;
	}
	void setHeight(double h){
		this->height=h;
	}
	virtual double computeArea()=0;
};
class Rectangle: public Shape{
	double computeArea(){
		return height*width;
	}
};
class Triangle: public Shape{
	double computeArea(){
		return height*width/2;
	}
	
};
int main()
{
	int choice;
	printf("1.Trianle 2.Rectangle: ");
	scanf("%d",&choice);
	if(choice!=1 and choice!=2){
		printf("Invalid Choice\n");
		return 0;
	}
	double height,width;
	printf("Give Height and Width: ");cin>>height>>width;
	//double height,width;
	Shape *S;
	if(choice==1){
		Triangle TA; S=&TA;
		S->setWidth(width);S->setHeight(height);
		cout<<"The Area of rectangle is:"<<S->computeArea();
	}else if(choice==2){
		Rectangle RC;S=&RC;
		S->setWidth(width);S->setHeight(height);
		cout<<"The Area of rectangle is:"<<S->computeArea();
	}
}
