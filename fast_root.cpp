#include<iostream>

using namespace std;
double get_rough_fast_square_root(double);
int main(){
	double n;
	cout << "Enter a number greater than 1 to find square root of: ";
	cin >> n;

	// we binary search between 1 and n, to find
	// integer lower and upper bound
	// having difference of 1
	double answer = get_rough_fast_square_root(n);
	cout << "Approximate square root of " << n << " is: " << answer << endl;

}

double get_rough_fast_square_root(double n){
	long long int l=1;
	long long int h=n;
	while(l<h){
		long long int mid = (l+h)/2;
		long long int mid_square = mid*mid;
		if(mid_square == n) return mid;
		// this equation is the core of the algorithm, along with binary search
		else if( h - l == 1) return (l) + (n - l*l)/(h*h - l*l);
		else if(mid_square < n) l=mid;
		else h=mid;
		
	}
	return 0.0;
}
