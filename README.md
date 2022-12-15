# My-project-2

# v2.0
Šioje programos versijoje pateikta programos dokumentacija. Ši dokumentacija parašyta naudojantis doxygen. Visi HTML failai su dokumentacija yra aplanke pavadinimu "html". Taip pat šiame faile yra įdėti cmake failai.

Programos instrukcija:
atsisiuntę failus tiesiog atidarykite  "c_make_run.bat" failą ir taip paleisite sukoduota programą.

# v1.5

Ši programos versija papildo versiją v1.2 tuo, kad šioje versijoje klasė studentas yra suskirstyta į dvi dalis. Ji suskirstyta į bazinę klasę žmogus ir išvestinę klasę studentas. Taip pat šioje versijoje sukurti galima tik studento klasės objektą, žmogaus klasės objektas yra apsaugotas ir šio tipo kintamieji negali būti pasiekiami. Šios klasės kintamieji gali būti pasiekti tik išvestinės klasės. Kitaip tariant žmogaus klasė yra abstrakčioji.

# v1.2

Ši programos versija papildo versiją v1.1 tuo, kad klasėje yra naudojama "Rule of three". Tai reiškia, kad naujoje programos versijos klasėje atsiranda destruktorius, kopijavimo konstruktorius ir kopijavimo priskyrimas.

Tai atliekama pradedant destruktoriumi. Destuktorius panaikina išsaugotus privačiajame kintamajame esančius namų darbus. Taip pat prieš tai sukuriami du konstruktoriai. Pirmasis skirtas priskirti kintamajam tuščius duomenis ir antrasis, skirtas priskirti visų studentų duomenis. Po destruktoriaus sekantis yra kopijavimo konstruktorius. Jis gauto studento duomenis priskiria privatiesiems kintamiesiems. Paskutinis yra kopijavimo priskyrimas. Jis atliekamas naudojant "operator". Tai daroma, kad pakeistų lygybės operatorių priimantį 2 klasės Studentas tipo kintamuosius ir kopijuotų duomenis iš vieno, į kitą.





# v1.1

Ši programos versija nuo V1.0 skiriasi tuo, kad šioje versijoje yra naudojama nebe struktūra talpinant duomenis, bet yra sukurta klasė, duomenims talpinti. Šioje klasėje yra privatieji kintamieji, jų "seteriai" ir "geteriai". Žemiau pateiktoje lentelėje palyginamas 100000 ir 1000000 duomenų suskirstymas į "galvočius" ir "nuskriaustukus" naudojant vector konteinerį. Jie lyginami pagal tai, kad pirmoje eilutėje duomenys sudėti į struktūra, o antroje į klasę.




duomenų vieta  | 100000  | 1000000 |
---------------|----------|----------|
struktūra      | 1.23758  |  11.4213 |
klasė          | 0.98599  |  9.11123  |

Iš lentelės matoma, kad klasės vietoj struktūros naudojimas sutaupo truputį laiko dirbant su dideliais duomenų kiekiais. Žemiau pateiktoje lentelėje yra pateikti laikai naudojant flagus -O1, -O2 ir -O3:

duomenų vieta  | 100000  | 1000000 |
---------------|----------|----------|
nėra           | 0.98599  |  9.11123 |
O1             | 0.759545  |   7.15002 |
O2             |  0.784276  |   7.04628 |
O3             | 0.775341  |  7.26119  |

Lentelėje matoma, kad naudojant flagus programa atliekama daug greičiau. Taip pat matoma, kad flagas -O2 darbą atliko greičiausiai.
