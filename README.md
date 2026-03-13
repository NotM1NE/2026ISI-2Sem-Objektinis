
# Studentų duomenų apdorojimo programa (v0.4)

## Programos aprašymas

Ši programa skirta studentų duomenų generavimui, nuskaitymui iš failų, jų apdorojimui bei skirstymui į dvi kategorijas pagal galutinį pažymį.

Programa realizuota naudojant **C++** kalbą ir standartines bibliotekas.
Duomenų saugojimui naudojamas **vector konteineris**.

Studentai skirstomi į dvi grupes:

- **Failed** – studentai, kurių galutinis balas < 5.0
- **Passed** – studentai, kurių galutinis balas ≥ 5.0

Sugeneruoti studentų duomenys saugomi `.txt` failuose, o po apdorojimo studentai išvedami į du atskirus failus:

- `failed_*.txt`
- `passed_*.txt`

---

# Programos funkcionalumas

Programa gali:

- Generuoti studentų duomenų failus
- Nuskaityti studentų duomenis iš failų
- Apskaičiuoti galutinį pažymį (vidurkį ir medianą)
- Rūšiuoti studentus pagal:
  - vardą
  - pavardę
  - galutinį balą (vidurkį)
  - galutinį balą (medianą)
- Skirstyti studentus į dvi grupes:
  - vargšiukai
  - kietiakiai
- Išvesti rezultatus į:
  - konsolę
  - failus
- Atlikti programos **spartos analizę**

---

# Testavimo metodika

Programos veikimo sparta buvo testuojama su penkiais skirtingo dydžio studentų failais:

- 1000 įrašų
- 10000 įrašų
- 100000 įrašų
- 1000000 įrašų
- 10000000 įrašų

Kiekvienas testas buvo paleistas **4 kartus**, o rezultatai pateikiami kaip **vidurkis**.

Buvo matuojami šie etapai:

1. Failo generavimas
2. Duomenų nuskaitymas iš failo
3. Studentų skirstymas į grupes
4. Surūšiuotų studentų išvedimas į failus
5. Bendras programos veikimo laikas

---

# Testavimui naudoto kompiuterio specifikacija

Programos spartos testavimas buvo atliktas naudojant šį kompiuterį:

| Komponentas | Specifikacija                                |
| ----------- | -------------------------------------------- |
| CPU         | AMD Ryzen 9 9900X (12 branduolių, 4.40 GHz) |
| RAM         | 32 GB DDR5 RAM (6000 MT/s)                   |
| GPU         | NVIDIA GeForce RTX 5070 Ti (16 GB VRAM)      |
| OS          | Windows PRO 64-bit                           |
| MotherBoard | B850 Pro RS WiFi                             |

---

# Testavimo rezultatai

| Failo dydis | Generavimas (s) | Nuskaitymas (s) | Skirstymas (s) | Išvedimas (s) | Bendras laikas (s) |
| ----------- | --------------- | --------------- | -------------- | -------------- | ------------------ |
| 1000        | 0.003622        | 0.007607        | 0.000256       | 0.004009       | 0.015495           |
| 10000       | 0.028741        | 0.017892        | 0.002305       | 0.031429       | 0.080367           |
| 100000      | 0.274508        | 0.227626        | 0.024047       | 0.273741       | 0.799922           |
| 1000000     | 2.894991        | 2.750289        | 0.281213       | 3.152176       | 9.078671           |
| 10000000    | 28.614415       | 17.397497       | 2.334456       | 28.629521      | 76.975890          |

---

# Rezultatų analizė

Testavimo rezultatai rodo, kad programos vykdymo laikas didėja beveik **linijiškai didėjant duomenų kiekiui**.

Didžiausią įtaką bendram programos veikimo laikui turi:

- failų generavimas
- duomenų išvedimas į failus

Studentų skirstymas į dvi grupes yra labai greita operacija, nes atliekamas tik vienas perėjimas per studentų konteinerį.

Net ir su **10 000 000 studentų įrašų** programa sėkmingai apdoroja duomenis per maždaug **77 sekundes**, todėl galima teigti, kad pasirinkti algoritmai ir duomenų struktūros yra pakankamai efektyvūs darbui su dideliais duomenų kiekiais.

---

# Screenshots

<img width="294" height="157" alt="image" src="https://github.com/user-attachments/assets/24cff810-6512-464b-944b-bba636ddd707" />
<img width="292" height="155" alt="image" src="https://github.com/user-attachments/assets/0298c159-9749-4579-9622-d9f695a6a346" />
<img width="299" height="158" alt="image" src="https://github.com/user-attachments/assets/1c25eaca-22df-4cb0-9e08-79889b8d1577" />
<img width="291" height="152" alt="image" src="https://github.com/user-attachments/assets/ddb7a269-9425-4925-b7e6-475007f0f422" />
<img width="296" height="149" alt="image" src="https://github.com/user-attachments/assets/c1c32fba-39b4-4cfc-81da-e266f8c94bc2" />

<img width="862" height="596" alt="image" src="https://github.com/user-attachments/assets/57f9f738-b191-4d56-a54e-3df982e3de6f" />
<img width="665" height="688" alt="image" src="https://github.com/user-attachments/assets/4877781b-b3fc-442f-9f9f-6c54f1ba72d8" />

---
