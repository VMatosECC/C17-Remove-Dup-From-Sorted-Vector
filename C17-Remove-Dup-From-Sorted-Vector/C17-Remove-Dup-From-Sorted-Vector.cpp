// C17-Remove-Dup-From-Sorted-Vector.cpp 

// ConsoleApplication21.cpp 

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void showVector(vector<T> v, string caption = "") {
    cout << caption << " (Sise: " << v.size() << ")" << endl;
    for (auto item : v) cout << item << ", ";
    cout << endl;
}


int main()
{
    //Sorted vector holding duplicates
    vector<int> v{ 11, 22, 22, 33, 33, 33, 44, 55, 55, };
    showVector(v, "original");

    int slow = 0;
    int fast = 1;
    while (fast < v.size())
    {
        if (v[fast] != v[slow]) {
            slow++;
            v[slow] = v[fast];
        }
        fast++;
    }

    // Resize to keep only elements from index 0 up to index slow
    v.resize(slow + 1);
    showVector(v, "Dups removed");

    cout << "\nAll done!\n";
}

