#include <iostream>
using namespace std;

#define MAX_NODI 100
#define INF 1000000000 

template <typename T>
class Grafo {
private:
    T nodi[MAX_NODI]; 
    int matriceAdiacenza[MAX_NODI][MAX_NODI]; 
    bool esisteNodo[MAX_NODI]; 
    int numeroNodi = 0; 

public:
    Grafo() {
        for (int i = 0; i < MAX_NODI; ++i) {
            esisteNodo[i] = false;
            for (int j = 0; j < MAX_NODI; ++j) {
                matriceAdiacenza[i][j] = INF;
            }
            matriceAdiacenza[i][i] = 0;
        }
    }

    void aggiungiNodo(const T& nodo) {
        if (numeroNodi >= MAX_NODI) {
            cout << "Errore: numero massimo di nodi raggiunto.\n";
            return;
        }
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                cout << "Errore: il nodo esiste già.\n";
                return;
            }
        }
        nodi[numeroNodi] = nodo;
        esisteNodo[numeroNodi] = true;
        numeroNodi++;
    }

    void aggiungiArco(const T& sorgente, const T& destinazione, int peso) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = peso;
    }

    void rimuoviNodo(const T& nodo) {
        int indice = trovaIndice(nodo);
        if (indice == -1) {
            cout << "Errore: il nodo non esiste.\n";
            return;
        }
        esisteNodo[indice] = false;
        for (int i = 0; i < MAX_NODI; ++i) {
            matriceAdiacenza[indice][i] = INF;
            matriceAdiacenza[i][indice] = INF;
        }
    }

    void rimuoviArco(const T& sorgente, const T& destinazione) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = INF;
    }

    void nodiAdiacenti(const T& nodo) const {
        int indice = trovaIndice(nodo);
        if (indice == -1) {
            cout << "Errore: il nodo non esiste.\n";
            return;
        }
        cout << "Nodi adiacenti a " << nodo << ": ";
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && matriceAdiacenza[indice][i] != INF) {
                cout << nodi[i] << " (peso: " << matriceAdiacenza[indice][i] << ") ";
            }
        }
        cout << "\n";
    }

    void stampa() const {
        cout << "Matrice di Adiacenza:\n";
        for (int i = 0; i < numeroNodi; ++i) {
            if (!esisteNodo[i]) continue;

            for (int j = 0; j < numeroNodi; ++j) {
                if (!esisteNodo[j]) continue;

                if (matriceAdiacenza[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << matriceAdiacenza[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    bool verificaNodo(const T& nodo) const {
        return trovaIndice(nodo) != -1;
    }

    bool verificaArco(const T& sorgente, const T& destinazione) const {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            return false;
        }
        return matriceAdiacenza[indiceSorgente][indiceDestinazione] != INF;
    }

private:
    int trovaIndice(const T& nodo) const {
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Grafo<string> grafo;

    grafo.aggiungiNodo("Yamaha R1");
    grafo.aggiungiNodo("Honda CBR1000RR");
    grafo.aggiungiNodo("Kawasaki Ninja ZX-10R");
    grafo.aggiungiNodo("Suzuki GSX-R1000");
    grafo.aggiungiNodo("BMW S1000RR");

    grafo.aggiungiArco("Yamaha R1", "Honda CBR1000RR", 320);
    grafo.aggiungiArco("Honda CBR1000RR", "Kawasaki Ninja ZX-10R", 310);
    grafo.aggiungiArco("Kawasaki Ninja ZX-10R", "Suzuki GSX-R1000", 305);
    grafo.aggiungiArco("Suzuki GSX-R1000", "BMW S1000RR", 330);
    grafo.aggiungiArco("BMW S1000RR", "Yamaha R1", 330);
    grafo.aggiungiArco("Yamaha R1", "Suzuki GSX-R1000", 315);

    grafo.stampa();

    cout << "\nEsiste il nodo 'Honda CBR1000RR'? " << (grafo.verificaNodo("Honda CBR1000RR") ? "Si" : "No") << endl;
    cout << "Esiste il nodo 'Ducati Panigale V4'? " << (grafo.verificaNodo("Ducati Panigale V4") ? "Si" : "No") << endl;

    grafo.nodiAdiacenti("Yamaha R1");
    grafo.nodiAdiacenti("Suzuki GSX-R1000");

    cout << "\nEsiste un arco tra 'Yamaha R1' e 'Honda CBR1000RR'? " << (grafo.verificaArco("Yamaha R1", "Honda CBR1000RR") ? "Si" : "No") << endl;
    cout << "Esiste un arco tra 'Honda CBR1000RR' e 'BMW S1000RR'? " << (grafo.verificaArco("Honda CBR1000RR", "BMW S1000RR") ? "Si" : "No") << endl;

    grafo.rimuoviNodo("Kawasaki Ninja ZX-10R");
    cout << "\nGrafo dopo la rimozione di 'Kawasaki Ninja ZX-10R':\n";
    grafo.stampa();
}
