#include <iostream>
#include <string>
using namespace std;

class Sottosistema1{
public: //Operazioni complesse del sottosistema
    string Operazione1() const{
        return "Sottosistema1: Pronto!\n";
    }
    string OperazioneN() const{
        return "Sottosistema1: Avviato!\n";
    }
};

class Sottosistema2{
public: //Operazioni complesse del sottosistema
    string Operazione1() const{
        return "Sottosistema2: Caricamento sottosistema 2 completato. \n";
    }
    string OperazioneZ() const{
        return "Sottosistema2: Sono in esecuzione!\n";
    }
};

class Facade{
protected:
    Sottosistema1 *sottosistema1_;
    Sottosistema2 *sottosistema2_;
public:
    Facade(
        Sottosistema1 *sottosistema1 = nullptr,
        Sottosistema2 *sottosistema2 = nullptr){
        this->sottosistema1_ = sottosistema1 ?: new Sottosistema1; //Se non è stato passato creane uno
        this->sottosistema2_ = sottosistema2 ?: new Sottosistema2;
    }
    ~Facade(){
        delete sottosistema1_;
        delete sottosistema2_;
    }
    string Operazione(){ //Metodo utilizzabile
        string result = "Facade: Preparazione dei sottosistemi in corso...\n";
        result += this->sottosistema1_->Operazione1();
        result += this->sottosistema2_->Operazione1();
        result += "Facade: Caricamento avvenuto con successo.\n";
        result += "Facade: Esecuzione in corso:\n";
        result += this->sottosistema1_->OperazioneN();
        result += this->sottosistema2_->OperazioneZ();
        result += "Facade: L'operazione è terminata con successo!";
        return result;
    }
};

void ClientCode(Facade *facade){
    cout << facade->Operazione();
}

int main(){
    Sottosistema1 *sottosistema1 = new Sottosistema1;
    Sottosistema2 *sottosistema2 = new Sottosistema2;
    Facade *facade = new Facade(sottosistema1, sottosistema2);
    ClientCode(facade);

    delete facade;

    return 0;
}