#include <iostream>
using namespace std;

class ClasseAstratta{
public:
    void TemplateMethod() const{
        this->OperazioneSemplice1();
        this->OperazioneDifferente1();
        this->OperazioneSemplice2();
        this->Altro();
        this->OperazioneDifferente2();
        this->OperazioneSemplice3();
    }
protected:
    void OperazioneSemplice1() const{
        cout << "ClasseAstratta: Operazione semplice di base\n";
    }
    void OperazioneSemplice2() const{
        cout << "ClasseAstratta: Questa è un altra operazione semplice della classe astratta\n";
    }
    void OperazioneSemplice3() const{
        cout << "ClasseAstratta: Operazione semplice numero 3 della classe astratta\n";
    }
    virtual void OperazioneDifferente1() const = 0;
    virtual void OperazioneDifferente2() const = 0;
    
    virtual void Altro() const {}
};
class ClasseConcreta1 : public ClasseAstratta{
protected:
    void OperazioneDifferente1() const override{
        cout << "ClasseConcreta1: Implementata operazione semplice 1 - CLASSE 1\n";
    }
    void OperazioneDifferente2() const override{
        cout << "ClasseConcreta1: Implementata operazione semplice 2 - CLASSE 1\n";
    }
};

class ClasseConcreta2 : public ClasseAstratta{
protected:
    void OperazioneDifferente1() const override{
        cout << "ClasseConcreta2: Implementata operazione semplice 1 - CLASSE 2\n";
    }
    void OperazioneDifferente2() const override{
        cout << "ClasseConcreta2: Implementata operazione semplice 2 - CLASSE 2\n";
    }
    void Altro() const override{
        cout << "ClasseConcreta2: Overraid di Altro - CLASSE 2\n";
    }
};

void ClientCode(ClasseAstratta *classe_){
    classe_->TemplateMethod();
}

int main(){
    cout << "Lo stesso codice funziona per più sottoclassi:\n";
    ClasseConcreta1 *classeConcreta1 = new ClasseConcreta1;
    ClientCode(classeConcreta1);
    cout << "\n";
    cout << "Si differenzia solo negli elementi fondamentali:\n";
    ClasseConcreta2 *classeConcreta2 = new ClasseConcreta2;
    ClientCode(classeConcreta2);
    
    return 0;
}