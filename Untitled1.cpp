#include <iostream>
using namespace std;

int main (){
	
	int Mark1, Mark2 , Mark3 ;
	float Total , Average ;
	
	cout << "Enter marks of first Subject out of 100 : " << endl;
	cin >> Mark1 ;
	  
	cout << "Enter marks of Second Subject out of 100 : " << endl;
	cin >> Mark2;
	
	cout << "Enter marks of Third Subject out of 100 : " << endl;
	cin >> Mark3;
	
	Total = Mark1 + Mark2 + Mark3 ;
	Average = Total / 3 ;
	
	cout << "Total : " << Total << endl;
	cout << "Average : " << Average << endl;
	
	if ( Total >= 80 ){
		
		cout << "You Got Grade A " << endl;
	}
	
	else if ( Total >= 70 ){
		
		cout << "You Got Grade B " << endl;
	}
	
	else if ( Total >= 60 ){
		
		cout << "You Got Grade C " << endl;
	}
	  
	else {
		
		cout << "Your Fail " << endl;
	}
	
	
	return 0;
	
}
