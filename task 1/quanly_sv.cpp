#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
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

class student_list {
public:
  vector<student> student_even;
  list<student> student_odd;

  void load_data_from_database() {
    
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
      getline(cin, name);
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
      }
    }
    for(auto student_entity: student_even) {
      if(code == student_entity.get_student_code()) {
        print_infor_one_user(student_entity);
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_name(string name) {
    for(auto student_entity: student_odd) {
      if(name == student_entity.get_student_name()) {
        print_infor_one_user(student_entity);
      }
    }
    for(auto student_entity: student_even) {
      if(name == student_entity.get_student_name()) {
        print_infor_one_user(student_entity);
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_age(int age) {
    for(auto student_entity: student_odd) {
      if(age == student_entity.get_student_age()) {
        print_infor_one_user(student_entity);
      }
    }
    for(auto student_entity: student_even) {
      if(age == student_entity.get_student_age()) {
        print_infor_one_user(student_entity);
      }
    }
    cout << "not find that" << endl;
  }

  void find_by_point(float point) {
    for(auto student_entity: student_odd) {
      if(point == student_entity.get_student_point()) {
        print_infor_one_user(student_entity);
      }
    }
    for(auto student_entity: student_even) {
      if(point == student_entity.get_student_point()) {
        print_infor_one_user(student_entity);
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
    // load dữ liệu từ database cho trước
    
  }
};

int main() {

  freopen("input.txt", "r", stdin);
  app quanly_sinhvien;
  quanly_sinhvien.run();
}