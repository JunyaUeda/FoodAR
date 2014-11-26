#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

using namespace std;

class FileManager {

/*method*/
public:

private:
	FileManager();
    void addFileName(string filepath);  
    string getFileName(int index);
/*property*/
private:
    vector<string> _fileNames;
};

#endif // FILEMANAGER_H
