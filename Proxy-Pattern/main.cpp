#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

class Object{
public:
    virtual void Request() const = 0;
};

class OggettoReale : public Object{
public:
    void Request() const override{
        cout << "OggettoReale: Operazione avvenuta.\n";
    }
};

class Proxy : public Object{
private:
    OggettoReale *oggetto_reale_;

    bool CheckAccess() const{
        cout << "Proxy: Verifica che l'accesso sia possibile o meno\n";
        srand (time(NULL));
        return rand () % 2;
    }
    void LogAccess() const{
        cout << "Proxy: Registrazione della richiesta\n";
    }

public:
    Proxy(OggettoReale *oggetto_reale) : oggetto_reale_(new OggettoReale(*oggetto_reale)){}

    ~Proxy(){
        delete oggetto_reale_;
    }

    void Request() const override{
        if (this->CheckAccess()){
            this->oggetto_reale_->Request();
            this->LogAccess();
        }
        else{
            cout << "Request: Accesso non abilitato!\n";
        }
    }
};

void ClientCode(const Object &object){
    object.Request();
}

int main()
{
    cout << "Main: Eseguo il codice con un oggetto reale\n";
    OggettoReale *oggetto_reale = new OggettoReale;
    ClientCode(*oggetto_reale);
    cout << "\n";
    cout << "Main: Eseguo il codice con un Proxy:\n";
    Proxy *proxy = new Proxy(oggetto_reale);
    ClientCode(*proxy);

    return 0;
}