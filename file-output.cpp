#include <iostream>

#include <fstream>


int main(int argc, char const *argv[]) {

  std::ofstream outfile;
  outfile.open("./written-people.txt", std::ofstream::app);

  outfile << "Darth Vader 1.0" << std::endl;
  outfile.close();

  return 0;
}
