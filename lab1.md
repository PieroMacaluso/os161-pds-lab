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
```
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
```
sys161 -w kernel
```
sulla seconda, dallo stesso direttorio
```
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
```
mips-harvard-os161-gdb –tui kernel
```
- ddd
```
ddd --debugger  mips-harvard-os161-gdb kernel
```
- l’editor emacs, da cui è possibile attivare una finestra di debugger: una volta entrati in emacs (comando “emacs”), il debugger si attiva con tools->Debugger, modificando il comando proposto (riga in basso) con:
```
mips-harvard-os161-gdb –i=mi kernel
```
**ATTENZIONE**: nel caso in cui sys161 sia andato in crash, occorre farlo ripartire, e ri-connettere il debugger, facendolo ripartire, oppure ri-eseguendo semplicemente il comando “dbos161”. In tal caso, NON E’ NECESSARIO FAR RIPARTIRE mips-harvard-os161-gdb, MA SOLO sys161. Va comunque, dal deburrer, ri-connesso il socket (ad esempio rieseguendo “dbos161” o altro comando equivalente, eventualmente aggiunto a os161/root/.gdbinit.

## Modificare il kernel

> (I sorgenti del kernel sono nella cartella os161/os161-base-2.0.2/kern e relative sotto-cartelle: si omette in questa parte il prefisso e si indicano i direttori a partire da “kern”.

Una nuova versione del kernel implica modifica e/o aggiunta di file sorgenti. Si veda la descrizione [Bulding OS/161](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html) (sezioni: “Configure a kernel” e “Compile a kernel”).<div class="WordSection1">

**<span style="font-size:18.0pt">PdS 2019 - Laboratorio OS161 1</span>**

Il Sistema SIS161 – OS161 è installato in una macchina virtuale VBOX OSE, con S.O. Linux Ubuntu 14.04 (versione in inglese).

Presso il LAIB1 sono disponibili macchine virtuali oVirt (Open Virtualization Manager) con Ubuntu 14.04 (versione in italiano)

La macchina virtuale (file linux-pds-ovf10.ova) è anche disponibile per download (ad esempio per uso su PC personale) su [https://elearning.polito.it/secure/linux-pds-ovf10.ova](https://elearning.polito.it/secure/linux-pds-ovf10.ova) (solo da intranet politecnico, occorre login con credenziali studente). Si consiglia, per uso personale, di installare VirtualBox (https://www.virtualbox.org).

# <span style="font-family:&quot;Times&quot;,&quot;serif&quot;">Per attivare la macchina virtuale, eseguire i passi sotto-elencati</span>

1)    Login, al LABINF, su Windows (preferibile) o Linux. Login su Linux (versione specifica per OS161) al LAIB,

2)    Copiare il file linux-pds-ovf10.ova in un direttorio locale. Si tratta di un file compresso da cui verrà successivamente estratta la macchina virtuale. Al LABINBF il file si trova nella cartella [\\cclix1\corsi\cabodi](file:///\\cclix1\corsi\cabodi) (windows) oppure smb://cclix1/corsi/cabodi. Su windows, il file va copiato in locale, evitando il disco Z: (dimensione non sufficiente). Su linux usare /var/tmp/<matricola>.

3)    Avviare Virtual Box.

4)    Importare la macchina virtuale utilizzando il comando “import appliance” (“importa applicazione virtuale”), Attenzione: per l’esecuzione al LABINF, nella finestra di configurazione della macchina virtuale, su consiglia di modificare il direttorio per l’immagine del disco virtuale, collocandolo in “/var/tmp” (per problemi di quota su disco),

5)    Avviare la macchina virtuale.

6)    E’ abilitato automaticamente il login con

<span style="font-family:Symbol" lang="EN-US">·</span>         USER: pds

<span style="font-family:Symbol" lang="EN-US">·</span>         PASSWORD: pdsuser

 7)    La macchina virtuale potrà essere esportata, al termine del lavoro, con una procedura duale: comando “export appliance” (esporta applicazione virtuale).

**<span style="font-size:11.0pt;line-height:115%">Procedura per Linux al LAIB</span>**

Linux è disponibile come macchina virtuale in VDI (accessibile mediante client oVirt). La descrizione dettagliata viene fornita in un altro documento.

**_Al termine del lavoro, è NECESSARIO chiudere la macchina virtuale linux (comando “arresta” in alto a destra, icona ingranaggio)._** 

# <span style="font-family:&quot;Times&quot;,&quot;serif&quot;">Ambiente OS161</span>

Il sistema operativo os161 è stato pre-installato nel direttorio **os161/os161-base-2.0.2**, mentre i pacchetti SW richiesti, binutils, compilatore gcc e debugger gdb, emulatore MIPS, sono installati nella cartella **os161/tools**. SI NOTI CHE TUTTI I DIRETTORI SONO INDICATI A PARTIRE DA $HOME, che è /usr/pds (versione VBOX) oppure /home/corso (versione VDI/LAIB1).

Si ricorda che il sistema OS161 è attivato sull’emulatore di processore MIPS, SYS161\. Al fine di ri-compilare OS161, nonché di fare debug e altre operazioni (ad esempio visualizzazione di file eseguibili), sono necessari programmi previsti per la piattaforma MIPS, che sono stati installati con il prefisso “**mips-harvard-os161-“: mips-harvard-os161**-gcc, **mips-harvard-os161**-gdb (eseguibili in **os161/tools**/bin).

Il sito web di riferimento è: [http://os161.eecs.harvard.edu/](http://os161.eecs.harvard.edu/). L’ultima versione è disponibile (con le precedenti) su [http://os161.eecs.harvard.edu/download/](http://os161.eecs.harvard.edu/download/).

Un altro sito con informazioni interessanti è quello del corso cs350 dell’università di Waterloo (Canada): [http://www.student.cs.uwaterloo.ca/~cs350/common/OS161main.html](http://www.student.cs.uwaterloo.ca/%7Ecs350/common/OS161main.html)

Sul desktop della macchina virtuale è presente un link al codice sorgente “navigabile” da un web browser. Per eventuali installazioni sul proprio PC, occorre seguire le istruzioni presenti su uno dei siti sopra proposti. Si forniscono a parte degli script di installazione per un sistema Linux-Ubuntu.

Informazioni dettagliate su avvio ed esecuzione di OS161 sono raggiungibili, ad esempio, dal link: [Working with OS161](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html)

La cartella iniziale di **lavoro** proposta è **pds-os161/root**.

[<span style="color:black;text-decoration:none"> </span>](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html)

<span style="display:inline-block">_ATTENZIONE: ci sono quindi due direttori_</span>

<span style="display:inline-block"><span style="font-family:Symbol">·</span>         _os161: contiene sorgenti, file di configurazione, compilazione ed eseguibili, di os161 e dei tool utilizzati (è quindi l’area in cui si modifica e ri-compila os161)_</span>

<span style="display:inline-block"><span style="font-family:Symbol">·</span>         _pds-os161/root: si tratta del direttorio in cui eseguire il (fare boot del) sistema operativo, ed eventualmente attivare processi user (è l’area in cui si esegue e si testa il sistema os161).  _</span>

Per fare bootstrap di OS161 in ambiente emulato sys161 (da una shell, attivabile in una finestra “Terminal”), sono possibili due modalità:

<span style="font-family:Symbol">·</span>     Esecuzione normale:  

_cd $HOME/pds-os161/root  
sys161 kernel_  

Compare una videata come la seguente

_<span lang="EN-US">sys161: System/161 release 2.0.8, compiled Mar 30 2016 12:38:39</span>_

_<span lang="EN-US">OS/161 base system version 2.0.2</span>_

_<span style="color:black" lang="EN-US">Copyright (c) 2000, 2001-2005, 2008-2011, 2013, 2014</span>_

_<span lang="EN-US">President and Fellows of Harvard College.  All rights reserved.</span>_

_<span lang="EN-US">Put-your-group-name-here's system version 0 (DUMBVM #1)</span>_

_<span lang="EN-US">788k physical memory available</span>_

_<span lang="EN-US">Device probe...</span>_

_<span lang="EN-US">lamebus0 (system main bus)</span>_

_<span lang="EN-US">emu0 at lamebus0</span>_

_<span lang="EN-US">ltrace0 at lamebus0</span>_

_<span lang="EN-US">ltimer0 at lamebus0</span>_

_<span lang="EN-US">beep0 at ltimer0</span>_

_<span lang="EN-US">rtclock0 at ltimer0</span>_

_<span lang="EN-US">lrandom0 at lamebus0</span>_

_<span lang="EN-US">random0 at lrandom0</span>_

_<span lang="EN-US">lhd0 at lamebus0</span>_

_<span lang="EN-US">lhd1 at lamebus0</span>_

_<span lang="EN-US">lser0 at lamebus0</span>_

_<span lang="EN-US">con0 at lser0</span>_

<span lang="EN-US"> </span>

_<span lang="EN-US">cpu0: MIPS/161 (System/161 2.x) features 0x0</span>_<span lang="EN-US"> </span>

_OS/161 kernel [? for menu]:_

Dalla quale sono attivabili comandi (menu con ?). Alcuni comandi (es. quelli selezionabili con ?o) non sono completamente disponibili, in quanto OS161 non è un sistema completo (richiede aggiunte da parte dello studente).

<span style="font-family:Symbol">·</span>     Esecuzione con **_debugger_**.

**_ATTENZIONE: il programma eseguito sul sistema Ububtu è sys161\. Sys161 è un eseguibile per la macchina host (con processore Intel o AMD, sys161 viene già fornito e NON necessita debug). Il comando “sys161 kernel” manda in esecuzione “sys161”, un programma che funge da macchina virtuale con processore MIPS, per la quale “kernel” è un file “eseguibile” che viene caricato e mandato in esecuzione: obiettivo del laboratorio è interagire con “kernel”, eseguito su macchina MIPS (sys161), NON interagire con sys161\._**

Occorre evitare di fare il debug dell’emulatore SYS161\. Il debugger (per la piattaforma MIPS) deve quindi essere eseguito una volta avviato SYS161\. A tale scopo occorrono due processi, uno per eseguire sys161 (avviato in una modalità predisposta per fare debug del kernek) e uno per mips-harvard-os161-gdb (un debugger predisposto per macchina mips), comunicanti mediante socket. Si consiglia di attivare due finestre terminale. Sulla prima, dal direttorio pso-os161/root eseguire il comando:  
<span style="font-family:&quot;Courier New&quot;">  
_sys161 -w kernel  
_</span>  
sulla seconda, dallo stesso direttorio  

_<span style="font-family:&quot;Courier New&quot;">mips-harvard-os161-gdb kernel  
(gdb) dir ../../os161/os161-base-2.0.2/kern/compile/DUMBVM  
(gdb) target remote unix:.sockets/gdb  
</span>_  
attenzione ad utilizzare lo stesso kernel. DUMBVM rappresenta una particolare versione, eventualmente modificata, del sistema operativo os161\. Le tre righe rappresentano, rispettivamente:

<span style="font-family:Symbol">·</span><span style="font-size:7.0pt;line-height:
115%;font-family:&quot;Times New Roman&quot;,&quot;serif&quot;"></span> L’eseguibile (MIPS) di cui fare debug

<span style="font-family:Symbol">·</span><span style="font-size:7.0pt;line-height:
115%;font-family:&quot;Times New Roman&quot;,&quot;serif&quot;"></span> Il direttorio (di compilazione) da cui partire per localizzare i file sorgenti (solo se si è interessati, **fortemente consigliato**, a una sessione di debug in cui si si visualizzi il programma sorgente C). In questo caso è sufficiente localizzare i file oggetto, che contengono i riferimenti ai sorgenti

<span style="font-family:Symbol">·</span><span style="font-size:7.0pt;line-height:
115%;font-family:&quot;Times New Roman&quot;,&quot;serif&quot;"></span> La connessione al socket per far colloquiare sys161 e debugger

La creazione di una nuova versione viene descritta nel seguito (“Modificare il Kernel”). Se, dopo aver ricompilato altri kernel (es. kernel-GENERIC, kernel-ASST1, kernel-HELLO, …) si utilizzerà uno di questi, va usato lo stesso nelle due finestre.

I due comandi iniziali (dir e target) sono stati per comodità inseriti in un file di comandi di inizializzazione per gdb (os161/root/.gdbinit), che definisce un unico comando, “dbos161” (e lo chiama, rendendo inutile l’esecuzione esplicita). QUINDI, NELLA VERSIONE INSTALLATA, NON SONO NECESSARI I TRE COMANDI, SE SI USA DUMBVM. SE SI CAMBIA VERSIONE, SI CONSIGLIA DI MODIFICARE OPPORTUNAMENTE  os161/root/.gdbinit, in modo da prevedere altre versioni. Si può infatti modificare tale file aggiungendo altri comandi per eventuali altre versioni.

La versione di gdb appena descritta corrisponde alla versione “in linea” (piuttosto scomoda). SI SCONSIGLIA DECISAMENTE DI USARE QUESTA VERSIONE. MEGLIO LE ESECUZIONI CON INTERFACCIA A FINESTRE, DESCRITTE SOTTO:

       Per eventuale esecuzione di gdb con interfaccia a finestre, sono disponibili:

<span style="font-family:Symbol">·</span> gdb in versione con finestra per il sorgente (è la scelta più elementare/semplice):  

_<span style="font-family:&quot;Courier New&quot;">mips-harvard-os161-gdb –tui kernel</span>_

<span style="font-family:Symbol" lang="EN-US">·</span><span lang="EN-US">ddd (comando</span> _<span style="font-family:
&quot;Courier New&quot;" lang="EN-US">ddd</span>_ <span lang="EN-US"></span> _<span style="font-family:&quot;Courier New&quot;" lang="EN-US">--debugger</span>_<span lang="EN-US"></span> _<span style="font-family:&quot;Courier New&quot;" lang="EN-US">mips-harvard-os161-gdb kernel)</span>_

<span style="font-family:
Symbol">·</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">l’editor</span> _<span style="font-family:&quot;Courier New&quot;">emacs,</span> _da cui è possibile attivare una finestra di debugger: una volta entrati in emacs (comando “emacs”), il debugger si attiva con tools->Debugger, modificando il comando proposto (riga in basso) con:  
_<span style="font-family:&quot;Courier New&quot;">mips-harvard-os161-gdb –i=mi kernel</span>_

_<span style="font-family:&quot;Courier New&quot;">ATTENZIONE:</span> _nel caso in cui sys161 sia andato in crash, occorre farlo ripartire, e ri-connettere il debugger, facendolo ripartire, oppure ri-eseguendo semplicemente il comando “dbos161”_<span style="font-family:&quot;Courier New&quot;">.</span>_ In tal caso, NON E’ NECESSARIO FAR RIPARTIRE _<span style="font-family:&quot;Courier New&quot;">mips-harvard-os161-gdb</span>_, MA SOLO sys161\. Va comunque, dal deburrer, ri-connesso il socket (ad esempio rieseguendo “dbos161” o altro comando equivalente, eventualmente aggiunto a os161/root/.gdbinit.

# <span style="font-family:&quot;Times&quot;,&quot;serif&quot;">Modificare il kernel</span>

_<u><span style="color:black">(I sorgenti del kernel sono nella cartella os161/os161-base-2.0.2/kern e relative sotto-cartelle: si omette in questa parte il prefisso e si indicano i direttori a partire da “kern”).</span></u>_

<span style="color:black">Una nuova versione del kernel implica modifica e/o aggiunta di file sorgenti. Si veda la descrizione</span> [Bulding OS/161 (sezioni: “Configure a kernel” e “Compile a kernel”)<span style="color:black;text-decoration:none">.</span>](http://www.student.cs.uwaterloo.ca/~cs350/common/WorkingWith161.html)

<span style="color:black">Ogni nuova versione del kernel corrisponde a un file di configurazione (scritto in maiuscolo) nella cartella os161/os161-base-2.0.2/kern/conf). Nelle vecchie versioni di os161 le configurazioni avevano nomi ASSTx (x=0,1,2,3,4, …). Ora si propone DUMBVM (o DUMBVM-OPT) per la versione con gestione della memoria “dumbvm”, GENERIC (o GENERIC-OPT) per una nuova versione, ad esempio la prima su cui lavorare, altri nomi, in funzione del tipo di lavoro effettuato.</span>

<span style="color:black">Si consiglia di iniziare su DUMBVM, per la prima esecuzione, senza modifiche, per passare poi a una nuova versione, chiamata HELLO. Il primo lavoro consiste nell’inserire un messaggio aggiuntivo su video al bootstrap. Per fare questo, si chiede di aggiungere un file hello.c nel direttorio kern/main, nel quale creare una funzione hello(), che scrive un messaggio su video utilizzando la funzione kprintf.</span>

<span style="color:black">Si riportano qui le istruzioni dettagliate</span>

<span style="color:black" lang="EN-US">Creare un file</span> <span style="font-family:&quot;Courier New&quot;;color:black" lang="EN-US">kern/main/hello.c</span>

<span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Scrivere nel file appena creato una funzione</span> <span style="font-family:&quot;Courier New&quot;;
color:black">hello</span> <span style="color:black">che utilizza</span> <span style="font-family:&quot;Courier New&quot;;color:black">kprintf</span><span style="color:black">() per scrivere un messaggio a video. Pur se non necessario, si consiglia di creare un file</span> <span style="font-family:&quot;Courier New&quot;;
color:black">kern/include/hello.h</span><span style="color:black">, che contenga il prototipo della funzione hello. ATTENZIONE: il compilatore C usato necessita parametro void nel caso di assenza di parametri. Ad esempio, il prototipo di hello potrebbe essere</span>

<span style="font-family:&quot;Courier New&quot;;color:black">void hello (void);</span>

<span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Modificare</span> <span style="font-family:&quot;Courier New&quot;;color:black">kern/main/main.c</span> <span style="color:black">inserendo una chiamata a hello</span><span style="font-family:&quot;Courier New&quot;;color:black">().</span> <span style="font-family:
&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Per utilizzare correttamente</span> <span style="font-family:&quot;Courier New&quot;;color:black">kprintf</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">, è necessario includere</span> <span style="font-family:&quot;Courier New&quot;;color:black">types.h</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">e</span> <span style="font-family:&quot;Courier New&quot;;color:black">lib.h</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">.</span>

<span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">L’eventuale inclusione di</span> <span style="font-family:&quot;Courier New&quot;;color:black">hello.h</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">(</span><span style="font-family:&quot;Courier New&quot;;color:black">#include “hello.h”</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">) va fatta sia in</span> <span style="font-family:&quot;Courier New&quot;;color:black">main.c</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">che in</span> <span style="font-family:&quot;Courier New&quot;;color:black">hello.c</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">.</span>

<span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">Modificare</span> <span style="font-family:&quot;Courier New&quot;;
color:black">kern/conf/conf.kern</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">inserendo il nuovo file</span> <span style="font-family:&quot;Courier New&quot;;
color:black">hello.c.</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">nell’elenco dei file.</span> <span style="font-family:
&quot;Times New Roman&quot;,&quot;serif&quot;;color:black" lang="EN-US">Ad esempio</span>

<span style="font-family:&quot;Courier New&quot;;
color:black" lang="EN-US">file      main/main.c</span>

<span style="font-family:&quot;Courier New&quot;;
color:black" lang="EN-US">file      main/menu.c</span>

**_<span style="font-family:&quot;Courier New&quot;;
color:black" lang="EN-US">defoption hello</span>_**

**_<span style="font-family:&quot;Courier New&quot;;
color:black" lang="EN-US">optfile   hello   main/hello.c</span>_**

<span style="color:black" lang="EN-US"> </span>

<span style="font-size:12.0pt;
color:black">Riassumendo, al fine di chiamare in main.c una funzione presente in hello.c, è necessario (in main.c) il prototipo di tale funzione. Questo può essere fatto in modo esplicito, oppure (soluzione migliore) includendo al file</span> <span style="font-family:&quot;Courier New&quot;;color:black">kern/include/hello.h.</span>

<span style="color:black">Riconfigurare e ricompilare il sistema</span>

<span style="color:black">CONFIGURAZIONE</span>

<span style="font-size:12.0pt;color:black">In kern/conf generare il file HELLO (ad es. copiando DUMBVM: ATTENZIONE, **aggiungere a tale file una riga “option hello”**!) e dare il commando</span>

<span style="font-size:12.0pt;color:black">./config HELLO</span>

<span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">Per fare in modo che</span> <span style="font-family:&quot;Courier New&quot;;
color:black">hello.c</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">e la chiamate a</span> <span style="font-family:&quot;Courier New&quot;;
color:black">hello</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;
color:black">() siano visibili/attive solo con l’opzione di configurazione hello, sono quindi necessari i passi seguenti:</span>

<span style="font-family:Symbol">·</span><span style="font-size:7.0pt;font-family:
&quot;Times New Roman&quot;,&quot;serif&quot;"></span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">Usare l’opzione hello, definita in</span> <span style="font-family:&quot;Courier New&quot;">conf.kern</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">e rendere hello.c file opzionale (abilitato da tale opzione). Come conseguenza sarò generato automaticamente un file opt-hello.h, contenente</span> <span style="font-family:&quot;Courier New&quot;">#define OPT_HELLO 1</span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">oppure</span> <span style="font-family:&quot;Courier New&quot;">#define OPT_HELLO 0</span>

<span style="font-family:Symbol">·</span><span style="font-size:7.0pt;font-family:
&quot;Times New Roman&quot;,&quot;serif&quot;"></span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">Rendere opzionali le istruzioni di altri file che utilizzino hello:</span>

<span style="font-family:&quot;Courier New&quot;">o</span><span style="font-size:7.0pt;font-family:&quot;Times New Roman&quot;,&quot;serif&quot;"></span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">Il file</span> <span style="font-family:&quot;Courier New&quot;">hello.h</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">  

</span><span style="font-family:&quot;Courier New&quot;">#ifndef _HELLO_H_  
#define _HELLO_H_  

void hello(void);  

#endif  
</span><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">  
potrebbe rendere opzionale il suo contenuto come segue  

</span><span style="font-family:&quot;Courier New&quot;">#ifndef _HELLO_H_  
#define _HELLO_H_  

**#include “opt-hello.h”  
#if OPT_HELLO  
**void hello(void);  
**#endif  
**  
#endif</span>

<span style="font-family:&quot;Courier New&quot;">o</span><span style="font-size:7.0pt;font-family:&quot;Times New Roman&quot;,&quot;serif&quot;"></span> <span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">La chiamata a hello() nel main può esser resa opzionale come segue  
</span><span style="font-family:&quot;Courier New&quot;">#if OPT_HELLO  
   hello();  
#endif</span>

<span style="font-size:12.0pt;
color:black">COMPILAZIONE</span>

<span style="font-size:12.0pt;color:black">In kern/compile/HELLO effettuare</span>

<span style="font-size:12.0pt;color:black">bmake depend</span>

<span style="font-size:12.0pt;color:black">bmake</span>

<span style="font-size:12.0pt;color:black">bmake install</span>

<span style="font-size:12.0pt;
color:black">Nel caso di errori di compilazione, è sufficiente ripetere bmake. Provare a eseguire os161 per verificare che al bootstrap sia stampato il messaggio.</span>

# <span style="font-family:&quot;Times&quot;,&quot;serif&quot;">Programmazione concorrente con OS161</span>

<span style="font-size:12.0pt">Realizzare questo esercizio con configurazione: THREADS, anziche’ DUMBVM o HELLO: Si consiglia di tentare una configurazione nuova solamente come esercizio, nonostante non ve ne sia necessità (non si modifica nessun sorgente).</span>

**<span style="font-size:13.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Built-in thread tests</span>**

<span style="font-size:12.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Quando si avvia os161, tra le opzioni disponibili dal menu, si possono avviare i test per thread. Si tratta di funzioni NON caricate come eseguibili separati, ma direttamente likati nel kernel (in pratica, quindi, di parti del kernel).  
I programmi di test dei thread usano sincronizzazione basata su semafori. Si può tentare di tracciarne l’esecuzione in GDB, per verificare come lavora lo scheduler, cone sono creati i thread, e cosa succede al context-switch. Per far questo, si consiglia di tracciare funzioni quali thread_create thread_fork, thread_yield, …</span>

<span style="font-size:12.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Il test tt1 stampa i numeri da 0 a 7 ad ogni loop del thread, tt2 stampa solo ad inizio e fine dei thread (serve a dimostrare che lo scheduler non genera starvation). I threads sono avviati e girano per un po’ di iterazioni. Il test tt3 utilizza semafori, che nella versione base di OS161 non funzionano correttamente: il problema sarà affrontato in un futuro laboratorio.</span>

<span style="font-size:12.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Il sorgente di avvio dei test si trova in menu.c</span>

**<span style="font-size:12.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Per fare debug di programmi con thread</span>**

<span style="font-size:12.0pt;
font-family:&quot;Times New Roman&quot;,&quot;serif&quot;;color:black">Siccome la funzione thread_yield viene chiamata a intervalli random, per generare (e farne il debug) sequenze di esecuzione ripetibili si consiglia di usare un seme per inizializzazione fissa del generatore di numeri casuali (direttiva “random” in sys161.conf). Passare ad autoseed sono quando tutto funziona.</span>

# Eseguire un programma utente in OS161 (chiamare la nuova versione del sistema USERP)

OS/161 contiene un insieme di programmi utente già predisposti per l'esecuzione sul kernel. Questo insieme include programmi di utilità comuni in ambito UNIX, quali <tt>ls</tt> and <tt>cat</tt>, oltre a vari altri programmi di test.  I sorgenti di tali programmi si trovano, a partire dalla radice dei sorgenti (<tt>os161/os161-base-1.99.05</tt>), in <tt>userland/{bin,sbin,testbin}</tt>.

Molti dei programmi sopra citati non sono in grado di funzionare correttamente,  con OS161 nella forma iniziale, in quanto le “system calls” chiamate non sono ancora implementate. Per farli funzionare correttamente occorre quindi implementare tali system calls.

Per creare gli eseguibili dei programmi utente occorre,  a partire dai direttori dei file sorgenti, eseguire

**bmake**

Gli eseguibili creati, in formato ELF, sono installati nel direttorio <tt>pds-os161/root/</tt> nei sotto-direttori <tt>bin</tt>, <tt>sbin</tt> e <tt>testbin</tt>, rispettivamente. Un insieme di programmi eseguibili già predisposti è presente in tali direttori.

Obiettivo iniziale del laboratorio è analizzare la fase di “load” di un eseguibile, sino all'avvio dell'esecuzione, NONOSTANTE il programma non funzioni poi correttamente (nella seconda parte del laboratorio si realizzeranno due system call in grado di supportare INPUT e OUTPUT, permettendo quindi l'esecuzione completa di alcuni programmi di test).

Per analizzare la fase di load e avvio dell'esecuzione di un programma di test,  occorre attivare il programma dal menu di os161, mediante il comando “p <programma>”, ad esempio “<span style="font-family:&quot;Courier New&quot;">p testbin/palin”</span>, “<span style="font-family:&quot;Courier New&quot;">p sbin/reboot”</span>, dopo aver impostato uno o più breakpoints del debugger, sulle funzioni che eseguono tali operazioni. <span lang="EN">Si consiglia, ad esempio, di mettere breakpoints su:</span>

<span style="font-family:&quot;Courier New&quot;" lang="EN">common_prog,  thread_fork,  thread_startup,  cmd_progthread,  runprogram,  load_elf,</span> <span lang="EN">...</span>

Si analizzi, in particolare, la fase di attivazione di un nuovo thread e di caricamento del file ELF.  Si determini a quali indirizzi di memoria (e come) vengono caricate le parti del file ELF. A tale scopo, si noti che in varie parti del codice sorgente di kernel, compaiono istruzioni del tipo DEBUG(...), che eseguono eventuali kprintf, controllate dal valore della variabile globale dbflags.  Per la definizione completa dei valori da assegnare a dbflags, si veda il file <tt>kern/include/lib.h</tt><tt><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">.</span></tt> <tt><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">Se ad esempio, si volessero attivare le DEBUG in</span> load_segment</tt><tt><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">, occorrerebbe attivare, in dbflags, il flag DB_EXEC, definito come 0x040\. A tale scopo, si può ad esempio usare l'istruzione di gdb: set dbflags = 0x040.</span></tt>

<tt><span style="font-family:&quot;Times New Roman&quot;,&quot;serif&quot;">Utilizzando quindi le istruzioni DEBUG, opportunamente attivate in GDB, si chiede pertanto di esaminare l'esecuzione di</span> load_elf,</tt> <tt><span style="font-family:
&quot;Times New Roman&quot;,&quot;serif&quot;">di determinare come viene predisposto lo spazio degli indirizzi del thread in esecuzione (segmento di codice, dati, e stack) e come viene attivata l'esecuzione del programma in user-mode.</span></tt>

Si provi inoltre a verificare quale/quanta memoria viene allocata per il thread in esecuzione, e quale di questa memoria viene rilasciata al termine di tale esecuzione. Si modifichi la funzione <span style="font-family:&quot;Courier New&quot;">load_elf</span> in modo tale che vengano stampati a video le dimensioni e gli indirizzi logici e fisici di partenza dei segmenti di memoria virtuale e dello stack.

Quale funzione occorrerebbe modificare per rilasciare tutta la memoria utilizzata? Sarebbe possibile una minima modifica al kernel tale da ripristinare lo stato della memoria precedente all'esecuzione del thread?<spacer type="BLOCK" align="BOTTOM" width="104" height="16"></spacer>

# Scrivere una nuova system call in OS161 (SYSCALL)

La funzione principale di un kernel è quella di fornire il supporto per programmi user-level. Tale supporto è in genere fornito tramite le "system calls". Si noti che un programma utente viene attivato dal menu di os161 mediante il comando “p programma”, ad esempio “<span style="font-family:&quot;Courier New&quot;">p testbin/palin”</span>, “<span style="font-family:&quot;Courier New&quot;">p sbin/reboot”</span>.

Os161, nella versione base, fornisce solo 2 system call (<span style="font-family:&quot;Courier New&quot;">reboot</span> e <span style="font-family:
&quot;Courier New&quot;">__time</span>).  Ad esempio, la system call <span style="font-family:&quot;Courier New&quot;">reboot()</span>, viene implementata dalla funzione di kernel  <span style="font-family:&quot;Courier New&quot;">sys_reboot()</span>,  in <span style="font-family:&quot;Courier New&quot;">main.c</span>.  Si ricorda che una system call permette a un programma (in modalità user) di richiedere un servizio al kernel, mediante una trap che attiva la funzione <span style="font-family:&quot;Courier New&quot;">syscall()</span>.

In GDB, se si vuole mettere un breakpoint su <span style="font-family:&quot;Courier New&quot;">sys_reboot</span> e attivarla, basta (dopo aver messo il break point e aver fato ripartire il kernel (ad esempio con i comandi GDB “_break sys_reboot”_ e “_continue”)_ chiamare il programma <span style="font-family:&quot;Courier New&quot;">sbin/reboot</span> (comando “p sbin/reboot”). Una volta che gdb si trova in <span style="font-family:&quot;Courier New&quot;">sys_reboot()</span>, usare <span style="font-family:&quot;Courier New&quot;">backtrace</span>, oppure <span style="font-family:&quot;Courier New&quot;">up/down</span>, per localizzare la sequenza delle chiamate.  In breve, la funzione utente <span style="font-family:&quot;Courier New&quot;">reboot()</span>,  attiverà indirettamente una trap di sistema, che chiamerà la funzione <span style="font-family:&quot;Courier New&quot;">syscall()</span> (file <span style="font-family:&quot;Courier New&quot;">kern/arch/mips/syscall.c</span>), la quale,  mediante un costrutto <span style="font-family:&quot;Courier New&quot;">switch/case</span>,  attiverà la <span style="font-family:&quot;Courier New&quot;">sys_reboot()</span>.  

A questo punto è possible tentare di creare una nuova system call. Per generare una nuova system call occorre:

<span style="font-family:Symbol" lang="EN">·</span>    creare nuove funzioni utente, oppure utilizzarne di esistenti (ma ancora prive di supporto, in os161 base). Nel caso specifico,  si consiglia di utilizzare le funzioni <span style="font-family:&quot;Courier New&quot;">write</span> e <span style="font-family:&quot;Courier New&quot;">read,</span>  che vengono indirettamente richiamata da <span style="font-family:&quot;Courier New&quot;">printf</span> e <span style="font-family:&quot;Courier New&quot;">scanf</span>.

<span style="font-family:Symbol" lang="EN">·</span>    Generare nuove system call da associare alle funzione utente.

<span style="font-family:
&quot;Courier New&quot;">o</span>   Occorre un codice intero (si veda il file <span style="font-family:&quot;Courier New&quot;">kern/include/kern/syscall.h</span>), da utilizzare nel costrutto <span style="font-family:&quot;Courier New&quot;">switch/case</span> (in <span style="font-family:&quot;Courier New&quot;">syscall()</span>) visto in precedenza (le costanti <span style="font-family:&quot;Courier New&quot;">SYS_read</span> e <span style="font-family:&quot;Courier New&quot;">SYS_write</span> sono già definite (<span style="font-family:&quot;Courier New&quot;">50</span> e <span style="font-family:&quot;Courier New&quot;">55</span>) e quindi utilizzabili).

<span style="font-family:
&quot;Courier New&quot;">o</span>   Occorre una funzione da richiamare, nel costrutto switch.  Utilizzando le convenzioni già utilizzate, si consiglia di generare (in analogia a <span style="font-family:&quot;Courier New&quot;">sys_reboot</span>) le funzioni <span style="font-family:&quot;Courier New&quot;">sys_write() e</span> <span style="font-family:&quot;Courier New&quot;">sys_read()</span> (Si consiglia di iniziare dalla prima). La funzione <span style="font-family:&quot;Courier New&quot;">sys_reboot()</span> si trova nel file <span style="font-family:&quot;Courier New&quot;">menu.c</span>, ma si consiglia di generare un nuovo sorgente nel direttorio <span style="font-family:
&quot;Courier New&quot;">kern/syscall</span> (ad es. <span style="font-family:&quot;Courier New&quot;">stdio_syscalls.c</span>,  analogo a <span style="font-family:&quot;Courier New&quot;">time_syscalls.c</span>),  nel quale realizzare le funzioni <span style="font-family:&quot;Courier New&quot;">sys_write()</span> e <span style="font-family:&quot;Courier New&quot;">sys_read(),</span> cominciando dalla prima).

<span style="font-family:
&quot;Courier New&quot;">o</span>   Passaggio dei parametri. La funzione <span style="font-family:&quot;Courier New&quot;">syscall()</span>,  attivata da trap,  riceve come parametro <span style="font-family:&quot;Courier New&quot;">struct</span> <span style="font-family:&quot;Courier New&quot;">trapframe</span> <span style="font-family:&quot;Courier New&quot;">*tf</span>.  La struct puntata contiene, tra le altre informazioni, i parametri passati alla <span style="font-family:
&quot;Courier New&quot;">write</span> (un file id, un puntatore a una stringa e il numero di caratteri da stampare – ATTENZIONE, la stringa non è necessariamente terminata da ‘<span style="font-family:&quot;Courier New&quot;">\0’</span>). Tali parametri sono reperibili in <span style="font-family:&quot;Courier New&quot;">tf->tf_a0, …_a1, …_a2, …_a3</span>.  Si vedano le system call già implementate, lavorando in modo analogo per <span style="font-family:&quot;Courier New&quot;">sys_write()e</span> <span style="font-family:&quot;Courier New&quot;">sys_read()</span>.  Per conoscere i prototipi esatti delle funzioni  <span style="font-family:&quot;Courier New&quot;">write()</span>e <span style="font-family:&quot;Courier New&quot;">read(),</span> usare i comandi (da finestra terminale) “_man 2 write”_ e “_man 2 read”_.

<span style="font-family:Symbol" lang="EN">·</span>         Aggiungere le informazioni necessarie per fare make di un nuovo kernel, e realizzarlo:

<span style="font-family:
&quot;Courier New&quot;">o</span>   Aggiungere il prototipo della sys_write al file <span style="font-family:&quot;Courier New&quot;">kern/include/syscall.h</span>.

<span style="font-family:
&quot;Courier New&quot;">o</span>   Determinare a quale configurazione si fa riferimento in <span style="font-family:&quot;Courier New&quot;">kern/conf</span> (es SYSCALL).

<span style="font-family:
&quot;Courier New&quot;">o</span>   In <span style="font-family:&quot;Courier New&quot;">conf.kern</span> aggiungere il nuovo file (es. <span style="font-family:&quot;Courier New&quot;">syscalls/stdio_syscalls.c</span>)

<span style="font-family:
&quot;Courier New&quot;">o</span>   Rifare il make del kernel

<span style="font-family:Symbol" lang="EN">·</span>         Eseguire (possibilmente in debug) un programma utente che attivi la system call. Un esempio è la testbin/palin (sorgenti in <span style="font-family:&quot;Courier New&quot;">userland/testbin</span>). Attenzione, i programmi attivabili da menu come “p testbin/xxx” non supportano gli argomenti al main (per abilitarli serve una implementazione della <span style="font-family:&quot;Courier New&quot;">malloc</span>, in quanto le stringhe vanno passate dal menu ai thread che mandano in esecuzione (in user space) un file eseguibile (elf). Nella versione attuale, quindi, i programmi vanno chiamati senza argomenti (quindi non funzionano completamente, o vanno modificati).

Informazioni più dettagliate sulle system calls sono reperibili sul documento “understanding system calls”

</div>
