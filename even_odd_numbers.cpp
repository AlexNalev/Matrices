#include<iostream>
#include<vector>

using namespace std;

void count_even_odd_numbers(vector<int> numbers){
	int even_counter = 0, odd_counter = 0;
	for(auto number : numbers){
		if(number % 2 == 0){
			even_counter ++;
		}
		else{
			odd_counter ++;
		}
	}
	cout << "You have:\n";
	cout << "- " << even_counter << " even numbers in the array\n";
	cout << "- " << odd_counter << " odd numbers in the array\n";
}


void ask_array_data(vector<int>& numbers){
	int number_elements, auxiliary;
	cout << "Number of elements? ";
	cin >> number_elements;
	
	for(int i = 0; i < number_elements; i++){
		cout << "Element " << i+1 << ": ";
		cin >> auxiliary;
		numbers.push_back(auxiliary);
	}
}

int main(){
	vector<int> n;
	ask_array_data(n);
	count_even_odd_numbers(n);

	return 0;
}
