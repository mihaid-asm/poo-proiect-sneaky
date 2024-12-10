# poo-proiect-sneaky

<p>Sneaky: The Game (2023-2024)</p>

<p>Sneaky este un joc realizat de Duzi Mihai-Nicolae(grupa 152) in C++ folosind POO.</p>

<p>Scopul jocului este sa colectati un numar suficient de iteme fara a fi surprinsi de inamici(marcati cu litere mari diferite de P).</p>

<p>Atat jucatorul(marcat cu litera P), cat si monstrii/inamicii au un "Health", un "Damage" si un "Range".</p>

<p>Daca jucatorul intra in range-ul unui monstru, acesta pierde atata "Health" cat damage are inamicul.</p>

<p>Daca un monstru este in range-ul jucatorului, monstrul pierde atata "Health" cat damage are jucatorul.</p>

<p>Daca un monstru ajunge cu "Health"<=0, acesta dispare de pe harta, iar daca jucatorul ajunge la "Health"<=0 jocul este considerat pierdut.</p>
  
<p>Fiecare nivel are un target, fiind necesar ca jucatorul sa-l atinga pentru a castiga jocul, colectand itemele marcate cu cifre ale caror cifra reprezinta valoarea in puncte.</p>

<p>Jocul are 3 niveluri, la inceputul programului jucatorul avand posibilitatea sa aleaga un nivel(de la 1 la 3).</p>

<p>Datele despre un nivel sunt in fisirele de forma "Xjoc.in", unde X este 1, 2 sau 3.</p>

<p>Pe prima linie se afla inaltimea si latimea hartii, pe urmatoarea linie se afla datele despre jucator(health, damage, range, coordonate, look, puncte obtinute),</p>

<p>Pe urmatoarea linie se afla M=numarul de monstri iar pe urmatoarele M linii se afla datele despre monstri(health, damage, range, coordonate, look),</p>

<p>Pe urmatoarea linie se afla I=numarul de iteme iar pe urmatoarele I linii se afla datele despre iteme(valoarea si coordonatele)</p>
<p>Pe ultima linie se afla numarul de puncte pe care trebuie sa-l obtina jucatorul pentru a castiga.</p>
