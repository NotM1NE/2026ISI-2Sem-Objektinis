# Studentų rūšiavimo aplikacijos veikimo greičio testų rezultatai

Šiame repozitoriuje pateikiami studentų rūšiavimo aplikacijos veikimo greičio testų rezultatai. Aplikacija naudoja įvairius konteinerius (`vector`, `list`, ir `deque`) skirtingoms operacijoms, tokioms kaip generavimas, nuskaitymas, rūšiavimas ir išvedimas. Žemiau pateikiami testų rezultatai pagal tris strategijas.

## Strategijos aprašymai

### **Strategija 1: SplitStudentsStrategy1**
Šioje strategijoje studentai yra suskirstomi į dvi grupes pagal jų **vidurkį** (`vid`):
- **Nepavykę studentai**: Jei vidurkis yra mažesnis nei 5.0, studentas priskiriamas nepavykusių grupėms.
- **Sėkmingi studentai**: Jei vidurkis yra 5.0 arba didesnis, studentas patenka į sėkmingų grupę.

### **Strategija 2: SplitStudentsStrategy2**
Šioje strategijoje studentai taip pat yra skirstomi pagal jų **vidurkį** (`vid`), tačiau šiuo atveju:
- **Nepavykę studentai**: Jei vidurkis yra mažesnis nei 5.0, studentas priskiriamas nepavykusių grupėms.
- **Sėkmingi studentai**: Jei vidurkis yra 5.0 arba didesnis, studentas priskiriamas sėkmingų grupėms, tačiau po to **pakeičiama originali grupė** (`grupe`) tik su sėkmingais studentais, t. y. nepavykę studentai pašalinami.

### **Strategija 3: SplitStudentsStrategy3**
Šioje strategijoje naudojama **stabilių skyrių** (angl. `stable_partition`) funkcija, kad studentai būtų suskirstyti į dvi grupes pagal jų **vidurkį** (`vid`):
- **Nepavykę studentai**: Jei vidurkis yra mažesnis nei 5.0, studentas priskiriamas nepavykusių grupėms.
- **Sėkmingi studentai**: Jei vidurkis yra 5.0 arba didesnis, studentas patenka į sėkmingų grupę.
- Skirtingai nuo kitų strategijų, ši naudoja **stabilų skyrių**, todėl tvarka grupėje išlieka, o studentai, turintys vidurkį žemiau 5.0, perkelia į „nepavykusių“ grupę, o „sėkmingų“ grupė paliekama originalioje.

---

## Testų rezultatai pirmai strategijai (Vector aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 |  Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.002998 s                  | 0.006527 s                 | 0.000251 s                 | 0.003558 s                | 0.013334 s               |
| `studentaiGen10000.txt`| 0.0026884 s                  | 0.015736 s                 | 0.002487 s                 | 0.028138 s                | 0.073247 s               |
| `studentaiGen100000.txt`| 0.248325 s                  | 0.173552 s                 | 0.022180 s                 | 0.260669 s                | 0.704728 s               |
| `studentaiGen1000000.txt`| 3.766192 s                 | 2.079194 s                | 0.263609 s                 | 3.458266 s                | 9.567267 s              |
| `studentaiGen10000000.txt`| 38.419363 s                 | 22.721324 s                | 2.409480 s                 | 33.651589 s               | 97.201759 s              |

---

## Testų rezultatai antrai strategijai (Vector aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003478 s                  | 0.008294 s                 | 0.000313 s                 | 0.001717 s                | 0.013804 s               |
| `studentaiGen10000.txt`| 0.027147 s                  | 0.025231 s                 | 0.002807 s                 | 0.011151 s                | 0.066337 s               |
| `studentaiGen100000.txt`| 0.263462 s                  | 0.184228 s                 | 0.032533 s                 | 0.116319 s                | 0.593845 s               |
| `studentaiGen1000000.txt`| 3.008995 s                  | 1.905305 s                 | 0.377876 s                 | 1.106939 s                | 6.399118 s               |
| `studentaiGen10000000.txt`| 33.468624 s                 | 17.679091 s                | 3.341486 s                 | 12.871163 s               | 67.360371 s              |

---

## Testų rezultatai trečiai strategijai (Vector aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.002977 s                  | 0.006969 s                 | 0.000444 s                 | 0.001685 s                | 0.012077 s               |
| `studentaiGen10000.txt`| 0.025391 s                  | 0.016312 s                 | 0.003123 s                 | 0.011463 s                | 0.056291 s               |
| `studentaiGen100000.txt`| 0.245076 s                  | 0.158526 s                 | 0.033171 s                 | 0.109411 s                | 0.546186 s               |
| `studentaiGen1000000.txt`| 3.002385 s                  | 1.812393 s                 | 0.361922 s                 | 1.120008 s                | 6.296710 s               |
| `studentaiGen10000000.txt`| 30.761248 s                 | 14.458386 s                | 3.242363 s                 | 12.401157 s               | 60.953156 s              |

---
## Testų rezultatai pirmai strategijai (List aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003263 s                  | 0.007302 s                 | 0.000164 s                 | 0.003475 s                | 0.014205 s               |
| `studentaiGen10000.txt`| 0.025255 s                  | 0.019410 s                 | 0.001701 s                 | 0.029586 s                | 0.075952 s               |
| `studentaiGen100000.txt`| 0.247232 s                  | 0.223662 s                 | 0.021465 s                 | 0.271386 s                | 0.763748 s               |
| `studentaiGen1000000.txt`| 3.155149 s                  | 1.892796 s                 | 0.221638 s                 | 2.863834 s                | 8.133421 s               |
| `studentaiGen10000000.txt`| 26.314885 s                 | 20.321665 s                | 2.261283 s                 | 26.514885 s               | 75.412720 s              |

---

## Testų rezultatai antrai strategijai (List aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003281 s                  | 0.007569 s                 | 0.000216 s                 | 0.001683 s                | 0.012750 s               |
| `studentaiGen10000.txt`| 0.027257 s                  | 0.022538 s                 | 0.002945 s                 | 0.011801 s                | 0.064543 s               |
| `studentaiGen100000.txt`| 0.328736 s                  | 0.204150 s                 | 0.038384 s                 | 0.156786 s                | 0.728057 s               |
| `studentaiGen1000000.txt`| 2.937236 s                  | 1.884826 s                 | 0.430684 s                 | 1.156896 s                | 6.409645 s               |
| `studentaiGen10000000.txt`| 27.598120 s                 | 21.286479 s                | 4.588229 s                 | 11.369152 s               | 64.841982 s              |

---

## Testų rezultatai trečiai strategijai (List aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003597 s                  | 0.009385 s                 | 0.000301 s                 | 0.001608 s                | 0.014892 s               |
| `studentaiGen10000.txt`| 0.031847 s                  | 0.031200 s                 | 0.003548 s                 | 0.012614 s                | 0.079210 s               |
| `studentaiGen100000.txt`| 0.261743 s                  | 0.158653 s                 | 0.039343 s                 | 0.113736 s                | 0.573478 s               |
| `studentaiGen1000000.txt`| 2.961972 s                  | 2.502863 s                 | 0.490625 s                 | 1.413467 s                | 7.368928 s               |
| `studentaiGen10000000.txt`| 28.395054 s                 | 23.354187 s                | 4.936832 s                 | 11.539675 s               | 68.225751 s              |

---

## Testų rezultatai pirmai strategijai (Deque aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003353 s                  | 0.007149 s                 | 0.000133 s                 | 0.003624 s                | 0.014262 s               |
| `studentaiGen10000.txt`| 0.028435 s                  | 0.019395 s                 | 0.001372 s                 | 0.028755 s                | 0.077962 s               |
| `studentaiGen100000.txt`| 0.281317 s                  | 0.173646 s                 | 0.015561 s                 | 0.276210 s                | 0.746741 s               |
| `studentaiGen1000000.txt`| 3.686049 s                  | 1.874159 s                 | 0.169198 s                 | 3.543873 s                | 9.273307 s               |
| `studentaiGen10000000.txt`| 36.189720 s                 | 18.583712 s                | 1.675592 s                 | 32.627610 s               | 89.076915 s              |

---

## Testų rezultatai antrai strategijai (Deque aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003242 s                  | 0.007314 s                 | 0.000202 s                 | 0.001660 s                | 0.012502 s               |
| `studentaiGen10000.txt`| 0.027547 s                  | 0.017871 s                 | 0.001800 s                 | 0.012133 s                | 0.059354 s               |
| `studentaiGen100000.txt`| 0.307179 s                  | 0.179200 s                 | 0.027586 s                 | 0.118407 s                | 0.632383 s               |
| `studentaiGen1000000.txt`| 2.545580 s                  | 1.122231 s                 | 0.272649 s                 | 1.316712 s                | 5.257218 s               |
| `studentaiGen10000000.txt`| 34.829918 s                 | 19.028429 s                | 3.454247 s                 | 13.640352 s               | 70.953273 s              |

---

## Testų rezultatai trečiai strategijai (Deque aplikacija)

**Visi testai buvo paleisti 5 kartus.**

| Failas                 | Vidutinis generavimo laikas | Vidutinis nuskaitymo laikas | Vidutinis skirstymo laikas | Vidutinis išvedimo laikas | Vidutinis bendras laikas |
|------------------------|-----------------------------|----------------------------|----------------------------|---------------------------|--------------------------|
| `studentaiGen1000.txt` | 0.003321 s                  | 0.007597 s                 | 0.000285 s                 | 0.001724 s                | 0.013007 s               |
| `studentaiGen10000.txt`| 0.026026 s                  | 0.020119 s                 | 0.003299 s                 | 0.011452 s                | 0.060899 s               |
| `studentaiGen100000.txt`| 0.262796 s                  | 0.179749 s                 | 0.033699 s                 | 0.129781 s                | 0.606036 s               |
| `studentaiGen1000000.txt`| 3.668641 s                  | 1.721451 s                 | 0.374394 s                 | 1.331817 s                | 7.096330 s               |
| `studentaiGen10000000.txt`| 36.846277 s                 | 15.955646 s                | 3.753802 s                 | 13.756016 s               | 70.311922 s              |

---


## Pastabos

- Testai buvo vykdomi kompiuteryje su šiais parametrais:
  
| Komponentas | Specifikacija                                |
| ----------- | -------------------------------------------- |
| CPU         | AMD Ryzen 9 9900X (12 branduolių, 4.40 GHz) |
| RAM         | 32 GB DDR5 RAM (6000 MT/s)                   |
| GPU         | NVIDIA GeForce RTX 5070 Ti (16 GB VRAM)      |
| OS          | Windows PRO 64-bit                           |
| MotherBoard | B850 Pro RS WiFi                             |

- Naudoti konteineriai: `std::vector`, `std::list` ir `std::deque`.
- Testavimai atlikti su įvairaus dydžio failais: `studentaiGen1000.txt`, `studentaiGen10000.txt`, `studentaiGen100000.txt`, `studentaiGen1000000.txt`, ir `studentaiGen10000000.txt`.

## Greičiausi rezultatai

- **Greičiausia strategija:** Strategija 2 (SplitStudentsStrategy2) yra greičiausia, nes ji pašalina nepavykusius studentus ir atnaujina grupę, todėl apdorojimo laikai yra žymiai mažesni, ypač su didesniais failais. Tai ypač pastebima, kai palyginami bendri laikai su kitomis strategijomis.
- **Greitesni konteineriai:** Nors jūsų rezultatai rodo, kad `deque` buvo greičiausias su didesniais failais (ypač su dideliais duomenimis), tai iš dalies priklauso nuo operacijų tipo, kurios atliekamos. `Deque` pasirodė greičiausias, nes jis leidžia greitesnį įterpimą ir pašalinimą tiek priekiniame, tiek galiniame galai, kas ypač svarbu apdorojant didelius duomenis.

## Konteinerių palyginimas
- `deque` pasirodė geriausiai su didesniais failais, nes jis efektyviau atlieka operacijas tiek pradžioje, tiek pabaigoje.
- `vector` buvo greitesnis su mažesniais failais, nes jis turi mažesnį atminties valdymo overhead'ą ir dažnai pasižymi greitesniu nuskaitymu bei rūšiavimu.
- `list` buvo lėčiausias dėl būtinybės atlikti elementų perstumdymą, ypač su dideliais duomenų rinkiniais.

## Nuotraukos
**vector_app**

<img width="301" height="748" alt="Screenshot 2026-03-26 001148" src="https://github.com/user-attachments/assets/e6f4ad7b-4a9a-46a7-84c5-cfa3156f10d1" />
<img width="306" height="740" alt="Screenshot 2026-03-26 001859" src="https://github.com/user-attachments/assets/9026e942-d30b-4aa4-8b20-ac8dcf862252" />
<img width="302" height="745" alt="Screenshot 2026-03-26 002624" src="https://github.com/user-attachments/assets/0a1070e0-22bf-4f8f-9b4f-9ddfbe6835c9" />

**list_app**

Pamirsau

**deque_app**

<img width="292" height="739" alt="Screenshot 2026-03-25 235058" src="https://github.com/user-attachments/assets/5c610194-d84c-4fb3-9d51-4b521d77013e" />
<img width="295" height="741" alt="Screenshot 2026-03-25 235316" src="https://github.com/user-attachments/assets/c9cdaab4-677e-4175-8f95-eabea7313187" />
<img width="297" height="740" alt="Screenshot 2026-03-26 000123" src="https://github.com/user-attachments/assets/4ed6e2ba-3672-4a79-a7bf-55349dce8f7b" />


