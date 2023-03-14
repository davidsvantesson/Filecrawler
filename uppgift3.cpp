#include <algorithm>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void search_files(string search_path, search_string) // The path to the directory
{
  if (!exists(dir_path(p)))
  {
    for ( itr-> (search_path); itr != end_itr; ++itr)
    {
      if (is_directory(itr->path()))
      {
        if (itr->path().filename() ! = "." && itr->path() filename() = "..")
        {
          search_files(itr->path(), search_string)
        }
      }
    }
    else if (is_regular_file_name(p))
    {
      ifstream file(p.string());
      std::string word;
      std::string line;
      while (getline(file, line))
      {
        if (line.find(search_string) != string::npos)
        {
          cout << "The string was found in: " << p.string() << endl;
          break;
        }
      }
      else
      {
        cout << "An error occured, the file can't be opemed"
      }
    }
  }
}
  int main(int argc, char **argv)
  {
    string search_path = "../Testdata";
    string search_string
        string line;
    cout << "Enter the string you want to find" << endl;
    cin >> string;

    search_files(path(search_path), search_string) return 0;
  }
