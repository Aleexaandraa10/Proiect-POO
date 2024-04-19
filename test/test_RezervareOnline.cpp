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

// Test afisare
TEST(RezervareOnlineTest, Afisare) {
    RezervareOnline rezervare(4, "12:00", "05.05.2023", "Etaj", "Bianca", "AB12345678");
    testing::internal::CaptureStdout();
    rezervare.afisare(std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "Numele pe care a fost facuta rezervarea este: Bianca\n";
    expected_output += "Nr de persoane care participa este: 4\n";
    expected_output += "Ora la care masa a fost rezervata este: 12:00\n";
    expected_output += "Data rezervarii este: 05.05.2023\n";
    expected_output += "Zona restaurantului aleasa este: Etaj\n";
    expected_output += "Iar: AB12345678 este id-ul rezervarii\n";

    EXPECT_EQ(output, expected_output);
}

// Test ValidareIdRezervare pentru Id corect
TEST(RezervareOnlineTest, ValidareIdRezervareCorect) {
    RezervareOnline rezervare(4, "12:00", "03.04.2023", "Demisol", "Ana", "a567");
    testing::internal::CaptureStdout();
    rezervare.ValidareIdRezervare();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Id-ul este corect!\n");
}

// Test ValidareIdRezervare pentru Id necorespunzator (lungime incorecta)
TEST(RezervareOnlineTest, ValidareIdRezervareLungimeIncorecta) {
    RezervareOnline rezervare(4, "12:00", "03.04.2023", "Demisol", "Ana", "a");
    testing::internal::CaptureStdout();
    rezervare.ValidareIdRezervare();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Id-ul nu se incadreaza in limitele noastre de lungime.\n");
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

