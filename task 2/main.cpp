#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T> class vectorClass {
public:
    // arr is the integer pointer
    // which stores the address of our vector
    T* arr;
 
    // capacity is the total storage
    // capacity of the vector
    int capacity;
 
    // current is the number of elements
    // currently present in the vector
    int current;
 
public:
    // Default constructor to initialise
    // an initial capacity of 1 element and
    // allocating storage using dynamic allocation
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    // destructor to deallocate storage allocated by dynamic
    // allocation to prevent memory leak
    ~vectorClass() { delete[] arr; }
 
    // Function to add an element at the last
    void push(T data)
    {
 
        // if the number of elements is equal to the
        // capacity, that means we don't have space to
        // accommodate more elements. We need to double the
        // capacity
        if (current == capacity) {
            T* temp = new T[2 * capacity];
 
            // copying old array elements to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
 
            // deleting previous array
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
 
        // Inserting data
        arr[current] = data;
        current++;
    }
 
    // function to add element at any index
    void push(T data, int index)
    {
 
        // if index is equal to capacity then this
        // function is same as push defined above
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
 
    // function to extract element at any index
    T get(int index)
    {
        // if index is within the range
        if (index < current)
            return arr[index];
        // if index is not within range
        // return -1;
    }
 
    // function to delete last element
    void pop() { current--; }
 
    // function to get size of the vector
    int size() { return current; }
 
    // function to get capacity of the vector
    int getcapacity() { return capacity; }
 
    // function to print array elements
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
 
class item {
private:
  string code_item;
  string name_item;
  string name_nsx;
public:
  item() {

  };
  item(string code, string name, string nsx) {
    code_item = code;
    name_item = name;
    name_nsx = nsx;
  }

  void set_code_item(string code) {
    code_item = code;
  }
  void set_name_item(string name) {
    name_item = name;
  }
  void set_name_nsx(string nsx) {
    name_nsx = nsx;
  }

  string get_code_item() {
    return code_item;
  }
  string get_name_item() {
    return name_item;
  }
  string get_name_nsx() {
    return name_nsx;
  }
};

class bill {
private: 
  string code_bill;
  string code_item;
  string type; // sell or buy
  int num;
  string day_sell_buy;
  int price;
public: 
  bill() {

  }

  bill(string bill, string item, string t, int n, string day, int p) {
    code_bill = bill;
    code_item = item;
    type = t;
    num = n;
    day_sell_buy = day;
    price = p;
  } 

  string get_code_bill() {
    return code_bill;
  }
  string get_code_item() {
    return code_item;
  }
  string get_type() {
    return type;
  }
  int get_num() {
    return num;
  }
  string get_day_sell_buy() {
    return day_sell_buy;
  }
  int get_price() {
    return price;
  }
};

class store {
private:
  vectorClass<item> item_list;
  vectorClass<bill> bill_list;
public:
  store() {

  }

  void read_item_list() {
    string path = "item_list.txt";
    ifstream file(path);
    string code_item, name_item, name_nsx;
    if(file.is_open()) {
      while(!file.eof()) {
        file >> code_item >> name_item >> name_nsx;
        cout << code_item << ' ' << name_item << ' ' << name_nsx << endl;
        item item_u(code_item, name_item, name_nsx);
        item_list.push(item_u);
      }
    }
    else {
      cout << "can't open this file" << endl;
    }
    file.close();
  }

  void read_bill_list() {
    string path = "bill_list.txt";
    ifstream file(path);
    string code_bill, code_item, type, day_sell_buy;
    int num, price;
    if(file.is_open()) {
      while(!file.eof()) {
        file >> code_bill >> code_item >> type >> num >> day_sell_buy >> price;
        cout << code_bill << ' ' << code_item << ' ' << type << ' ' << num << ' ' << day_sell_buy << ' ' << price << endl;
        bill bill_u(code_bill, code_item, type, num, day_sell_buy, price);
        bill_list.push(bill_u);
      }
    }
    else {
      cout << "can't open this file" << endl;
    }
    file.close();
  }

  void read_data() {
    cout << "choose option" << endl;
    cout << "1. read item list from file" << endl;
    cout << "2. read bill list from file" << endl;
    int option; cin >> option;
    cout << "you choose: option " << option << endl; 
    if(option == 1) {
      read_item_list();
    }
    else {
      read_bill_list();
    }
  }

  void export_item_list() {
    string path = "export_item_list.txt";
    ofstream out(path);
    // cout << item_list.get(0).get_code_item();
    for(int i = 0; i < item_list.size(); ++i) {
      // cout << "hello" << endl;
      item item_t = item_list.get(i);
      string code_item = item_t.get_code_item();
      string name_item = item_t.get_name_item();
      string name_nsx = item_t.get_name_nsx();
      out << code_item << ' ' << name_item << ' ' << name_nsx << endl;
    }
    out.close();
  }

  void export_bill_list() {
    string path = "export_bill_list.txt";
    ofstream out(path);
    for(int i = 0; i < bill_list.size(); ++i) {
      bill bill_t = bill_list.get(i);
      string code_bill = bill_t.get_code_bill();
      string code_item = bill_t.get_code_item();
      string type = bill_t.get_type();
      int num = bill_t.get_num();
      string day_sell_buy = bill_t.get_day_sell_buy();
      int price = bill_t.get_price();
      out << code_bill << ' ' << code_item << ' ' << type << ' ' << num << ' ' << day_sell_buy << ' ' << price << endl;
    }
    out.close();
  }

  void export_data() {
    cout << "choose option" << endl;
    cout << "1. export item list to file" << endl;
    cout << "2. export bill list to file" << endl;
    int option; cin >> option;
    cout << "you choose option: " << option << endl;
    if(option == 1) {
      export_item_list(); 
    }
    else {
      export_bill_list();
    }
  }

};


int main() {

  store store_manager;
  store_manager.read_data();
  store_manager.export_data();

  return 0;
}