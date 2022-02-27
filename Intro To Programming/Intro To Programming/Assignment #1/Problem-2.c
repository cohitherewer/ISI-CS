/*
NAME: ABHINABA CHAKRABORTY
ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Find the Roots of a quadratic equation: ax^2+bx=c=0
	Coefficients (a,b,c) are your inputs.
*/
#include<stdio.h>
#include<math.h>
struct complexNumber{
	float real,img;
};
struct complexNumber roots(float a,float b,float d,int var){
	struct complexNumber r;
	if(var==1){
		if(d>=0){
			float x=pow(d,0.5);
			float ans=(-b+x)/(2*a);
			r.real=ans;r.img=0;
		}else{
			r.real=-b/(2*a);
			r.img=pow(-d,0.5)/(2*a);
		}
	}else if(var==2){
		if(d>=0){
			float x=pow(d,0.5);
			float ans=(-b-x)/(2*a);
			r.real=ans;r.img=0;
		}else{
			r.real=-b/(2*a);
			r.img=-pow(-d,0.5)/(2*a);
		}
	}
	return r;
}
int main()
{
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	float d=b*b-4*a*c;
	if(d>=0){
		struct complexNumber root1=roots(a,b,d,1);
		struct complexNumber root2=roots(a,b,d,2);
		printf("roots are %.3f and %.3f\n",root1.real,root2.real);
		printf("The ratio of two roots are: %.3f\n",root1.real/root2.real);
	}else{
		struct complexNumber root1=roots(a,b,d,1);
		struct complexNumber root2=roots(a,b,d,2);
		printf("roots are (%.3f %.3fi) and (%.3f %.3fi)\n",root1.real,root1.img,root2.real,root2.img);
		
		struct complexNumber ratio;
		ratio.real=(pow(root1.real,2)-pow(root1.img,2))/(pow(root1.real,2)+pow(root1.real,2));
		ratio.img=2*root1.real*root1.img/(pow(root1.real,2)-pow(root1.img,2));
		printf("The ratio of two roots are %.3f %.3fi",ratio.real,ratio.img);
	}

}