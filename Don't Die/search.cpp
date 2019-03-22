#include <string>
#include <iostream>

class Item 
{
  public:
   Item(void) {}
   Item(void) {}
   Item(std::string new_name) 
   {
      my_name=new_name;
   }
   void setName(std::string new_name) 
   {
      my_name= new_name;
   }
   std::string getName(void) 
   {
      return my_name;
   }
  private:
   std::string my_name;
};  

class Item_Manager 
{
  public:
   Item_Manager(void) {}
   Item_Manager(void) {}  
   void addItem(Item * my_item, int num_items) 
   {
      my_item_counters.insert( std::pair<std::string,int>(Item.getName(),num_items) );
   }
   int getNumItems(std::string my_item_name) 
   {
      return my_item_counters[my_item_name];
   }
  private: 
   std::map<std::string, int> my_item_counts;
};

int main () {
   Item * test_item = new Item("shoe");
   Item * test_item2 = new Item("hat");
   Item_Manager * my_manager = new Item_Manager();

   my_manager->addItem(test_item, 5);
   my_manager->addItem(test_item2,10);
   std::cout << "I have " << my_manager->getNumItems(test_item->getName())
             << " " << test_item->getName() << " and " 
             << my_manager->getNumItems(test_item2->getName())
             << " " << test_item2->getName() << std::endl;

   delete test_item;
   delete test_item2;
   delete my_manager;
}