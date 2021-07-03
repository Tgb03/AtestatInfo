# AtestatInfo

Acest README va contine informatiile necesare pentru setup.

Executabilele pentru fiecare versiune se vor afla in fisierele:
1. Debug x86   : "AtestatInfo/Debug"
2. Release x86 : "AtestatInfo/Release"
3. Debug x64   : "AtestatInfo/x64/Debug"
4. Release x64 : "AtestatInfo/x64/Release"

Fara fisierul "Data" aplicatia nu poate afisa text, dar poate rula.

Pentru a compila codul descarcat de pe Github trebuie: 

1. In fisierul "Library" se afla 2 fisiere "SFML-2.5.1" si fisierul "SFML-2.5.1-windows-vc15-64-bit". Acestea trebuie descarcate.
2. Pe urma trebuie amandoua fisierele mutate din Downloads pe desktop cu path-ul urmator: ("C:\Users\User\Desktop\...")
3. Daca nu pot fi puse acolo trebuie modificate proprietatile din visual studio pentru a face linking cu fisierele. Cum se face:
  a) Pentru a intra in proprietati din top bar click pe "Project" -> "AtestatInfo Properties".
  b) "Configuration Properties" -> Click pe "C/C++". Aici trebuie modificate "Additional Include Directories". Dar deoarece SFML are librarii diferite pentru x86 bit si x64 bit trebuie facuta de doua ori, pentru fiecare versiune. Astfel sus in pagina de proprietati asigurati-va ca scrie "Platform: Win32"
  c) Dupa un click pe "Additional Include Directiories" va aparea in dreapta o sageata in jos. Click pe aceasta, pe urma "<Edit...>"
  d) Aici scrieti path-ul fisierului "SFML-2.5.1". Acum trebuie repetate, dar pentru "Platform: x64" (sus in pagina de Proprietati) si fisierul "SFML-2.5.1-windows-vc15-64-bit"
  * Daca ceva nu functioneaza un in depth guide se afla pe link-ul: https://www.sfml-dev.org/tutorials/2.5/start-vc.php


Proiectul a fost facut in totalitate de elevul Trandafir Tudor de la liceul Ovidius Constanta
