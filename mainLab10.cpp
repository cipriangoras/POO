#include <iostream>
#include <exception>
#include"array.cpp"
using namespace std;
int main() {
    try {
        Array<int> myArray(5);
        
        myArray += 30;
        myArray += 10;
        myArray += 20;
        myArray += 5;
        for (auto it = myArray.GetBeginIterator(); it != myArray.GetEndIterator(); ++it) {
            cout << *it << endl;
        }
        cout << endl;
        myArray.Sort();
        for (auto it = myArray.GetBeginIterator(); it != myArray.GetEndIterator(); ++it) {
            cout << *it << endl;
        }
        cout << "gasit la indexul: " << myArray.BinarySearch(10) << endl;
        cout << "Elementul de pe pozitia 1 este: " << myArray[1] << endl;

        //out_of_range
        cout << "Elementul de pe pozitia 10 este: " << myArray[10] << endl;


        //out_of_range
        myArray.Insert(10, 40);


        int index = myArray.Find(20);
        if (index != -1) {
            cout << "Elementul 20 se afla la pozitia: " << index << endl;
        }
        else {
            cout << "Elementul 20 nu a fost gasit in array." << endl;
        }

        
        index = myArray.Find(50);
        if (index != -1) {
            cout << "Elementul 50 se afla la pozitia: " << index << endl;
        }
        else {
            cout << "Elementul 50 nu a fost gasit in array." << endl;
        }
    }
    catch (const std::out_of_range& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    return 0;
}
