#include <gtest/gtest.h>
#include "RezervareOnline.h"

// Test constructor
TEST(RezervareOnlineTest, Constructor) {
    RezervareOnline rezervare(4, "12:00", "01.05.2024", "Parter", "Max", "AB12345678");

    EXPECT_EQ(rezervare.GetNrPersoane(), 4);
    EXPECT_EQ(rezervare.GetOra(), "12:00");
    EXPECT_EQ(rezervare.GetData(), "01.05.2024");
    EXPECT_EQ(rezervare.GetZonaRestaurant(), "Parter");
    EXPECT_EQ(rezervare.GetNumeRezervare(), "Max");
    EXPECT_EQ(rezervare.GetId(), "AB12345678");
}

// Test operator==
TEST(RezervareOnlineTest, OperatorEqual) {
    RezervareOnline rezervare1(4, "12:00", "02.05.2024", "Parter", "Mihai", "AB12345678");
    RezervareOnline rezervare2(4, "12:00", "02.05.2024", "Parter", "Mihai", "AB12345678");
    RezervareOnline rezervare3(2, "14:00", "02.05.2024", "Etaj", "Mihaela", "CD98765432");

    EXPECT_TRUE(rezervare1 == rezervare2);
    EXPECT_FALSE(rezervare1 == rezervare3);
}

// Test operator=
TEST(RezervareOnlineTest, OperatorAtribuire) {
    RezervareOnline rezervare1(4, "12:00", "02.05.2024", "Parter", "Mihai", "AB1234");
    RezervareOnline rezervare2;

    rezervare2 = rezervare1;

    EXPECT_EQ(rezervare2.GetNrPersoane(), rezervare1.GetNrPersoane());
    EXPECT_EQ(rezervare2.GetOra(), rezervare1.GetOra());
    EXPECT_EQ(rezervare2.GetData(), rezervare1.GetData());
    EXPECT_EQ(rezervare2.GetZonaRestaurant(), rezervare1.GetZonaRestaurant());
    EXPECT_EQ(rezervare2.GetNumeRezervare(), rezervare1.GetNumeRezervare());
    EXPECT_EQ(rezervare2.GetId(), rezervare1.GetId());
}
