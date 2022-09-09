#include <iostream>
#include <list>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

int main() {

    cout << "---FileSystem---" << endl;

    auto recursiveGetFileNamesByExtension = [](const fs::path& path, const string& extension)
    {
        list<string> myList;
        for(auto& p: fs::recursive_directory_iterator(path))
            if(p.is_regular_file() && p.path().extension().compare(extension) == 0)
                myList.push_back(p.path().filename().string());

        return myList;
    };

    list<string> myList = recursiveGetFileNamesByExtension("films",".txt");

    for(const auto& e:myList)
        cout << e << endl;

    cout << "---Bye, bye!---" << endl;
    return 0;
}
