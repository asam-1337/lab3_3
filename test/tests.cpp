//
// Created by sam on 19.12.2021.
//

#include "gtest/gtest.h"
#include "../src/PCB_d.h"


using namespace PCB_1;

TEST(StructConstructor, defultConstructor)
{
    contact c1;
    EXPECT_EQ(c1.x, 0);
    EXPECT_EQ(c1.y, 0);
    EXPECT_EQ(c1.type, false);
    EXPECT_EQ(c1.connect, -1);
    EXPECT_EQ(c1.exist, true);
}

TEST(StructConstructor, oneArgConstructor)
{
    contact c1(true,2,4);
    EXPECT_EQ(c1.x, 2);
    EXPECT_EQ(c1.y, 4);
    EXPECT_EQ(c1.type, true);
    EXPECT_EQ(c1.connect, -1);
    EXPECT_EQ(c1.exist, true);
}

TEST(Constructor, defultConstructor)
{
    PCB p1;
    EXPECT_EQ(p1.getSZ(), 10);
    EXPECT_EQ(p1.getCurr_sz(), 0);
}

TEST(Constructor, copyConstructor)
{
    PCB p1;
    p1 += contact(true, 2, 4);
    p1 += contact(true, 0, 0);
    p1 += contact(false, 1, 0);
    PCB p2(p1);
    EXPECT_EQ(p1.getSZ(), 10);
    EXPECT_EQ(p1.getCurr_sz(), 3);
}

TEST(Methods, getters)
{
    PCB p1;
    EXPECT_EQ(p1.getSZ(), 10);
    EXPECT_EQ(p1.getCurr_sz(), 0);
}

TEST(Methods, correction_check)
{
    PCB p1;
    p1 += contact(true, 2, 4);
    p1 += contact(true, 0, 0);
    p1 += contact(false, 1, 0);
    EXPECT_EQ(p1.correction_check(0,1), 1);
    EXPECT_EQ(p1.correction_check(0,2), 0);
    EXPECT_EQ(p1.correction_check(1,2), 0);
}

TEST(Methods, get_track_length)
{
    PCB p1;
    p1 += contact(true, 2, 2);
    p1 += contact(true, 0, 0);
    p1 += contact(false, 3, 4);
    EXPECT_ANY_THROW(p1.get_track_length(0,1));
    EXPECT_NEAR(p1.get_track_length(1,2), 5, 0.001);
}

TEST(Methods, establish_connect)
{
    PCB p1;
    p1 += contact(true, 2, 4);
    p1 += contact(true, 0, 0);
    p1 += contact(false, 1, 0);
    EXPECT_EQ(p1.establish_connect(0,1), 1);
    EXPECT_EQ(p1.establish_connect(0,2), 0);
    EXPECT_EQ(p1.establish_connect(1,2), 1);
}

