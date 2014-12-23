#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "../Param/matSet.h"

class InputManager {

/*method*/
public:
    static InputManager& getInstance();
    void updateCurrentSrc(Mat& bgrImg) {
        _currentSrcSet.setBgr(bgrImg);
    }

    Mat currentBGRMat() {
        return _currentSrcSet.bgr();
    }
    MatSet& currentSrcSet() {
        return _currentSrcSet;
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
