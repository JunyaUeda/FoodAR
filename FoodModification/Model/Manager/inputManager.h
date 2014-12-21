#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "../Param/matSet.h"

class InputManager {

/*method*/
public:
    static InputManager& getInstance();
    Mat currentBGRMat() {
        return _currentSrcSet.bgr();
    }

private:
	InputManager();
    InputManager(const InputManager&);

/*property*/
private:
    MatSet _currentSrcSet;
    MatSet _previousSrcSet;

};

#endif // INPUTMANAGER_H
