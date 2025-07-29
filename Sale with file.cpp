#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Sale {
    string name;
    int price;
    int quantity;
};

class Inventory {
private:
    vector<Sale> items;

public:
	Inventory(){
		items = loadItemsFromFile();
	}
    void addItem() {
    	int choice;
        Sale item;
        do{
		cout<<"====================="<<endl;
		cout<<" A D D   I T E M S"<<endl;
		cout<<"====================="<<endl;
		cout << "Name: ";
        cin >> item.name;
        cout << "Price: ";
        cin >> item.price;
        cout << "Quantity: ";
        cin >> item.quantity;
        items.push_back(item);
        saveItemsToFile(items);
        cout << "Saved Successfully" << endl;
		cout <<" Enter '1' for continue or '0' for exit: ";
		cin>>choice;
		system("cls");    
	}
	while(choice!=0 && choice==1);
	}
    

    void searchItem() {
        string name;
        cout<<"=========================="<<endl;
		cout<<" S E A R C H   I T E M S"<<endl;
		cout<<"=========================="<<endl;
        cout << "Enter the name of the item to search: ";
        cin >> name;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].name == name) {
                cout << "Name: " << items[i].name << endl;
                cout << "Price: " << items[i].price << endl;
                cout << "Quantity: " << items[i].quantity << endl << endl;
            }
        }
    }

    void sellItem() {
        string name;
        cout<<"====================="<<endl;
		cout<<" S E L L   I T E M S"<<endl;
		cout<<"====================="<<endl;
        cout << "Enter the name of the item to sell: ";
        cin >> name;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].name == name) {
                int soldQuantity;
                cout << "Enter the sold quantity: ";
                cin >> soldQuantity;
                items[i].quantity -= soldQuantity;
                cout << "Remaining Quantity of " << items[i].name << " is: " << items[i].quantity << endl;
            }
        }
    }

    void showAllItems() {
    	cout<<"====================="<<endl;
		cout<<" I T E M S   L I S T"<<endl;
		cout<<"====================="<<endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "Name: " << items[i].name << endl;
            cout << "Price: " << items[i].price << endl;
            cout << "Quantity: " << items[i].quantity << endl << endl;
        }
    }
    
    void saveItemsToFile(const vector<Sale>&items){
    	ofstream outputFile("inventory.txt");  // open the file for writing 
    	if(outputFile.is_open()){
    		for(int i=0;i<items.size();++i){
    			outputFile <<items[i].name<<" "<<items[i].price<<" "<<items[i].quantity<<endl;
			}
			outputFile.close();  // close the file after writing
			cout<<"Items saved to file successfully."<<endl;
			
		}
		else{
			cout<<"Error: Unable to open the file for writing."<<endl;
		}
	}
	
	vector<Sale> loadItemsFromFile() {
    vector<Sale> items;
    ifstream inputFile("inventory.txt"); // Open the file for reading
    if (inputFile.is_open()) {
        Sale item;
        while (inputFile >> item.name >> item.price >> item.quantity) {
            items.push_back(item);
        }
        inputFile.close(); // Close the file after reading
        cout << "Items loaded from file successfully." << endl;
    } else {
        cout << "Error: Unable to open the file for reading." << endl;
    }
    return items;
}
};

int main() {
    Inventory inventory;
    while (true) {
        int choice;
        cout<< "================================================"<<endl;
        cout<< " S A L E S   M A N A G E M E N T   S Y S T E M"<<endl;
        cout<< "================================================"<<endl;
        cout << "1. Add items" << endl;
        cout << "2. Search items" << endl;
        cout << "3. Sold items" << endl;
        cout << "4. Show all items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
		system("cls");
        switch (choice) {
            case 1:
                inventory.addItem();
                
                break;
            case 2:
                inventory.searchItem();
                break;
            case 3:
                inventory.sellItem();
                break;
            case 4:
                inventory.showAllItems();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid Input" << endl << endl;
                break;
        }
    }
    return 0;
}
