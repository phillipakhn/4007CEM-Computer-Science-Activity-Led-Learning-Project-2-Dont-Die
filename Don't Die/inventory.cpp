#include <iostream>
#include <list>
#include <vector>
#include <string>


using namespace std;


struct Item{
    string name; 
    int cost; 
    int use; 
    int ability; 
};

int main()
{
    int item;
    item = knife{
        "Knife", //This item name is 'Short Sword'.
        25, //Cost 25 gold pieces.
        3, //Purpose 3.
        5 // Damage +5 attack.
    };

    string entry; // commands.
    vector<string> Equipment = { "<Empty>", "<Empty>", "<Empty>", "<Empty>","<Empty>" }; //Current equipment.
    vector<string> Inventory = {Knife.name}; //Inventory.
    string Slots = { "Helmet", "Chest", "Gloves", "Pants", "Shoes" }; //Inventory Spots

    while (true){
        cin >> input;
        if (input == "item"){
            for (int i = 0; i < 5; i++){
                cout << item[i];
                if (Equipment[i] == "<Empty>")
                cout << " " << Item[i] << endl;
            }
        }

        if (input == "on"){
            cout << "What would you like to wear? ";
            cin >> input;
            for (int i = 0; i < item.size(); i++){
                if (input == item[i]){
                    //But how to identify what kind of item it is? ##########
                    cout << "Successfully equiped!" << endl;
                }
            }
        }
        
        

        if(input == "inv"){
            for (int i = 0; i < item.size(); i++){
                cout << "|#############################################################" << endl;
                cout << "|  " << item[i] << endl;
                cout << "|  Carried items " << item.size() << " / " << 20 << endl;
                cout << "|#############################################################" << endl;
            }
        }

    }
    return 0;   
}