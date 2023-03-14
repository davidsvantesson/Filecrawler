#include <algorithm>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void search_files(string search_path, string search_string) // The path to the directory
{
  if (!fs::exists(search_path))
  {
    fs::directory_iterator itr(search_path);
    for ( ; itr != fs::end(itr); ++itr)
    {
      if (is_directory(itr->path()))
      {
        if (itr->path().string() != "." && itr->path().string() != "..")
        {
          search_files(itr->path().string(), search_string);
        }
      }
    }
  }
  else if (fs::is_regular_file(search_path))
  {
    ifstream file(search_path);
    std::string word;
    std::string line;
    while (getline(file, line))
    {
      if (line.find(search_string) != string::npos)
      {
        cout << "The string was found in: " << search_path << endl;
        break;
      }
    }
/* Här skulle du hantera om filen inte är öppnad, se https://cplusplus.com/reference/fstream/ifstream/is_open/ */
/*
      else
      {
        cout << "An error occured, the file can't be opemed";
      }
    }
*/
  }
}

int main(int argc, char **argv)
{
  string search_path = "../Testdata";
  string search_string;
  cout << "Enter the string you want to find" << endl;
  cin >> search_string;
  search_files(search_path, search_string);
  return 0;
}
