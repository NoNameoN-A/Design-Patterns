#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Component{
protected:
    Component *parent_;

public:
    virtual ~Component() {}
    void SetParent(Component *parent){
        this->parent_ = parent;
    }
    Component *GetParent() const{
        return this->parent_;
    }
    virtual void Add(Component *componente) {}
    virtual void Remove(Component *componente) {}

    virtual bool IsComposite() const{
        return false;
    }

    virtual string Operation() const = 0;
};

class Foglia : public Component{ //Foglia
public:
    string Operation() const override{
        return "Foglia";
    }
};

class Composite : public Component{
protected:
    list<Component *> lista_di_componenti_;

public:

    void Add(Component *componente) override{
        this->lista_di_componenti_.push_back(componente);
        componente->SetParent(this);
    }

    void Remove(Component *componente) override{
        lista_di_componenti_.remove(componente);
        componente->SetParent(nullptr);
    }
    bool IsComposite() const override{
        return true;
    }
    string Operation() const override{
        string result;
        for (const Component *c : lista_di_componenti_){
            if (c == lista_di_componenti_.back()){
                result += c->Operation();
            }
            else{
                result += c->Operation() + "+";
            }
        }
        return "ramo(" + result + ")";
    }
};

void ClientCode(Component *componente){
    cout << "RESULT: " << componente->Operation();
    
}

void ClientCode2(Component *componente1, Component *componente2)
{
    if (componente1->IsComposite()){
        componente1->Add(componente2);
    }
    cout << "RESULT: " << componente1->Operation();
}

int main()
{
    Component *simple = new Foglia;
    cout << "Componente semplice\n";
    ClientCode(simple);
    cout << "\n\n";


    Component *albero = new Composite;
    Component *ramo1 = new Composite;

    Component *Foglia_1 = new Foglia;
    Component *Foglia_2 = new Foglia;
    Component *Foglia_3 = new Foglia;
    ramo1->Add(Foglia_1);
    ramo1->Add(Foglia_2);
    Component *ramo2 = new Composite;
    ramo2->Add(Foglia_3);
    albero->Add(ramo1);
    albero->Add(ramo2);
    cout << "Componente complesso albero:\n";
    ClientCode(albero);
    cout << "\n\n";

    cout << "Se provo a gestire un oggetto complesso insieme ad uno semplice non ho problemi:\n";
    ClientCode2(albero, simple);
    cout << "\n";

    delete simple;
    delete albero;
    delete ramo1;
    delete ramo2;
    delete Foglia_1;
    delete Foglia_2;
    delete Foglia_3;

    return 0;
}