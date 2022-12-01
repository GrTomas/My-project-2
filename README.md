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

Lentelėje matoma, kad naudojant flagus programa atliekama daug grečiaiu. Taip pat matoma, kad flagas -O2 darbą atliko greičiausiai.
