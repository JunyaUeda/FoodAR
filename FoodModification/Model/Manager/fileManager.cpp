#include "fileManager.h"

FileManager::FileManager() {
    _fileNames.push_back("../FoodModification/Settings.xml");
}

string FileManager::getFileName(int index) {
	return _fileNames.at(index);
}
