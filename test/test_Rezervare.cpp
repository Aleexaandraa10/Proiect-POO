#include "gtest/gtest.h"
#include "Rezervare.h"

//Testare toate Getterele
TEST(RezervareSuiteName, ConstructorWithAllParameters){
    Rezervare rezervare_simpla(5,"23:30","25.04.2024","Terasa","Alexia");
    EXPECT_EQ(rezervare_simpla.GetNumeRezervare(),"Alexia");
    EXPECT_EQ(rezervare_simpla.GetNrPersoane(),5);
    EXPECT_EQ(rezervare_simpla.GetZonaRestaurant(),"Terasa");
    EXPECT_EQ(rezervare_simpla.GetOra(),"23:30");
    EXPECT_EQ(rezervare_simpla.GetData(),"25.04.2024");
}

//Testare constructor care are ca parametru un obiect de tip Rezervare
TEST(RezervareTest, CopyConstructor) {
    Rezervare rezervare1(3, "18:30", "21.04.2024", "Demisol", "Matei");
    const Rezervare& rezervare2(rezervare1);
    EXPECT_EQ(rezervare1, rezervare2);
}

//Testare operator =
TEST(RezervareTest, AssignmentOperator) {
    Rezervare rezervare1(5, "20:00", "01.04.2024", "Terasa", "Matei");
    const Rezervare& rezervare2 = rezervare1;
    EXPECT_EQ(rezervare1, rezervare2);
}

//Testare Setters si Getters
TEST(RezervareTest, AccessAndModificationMethods) {
    Rezervare rezervare(4, "12:00", "19.03.2024", "Etaj", "Alex");
    rezervare.SetNrPersoane(6);
    rezervare.SetOra("13:00");
    rezervare.SetData("23.04.2024");
    EXPECT_EQ(rezervare.GetNrPersoane(), 6);
    EXPECT_EQ(rezervare.GetOra(), "13:00");
    EXPECT_EQ(rezervare.GetData(), "23.04.2024");
}

//Testare operatorul de ==
TEST(RezervareTest, ComparisonOperators) {
    Rezervare rezervare1(3, "18:30", "21.04.2024", "Parter", "Andrei");
    Rezervare rezervare2(3, "18:30", "21.04.2024", "Parter", "Andrei");
    Rezervare rezervare3(4, "20:00", "22.04.2024", "Terasa", "Matei");
    EXPECT_TRUE(rezervare1 == rezervare2);
    EXPECT_FALSE(rezervare1 == rezervare3);
    EXPECT_TRUE(rezervare1 != rezervare3);
}

//Testare fct ValidareIdRezervare()
TEST(RezervareTest, OtherMethods) {
    Rezervare rezervare(4, "12:00", "2024-04-19", "Zona A", "John Doe");
    EXPECT_EQ(rezervare.CalculeazaCostTotal(4, 50.0), 200.0);
    testing::internal::CaptureStdout();
    rezervare.ValidareIdRezervare();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Rezervarea nu a fost facuta online, deci nu va putem verifica corectitudinea id-ului.\n");
}

// Test operator >
TEST(RezervareTest, OperatorGreaterThan) {
    Rezervare rezervare1(2, "14:00", "2024-04-20", "Demisol","Marcel");
    Rezervare rezervare2(2, "15:00", "2024-04-20", "Terasa","Marinel");

    EXPECT_TRUE(rezervare2 > "20:00");
    EXPECT_TRUE(rezervare1 > "14:01");
    EXPECT_FALSE(rezervare2 > "14:59");
    EXPECT_FALSE(rezervare1 > "11:00");
}
