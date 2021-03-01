/*

	1. Store the coordinates in a container -> coordinates
	2. Store the first k elements of coordinates in a container -> nearest_elements
	3. Sort nearest_elements so we can keep track of the biggest value (base on the result inside the squeare root of the pythagorean theorem (sqrt(x² + y²)))
			3.a) Compare the biggest value of nearest_elements (a), to the elements[k+1 ... n] of coordinates (b)
			for i = k; i < b.size(); i++:      //i = k+1 if you base goes from 1
				if a > b:
					- pop a from nearest_elements
					- add b to nearest_elements
					- repeat 3


---------------------Takeaways
 * Not overcomplicate your life by trying to use the other containers in C++. Vectors are more than enough, 'cause you can iterate through them, use the index property. And maybe you won't have track of the biggest or the smallest element, but it's easy to implement with the sort algorithm and an extra variable.

 * Use vectors for everything xD. Not, but really, vectors are more comfortable. Due that not all the containers allow you to iterate through them or use the index property.

 * The erase operation from the vector. You can give it an index and it will delete that element.

 * The indicators of the beginnin and end of a vector are really useful, is like using a reference. Like when you send an array to a function and decays to a pointer (obviously is not the same, but I find that similar).

 * The sort algorithm in C++ works better with a vector. Again, vectors are kind, vectors are friends. As the third argument will be added the so called comparator, which is a function.

 * For comparators have to be builded an extra function, where, in this case, had to be compared two objects. And more specifically, an operation that involved the coordinates values. It returns a bool value based on a comparison.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Coordinate{
	public:
		int x;
		int y;
		int distance;

		Coordinate(){}

		Coordinate(int x, int y){
			this->x = x;
			this->y = y;
		}

		int calculateDistance(){
			distance = x * x + y * y;
			return distance;
		}
};


bool compareDistance(Coordinate c1, Coordinate c2){
	return (c1.calculateDistance() > c2.calculateDistance());	
}

int main(){
	int k_points;
	
	//Store the coordinates
	vector<Coordinate> coordinates{{3, 5}, {-1, 3}, {1, 1}, {-3, 1}, {-1, -1}, {3, -2}};

	vector<Coordinate> nearest_elements;
	Coordinate max_coordinate;

	//Ask for the k nearest elements
	do{
		cout << "Number of nearest points: ";
		cin >> k_points;
	}while(k_points <= 0 || k_points > coordinates.size());
	
	//Store the first k elements in the queue
	for(int i = 0; i < k_points; i++){
		nearest_elements.push_back(coordinates[i]);
	}

	//Sort first k_points nearest_elements
	sort(nearest_elements.begin(), nearest_elements.end(), compareDistance);

	for(int i = k_points; i < coordinates.size(); i++){
		//Have the max coordinate from the nearest_elements
		max_coordinate.x = nearest_elements[0].x;
		max_coordinate.y = nearest_elements[0].y;

		if(max_coordinate.calculateDistance() > coordinates[i].calculateDistance()){
			nearest_elements.erase(nearest_elements.begin());
			nearest_elements.push_back(coordinates[i]);
			sort(nearest_elements.begin(), nearest_elements.end(), compareDistance);
		}
	}
	
	//Show nearest_elements
	cout << "The final nearest elements to the origin are:\n";
	for(auto i: nearest_elements){
		cout << "(" << i.x << " , " << i.y << ")" << endl;
	}

	return 0;
}
