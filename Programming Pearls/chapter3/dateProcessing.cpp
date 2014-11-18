#include<iostream>
#include<string>
#include<ctime>

using namespace std;

bool leap_year(int year)
{
		if((year % 400 == 0) || ((year % 4 == 0)&&(year % 100) != 0))
		{
			return true;
		}

		return false;
}
//算出给定的两个日期间相隔的天数
int count(string date1,string date2)
{

		int day_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int days;
		int year1 = stoi(date1.substr(0,4));
		int month1 = stoi(date1.substr(5,2));
		int day1 = stoi(date1.substr(8,2));
		int year2 = stoi(date2.substr(0,4));
		int month2 = stoi(date2.substr(5,2));
		int day2 = stoi(date2.substr(8,2));
		
	    days =  day_in_month[month1] - day1;
		days +=day2;
		if((month1 == month2)&&(year1==year2))  //同年同月
				days -= day_in_month[month1];
		if(leap_year(year1))
				day_in_month[2] = 29;

		if(year2-year1 == 0)   //同年不同月
		{
			for(int i =month1+1;i<month2;++i)
			{
					days+=day_in_month[i];
			}	
			return days;
		}
		else     //不同年
		{
	    for(int i = month1+1;i <= 12;++i)
		{
				days +=day_in_month[i];
		}	

		for(int i = year1+1;i<year2;++i)
		{
				int temp = 365;
				if(leap_year(i))
						temp = 366;
				days += temp;
		}

		if(!leap_year(year2))
				day_in_month[2] = 28;
		else
				day_in_month[2] = 29;

		for(int i =1;i < month2;++i)
		{
				days += day_in_month[i];
		}

		return days;
}
}
//指定日期，给出是星期几
string weekcount(string date)
{
		string w;
		string week[] = {"Sun","Mon","Tue","Wen","Thu","Fri","Sat"};
		time_t t = time(0);
		tm* tm1 = localtime(&t);

		int yearnow = tm1->tm_year;
		int monthnow = tm1->tm_mon;
		int daynow = tm1->tm_mday;
		int wenow = tm1->tm_wday;

		string datenow;
		datenow = to_string(yearnow+1900) + '-' + to_string(monthnow+1) + '-' + to_string(daynow);
		int days = count(date,datenow);

		int temp = days%7;
		for(int i =0;i<temp;++i)
		{
				wenow--;
				if(wenow<0)
						wenow = 6 ;
		}
		w = week[wenow];

		return w;
}

int main(void)
{
		string s1("2013-11-16");
		string s2("2014-11-10");
		cout<<count(s1,s2)<<endl;
		cout<<weekcount(s2)<<endl;
		return 0;
}
