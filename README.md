# v1.2

Ši programos versija papildo versiją v1.1 tuo, kad klasėje yra naudojama "Rule of three". Tai reiškia, kad naujoje programos versijos klasėje atsiranda destruktorius, kopijavimo konstruktorius ir kopijavimo priskyrimas.

Tai atliekama pradedant destruktoriumi. Destuktorius panaikina išsaugotus privačiajame kintamajame esančius namų darbus. Taip pat prieš tai sukuriami du konstruktoriai. Pirmasis skirtas priskirti kintamajam tuščius duomenis ir antrasis, skirtas priskirti visų studentų duomenis. Po destruktoriaus sekantis yra kopijavimo konstruktorius. Jis gauto studento duomenis priskiria privatiesiems kintamiesiems. Paskutinis yra kopijavimo priskyrimas. Jis atliekamas naudojant "operator". Tai daroma, kad pakeistų lygybės operatorių priimantį 2 klasės Studentas tipo kintamuosius ir kopijuotų duomenis iš vieno, į kitą.
