#include <iostream>
#include <string>
using namespace std;
	
class DailyTimeAnalyzer{
	private:
	    string activity[50];
	    double time[50];
	    int n;
	
	public:
	
	    DailyTimeAnalyzer(){
	        n = 0;
	    }
	
		void inputActivities(){
		    string input;
		    n = 0;
		
		    cout << "Enter your daily activities\nminimum 7 activities should be added\n";
		    cout << "Type 'END' when you are finished\n";
		
		    while (n < 50){
		        cout << "Enter activity " << n + 1 << ": ";
		        getline(cin, input);
		
		        if(input == "end" || input == "END" || input == "End"){
		            if (n < 7){
		                cout << "You must enter at least 7 activities\n";
		                cout << "Please enter more activities";
		                continue;
		            }
		            else{
		                break;
		            }
		        }
		
		        activity[n] = input;
		        cout << "Enter time spent on " << activity[n] << " (hours): ";
				cin >> time[n];
		        cin.ignore();
		        n++;
		        cout << endl;
		    }
		
		    if (n == 50){
		        cout << "Limit of activities reached\n";
		    }
		}
			
	    void displayActivities(){
	        cout << "Your Activities\n";
	
	        for (int i = 0; i < n; i++){
	            cout<< activity[i] << endl;
	        }
	    }
	
	    void displaySorted(string algorithm, string names[], double values[]){
	        cout << algorithm << "\n";	
	    	
			cout << "Sorted Activities:\n";
			for (int i = 0; i < n; i++){
	            cout << names[i] << endl;
	        }
	        cout << "Time values are hidden initially.\n";
	    }
	
	    void copyArray(string names[], double values[]){
	        for (int i = 0; i < n; i++){
	            names[i] = activity[i];
	            values[i] = time[i];
	        }
	    }
	
		void bubbleSort(){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int i = 0; i < n - 1; i++){
	            for (int j = 0; j < n - i - 1; j++){
	            	
	                if (values[j] > values[j + 1]){
	                	
	                    double temp = values[j];
	                    values[j] = values[j + 1];
	                    values[j + 1] = temp;
	
	                    string tempName = names[j];
	                    names[j] = names[j + 1];
	                    names[j + 1] = tempName;
	                }
	            }
	        }
	
	        displaySorted("Bubble Sort", names, values);
	    }
	
	    void selectionSort(){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int i = 0; i < n - 1; i++){
	            int minIndex = i;
	
	            for (int j = i + 1; j < n; j++){
	                if (values[j] < values[minIndex]){
	                    minIndex = j;
	                }
	            }
	
	            double temp = values[i];
	            values[i] = values[minIndex];
	            values[minIndex] = temp;
	
	            string tempName = names[i];
	            names[i] = names[minIndex];
	            names[minIndex] = tempName;
	        }
	
	        displaySorted("Selection Sort", names, values);
	    }
	
	    void insertionSort(){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int i = 1; i < n; i++){
	            double key = values[i];
	            string keyName = names[i];
	            int j = i - 1;
	
	            while (j >= 0 && values[j] > key){
	                values[j + 1] = values[j];
	                names[j + 1] = names[j];
	                j--;
	            }
	
	            values[j + 1] = key;
	            names[j + 1] = keyName;
	        }
	
	        displaySorted("Insertion Sort", names, values);
	    }
		
	    void shellSort(){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int gap = n / 2; gap > 0; gap = gap / 2){
	            
				for (int i = gap; i < n; i++){
	                double temp = values[i];
	                string tempName = names[i];
	                int j;
	
	                for (j = i; j >= gap && values[j - gap] > temp; j = j - gap){
	                    values[j] = values[j - gap];
	                    names[j] = names[j - gap];
	                }
	
	                values[j] = temp;
	                names[j] = tempName;
	            }
	        }
	
	        displaySorted("Shel Sort", names, values);
	    }
	
	    void combSort(){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        int gap = n;
	        bool swapped = true;
	        
	        while (gap != 1 || swapped){
	            gap = (gap * 10) / 13;
	
	            if (gap < 1){
	                gap = 1;
	            }
	
	            swapped = false;
	
	            for (int i = 0; i + gap < n; i++){
	                if (values[i] > values[i + gap]){
	                    double temp = values[i];
	                    values[i] = values[i + gap];
	                    values[i + gap] = temp;
	
	                    string tempName = names[i];
	                    names[i] = names[i + gap];
	                    names[i + gap] = tempName;
	
	                    swapped = true;
	                }
	            }
	        }
	
	        displaySorted("Comb Sort", names, values);
	    }
	
	    void sortingMenu(){
	        int choice;
	
	        do{
	            cout << "Sorting Menu\n";	
	            cout << "1. Bubble Sort\n";
	            cout << "2. Selection Sort\n";
	            cout << "3. Insertion Sort\n";
	            cout << "4. Shell Sort\n";
	            cout << "5. Comb Sort\n";
	            cout << "6. All Five Algorithms\n";
	            cout << "0. Back to Main Menu\n";
	
	            cout << "Enter your choice: ";
	            cin >> choice;
	
	            switch (choice){
	            case 1:
	                bubbleSort();
	                break;
	
	            case 2:
	                selectionSort();
	                break;
	
	            case 3:
	                insertionSort();
	                break;
	
	            case 4:
	                shellSort();
	                break;
	
	            case 5:
	                combSort();
	                break;
	
	            case 6:
	                bubbleSort();
	                selectionSort();
	                insertionSort();
	                shellSort();
	                combSort();
	                break;
	
	            case 0:
	                cout << "Returning to main menu\n";
	                break;
	
	            default:
	                cout << "Invalid choice!\n";
	            }
	
	        }
			while (choice != 0);
	    }
		
	    void HowMuchTime(){
	        string target;
	        cin.ignore();
	
	        cout << "Enter activity name: " << endl;
	        getline(cin, target);
	
	        for (int i = 0; i < n; i++){
	            if (activity[i] == target){
	                cout << "Preference found: "<< activity[i] << endl;
	                cout << "Time spent on " << activity[i] << ": " << time[i] << " hours.\n";
	                return;
	            }
	        }
	        cout << "\nActivity not found.\n";
	    }
	
	    int linearSearch(string target, int &comparisons){
	        comparisons = 0;
	
	        for (int i = 0; i < n; i++){
	            comparisons++;
	
	            if (activity[i] == target){
	                return i;
	            }
	        }
	
	        return -1;
	    }
	
	    int binarySearch(string target, int &comparisons){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int i = 0; i < n - 1; i++){
	        	
	            for (int j = 0; j < n - i - 1; j++){
	                if (names[j] > names[j + 1]){
	                    string tempName = names[j];
	                    names[j] = names[j + 1];
	                    names[j + 1] = tempName;
	
	                    double tempTime = values[j];
	                    values[j] = values[j + 1];
	                    values[j + 1] = tempTime;
	                }
	            }
	        }
	
	        comparisons = 0;
	        int low = 0;
	        int high = n - 1;
	
	        while (low <= high){
	            int mid = low + (high - low) / 2;
	            comparisons++;
	
	            if (names[mid] == target){
	                return mid;
	            }
	
	            if (names[mid] < target){
	                low = mid + 1;
	            }
	            else{
	                high = mid - 1;
	            }
	        }
	
	        return -1;
	    }
	
	    int interpolationSearch(double targetTime, int &comparisons){
	        string names[50];
	        double values[50];
	        copyArray(names, values);
	
	        for (int i = 0; i < n - 1; i++){
	        	
	            for (int j = 0; j < n - i - 1; j++){
	                if (values[j] > values[j + 1]){
	                    double temp = values[j];
	                    values[j] = values[j + 1];
	                    values[j + 1] = temp;
	
	                    string tempName = names[j];
	                    names[j] = names[j + 1];
	                    names[j + 1] = tempName;
	                }
	            }
	        }
	
	        comparisons = 0;
	        int low = 0;
	        int high = n - 1;
	
	        while(low <= high && targetTime >= values[low] && targetTime <= values[high]){
	            comparisons++;
	
	            if (values[low] == values[high]){
	                if (values[low] == targetTime){
	                    cout << "Activity: " << names[low] << endl;
	                    return low;
	                }
	
	                return -1;
	            }
	
	            int pos = low + ((targetTime - values[low]) * (high - low)) / (values[high] - values[low]);
	
	            if (values[pos] == targetTime){
	                cout << "Activity: "  << names[pos] << endl;
	                return pos;
	            }
	
	            if (values[pos] < targetTime){
	                low = pos + 1;
	            }
	            else{
	                high = pos - 1;
	            }
	        }
	
	        return -1;
	    }
	
		void findMaximumTime(){
	        int maxIndex = 0;
	
	        for (int i = 1; i < n; i++){
	            if (time[i] > time[maxIndex]){
	                maxIndex = i;
	            }
	        }
	
	        cout << "Time Analysis Resport" << endl;
	        cout << "You usually spend the most time on: " << activity[maxIndex] << endl;
	        char choice;
	
	        cout << "How much time? (y/n): ";
	        cin >> choice;
	
	        if (choice == 'y' || choice == 'Y'){
	            cout << "Total time spent on " << activity[maxIndex] << ": " << time[maxIndex]  << " hours\n";
	        }
	    }
	
	    void searchingMenu(){
	        int choice;
	
	        do{
	            cout << "Searching and Time Analysis" << endl;
	            cout << "1. Linear Search\n";
	            cout << "2. Binary Search\n";
	            cout << "3. Interpolation Search\n";
	            cout << "4. All Searching Techniques\n";
	            cout << "5. Any Two Searching Techniques\n";
	            cout << "6. Find Activity With Maximum Time\n";
	            cout << "0. Back to Main Menu\n";
	            cout << "Enter your choice: ";
	            cin >> choice;
	
	            if (choice == 1){
	                string target;
	                int comparisons;
	                cin.ignore();
	
	                cout << "Enter activity to search: "<< endl;
	                getline(cin, target);
	
	                int result = linearSearch(target, comparisons);
	
	                cout << "Linear Search" << endl;
	
	                if (result != -1){
	                    cout << "Preference found: " << activity[result] << endl;
	                    cout << "Number of comparisons: "<< comparisons << endl;
	                    char answer;
	
	                    cout << "How much time? (y/n): ";
	                    cin >> answer;
	
	                    if (answer == 'y' || answer == 'Y'){
	                        cout << "Time spent on " << activity[result]<< ": " << time[result]  << " hours.\n";
	                    }
	                }
	                else{
	                    cout << "Preference not found.\n";
	                    cout << "Number of comparisons: " << comparisons << endl;
	                }
	            }
		
	            else if (choice == 2){
	                string target;
	                int comparisons;
	                cin.ignore();
	
	                cout << "Enter activity to search: "<< endl;
	                getline(cin, target);
	
	                int result = binarySearch(target, comparisons);
	
	                cout << "Binary Search" << endl;
	
	                if (result != -1){
	                	cout << "Preference found: "<< target << endl;
	                    cout << "Number of comparisons: "  << comparisons << endl;
	                    char answer;
	                    cout << "How much time? (y/n): ";
	                    cin >> answer;
	
	                    if (answer == 'y' || answer == 'Y'){
	                        for (int i = 0; i < n; i++){
	                            if (activity[i] == target){
	                                cout << "Time spent on " << activity[i] << ": " << time[i] << " hours.\n";
	                                break;
	                            }
	                        }
	                    }
	                }
	                else{
	                    cout << "Preference not found.\n";
	                    cout << "Number of comparisons: " << comparisons << endl;
	                }
	            }
	
	
	            else if (choice == 3){
	                double targetTime;
	                int comparisons;
	
	                cout << "\nEnter time to search: ";
	                cin >> targetTime;
	
	                int result = interpolationSearch(targetTime, comparisons);
	
	                cout << "Interpolation Search" << endl;
	
	                if (result != -1){
	                    cout << "Time value found: " << targetTime << " hours.\n";
	                    cout << "Number of comparisons: " << comparisons << endl;
	                }
	                else{
	                    cout << "Time value not found.\n";
	                    cout << "Number of comparisons: " << comparisons << endl;
	                }
	            }
	
	            else if (choice == 4){
	                string target;
	                double targetTime;
	
	                int linearComparisons;
	                int binaryComparisons;
	                int interpolationComparisons;
	
	                cin.ignore();
	                cout << "Enter activity for " << "Linear and Binary Search: ";
	
	                getline(cin, target);
	
	                int linearResult = linearSearch(target, linearComparisons);
	
	                int binaryResult = binarySearch(target, binaryComparisons);
	
	
	                cout << "Search Result" << endl;	
	                cout << "Linear Search:" << endl;
	
	                if (linearResult != -1){
	                    cout << "Preference found: "<< activity[linearResult] << endl;
	                }
	                else{
	                    cout << "Preference not found\n";
	                }
	
	                cout << "Comparisons: "  << linearComparisons << endl;
	                cout << "Binary Search:\n";
	
	                if (binaryResult != -1){
	                    cout << "Preference found: "<< target << endl;
	                }
	                else{
	                    cout << "Preference not found.\n";
	                }
	
	                cout << "Comparisons: "<< binaryComparisons << endl;
	
	
	                cout << "Enter time for Interpolation Search: " << endl;
	                cin >> targetTime;
	
	
	                int interpolationResult = interpolationSearch(targetTime, interpolationComparisons);
	                cout << "Interpolation Search:\n";
	
	                if (interpolationResult != -1){
	                    cout << "Time value found: " << targetTime << " hours\n";
	                }
	                else{
	                    cout << "Time value not found\n";
	                }
	
	                cout << "Comparisons: "<< interpolationComparisons  << endl;
	            }
	
	
	            else if (choice == 5){
	                int technique1;
	                int technique2;
	
	                cout << "Select first technique:\n";
	                cout << "1. Linear Search\n";
	                cout << "2. Binary Search\n";
	                cout << "3. Interpolation Search\n";
	
	                cout << "Enter choice: ";
	                cin >> technique1;
	
	
	                cout << "Select second technique:\n";
	                cout << "1. Linear Search\n";
	                cout << "2. Binary Search\n";
	                cout << "3. Interpolation Search\n";
	
	                cout << "Enter choice: ";
	                cin >> technique2;
	
	                if (technique1 == 1 ||technique1 == 2 ||technique2 == 1 ||technique2 == 2){
	                    string target;
	                    cin.ignore();
	                    cout << "Enter activity name: ";
	                    getline(cin, target);
	
	                    if (technique1 == 1){
	                        int comparisons;
	                        int result = linearSearch(target,comparisons);
	
	                        cout << "Linear Search: ";
	                        if (result != -1)
	                            cout << "Preference found";
	                        else
	                            cout << "Not found";
	
	                        cout << "Comparisons: " << comparisons << endl;
	                    }
	
	
	                    if (technique1 == 2){
	                        int comparisons;
	
	                        int result = binarySearch(target,comparisons);
	                        cout << "Binary Search: ";
	
	                        if (result != -1)
	                            cout << "Preference found";
	                        else
	                            cout << "Not found";
	
	                        cout << "Comparisons: "<< comparisons << endl;
	                    }
	
	
	                    if (technique2 == 1){
	                        int comparisons;
	
	                        int result = linearSearch(target, comparisons);
	                        cout << "Linear Search: ";
	
	                        if (result != -1)
	                            cout << "Preference found";
	                        else
	                            cout << "Not found";
	
	                        cout << "Comparisons: "<< comparisons << endl;
	                    }
	
	
	                    if (technique2 == 2){
	                        int comparisons;
	
	                        int result =  binarySearch(target, comparisons);
	                        cout << "Binary Search: ";
	
	                        if (result != -1)
	                            cout << "Preference found";
	                        else
	                            cout << "Not found";
	
	                        cout << "Comparisons: " << comparisons << endl;
	                    }
	                }
	
	
	                if (technique1 == 3 ||technique2 == 3){
	                    double targetTime;
	
	                    cout << "Enter time for "<< "Interpolation Search: ";
	                    cin >> targetTime;
	
	                    if (technique1 == 3){
	                        int comparisons;
	
	                        int result = interpolationSearch(targetTime, comparisons);
	                        cout << "Interpolation Search: ";
	
	                        if (result != -1)
	                            cout << "Time found";
	                        else
	                            cout << "Time not found";
	
	                        cout << "Comparisons:" << comparisons << endl;
	                    }
	
	
	                    if (technique2 == 3){
	                        int comparisons;
	
	                        int result =  interpolationSearch(targetTime, comparisons);
	                        cout << "Interpolation Search: ";
	
	                        if (result != -1)
	                            cout << "Time found";
	                        else
	                            cout << "Time not found";
	
	                        cout << "Comparisons: " << comparisons << endl;
	                    }
	                }
	            }
	
	
	            else if (choice == 6){
	                findMaximumTime();
	            }
	
	
	            else if (choice == 0){
	                cout << "Returning to main menu" << endl;
	            }
	
	
	            else{
	                cout << "Invalid choice!\n";
	            }
	
	        }
			while (choice != 0);
	    }
	
	    void mainMenu(){
	        int choice;

	        do{
	            cout << "Daily Time Investment Analyzer" << endl;	
	            cout << "1. Display Activities\n";
	            cout << "2. Sorting\n";
	            cout << "3. Searching and Time Analysis\n";
	            cout << "4. How Much Time?\n";
	            cout << "0. Exit\n";
	            cout << "Enter your choice: ";
	            cin >> choice;
	
	            switch (choice){
	            case 1:
	                displayActivities();
	                break;
	
	            case 2:
	                sortingMenu();
	                break;
	
	            case 3:
	                searchingMenu();
	                break;
	
	            case 4:
	                HowMuchTime();
	                break;
	
	            case 0:
	                cout << "Thank you <3 Bye Bye" << endl;
	                break;
	
	            default:
	                cout << "Invalid choice!\n";
	            }
	
	        }
			while (choice != 0);
	    }
};
	
int main(){
	DailyTimeAnalyzer Program;
	Program.inputActivities();
    Program.mainMenu();
		
    return 0;
	}
