#include <iostream>
#include <random>
#include <ctime> 
#include <vector>

using namespace std;

class Estrategia{
    protected:
        string type;
        int cont;
    public:
        Estrategia(){}
        ~Estrategia(){}
        string getType(){return type;};
        virtual void function(int n) = 0;
};

class Five_Pares: public Estrategia{
    public:
        void function(int n) override{
            if (cont == 5){
                cout << "Ganas.";
            }else if(n % 2 == 0){
                cont++;
            }
        }
};

class Five_Impares: public Estrategia{
    public:
        void function(int n) override{
            if(cont == 5){
                cout << "Ganas.";
            }else if(n % 2 != 0){
                cont++;
            }
        }
};

class is_Primo: public Estrategia{
    public:
        void function(int n) override{
            int divisor = 1;
            int divisores = 0;
            do{
                if(n % divisor == 0){
                    divisores++;
                }
                divisor++;
            }while(divisor <- n);
            if(cont == 1){
                cout << "Ganas.";
            }else if(divisores == 2){
                cont++;
            }
        }

};

class Ten_multiplo: public Estrategia{
    public:
    void function(int n) override{
        if(cont == 3){
            cout << "Ganas.";
        }else if(n % 10 == 0){
            cont++;
        }
    }
};


class Twenty_five_multiplo: public Estrategia{
    public:
    void function(int n) override{
        if (cont == 2){
            cout << "Ganas.";
        }
        if(n % 25 == 0){
            cont++;
        }
    }
};


class Jugador{
    private:
        string name;
        Estrategia* estrategia;
    public:
        Jugador(string nombre){
            this->name = name;
        }
        string getName(){return name;}
        void displayData(){
            cout << "Nombre: " << name << "\n";
            cout << "Estrategia Ganadora: " << estrategia->getType() << endl;
        }
        void setEstrategia(Estrategia* estrategia){
            this->estrategia = estrategia;
        }
        ~Jugador(){};

};

class XYZ{
    protected:
        XYZ(){}
        static XYZ* system;
        vector<Jugador> jugadores;
    public:
        XYZ(XYZ &other) = delete;
        void operator = (const XYZ & ) = delete;
        static XYZ *GetInstance();
        void initial_game(){
            string name = "";
            for(int i = 1; i <=5; i++){
                int option = 0;
                cout << "\nIngrese su nombre: ";
                cin>> name;
                Jugador* jugador = new Jugador(name);
                cout << "Ingrese una de las siguientes opciones: \n";
                cout << "Opcion 1 : Cinco pares\n";
                cout << "Opcion 2 : Cinco impares\n";
                cout << "Opcion 3 : Un numero primo\n";
                cout << "Opcion 4 : Tres numeros multiplos de 10\n";
                cout << "Opcion 5 : Dos numeros multipos de 25\n";
                cout << "Opcion: ";
                cin >> option;
                if(option == 1){
                    auto* five_Pares = new Five_Pares();
                    jugador->setEstrategia(five_Pares);
                }else if(option == 2){
                    auto* five_Impares = new Five_Impares();
                    jugador->setEstrategia(five_Impares);
                }else if(option == 3){
                    auto* is_prime = new is_Primo();
                    jugador->setEstrategia(is_prime);
                }else if(option == 4){
                    auto* three_mult10 = new Ten_multiplo();
                    jugador->setEstrategia(three_mult10);
                }else if(option == 5){
                    auto* two_mult25 =  new Twenty_five_multiplo();
                    jugador->setEstrategia(two_mult25);
                }
                jugadores.push_back(jugador);
            }
        }
        void play(){
        srand(time(NULL));
        int i = 0;
        while(true){
            int random = rand()%100;
            jugadores[i]->getStrategy()->function(random);
            if(jugadores[i]->getStrategy()->getWinner()){
                cout<<"Fin del juego, gano el jugador "<<i+1<<endl;
                break;
            }
            if(i<jugadores.size())
                i=0;
            i++;
        }
    }


};


XYZ* XYZ::system = nullptr;

XYZ* XYZ::GetInstance(){
    if(system == nullptr)
      system = new XYZ();
    return system;
}

int main(){
    XYZ*control = XYZ::GetInstance();
    control->initial_game();
    control->jugador();
    delete control;
}