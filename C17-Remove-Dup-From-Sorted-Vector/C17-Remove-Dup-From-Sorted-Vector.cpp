// C17-Remove-Dup-From-Sorted-Vector.cpp 
//     Remove-even-numbers

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void showVector(vector<T> v, string caption = "") {
	cout << caption << " (Size: " << v.size() << ")" << endl;
	for (auto item : v) cout << item << ", ";
	cout << endl;
}

void experiment01() {
	// Remove dups from Sorted vector
	vector<int> vnums = { 11, 22, 22, 33, 33, 33, 44, 55, 55,};
	showVector(vnums, "Before removing duplicates");

	int slow = 0; // Points to the position of the last confirmed unique element

	for (int fast = 1; fast < vnums.size(); ++fast) {
		// When fast finds a new unique value:
		if (vnums[fast] != vnums[slow]) {
			slow++;                   // Advance slow pointer
			vnums[slow] = vnums[fast];  // Overwrite with the unique value
		}
	}

	// Resize vector to trim off extra remaining elements
	vnums.resize(slow + 1);
	showVector(vnums, "After removing duplicates");
}

void experiment02() {
	// Version 1 - Remove even from vector (using iterators)
	vector<int> vnums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	showVector(vnums, "Version2 - Before removing even numbers");

	for (auto it = vnums.begin(); it != vnums.end(); ) {
		if (*it % 2 == 0) {
			it = vnums.erase(it); // erase returns the next valid iterator
		}
		else {
			++it;
		}
	}

	//No resizing needed!
	showVector(vnums, "Version2 - After removing even numbers");

}

void experiment03() {
	// Version 2 - Remove even numbers from vector (using array notation)
	vector<int> vnums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	showVector(vnums, "Version3 - Before removing even numbers");

	size_t slow = 0; // Points to where the next odd number should go

	for (int fast = 0; fast < vnums.size(); ++fast) {
		if (vnums[fast] % 2 != 0) {   // Keep odd numbers
			vnums[slow] = vnums[fast];
			slow++;
		}
	}

	// Trim the vector to keep only the odd numbers
	vnums.resize(slow);

	showVector(vnums, "Version3 - After removing even numbers");



}

//-----------------------------------------------------------------------
int main()
{
	//experiment01();
	//experiment02();
	experiment03();

	cout << "\nAll done!\n";
}

