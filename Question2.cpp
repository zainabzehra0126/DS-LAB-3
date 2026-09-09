#include <iostream>
#include <string>
using namespace std;
	
class Career{
	private:
	    string field[9];
	    int rank[9];
	    int n;
	
	public:
	    CareerChoice(){
	        n = 0;
	    }
	
	    void selectPath(){
	        int choice;
	
	        cout << "Choose your career path:" << endl;
	        cout << "1. Academia" << endl;
	        cout << "2. Industry" << endl;
	        cout << "Enter choice: ";
	        cin >> choice;
	
	        if(choice == 1){
	            academia();
	        }
	        else if(choice == 2){
	            industry();
	        }
	        else{
	            cout << "Invalid choice." << endl;
	        }
	    }
	
	    void academia(){
	        n = 5;
	
	        field[0] = "University Professor/Lecturer";
	        field[1] = "Research Scientist";
	        field[2] = "Research Assistant";
	        field[3] = "PhD Researcher";
	        field[4] = "Academic Researcher";
	
	        cout << "Why would you choose Academia?" << endl;
	        cout << "Enter one line explaining your reason: ";
	        cin.ignore();
	        string reason;
	        getline(cin, reason);
	
	        cout << "Enter ranking from 1 to 5:" << endl;
	
	        for(int i = 0; i < n; i++){
	            cout << "Rank for " << field[i] << ": ";
				cin >> rank[i];
	        }
	
	        cout << "Academia selected successfully." << endl;
	        displayRanking();
	        searchMenu();
	    }
	
	    void industry(){
	        n = 9;
	
	        field[0] = "AI Engineer";
	        field[1] = "Software Engineer";
	        field[2] = "Data Scientist";
	        field[3] = "Machine Learning Engineer";
	        field[4] = "DevOps Engineer";
	        field[5] = "Data Engineer";
	        field[6] = "Cybersecurity Engineer";
	        field[7] = "Project Manager";
	        field[8] = "Cloud Engineer";
	
	        cout << "Why would you choose Industry?" << endl;
	        cout << "Enter one line explaining your reason: ";
	        cin.ignore();
	        string reason;
	        getline(cin, reason);
	
	        cout << "Enter ranking from 1 to 9:" << endl;
	
	        for(int i = 0; i < n; i++){
	            cout << "Rank for " << field[i] << ": ";
	            cin >> rank[i];
	        }
	
	        cout << "Industry selected successfully." << endl;
	        displayRanking();
	        searchMenu();
	    }
	
	    void displayRanking(){
	        cout << "Career Rankings" << endl;
	
	        for(int i = 0; i < n; i++){
				cout << rank[i] << field[i] << endl;
	        }
	    }
	
	    void linearSearch(int target){
	        int comparisons = 0;
	        bool found = false;
	
	        for(int i = 0; i < n; i++){
	            comparisons++;
	
	            if(rank[i] == target){
	                cout << "Linear Search: " << field[i] << " has rank " << target << endl;
	                cout << "Comparisons: " << comparisons << endl;
	                found = true;
	                break;
	            }
	        }
	
	        if(!found){
	            cout << "Rank not found." << endl;
	        }
	    }
	
	    void sortByRank(){
	        for(int i = 0; i < n - 1; i++){
	            
				for(int j = 0; j < n - i - 1; j++){
	                if(rank[j] > rank[j + 1]){
	                    int tempRank = rank[j];
	                    rank[j] = rank[j + 1];
	                    rank[j + 1] = tempRank;
	
	                    string tempField = field[j];
	                    field[j] = field[j + 1];
	                    field[j + 1] = tempField;
	                }
	            }
	        }
	    }
	
	    void binarySearch(int target){
	        sortByRank();
	
	        int low = 0;
	        int high = n - 1;
	        int comparisons = 0;
	
	        while(low <= high){
	            int mid = (low + high) / 2;
	            comparisons++;
	
	            if(rank[mid] == target){
	                cout << "Binary Search: " << field[mid] << " has rank " << target << endl;
	                cout << "Comparisons: " << comparisons << endl;
	                return;
	            }
	            else if(rank[mid] < target){
	                low = mid + 1;
	            }
	            else{
	                high = mid - 1;
	            }
	        }
	        cout << "Rank not found." << endl;
	    }
	
	    void interpolationSearch(int target){
	        sortByRank();
	
	        int low = 0;
	        int high = n - 1;
	        int comparisons = 0;
	
	        while(low <= high && target >= rank[low] && target <= rank[high]){
	            if(rank[high] == rank[low]){
	                comparisons++;
	
	                if(rank[low] == target){
	                    cout << "Interpolation Search: " << field[low] << " has rank " << target << endl;
	                    cout << "Comparisons: " << comparisons << endl;
	                    return;
	                }
	                break;
	            }
	
	            int pos = low + ((target - rank[low]) * (high - low)) / (rank[high] - rank[low]);
	
	            comparisons++;
	
	            if(rank[pos] == target){
	                cout << "Interpolation Search: " << field[pos] << " has rank " << target << endl;
	                cout << "Comparisons: " << comparisons << endl;
	                return;
	            }
	            else if(rank[pos] < target){
	                low = pos + 1;
	            }
	            else{
	                high = pos - 1;
	            }
	        }
	
	        cout << "Rank not found." << endl;
	    }
	
	    void searchMenu(){
	        int choice;
	        int target;
	
	        do{
	            cout << "Search Menu" << endl;
	            cout << "1. Linear Search" << endl;
	            cout << "2. Binary Search" << endl;
	            cout << "3. Interpolation Search" << endl;
	            cout << "4. All Search Techniques" << endl;
	            cout << "0. Exit" << endl;
	            cout << "Enter choice: ";
	            cin >> choice;
	
	            if(choice >= 1 && choice <= 4){
	                cout << "Enter rank to search: ";
	                cin >> target;
	            }
	
	            if(choice == 1){
	                linearSearch(target);
	            }
	            else if(choice == 2){
	                binarySearch(target);
	            }
	            else if(choice == 3){
	                interpolationSearch(target);
	            }
	            else if(choice == 4){
	                linearSearch(target);
	                binarySearch(target);
	                interpolationSearch(target);
	            }
	            else if(choice != 0){
	                cout << "Invalid choice." << endl;
	            }
	        }
			while(choice != 0);
	    }
	
	    void run(){
	        selectPath();
	    }
};
	
int main(){
	Career option;
	option.run();
	return 0;
}
