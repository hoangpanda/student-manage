#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// quan ly sinh vien 
class student {
private:
  int student_code;
  string student_name;
  int student_age;
  float student_point;

public:
  student(int code=-1, string name="", int age=-1, float point=-1) {
    student_code = code;
    student_name = name;
    student_age = age;
    student_point = point;
  }

  int get_student_code() {
    return student_code;
  }

  string get_student_name() {
    return student_name;
  }

  int get_student_age() {
    return student_age;
  }

  float get_student_point() {
    return student_point;
  }

};




template<typename a, typename b>
bool operator < (a& student_1, b& student_2) {
  // return true;
  float point_1 = student_1.get_student_point();
  float point_2 = student_2.get_student_point();
  return point_1 <= point_2;
}



class student_list {
public:
  vector<student> student_even;
  list<student> student_odd;

  void load_data_from_database() {
    string path = "input.txt";
    ifstream file(path);
    if(file.is_open()) {
      while(!file.eof()) {
        int code, age;
        string name;
        float point;
        file >> code >> name >> age >> point;
        student student_infor(code, name, age, point);
        add_student_infor(student_infor);
      }
    } 
  }

  void add_student_infor(student student_infor) {
    auto student_code = student_infor.get_student_code();
    if(student_code % 2 == 0) 
      student_even.push_back(student_infor);
    else 
      student_odd.push_back(student_infor);
  }

  void print_infor_one_user(student student_infor) {
    int code = student_infor.get_student_code();
    string name = student_infor.get_student_name();
    int age = student_infor.get_student_age();
    float point = student_infor.get_student_point();
    cout << code << ' ' << name << ' ' << age << ' ' << point << endl;
  }


  void get_input_from_user() {
    int num_input;
    cout << "please enter the number of student" << endl;
    cin >> num_input;
    cout << "num_input:" << num_input << endl;

    for(int i = 0; i < num_input; ++i) {
      cout << "please enter student info include: code, name, age, point" << endl;
      int code, age;
      string name;
      float point;
      cin >> code;
      // getline(cin, name);
      cin >> name;
      cin >> age >> point;
      student student_infor(code, name, age, point);
      add_student_infor(student_infor);      
    }
  }

  void print_all_data_from_database() {
    for(int i = 0; i < student_even.size(); ++i) {
      print_infor_one_user(student_even[i]);
    }

    for(auto student_entity: student_odd) {
      print_infor_one_user(student_entity);
    }
  }

  void export_all_data_from_database() {
    string output_path = "output.txt";
    ofstream out(output_path);
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      int code = student_infor.get_student_code();
      string name = student_infor.get_student_name();
      int age = student_infor.get_student_age();
      float point = student_infor.get_student_point();
      out << code << ' ' << name << ' ' << age << ' ' << point << endl;
    }

    for(auto student_entity: student_odd) {
      auto student_infor = student_entity;
      int code = student_infor.get_student_code();
      string name = student_infor.get_student_name();
      int age = student_infor.get_student_age();
      float point = student_infor.get_student_point();
      out << code << ' ' << name << ' ' << age << ' ' << point << endl;
    }
    out.close();
  } // xuất danh sách ra file txt

  int find_max_by_student_code() {
    int max_v = -1;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      int code = student_infor.get_student_code();
      max_v = max(max_v, code);
    }
    for(auto student_entity: student_odd) {
      int code = student_entity.get_student_code();
      max_v = max(max_v, code);
    }
    return (max_v, max_v);
  }

  int find_max_by_student_age() {
    int max_v = -1;
    int code_max = -1;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      int age = student_infor.get_student_age();
      int code = student_infor.get_student_code();
      if(age > max_v) {
        max_v = age;
        code_max = code; 
      } 
    }
    for(auto student_entity: student_odd) {
      int age = student_entity.get_student_age();
      int code = student_entity.get_student_code();
      if(age > max_v) {
        max_v = age;
        code_max = code; 
      } 
    }
    return (code_max, max_v);
  } 

  float find_max_by_student_point() {
    float max_v = -1;
    int code_max = -1;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      float point = student_infor.get_student_point();
      int code = student_infor.get_student_code();
      if(point > max_v) {
        max_v = point;
        code_max = code;
      }
    }
    for(auto student_entity: student_odd) {
      float point = student_entity.get_student_point();
      int code = student_entity.get_student_code();
      if(point > max_v) {
        max_v = point;
        code_max = code;
      }
    }
    return (code_max, max_v);
  }

  void find_max() {
    // ma so sinh vien, age, point
    cout << "choose option:" << endl;
    cout << "1. find max by student code" << endl;
    cout << "2. find max by student age" << endl;
    cout << "3. find max by student point" << endl;
    int option; cin >> option;

    if(option == 1) {
      int code, max_code = find_max_by_student_code();
      cout << code << ' ' << max_code << endl;
    }
    else if(option == 2) {
      int code, max_age = find_max_by_student_age();
      cout << code << ' ' << max_age << endl;
    } 
    else {
      int code, max_point = find_max_by_student_point();
      cout << code << ' ' << max_point << endl;
    }
  } // tìm max

  int find_min_by_student_code() {
    int max_v = 99999;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      int code = student_infor.get_student_code();
      max_v = min(max_v, code);
    }
    for(auto student_entity: student_odd) {
      int code = student_entity.get_student_code();
      max_v = min(max_v, code);
    }
    return (max_v, max_v);
  }

  int find_min_by_student_age() {
    int max_v = 99999;
    int code_max = 99999;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      int age = student_infor.get_student_age();
      int code = student_infor.get_student_code();
      if(age < max_v) {
        max_v = age;
        code_max = code; 
      } 
    }
    for(auto student_entity: student_odd) {
      int age = student_entity.get_student_age();
      int code = student_entity.get_student_code();
      if(age < max_v) {
        max_v = age;
        code_max = code; 
      } 
    }
    return (code_max, max_v);
  } 

  float find_min_by_student_point() {
    float max_v = 9999999;
    int code_max = 999999999;
    for(int i = 0; i < student_even.size(); ++i) {
      auto student_infor = student_even[i];
      float point = student_infor.get_student_point();
      int code = student_infor.get_student_code();
      if(point < max_v) {
        max_v = point;
        code_max = code;
      }
    }
    for(auto student_entity: student_odd) {
      float point = student_entity.get_student_point();
      int code = student_entity.get_student_code();
      if(point < max_v) {
        max_v = point;
        code_max = code;
      }
    }
    return (code_max, max_v);
  }

  void find_min() {
    // ma so sinh vien, age, point
    cout << "choose option:" << endl;
    cout << "1. find min by student code" << endl;
    cout << "2. find min by student age" << endl;
    cout << "3. find min by student point" << endl;
    int option; cin >> option;

    if(option == 1) {
      int code, max_code = find_min_by_student_code();
      cout << code << ' ' << max_code << endl;
    }
    else if(option == 2) {
      int code, max_age = find_min_by_student_age();
      cout << code << ' ' << max_age << endl;
    } 
    else {
      int code, max_point = find_min_by_student_point();
      cout << code << ' ' << max_point << endl;
    }
  } // tìm min 


  void find_by_code(int code) {
    for(auto student_entity: student_odd) {
      if(code == student_entity.get_student_code()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    for(auto student_entity: student_even) {
      if(code == student_entity.get_student_code()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_name(string name) {
    for(auto student_entity: student_odd) {
      if(name == student_entity.get_student_name()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    for(auto student_entity: student_even) {
      if(name == student_entity.get_student_name()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_age(int age) {
    for(auto student_entity: student_odd) {
      if(age == student_entity.get_student_age()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    for(auto student_entity: student_even) {
      if(age == student_entity.get_student_age()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_point(float point) {
    for(auto student_entity: student_odd) {
      if(point == student_entity.get_student_point()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    for(auto student_entity: student_even) {
      if(point == student_entity.get_student_point()) {
        print_infor_one_user(student_entity);
        return;
      }
    }
    cout << "not find that" << endl;
  }

  void find() {
    cout << "choose option" << endl;
    cout << "1. find by code" << endl;
    cout << "2. find by name" << endl;
    cout << "3. find by age" << endl;
    cout << "4. find by point" << endl;
    int option; cin >> option;

    if(option == 1) {
      int code; cin >> code;
      find_by_code(code);
    }
    else if(option == 2) {
      string name; getline(cin, name);
      find_by_name(name);
    }
    else if(option == 3) {
      int age; cin >> age;
      find_by_age(age);
    }
    else {
      float point; cin >> point;
      find_by_point(point);
    }
  } // tìm kiếm 


  void sort_student() {
    /*
    vector<student> student_even;
    list<student> student_odd;
     */
    cout << "choose option" << endl;
    cout << "1. sorted by odd student code" << endl;
    cout << "2. sorted by even student code" << endl;
    int option; cin >> option;
    cout << "you choose option: " << option << endl;


    if(option == 1) {
        // sort(student_even.begin(), student_even.end());
      student_odd.sort();
      cout << "sort complete" << endl;
    }
    else {
      student_odd.sort();
      cout << "sort complete" << endl;
    }
  }
};

class app {
  /*
  1. nhập input từ bàn phím
  2. xuất danh sách ra file txt
  3. sắp xếp danh sách
  4. thao tác tìm max, min, tìm kiếm 
  */
public:
  void run() {
      /* 
      nhập danh sách - option 1: function get_input_from_user();
      xuất danh sách ra file txt - option 2: function export_all_data_from_database();
      sắp xếp danh sách - option 3: function sort_student();
      tìm max theo 1 trường dữ liệu - option 4: function find_max()
      tìm min theo 1 trường dữ liệu - option 5: function find_min()
      tìm 1 student cụ thể theo 1 trường - option 6: function find()
      thoát chương trình - option 7: break
      */
      student_list student_manage_entity;
      student_manage_entity.load_data_from_database(); // load data from database

      // create menu
      while(true) {
        cout << "choose option" << endl;
        cout << "1. input list" << endl;
        cout << "2. output list" << endl;
        cout << "3. sort list" << endl;
        cout << "4. find max" << endl;
        cout << "5. find min" << endl;
        cout << "6. find" << endl;
        cout << "7. exit" << endl;
        int option; cin >> option;
        cout << "you choose: " << option << endl;

        if(option==1) {
          student_manage_entity.get_input_from_user();
        } 
        else if(option==2) {
          student_manage_entity.export_all_data_from_database();
        }
        else if(option == 3) {
          student_manage_entity.sort_student();
        }
        else if(option==4) {
          student_manage_entity.find_max();
        }
        else if(option==5) {
          student_manage_entity.find_min();
        }
        else if(option == 6) {
          student_manage_entity.find();
        }
        else {
          // option == 7
          cout << "exit from the app" << endl;
          break;
        }
      }

    }
};


int main() {
  app quanly_sinhvien;
  quanly_sinhvien.run();
}