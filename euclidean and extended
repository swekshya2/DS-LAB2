#include<iostream>
using namespace std;
//euclidean algorithm to find gcd
int euclideanGCD(int a,int b){
	while(b!=0){
		int temp =b;
		b=a%b;
		a= temp;
	}
	return a;
}
//extended euclidean algorithm
int extendedEuclidean(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int gcd= extendedEuclidean(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return gcd;
}
int main(){
	int a,b;
	cout<<"enter two integers: ";
	cin>>a>>b;
	//euclidean
	int gcd=euclideanGCD(a,b);
	cout<<"euclidean gcd: "<<gcd<<endl;
	//extended euclidean
	int x,y;
	int extGCD=extendedEuclidean(a,b,x,y);
	cout<<"entended euclidean gcd: "<<
	extGCD<<endl;
	cout<<"extended euclidean gcd: "<<
	extGCD<<endl;
	cout<<"coefficients x and y such that ax+by=gcd: "<<x<<", "<<y<<endl;
	return 0;
}
