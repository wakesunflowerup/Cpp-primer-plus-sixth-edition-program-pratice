double f_average(const double arr[],int n);

double f_max(const double arr[],int n);

double f_min(const double arr[],int n);

namespace SALES{
	const int QUARTERS =4;
	struct Sales{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales & s,const double ar[],int n);
	
	void setSales(Sales & s);
	
	void showSales(const Sales & s);
}


