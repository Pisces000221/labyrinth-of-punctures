#ifndef __lop__Config__
#define __lop__Config__

#include <string>
#include "cocos2d.h"

#define USE_AUDIO 0

namespace lop {

// Constants
extern const std::string title;
namespace res {
    extern const std::string engine_logo_file;
    extern const std::string main_font_l;
    extern const std::string main_font_r;
}

// Variables
extern cocos2d::Size vsize;
void init_vars();

std::string get_font_by_weight(int weight);

cocos2d::Label *label(std::string str, int fontsize, int weight = 2,
    cocos2d::Color3B colour = cocos2d::Color3B::WHITE,
    cocos2d::TextHAlignment alignment = cocos2d::TextHAlignment::LEFT, int linewidth = 0);

}

#endif
