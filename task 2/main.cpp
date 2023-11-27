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

  void input_item() {
    cout << "enter the number of item" << endl;
    int num_item; cin >> num_item;
    string code_item, name_item, name_nsx;
    for(int i = 0; i < num_item; ++i) {
      cin >> code_item >> name_item >> name_nsx;
      cout << code_item << ' ' << name_item << ' ' << name_nsx << endl;
      item item_u(code_item, name_item, name_nsx);
      item_list.push(item_u);
    }
  }

  void export_item() {
    
  }

  void input_export() {
    cout << "choose option" << endl;
    cout << "1. input item" << endl;
    cout << "2. export item" << endl; 
    int option; cin >> option;
    cout << "you choose: " << option << endl; 
    if(option == 1) {
      input_item();
    }
    else {
      export_item();
    }
  }

  void display_per_item(item item_t) {
    string code_item = item_t.get_code_item();
    string name_item = item_t.get_name_item();
    string name_nsx = item_t.get_name_nsx();
    cout << code_item << ' ' << name_item << ' ' << name_nsx << endl;
  }

  void display_all_item() {
    for(int i = 0; i < item_list.size(); ++i) {
      display_per_item(item_list.get(i));
    }
  }

  void statistic_num_item() {
    vectorClass<string> item_unique;
    for(int i = 0; i < item_list.size(); ++i) {
      item item_t = item_list.get(i);
      auto name_item = item_t.get_name_item();
      if(item_unique.size() == 0) {
        item_unique.push(name_item);
      }
      else {
        for(int j = 0; j < item_unique.size(); ++j) {
          if(item_unique.get(j) == name_item) {
            break;
          }
          else {
            item_unique.push(name_item);
          }
        }
      }
    }

    for(int j = 0; j < item_unique.size(); ++j) {
      string name = item_unique.get(j);
      int cnt = 0;
      for(int i = 0; i < item_list.size(); ++i) {
        item item_t = item_list.get(i);
        auto name_item = item_t.get_name_item();
        if(name == name_item) cnt++;
      }
      cout << name << ": " << cnt << endl;
    }



  }

};


int main() {

  store store_manager;
  // store_manager.read_data(); // đọc thông tin quản lý của store từ file -> program
  // store_manager.export_data(); // ghi thông tin quản lý của store vào file
  // store_manager.display_all_item(); // hiển thị toàn bộ danh sách mặt hàng hiện có 
  // store_manager.input_export(); // nhập xuất các mặt hàng
  // store_manager.statistic_num_item(); // thống kê số lượng mặt hàng tồn của mỗi cửa hàng

  // cout << "choose option:" << endl;
  // cout << "1. read management information of store from file to program" << endl;
  // cout << "2. export management information of store to file" << endl;
  // cout << "3. show the entire list of available items" << endl;
  // cout << "4. input and export item" << endl;
  // cout << "5. statistics on the number of items in stock for store" << endl;

  // int option; cin >> option;

  while(true) {
    cout << "choose option:" << endl;
    cout << "1. read management information of store from file to program" << endl;
    cout << "2. export management information of store to file" << endl;
    cout << "3. show the entire list of available items" << endl;
    cout << "4. input and export item" << endl;
    cout << "5. statistics on the number of items in stock for store" << endl;
    cout << "6. exit" << endl;
    int option; cin >> option;
    cout << "you choose option: " << option << endl;

    if(option == 1) {
      store_manager.read_data();
    }
    else if(option == 2) {
      store_manager.export_data();
    }
    else if(option == 3) {
      store_manager.display_all_item();
    }
    else if(option == 4) {
      store_manager.input_export();
    }
    else if(option == 5) {
      store_manager.statistic_num_item();
    }
    else if(option == 6) {
      break;
    }
  }


  return 0;
}