#include "Config.hpp"
#include "cocos2d.h"
using namespace cocos2d;

namespace lop {

// Constants
const std::string title = "Labyrinth of Punctures";
namespace res {
    const std::string engine_logo_file = "images/cocos2dx_portrait.png";
    const std::string main_font_l = "fonts/HeroLight.otf";
    const std::string main_font_r = "fonts/Hero.otf";
}

// Variables
cocos2d::Size vsize;
void init_vars()
{
    vsize = Director::getInstance()->getVisibleSize();
    CCLOG("visible size: %d x %d", (int)(vsize.width), (int)(vsize.height));
}

std::string get_font_by_weight(int weight)
{
    if (weight == 1) return res::main_font_l;
    else if (weight == 2) return res::main_font_r;
    else return res::main_font_r;
}

Label *label(std::string str, int fontsize, int weight,
    Color3B colour, TextHAlignment alignment, int linewidth)
{
    Label *r = Label::createWithTTF(
        TTFConfig(get_font_by_weight(weight).c_str(), fontsize),
        str, alignment, linewidth);
    r->setColor(colour);
    return r;
}

}
