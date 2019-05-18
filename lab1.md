# PdS 2019 - Laboratorio OS161 1

Il Sistema SIS161 – OS161 è installato in una macchina virtuale VBOX OSE, con S.O. Linux Ubuntu 14.04 (versione in inglese).

Presso il LAIB1 sono disponibili macchine virtuali oVirt (Open Virtualization Manager) con Ubuntu 14.04 (versione in italiano)

La macchina virtuale (file `linux-pds-ovf10.ova`) è anche disponibile per download (ad esempio per uso su PC personale) su [https://elearning.polito.it/secure/linux-pds-ovf10.ova](https://elearning.polito.it/secure/linux-pds-ovf10.ova) solo da intranet politecnico, occorre login con credenziali studente). Si consiglia, per uso personale, di installare VirtualBox ([https://www.virtualbox.org](https://www.virtualbox.org)).

## Attivazione macchina virtuale

Per attivare la macchina virtuale, eseguire i passi sotto-elencati

1. Login, al LABINF, su Windows (preferibile) o Linux. Login su Linux (versione specifica per OS161) al LAIB,
2. Copiare il file linux-pds-ovf10.ova in un direttorio locale. Si tratta di un file compresso da cui verrà successivamente estratta la macchina virtuale. Al LABINBF il file si trova nella cartella `\\cclix1\corsi\cabodi` (windows) oppure `smb://cclix1/corsi/cabodi`. Su windows, il file va copiato in locale, evitando il disco `Z:` (dimensione non sufficiente). Su linux usare `/var/tmp/<matricola>`.

3. Avviare Virtual Box.

4. Importare la macchina virtuale utilizzando il comando `import appliance` (importa applicazione virtuale), **Attenzione**: per l’esecuzione al LABINF, nella finestra di configurazione della macchina virtuale, su consiglia di modificare il direttorio per l’immagine del disco virtuale, collocandolo in `/var/tmp` (per problemi di quota su disco),

5. Avviare la macchina virtuale.

6. E’ abilitato automaticamente il login con

	- USER: pds

	- PASSWORD: pdsuser

 7. La macchina virtuale potrà essere esportata, al termine del lavoro, con una procedura duale: comando `export applianc`” (esporta applicazione virtuale).

### Procedura per Linux al LAIB

Linux è disponibile come macchina virtuale in VDI (accessibile mediante client oVirt). La descrizione dettagliata viene fornita in un altro documento.

Al termine del lavoro, è NECESSARIO chiudere la macchina virtuale linux (comando `arresta` in alto a destra, icona ingranaggio). 

## Ambiente OS161

Il sistema operativo os161 è stato pre-installato nel direttorio `os161/os161-base-2.0.2`, mentre i pacchetti SW richiesti, `binutils`, compilatore `gcc` e debugger `gdb`, emulatore `MIPS`, sono installati nella cartella `os161/tools`. SI NOTI CHE TUTTI I DIRETTORI SONO INDICATI A PARTIRE DA `$HOME`, che è `/usr/pds` (versione VBOX) oppure `/home/corso` (versione VDI/LAIB1).

Si ricorda che il sistema OS161 è attivato sull’emulatore di processore MIPS, SYS161. Al fine di ri-compilare OS161, nonché di fare debug e altre operazioni (ad esempio visualizzazione di file eseguibili), sono necessari programmi previsti per la piattaforma MIPS, che sono stati installati con il prefisso `mips-harvard-os161-`: `mips-harvard-os161-gcc`, `mips-harvard-os161-gdb` (eseguibili in `os161/tools/bin`).

Il sito web di riferimento è: [http://os161.eecs.harvard.edu/](http://os161.eecs.harvard.edu/). L’ultima versione è disponibile (con le precedenti) su [http://os161.eecs.harvard.edu/download/](http://os161.eecs.harvard.edu/download/).

Un altro sito con informazioni interessanti è quello del corso cs350 dell’università di Waterloo (Canada): [http://www.student.cs.uwaterloo.ca/~cs350/common/OS161main.html](http://www.student.cs.uwaterloo.ca/~cs350/common/OS161main.html)

Sul desktop della macchina virtuale è presente un link al codice sorgente “navigabile” da un web browser. Per eventuali installazioni sul proprio PC, occorre seguire le istruzioni presenti su uno dei siti sopra proposti. Si forniscono a parte degli script di installazione per un sistema Linux-Ubuntu.

Informazioni dettagliate su avvio ed esecuzione di OS161 sono raggiungibili, ad esempio, dal link: [Working with OS161](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html)

La cartella iniziale di lavoro proposta è `pds-os161/root`.

**ATTENZIONE**: ci sono quindi due direttori

- `os161`: contiene sorgenti, file di configurazione, compilazione ed eseguibili, di os161 e dei tool utilizzati (è quindi l’area in cui si modifica e ri-compila os161)

- `pds-os161/root`: si tratta del direttorio in cui eseguire il (fare boot del) sistema operativo, ed eventualmente attivare processi user (è l’area in cui si esegue e si testa il sistema os161).

Per fare bootstrap di OS161 in ambiente emulato sys161 (da una shell, attivabile in una finestra “Terminal”), sono possibili due modalità:

### Esecuzione normale:
```bash
cd $HOME/pds-os161/root
sys161 kernel
```
- Compare una videata come la seguente
```
sys161: System/161 release 2.0.8, compiled Mar 30 2016 12:38:39
OS/161 base system version 2.0.2
Copyright (c) 2000, 2001-2005, 2008-2011, 2013, 2014
President and Fellows of Harvard College.  All rights reserved.
Put-your-group-name-here's system version 0 (DUMBVM #1)
788k physical memory available
Device probe...
lamebus0 (system main bus)
emu0 at lamebus0
ltrace0 at lamebus0
ltimer0 at lamebus0
beep0 at ltimer0
rtclock0 at ltimer0
lrandom0 at lamebus0
random0 at lrandom0
lhd0 at lamebus0
lhd1 at lamebus0
lser0 at lamebus0
con0 at lser0
 
cpu0: MIPS/161 (System/161 2.x) features 0x0 
OS/161 kernel [? for menu]:
```
Dalla quale sono attivabili comandi (menu con `?`). Alcuni comandi (es. quelli selezionabili con `?o`) non sono completamente disponibili, in quanto OS161 non è un sistema completo (richiede aggiunte da parte dello studente).

### Esecuzione con debugger.

**ATTENZIONE**: il programma eseguito sul sistema Ububtu è sys161. Sys161 è un eseguibile per la macchina host (con processore Intel o AMD, sys161 viene già fornito e NON necessita debug). Il comando `sys161 kernel` manda in esecuzione `sys161`, un programma che funge da macchina virtuale con processore MIPS, per la quale “kernel” è un file “eseguibile” che viene caricato e mandato in esecuzione: obiettivo del laboratorio è interagire con “kernel”, eseguito su macchina MIPS (sys161), NON interagire con sys161.

Occorre evitare di fare il debug dell’emulatore SYS161. Il debugger (per la piattaforma MIPS) deve quindi essere eseguito una volta avviato SYS161. A tale scopo occorrono due processi, uno per eseguire `sys161` (avviato in una modalità predisposta per fare debug del kernek) e uno per `mips-harvard-os161-gdb` (un debugger predisposto per macchina mips), comunicanti mediante socket. Si consiglia di attivare due finestre terminale. Sulla prima, dal direttorio `pds-os161/root` eseguire il comando:
```bash
sys161 -w kernel
```
sulla seconda, dallo stesso direttorio
```bash
mips-harvard-os161-gdb kernel
(gdb) dir ../../os161/os161-base-2.0.2/kern/compile/DUMBVM
(gdb) target remote unix:.sockets/gdb
```
attenzione ad utilizzare lo stesso kernel. DUMBVM rappresenta una particolare versione, eventualmente modificata, del sistema operativo os161. Le tre righe rappresentano, rispettivamente:

- L’eseguibile (MIPS) di cui fare debug

- Il direttorio (di compilazione) da cui partire per localizzare i file sorgenti (solo se si è interessati, fortemente consigliato, a una sessione di debug in cui si si visualizzi il programma sorgente C). In questo caso è sufficiente localizzare i file oggetto, che contengono i riferimenti ai sorgenti

- La connessione al socket per far colloquiare sys161 e debugger

La creazione di una nuova versione viene descritta nel seguito (“Modificare il Kernel”). Se, dopo aver ricompilato altri kernel (es. kernel-GENERIC, kernel-ASST1, kernel-HELLO, …) si utilizzerà uno di questi, va usato lo stesso nelle due finestre.

I due comandi iniziali (`dir` e `target`) sono stati per comodità inseriti in un file di comandi di inizializzazione per gdb (`os161/root/.gdbinit`), che definisce un unico comando, `dbos161` (e lo chiama, rendendo inutile l’esecuzione esplicita).

**QUINDI, NELLA VERSIONE INSTALLATA, NON SONO NECESSARI I TRE COMANDI, SE SI USA DUMBVM. SE SI CAMBIA VERSIONE, SI CONSIGLIA DI MODIFICARE OPPORTUNAMENTE  `os161/root/.gdbinit`**, in modo da prevedere altre versioni. Si può infatti modificare tale file aggiungendo altri comandi per eventuali altre versioni.

La versione di gdb appena descritta corrisponde alla versione “in linea” (piuttosto scomoda). SI SCONSIGLIA DECISAMENTE DI USARE QUESTA VERSIONE. MEGLIO LE ESECUZIONI CON INTERFACCIA A FINESTRE, DESCRITTE SOTTO.

Per eventuale esecuzione di gdb con interfaccia a finestre, sono disponibili:

- gdb in versione con finestra per il sorgente (è la scelta più elementare/semplice):
```bash
mips-harvard-os161-gdb –tui kernel
```
- ddd
```bash
ddd --debugger  mips-harvard-os161-gdb kernel
```
- l’editor emacs, da cui è possibile attivare una finestra di debugger: una volta entrati in emacs (comando “emacs”), il debugger si attiva con tools->Debugger, modificando il comando proposto (riga in basso) con:
```
mips-harvard-os161-gdb –i=mi kernel
```
**ATTENZIONE**: nel caso in cui sys161 sia andato in crash, occorre farlo ripartire, e ri-connettere il debugger, facendolo ripartire, oppure ri-eseguendo semplicemente il comando “dbos161”. In tal caso, NON E’ NECESSARIO FAR RIPARTIRE mips-harvard-os161-gdb, MA SOLO sys161. Va comunque, dal deburrer, ri-connesso il socket (ad esempio rieseguendo “dbos161” o altro comando equivalente, eventualmente aggiunto a os161/root/.gdbinit.

## Modificare il kernel

> (I sorgenti del kernel sono nella cartella os161/os161-base-2.0.2/kern e relative sotto-cartelle: si omette in questa parte il prefisso e si indicano i direttori a partire da “kern”.

Una nuova versione del kernel implica modifica e/o aggiunta di file sorgenti. Si veda la descrizione [Bulding OS/161](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html) (sezioni: “Configure a kernel” e “Compile a kernel”).

Ogni nuova versione del kernel corrisponde a un file di configurazione (scritto in maiuscolo) nella cartella `os161/os161-base-2.0.2/kern/conf`). Nelle vecchie versioni di os161 le configurazioni avevano nomi ASSTx (x=0,1,2,3,4, …). Ora si propone DUMBVM (o DUMBVM-OPT) per la versione con gestione della memoria “dumbvm”, GENERIC (o GENERIC-OPT) per una nuova versione, ad esempio la prima su cui lavorare, altri nomi, in funzione del tipo di lavoro effettuato.

Si consiglia di iniziare su DUMBVM, per la prima esecuzione, senza modifiche, per passare poi a una nuova versione, chiamata HELLO. Il primo lavoro consiste nell’inserire un messaggio aggiuntivo su video al bootstrap. Per fare questo, si chiede di aggiungere un file `hello.c` nel direttorio `kern/main`, nel quale creare una funzione `hello()`, che scrive un messaggio su video utilizzando la funzione `kprintf`.

Si riportano qui le istruzioni dettagliate:

- Creare un file `kern/main/hello.c`

- Scrivere nel file appena creato una funzione `hello` che utilizza `kprintf()` per scrivere un messaggio a video. Pur se non necessario, si consiglia di creare un file `kern/include/hello.h`, che contenga il prototipo della funzione `hello`.
**ATTENZIONE**: il compilatore C usato necessita parametro void nel caso di assenza di parametri. Ad esempio, il prototipo di hello potrebbe essere `void hello (void);`

- Modificare `kern/main/main.c` inserendo una chiamata a `hello()`. Per utilizzare correttamente `kprintf`, è necessario includere `types.h` e `lib.h`.

- L’eventuale inclusione di `hello.h` `(#include “hello.h”`) va fatta sia in `main.c` che in `hello.c`.

- Modificare `kern/conf/conf.kern` inserendo il nuovo file `hello.c` nell’elenco dei file. Ad esempio
```
file      main/main.c
file      main/menu.c
defoption hello
optfile   hello   main/hello.c
```
 
> Riassumendo, al fine di chiamare in `main.c` una funzione presente in `hello.c`, è necessario (in `main.c`) il prototipo di tale funzione. Questo può essere fatto in modo esplicito, oppure (soluzione migliore) includendo al file `kern/include/hello.h`.

- Riconfigurare e ricompilare il sistema

### Configurazione

In `kern/conf` generare il file `HELLO` (ad es. copiando DUMBVM: **ATTENZIONE**, aggiungere a tale file una riga `option hello`!) e dare il commando
```
./config HELLO
```
Per fare in modo che `hello.c` e la chiamate a `hello()` siano visibili/attive solo con l’opzione di configurazione hello, sono quindi necessari i passi seguenti:

- Usare l’opzione `hello`, definita in `conf.kern` e rendere `hello.c` file opzionale (abilitato da tale opzione). Come conseguenza sarò generato automaticamente un file `opt-hello.h`, contenente `#define OPT_HELLO 1 `oppure `#define OPT_HELLO 0`

  Rendere opzionali le istruzioni di altri file che utilizzino hello:

   - Il file hello.h
```c
#ifndef _HELLO_H_
#define _HELLO_H_

void hello(void);

#endif
```
   potrebbe rendere opzionale il suo contenuto come segue

```c
#ifndef _HELLO_H_
#define _HELLO_H_

#include “opt-hello.h”
#if OPT_HELLO
void hello(void);
#endif

#endif
```

   -La chiamata a `hello()` nel main può esser resa opzionale come segue
```
#if OPT_HELLO
   hello();
#endif
```

### Compilazione

In `kern/compile/HELLO`effettuare
```bash
bmake depend
bmake
bmake install
```
 

Nel caso di errori di compilazione, è sufficiente ripetere `bmake`. Provare a eseguire os161 per verificare che al bootstrap sia stampato il messaggio.

## Programmazione concorrente con OS161

Realizzare questo esercizio con configurazione: THREADS, anziche’ DUMBVM o HELLO: Si consiglia di tentare una configurazione nuova solamente come esercizio, nonostante non ve ne sia necessità (non si modifica nessun sorgente).

### Built-in thread tests

Quando si avvia os161, tra le opzioni disponibili dal menu, si possono avviare i test per thread. Si tratta di funzioni NON caricate come eseguibili separati, ma direttamente likati nel kernel (in pratica, quindi, di parti del kernel).
I programmi di test dei thread usano sincronizzazione basata su semafori. Si può tentare di tracciarne l’esecuzione in GDB, per verificare come lavora lo scheduler, cone sono creati i thread, e cosa succede al context-switch. Per far questo, si consiglia di tracciare funzioni quali `thread_create` `thread_fork`, `thread_yield`, …

Il test `tt1` stampa i numeri da 0 a 7 ad ogni loop del thread, `tt2` stampa solo ad inizio e fine dei thread (serve a dimostrare che lo scheduler non genera starvation). I threads sono avviati e girano per un po’ di iterazioni. Il test `tt3` utilizza semafori, che nella versione base di OS161 non funzionano correttamente: il problema sarà affrontato in un futuro laboratorio.

Il sorgente di avvio dei test si trova in menu.c

#### Fare debug di programmi con thread

Siccome la funzione `thread_yield` viene chiamata a intervalli random, per generare (e farne il debug) sequenze di esecuzione ripetibili si consiglia di usare un seme per inizializzazione fissa del generatore di numeri casuali (direttiva “random” in `sys161.conf`). Passare ad autoseed sono quando tutto funziona.

## Eseguire un programma utente in OS161 (chiamare la nuova versione del sistema USERP)

<!-- TODO: change version of os161 -->

OS/161 contiene un insieme di programmi utente già predisposti per l'esecuzione sul kernel. Questo insieme include programmi di utilità comuni in ambito UNIX, quali ls and cat, oltre a vari altri programmi di test.  I sorgenti di tali programmi si trovano, a partire dalla radice dei sorgenti (`os161/os161-base-1.99.05`), in `userland/{bin,sbin,testbin}`.

Molti dei programmi sopra citati non sono in grado di funzionare correttamente,  con OS161 nella forma iniziale, in quanto le “system calls” chiamate non sono ancora implementate. Per farli funzionare correttamente occorre quindi implementare tali system calls.

Per creare gli eseguibili dei programmi utente occorre,  a partire dai direttori dei file sorgenti, eseguire

``bmake``

Gli eseguibili creati, in formato ELF, sono installati nel direttorio `pds-os161/root/ `nei sotto-direttori `bin`, `sbin` e `testbin`, rispettivamente. Un insieme di programmi eseguibili già predisposti è presente in tali direttori.

Obiettivo iniziale del laboratorio è analizzare la fase di “load” di un eseguibile, sino all'avvio dell'esecuzione, NONOSTANTE il programma non funzioni poi correttamente (nella seconda parte del laboratorio si realizzeranno due system call in grado di supportare INPUT e OUTPUT, permettendo quindi l'esecuzione completa di alcuni programmi di test).

Per analizzare la fase di load e avvio dell'esecuzione di un programma di test,  occorre attivare il programma dal menu di os161, mediante il comando `p <programma>`, ad esempio `p testbin/palin`, `p sbin/reboot`, dopo aver impostato uno o più breakpoints del debugger, sulle funzioni che eseguono tali operazioni. Si consiglia, ad esempio, di mettere breakpoints su:

- `common_prog`
- `thread_fork`
- `thread_startup`
- `cmd_progthread`
- `runprogram`
- `load_elf`

Si analizzi, in particolare, la fase di attivazione di un nuovo thread e di caricamento del file ELF.  Si determini a quali indirizzi di memoria (e come) vengono caricate le parti del file ELF. A tale scopo, si noti che in varie parti del codice sorgente di kernel, compaiono istruzioni del tipo `DEBUG(...)`, che eseguono eventuali kprintf, controllate dal valore della variabile globale dbflags.  Per la definizione completa dei valori da assegnare a dbflags, si veda il file `kern/include/lib.h`. Se ad esempio, si volessero attivare le DEBUG in load_segment, occorrerebbe attivare, in dbflags, il flag `DB_EXEC`, definito come `0x040`. A tale scopo, si può ad esempio usare l'istruzione di gdb: `set dbflags = 0x040`.

Utilizzando quindi le istruzioni DEBUG, opportunamente attivate in GDB, si chiede pertanto di esaminare l'esecuzione di `load_elf`, di determinare come viene predisposto lo spazio degli indirizzi del thread in esecuzione (segmento di codice, dati, e stack) e come viene attivata l'esecuzione del programma in user-mode.

Si provi inoltre a verificare quale/quanta memoria viene allocata per il thread in esecuzione, e quale di questa memoria viene rilasciata al termine di tale esecuzione. Si modifichi la funzione `load_elf` in modo tale che vengano stampati a video le dimensioni e gli indirizzi logici e fisici di partenza dei segmenti di memoria virtuale e dello stack.

Quale funzione occorrerebbe modificare per rilasciare tutta la memoria utilizzata? Sarebbe possibile una minima modifica al kernel tale da ripristinare lo stato della memoria precedente all'esecuzione del thread?

## Scrivere una nuova system call in OS161 (SYSCALL)

La funzione principale di un kernel è quella di fornire il supporto per programmi user-level. Tale supporto è in genere fornito tramite le "system calls". Si noti che un programma utente viene attivato dal menu di os161 mediante il comando `p <programma>`, ad esempio `p testbin/palin`, `p sbin/reboot`.

Os161, nella versione base, fornisce solo 2 system call (`reboot` e `__time`).  Ad esempio, la system call `reboot()`, viene implementata dalla funzione di kernel  `sys_reboot()`,  in `main.c`.  Si ricorda che una system call permette a un programma (in modalità user) di richiedere un servizio al kernel, mediante una trap che attiva la funzione `syscall()`.

In GDB, se si vuole mettere un breakpoint su `sys_reboot` e attivarla, basta (dopo aver messo il break point e aver fatto ripartire il kernel (ad esempio con i comandi GDB `break sys_reboot` e `continue`) chiamare il programma `sbin/reboot` (comando `p sbin/reboot`). Una volta che gdb si trova in `sys_reboot()`, usare `backtrace`, oppure `up/down`, per localizzare la sequenza delle chiamate.  In breve, la funzione utente `reboot()`,  attiverà indirettamente una trap di sistema, che chiamerà la funzione `syscall()` (file `kern/arch/mips/syscall.c`), la quale,  mediante un costrutto `switch/case`,  attiverà la `sys_reboot()`.  

A questo punto è possible tentare di creare una nuova system call. Per generare una nuova system call occorre:

- Creare nuove funzioni utente, oppure utilizzarne di esistenti (ma ancora prive di supporto, in os161 base). Nel caso specifico,  si consiglia di utilizzare le funzioni `write` e `read`,  che vengono indirettamente richiamata da printf e scanf.

- Generare nuove system call da associare alle funzione utente.

   - Occorre un codice intero (si veda il file `kern/include/kern/syscall.h`), da utilizzare nel costrutto switch/case (in `syscall()`) visto in precedenza (le costanti `SYS_read` e `SYS_write` sono già definite (`50` e `55`) e quindi utilizzabili).

   - Occorre una funzione da richiamare, nel costrutto `switch`.  Utilizzando le convenzioni già utilizzate, si consiglia di generare (in analogia a `sys_reboot`) le funzioni `sys_write()` e `sys_read()` (Si consiglia di iniziare dalla prima). La funzione `sys_reboot()` si trova nel file `menu.c`, ma si consiglia di generare un nuovo sorgente nel direttorio `kern/syscall` (ad es. `stdio_syscalls.c`,  analogo a `time_syscalls.c`),  nel quale realizzare le funzioni `sys_write()` e `sys_read()`, cominciando dalla prima).

  - Passaggio dei parametri. La funzione `syscall()`,  attivata da trap,  riceve come parametro `struct trapframe *tf`.  La struct puntata contiene, tra le altre informazioni, i parametri passati alla write (un file id, un puntatore a una stringa e il numero di caratteri da stampare – ATTENZIONE, la stringa non è necessariamente terminata da `\0`). Tali parametri sono reperibili in `tf->tf_a0, …_a1, …_a2, …_a3`.  Si vedano le system call già implementate, lavorando in modo analogo per `sys_write()`e `sys_read()`.  Per conoscere i prototipi esatti delle funzioni  `write()` e `read()`, usare i comandi (da finestra terminale) `man 2 write` e `man 2 read`.

- Aggiungere le informazioni necessarie per fare make di un nuovo kernel, e realizzarlo:

  - Aggiungere il prototipo della `sys_write` al file `kern/include/syscall.h`.

  - Determinare a quale configurazione si fa riferimento in `kern/conf` (es. `SYSCALL`).

   -In conf.kern aggiungere il nuovo file (es. `syscalls/stdio_syscalls.c`)

  - Rifare il make del kernel

- Eseguire (possibilmente in debug) un programma utente che attivi la system call. Un esempio è la `testbin/palin` (sorgenti in `userland/testbin`). Attenzione, i programmi attivabili da menu come `p testbin/xxx` non supportano gli argomenti al main (per abilitarli serve una implementazione della `malloc`, in quanto le stringhe vanno passate dal menu ai thread che mandano in esecuzione (in user space) un file eseguibile (elf). Nella versione attuale, quindi, i programmi vanno chiamati senza argomenti (quindi non funzionano completamente, o vanno modificati).

Informazioni più dettagliate sulle system calls sono reperibili sul documento “understanding system calls”