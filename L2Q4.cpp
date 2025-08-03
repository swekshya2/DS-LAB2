#include<iostream>
using namespace std;

void primeFactors(int n){
	cout << "prime factors of " << n << "are: ";
	//divide by 2 until odd
	while(n % 2 == 0){
		cout << 2 << " ";
		n /= 2;
	}
	//check odd numbers from 3 onward
	for(int i = 3; i * i <= n; i += 2){
		while( n % i == 0){
			cout<< i <<" ";
			n /= i;
		}
	}
	//if remaining n is a prime>2
	if(n > 2)
	cout << n;
cout << endl;
}
int main(){
	int num;
	cout << "enter a number: ";
	cin >> num;
	if(num < 2){
	cout << "no prime factors for numbers less than 2.\n"<<endl;
	}
	else{
	primeFactors(num);
	}
	return 0;
}
