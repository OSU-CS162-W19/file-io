#include <iostream>

#include <fstream>

struct student {
  std::string name;
  float gpa;
};

int main(int argc, char const *argv[]) {

  // for (int i = 0 ; i < argc; i++) {
  //   std::cout << "argv[ " << i << "]: " << argv[i] << std::endl;
  // }

  std::ifstream infile;
  infile.open("./testdata.txt");
  if (infile.fail()) {
    std::cerr << "Failed to open testdata.txt" << std::endl;
    return 1;
  }

  int n;
  infile >> n;
  std::cout << "n: " << n << std::endl;

  infile.close();

  return 0;
}
