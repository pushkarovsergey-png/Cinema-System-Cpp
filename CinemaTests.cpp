#include <gtest/gtest.h>
#include "Cinema.h"
#include <string>

TEST(CinemaTest, BookingFreeSeatReturnTrue) {
    Cinema cinema;

    bool result = cinema.bookSeat(5);

    EXPECT_TRUE(result);
}

TEST(CinemaTest, BookingTakenSeatReturnFalse) {
    Cinema cinema;
    cinema.bookSeat(5);

    bool result = cinema.bookSeat(5);

    EXPECT_FALSE(result);
}

TEST(CinemaTest, HallStatusShowsTakenSeat) {
    Cinema cinema;
    cinema.bookSeat(1);
    
    std::string status = cinema.getHallStatus();
    
    EXPECT_NE(status.find("[X]"), std::string::npos); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
