#include <gtest/gtest.h>
#include "RezervareTelefonica.h"
#include <stdexcept>

// Test constructor
TEST(RezervareTelefonicaTest, Constructor) {
    RezervareTelefonica rezervare(4, "12:00", "01.05.2024", "Parter", "Max", "1234567890");

    EXPECT_EQ(rezervare.GetNrPersoane(), 4);
    EXPECT_EQ(rezervare.GetOra(), "12:00");
    EXPECT_EQ(rezervare.GetData(), "01.05.2024");
    EXPECT_EQ(rezervare.GetZonaRestaurant(), "Parter");
    EXPECT_EQ(rezervare.GetNumeRezervare(), "Max");
    EXPECT_EQ(rezervare.GetTelefon(), "1234567890");
}

// Test operator==
TEST(RezervareTelefonicaTest, OperatorEqual) {
    RezervareTelefonica rezervare1(4, "12:00", "02.05.2024", "Parter", "Mihai", "1234567890");
    RezervareTelefonica rezervare2(4, "12:00", "02.05.2024", "Parter", "Mihai", "1234567890");
    RezervareTelefonica rezervare3(2, "14:00", "02.05.2024", "Etaj", "Mihaela", "9876543210");

    EXPECT_TRUE(rezervare1 == rezervare2);
    EXPECT_FALSE(rezervare1 == rezervare3);
}

//Test operator = si Getters
TEST(RezervareTelefonicaTest, OperatorAtribuire) {
    RezervareTelefonica rezervare1(4, "12:00", "02.05.2024", "Parter", "Mihai", "0775232042");
    RezervareTelefonica rezervare2;

    rezervare2 = rezervare1;

    EXPECT_EQ(rezervare2.GetNrPersoane(), rezervare1.GetNrPersoane());
    EXPECT_EQ(rezervare2.GetOra(), rezervare1.GetOra());
    EXPECT_EQ(rezervare2.GetData(), rezervare1.GetData());
    EXPECT_EQ(rezervare2.GetZonaRestaurant(), rezervare1.GetZonaRestaurant());
    EXPECT_EQ(rezervare2.GetNumeRezervare(), rezervare1.GetNumeRezervare());
    EXPECT_EQ(rezervare2.GetTelefon(), rezervare1.GetTelefon());
}


// Testare Schimba_NumarTelefon cu numar valid
TEST(RezervareTelefonicaTest, SchimbaNumarTelefonValid) {
    RezervareTelefonica rezervare(4, "12:00", "01.05.2024", "Parter", "Max", "1234567890");
    std::string numarNou = "9876543210";

    ASSERT_NO_THROW({
                        rezervare.Schimba_NumarTelefon(numarNou);
                    });
    EXPECT_EQ(rezervare.GetTelefon(), numarNou);
}

// Testare Schimba_NumarTelefon cu numar invalid
TEST(RezervareTelefonicaTest, SchimbaNumarTelefonInvalid) {
    RezervareTelefonica rezervare(4, "12:00", "01.05.2024", "Parter", "Max", "1234567890");
    std::string numarNou = "9876"; // Numar invalid

    EXPECT_THROW({
            rezervare.Schimba_NumarTelefon(numarNou);
                 }, std::invalid_argument);

    EXPECT_EQ(rezervare.GetTelefon(), "1234567890"); // Numărul nu ar trebui să fie schimbat
}
