#pragma once

#include "wx/wx.h"

#define L1_100_COLOR AudaColor::L1_100
#define L1_75_COLOR AudaColor::L1_75
#define L1_50_COLOR AudaColor::L1_50
#define L2_100_COLOR AudaColor::L2_100
#define L2_75_COLOR AudaColor::L2_75
#define L2_50_COLOR AudaColor::L2_50
#define L3_100_COLOR AudaColor::L3_100
#define L3_75_COLOR AudaColor::L3_75
#define OUTLINE_COLOR AudaColor::outlineCommon


#define TEST_GREEN AudaColor::test_Green
#define TEST_RED AudaColor::test_Red
#define TEST_BLUE AudaColor::test_Blue
#define TEST_YELLOW AudaColor::test_Yellow

// Color palette
class AudaColor {
public:
    static wxColour L1_100; //33
    static wxColour L1_75; //40
    static wxColour L1_50; //45
    static wxColour L2_100; //53
    static wxColour L2_75; //72
    static wxColour L2_50; //111
    static wxColour L3_100; //116
    static wxColour L3_75; //214

    // access color by name
    static wxColour &outlineCommon;
    
    // debug test color
    static wxColour test_Green;
    static wxColour test_Red;
    static wxColour test_Blue;
    static wxColour test_Yellow;
};
