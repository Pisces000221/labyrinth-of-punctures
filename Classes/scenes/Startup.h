#ifndef __lop__Scenes_Startup__
#define __lop__Scenes_Startup__

#include "cocos2d.h"
#include "Macros.h"

class Startup : public cocos2d::LayerColor
{
public:
    virtual bool init();  
    CREATE_FUNC(Startup);
    SCENE_FUNC(Startup);
};

#endif
