[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/0s82AB8Z)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=17578523&assignment_repo_type=AssignmentRepo)
### Traccia: Creazione e Gestione di un Grafo Personalizzato

#### **Descrizione del Task:**

Lo scopo dell'esercizio è lavorare con la classe `Grafo` per creare, manipolare e analizzare un grafo. Lo studente deve ideare un grafo personalizzato e implementarlo direttamente nel codice, insieme alle operazioni richieste.

---

### **Ideazione e Creazione del Grafo**
Il grafo puó essere relativo a diversi contesti: rete tra cittá, rete tra numeri, amicizie tra persone, connessione tra palazzi, ecc... Non ci devono essere grafi uguali tra studenti e soprattutto i temi dei grafi devono essere ben diversificati. Se ci saranno due grafi uguali tra studenti questi non saranno esonerati.
1. **Ideazione del Grafo**:
   - Ogni studente deve progettare un grafo *personale* che deve essere *orientato* e *pesato*, specificando:
     - I nodi del grafo (es. città, nomi, numeri, palazzi, persone, ecc...).
     - Gli archi tra i nodi con pesi.
   - Il grafo deve avere almeno:
     - 5 nodi.
     - 6 archi.
   - Lo studente deve caricare il disegno (realizzato in qualsiasi modo) del grafo realizzato. Se questo file non sará presente nella repository, lo studente non sará esonerato.

2. **Inserimento nel Codice**:
   - Lo studente deve implementare il grafo direttamente nel main, utilizzando i metodi della classe `Grafo`.
   - Inserire i nodi e gli archi ideati seguendo la struttura del proprio grafo.

### **Visualizzazione del Grafo**

1. **Visualizzazione dei nodi**:
   - Stampare il grafo a schermo.

### **Ricerca e Manipolazione**

1. **Ricerca**:
   - Verificare se un nodo esiste nel grafo.
   - Stampare i nodi adiacenti a un nodo specificato.
   - Verificare se un arco esiste tra due nodi.
2. **Manipolazione**:
   - Rimuovere un nodo e tutti i suoi archi associati.
   - Rimuovere un arco specifico (specificando sorgente e destinazione).

### **Modifica del Grafo**

1. **Aggiunta di nuovi nodi**:
   - Aggiungere un nuovo nodo al grafo.
2. **Aggiunta di nuovi archi**:
   - Aggiungere un nuovo arco, specificando sorgente, destinazione e peso.

---

### **Operazioni Aggiuntive per chi ha voto da 20 in su**

  **Connettività**:
   - Verificare nel main se due nodi specificati sono connessi.
   - Creare nella classe Grafo un nuovo metodo per trovare l'arco con peso minore tra gli archi uscenti di un nodo dato in input.

---

### **Operazioni Aggiuntive per chi vuole aumentare il voto da 22 in su**

  **Percorso Minimo**:
   - Implementare una funzione esterna al main per la ricerca dei cammini minimi utilizzando l'algoritmo di Dijkstra.
      ![image](https://github.com/user-attachments/assets/dc110a59-6858-4083-a6f6-736105a992db)
---

### **Esempio di Grafo Ideato**

Un grafo che rappresenta una rete di città:
- Nodi: `Milano`, `Roma`, `Napoli`, `Torino`, `Firenze`.
- Archi:
  - `Milano → Torino` (100 km)
  - `Torino → Firenze` (200 km)
  - `Firenze → Roma` (150 km)
  - `Roma → Napoli` (120 km)
  - `Napoli → Milano` (500 km)

