#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void ask_order_matrix(int& rows, int& columns){
	cout << "Rows: ";
	cin >> rows;
	cout << "Columns: ";
	cin >> columns;
}

void ask_values_of_matrix(int rows, int columns, vector<vector<int>>& matrix){
	int aux;
	vector<int> line;
	cout << "\n-------------------------------------\n";
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < columns; c++){
			cout << "Element [" << r+1 << "][" << c+1 << "]: ";
			cin >> aux;
			line.push_back(aux);
		}
		matrix.push_back(line);
		line.clear();
	}
	cout << "-------------------------------------\n\n";
}

void get_sums(vector<vector<int>> matrix, int rows, int columns){
	int sum = 0;
	int row_counter = 0;

	// sum of the rows:
	for(auto row: matrix){
		for(auto element: row){
			sum += element; 
		}
		cout << "Row " << row_counter+1 << " = " << sum << endl;
		row_counter++;
		sum = 0;
	}

 	//sum of the columns:
	for(int c = 0; c < columns; c++){
		for(auto element: matrix){
			sum += element[c];		
		}
		cout << "Column " << c+1 << " = " << sum << endl;
		sum = 0;
	}    
}

void show_elements(vector<vector<int>> matrix){
	cout << endl << "+-------------Elements of the matrix-------------+" << endl;
	for(auto row: matrix){
		for(auto element: row){
			cout << "\t" << element ;
		}
		cout << endl;
	}
	cout << "+-------------------------------------------------+" << endl;
}


int main(){
	int rows, columns;
	vector<vector<int>> matrix;

	ask_order_matrix(rows, columns);
	ask_values_of_matrix(rows, columns, matrix);
	get_sums(matrix, rows, columns);
	show_elements(matrix);

return 0;
}
