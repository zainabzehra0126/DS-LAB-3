#include <iostream>
#include <string>
using namespace std;
	
class TimetableSearch{
	private:
	    string courseCode[10];
	    int classroom[10];
	    string teacher[10];
	    string timing[10];
	    int n;
	
	public:
	    TimetableSearch(){
	        n = 0;
	    }
	
	    void inputData(){
	        cout << "Enter number of classes: ";
	        cin >> n;
	
	        for(int i = 0; i < n; i++){
	            cout << "Enter course code " << i + 1 << ": ";
	            cin >> courseCode[i];
	
	            cout << "Enter classroom number: ";
	            cin >> classroom[i];
	
	            cin.ignore();
	
	            cout << "Enter teacher name: ";
	            getline(cin, teacher[i]);
	
	            cout << "Enter class timing: ";
	            getline(cin, timing[i]);
	        }
	    }
	
	    void display(){
	        cout << "Class Details" << endl;
	
	        for(int i = 0; i < n; i++){
	            cout <<courseCode[i] << "\n" << classroom[i] << "\n" << teacher[i] << "\n" << timing[i] << endl;
	        }
	    }
	
	    int linearSearch(string target, int &comparisons){
	        comparisons = 0;
	
	        for(int i = 0; i < n; i++){
	            comparisons++;
	
	            if(courseCode[i] == target){
	                return i;
	            }
	        }
	
	        return -1;
	    }
	
	    void sortData(){
	        for(int i = 0; i < n - 1; i++){
	            for(int j = 0; j < n - i - 1; j++){
	                if(courseCode[j] > courseCode[j + 1]){
	                    swap(courseCode[j], courseCode[j + 1]);
	                    swap(classroom[j], classroom[j + 1]);
	                    swap(teacher[j], teacher[j + 1]);
	                    swap(timing[j], timing[j + 1]);
	                }
	            }
	        }
	    }
	
	    int binarySearch(string target, int &comparisons){
	        comparisons = 0;
	
	        int low = 0;
	        int high = n - 1;
	
	        while(low <= high){
	            int mid = (low + high) / 2;
	            comparisons++;
	
	            if(courseCode[mid] == target){
	                return mid;
	            }
	            else if(courseCode[mid] < target){
	                low = mid + 1;
	            }
	            else{
	                high = mid - 1;
	            }
	        }
	
	        return -1;
	    }
	
	    int convertCode(string code){
	        int value = 0;
	
	        for(int i = 0; i < code.length(); i++){
	            if(code[i] >= '0' && code[i] <= '9'){
	                value = value * 10 + (code[i] - '0');
	            }
	        }
	
	        return value;
	    }
	
	    int interpolationSearch(string target, int &comparisons){
	        comparisons = 0;
	
	        int targetValue = convertCode(target);
	        int low = 0;
	        int high = n - 1;
	
	        while(low <= high && targetValue >= convertCode(courseCode[low]) && targetValue <= convertCode(courseCode[high])){
	            int lowValue = convertCode(courseCode[low]);
	            int highValue = convertCode(courseCode[high]);
	
	            if(lowValue == highValue){
	                comparisons++;
	
	                if(lowValue == targetValue){
	                    return low;
	                }
	
	                return -1;
	            }
	
	            int pos = low +
	                ((targetValue - lowValue) * (high - low))
	                / (highValue - lowValue);
	
	            comparisons++;
	
	            int posValue = convertCode(courseCode[pos]);
	
	            if(posValue == targetValue)
	            {
	                return pos;
	            }
	            else if(posValue < targetValue)
	            {
	                low = pos + 1;
	            }
	            else
	            {
	                high = pos - 1;
	            }
	        }
	
	        return -1;
	    }
	
	    void ShowResult(int index, int comparisons, string method){
	        if(index != -1){
	            cout << method << ": Course Found" << endl;
	            cout << "Course Code: " << courseCode[index] << endl;
	            cout << "Classroom: " << classroom[index] << endl;
	            cout << "Teacher: " << teacher[index] << endl;
	            cout << "Class Timing: " << timing[index] << endl;
	            cout << "Comparisons: " << comparisons << endl;
	        }
	        else{
	            cout << method << ": Course Not Found" << endl;
	            cout << "Comparisons: " << comparisons << endl;
	        }
	    }
	
	    void Search(){
	        string target;
	        int choice;
	        int comparisons;
	        int index;
	
	        cout << "Enter course code to search: ";
	        cin >> target;
	
	        do{
	            cout << "Search Menu" << endl;
	            cout << "1. Linear Search" << endl;
	            cout << "2. Binary Search" << endl;
	            cout << "3. Interpolation Search" << endl;
	            cout << "4. All Search Techniques" << endl;
	            cout << "0. Exit" << endl;
	            cout << "Enter choice: ";
	            cin >> choice;
	
	            if(choice == 1){
	                index = linearSearch(target, comparisons);
	                ShowResult(index, comparisons, "Linear Search");
	            }
	            else if(choice == 2){
	                sortData();
	                index = binarySearch(target, comparisons);
	                ShowResult(index, comparisons, "Binary Search");
	            }
	            else if(choice == 3){
	                sortData();
	                index = interpolationSearch(target, comparisons);
	                ShowResult(index, comparisons, "Interpolation Search");
	            }
	            else if(choice == 4){
	                index = linearSearch(target, comparisons);
	                ShowResult(index, comparisons, "Linear Search");
	
	                sortData();
	
	                index = binarySearch(target, comparisons);
	                ShowResult(index, comparisons, "Binary Search");
	
	                index = interpolationSearch(target, comparisons);
	                ShowResult(index, comparisons, "Interpolation Search");
	            }
	            else if(choice != 0){
	                cout << "Invalid choice." << endl;
	            }
	        }
			while(choice != 0);
	    }
	
	    void run(){
	        inputData();
	
	        cout << "Timetable Data" << endl;
	        display();
	
	        Search();
	    }
	};
	
	int main(){
	    TimetableSearch timetable;
	    timetable.run();
	
	    return 0;
	}
