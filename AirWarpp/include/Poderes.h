#ifndef PODERES_H
#define PODERES_H


class Poderes
{
    public:
        Poderes();
        virtual ~Poderes();

        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        int GetID() { return ID; }
        void SetID(int val) { ID = val; }
        void Aplicar(ID);

    private:
        int x;
        int y;
        int ID;
};

#endif // PODERES_H
