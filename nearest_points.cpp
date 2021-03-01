/*
	1. Store the coordinates in a container -> coordinates
				ARRAY
	2. Store the first k elements of coordinates in a container -> nearest_elements
				MAX HEAP / PRIORITY QUEUE / QUEUE 
				COMPARATOR
	3. Sort nearest_elements so we can keep track of the biggest value (base on the result inside the squeare root of the pythagorean theorem (sqrt(x² + y²)))
			3.a) Compare the biggest value of nearest_elements (a), to the elements[k+1 ... n] of coordinates (b)
				* if a > b:
					- pop a
					- add b to nearest_elements
					- repeat 3

				FOR i = K + 1; i <= n; i++:
					NEAREST_ELEMENT_MAX() > COORDINNATES[i]:
						POP_MAX()
						nearest_elements.add(COORDINNATES[i])
						SORT nearest_elements
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Coordinate{
	int x;
	int y;

	Coordinate(int x, int y){
		this->x = x;
		this->y = y;
	}
};


bool compareDistance(Coordinate c1, Coordinate c2){
	int distance1 = c1.x * c1.x + c1.y * c1.y;
	int distance2 = c2.x * c2.x + c2.y * c2.y;
	return (distance1 > distance2);
}

int main(){
	int k_points;

	//Store the coordinates
	vector<Coordinate> coordinates{{3, 5}, {-1, 3}, {1, 1}, {-3, 1}, {-1, -1}, {3, -2}};

	vector<Coordinate> nearest_elements;

	//Ask for the k nearest elements
	cout << "Number of nearest points: ";
	cin >> k_points;
	
	//Store the first k elements in the queue
	for(int i = 0; i < k_points; i++){
		nearest_elements.push_back(coordinates[i]);
	}

	//Sort nearest_elements
	sort(nearest_elements.begin(), nearest_elements.end(), compareDistance);

	//Show nearest_elements
	for(auto i: nearest_elements){
		cout << i.x << " , " << i.y << endl;
	}

	return 0;
}
