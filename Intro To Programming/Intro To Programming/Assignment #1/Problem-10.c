/*ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Define a structure data type named date containing three integer members:
day, month, and year. Use this to store date of birth and current date and calculate the age
of a person.
*/
#include<stdio.h>
#include<stdlib.h>
struct data{
	int year,month,day;
};
int main()
{
	struct data* dob=(struct data *)malloc(sizeof(struct data *));
	scanf("%d %d %d",&dob->year,&dob->month,&dob->day);
	struct data* current=(struct data *)malloc(sizeof(struct data *));
	scanf("%d %d %d",&current->year,&current->month,&current->day);

	struct data* age=(struct data *)malloc(sizeof(struct data *));
	bool f1=false;
	if(dob->day <= current->day){
		age->day=current->day-dob->day;
	}else{
		f1=true;
		age->day=(30+current->day)-dob->day;
	}
	if(f1==true){
		current->month-=1;
		f1=false;
	}
	if(dob->month <= current->month){
		age->month=current->month-dob->month;
	}else{
		age->month=(12+current->month)-dob->month;
		f1=true;
	}
	if(f1==true){
		current->year-=1;
	}
	age->year=current->year-dob->year;

	printf("%d %d %d",age->year,age->month,age->day);
}