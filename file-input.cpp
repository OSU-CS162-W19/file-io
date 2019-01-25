#include <iostream>

#include <fstream>

#include <string>

struct student {
  std::string first_name;
  std::string last_name;
  float gpa;
};


void foo(std::ifstream& file) {

}

int main(int argc, char const *argv[]) {

  // for (int i = 0 ; i < argc; i++) {
  //   std::cout << "argv[ " << i << "]: " << argv[i] << std::endl;
  // }

  std::ifstream infile;
  infile.open("./testdata.txt");
  // infile.open(argv[1]);
  if (infile.fail()) {
    std::cerr << "Failed to open testdata.txt" << std::endl;
    return 1;
  }

  int n;
  // std::string str;
  infile >> n /*>> str*/;
  if (infile.fail()) {
    std::cerr << "Couldn't read n" << std::endl;
    return 1;
  }
  std::cout << "n: " << n << std::endl;
  // std::cout << "str: " << str << std::endl;

  char c;
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  std::cout << "done" << std::endl;

  std::string line;
  std::getline(infile, line);
  std::cout << "line: " << line << std::endl;

  foo(infile);

  infile.close();

  std::cout << std::endl << "== Reading students file" << std::endl;

  infile.open("./people-to-read.txt");
  if (infile.fail()) {
    std::cerr << "Failed to open people-to-read.txt" << std::endl;
    return 1;
  }

  int n_students = 10;
  struct student* students = new struct student[10];
  for (int i = 0; i < n_students; i++) {
    infile >> students[i].first_name >> students[i].last_name >> students[i].gpa;
  }

  std::cout << students[4].first_name << "\t" << students[4].gpa << std::endl;

  delete[] students;
  infile.close();

  std::cout << std::endl << "== Reading students file a second time" << std::endl;
  infile.open("./people-to-read.txt");
  if (infile.fail()) {
    std::cerr << "Failed to open people-to-read.txt" << std::endl;
    return 1;
  }

  struct student s;
  while (!infile.eof()) {
    infile >> s.first_name >> s.last_name >> s.gpa;
    if (!infile.fail()) {
      std::cout << s.first_name << "\t" << s.gpa << std::endl;
    }
  }

  return 0;
}
