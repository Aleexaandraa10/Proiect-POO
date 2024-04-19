#include "gtest/gtest.h"
#include "Mancare.h"

//Teste la Getters
TEST(MancareSuiteName, MancareTestName){
    Mancare mancare("Penne italiano", "Paste",300,45);
    EXPECT_EQ(mancare.GetPret(),45);
    EXPECT_EQ(mancare.GetGramaj(),300);
    EXPECT_EQ(mancare.GetNume(),"Penne italiano");
    EXPECT_EQ(mancare.GetCategorie(),"Paste");
}