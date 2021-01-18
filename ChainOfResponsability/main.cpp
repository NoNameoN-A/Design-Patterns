#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Handler{
public:
    virtual Handler *SetNext(Handler *handler) = 0;
    virtual string Handle(string request) = 0;
};

class HandlerAstratto : public Handler{
private:
    Handler *next_handler_;

public:
    HandlerAstratto() : next_handler_(nullptr){}
    Handler *SetNext(Handler *handler) override{ //Setto all'inizializzazione dell'handler
        this->next_handler_ = handler;
        return handler;
    }
    string Handle(string request) override{
        if (this->next_handler_){
            return this->next_handler_->Handle(request); //Prendo il prossimo che ho settato all'inizio nel main
        }

        return {};
    }
};

class ScimmiaHandler : public HandlerAstratto{
public:
    string Handle(string request) override{
        if (request == "Banana"){
            return "Scimmia: Voglio mangiare io questa " + request + ".\n";
        }
        else{
            return HandlerAstratto::Handle(request); //Richiama l'ascoltatore successivo
        }
    }
};
class ScoiattoloHandler : public HandlerAstratto{
public:
    string Handle(string request) override{
        if (request == "Noce"){
            return "Scoiattolo: Voglio mangiare io questa " + request + ".\n";
        }
        else{
            return HandlerAstratto::Handle(request); //Richiama l'ascoltatore successivo
        }
    }
};
class CaneHandler : public HandlerAstratto{
public:
    string Handle(string request) override{
        if (request == "Carne"){
            return "Cane: Voglio mangiare io questa " + request + ".\n";
        }
        else{
            return HandlerAstratto::Handle(request); //Richiama l'ascoltatore successivo
        }
    }
};

void ClientCode(Handler &handler){
    vector<string> cibo = {"Noce", "Banana", "Tazza di caffe"};
    for (const string &f : cibo){
        cout << "Client: Chi vuole " << f << "?\n";
        const string result = handler.Handle(f); //Entra nel primo ascoltatore
        if (!result.empty()){
            cout << "  " << result;
        }
        else{
            cout << "  " << f << " non l'ha toccata nessuno.\n";
        }
    }
}

int main(){
    ScimmiaHandler *scimmia = new ScimmiaHandler;
    ScoiattoloHandler *scoiattolo = new ScoiattoloHandler;
    CaneHandler *cane = new CaneHandler;
    scimmia->SetNext(scoiattolo)->SetNext(cane); //Primo: Scimmia | Secondo: Scoiattolo | Terzo: Cane

    cout << "Chain: Scimmia > Scoiattolo > Cane\n\n";
    ClientCode(*scimmia); //Il primo handler voglio che sia la scimmia
    cout << "\n";
    cout << "Subchain: Scoiattolo > Cane\n\n";
    ClientCode(*scoiattolo); //Il primo handler voglio che sia lo scoiattolo

    return 0;
}