#ifndef __lop__Scenes_Splash__
#define __lop__Scenes_Splash__

#include "cocos2d.h"
#include "Macros.h"

class Splash : public cocos2d::LayerColor
{
public:
    virtual bool init();  
    CREATE_FUNC(Splash);
    SCENE_FUNC(Splash);

    void goOn(float dt);
};

#endif
