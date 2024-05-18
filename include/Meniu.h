#ifndef MENIU_H
#define MENIU_H

class Meniu{
private:
    Meniu() = default;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;

    static Meniu& get_meniu();
};

#endif //MENIU_H
