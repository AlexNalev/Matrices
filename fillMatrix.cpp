#include<iostream>

using std::cout;
using std::endl;

class Matrix{
	public:
		int rows;
		int columns;
		int** arr;

		Matrix(int rows, int columns){
			this->rows = rows;
			this->columns = columns;

			arr = new int* [this->rows]; 	// Building the # of rows
			for(int i = 0; i < this->rows; i++){ 
				arr[i] = new int [this->columns]; // Building the # of columns for each row
			}
		}
	
		void fill_matrix(){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					if(i < j){
						arr[i][j] = 1;
					}
					else if(i == j){
						arr[i][j] = 0;
					}
					else{
						arr[i][j] = -1;
					}
				}
			}		
		}

		void show_matrix(){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					cout << "\t" << arr[i][j];
				}
				cout << endl;
			}
		}

		~Matrix(){
			for(int i = 0; i < rows; i++){
				delete [] arr[i];
			}
			delete [] arr;
			cout << "\nEverything was deleted successfully" << endl;
		}
};

int main(){
	Matrix m(5,2);
	m.fill_matrix();
	m.show_matrix();

return 0;
}
