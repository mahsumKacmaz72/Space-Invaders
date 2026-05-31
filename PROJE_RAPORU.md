# PROGRAMLAMA 2 PROJE RAPORU

## Proje Adi

Space Invaders Oyunu

## Projenin Amaci

Bu projede C++ programlama dili ve SFML kutuphanesi kullanilarak klasik Space Invaders mantigina benzeyen 2 boyutlu bir oyun gelistirdim. Projedeki amacim nesne yonelimli programlama konularini kullanarak oyuncu, dusman, mermi, engel, carpisma ve oyun durumlarini ayri yapilar halinde kodlamakti.

## Kullanilan Teknolojiler

- Programlama dili: C++
- Grafik ve ses kutuphanesi: SFML
- Derleme sistemi: CMake
- IDE / ortam: Visual Studio

## Oyunun Genel Tanimi

Oyunda oyuncu bir uzay gemisini kontrol eder. Dusmanlar ekranin ust tarafindan dalgalar halinde gelir. Oyuncu dusmanlari vurdukca skor kazanir. Dusmanlar da oyuncuya ates eder. Oyuncunun toplam 3 cani vardir. Canlar bittiginde oyun biter ve sonuc ekraninda skor gosterilir.

Oyuna baslamadan once baslangic ekrani gelir. Oyuncu `Space` tusuna basinca oyun baslar. Oyun bittikten sonra `R` tusuna basilarak oyun yeniden baslatilabilir.

## Kontroller

| Tus | Gorev |
| --- | --- |
| `Space` | Oyunu baslatma ve ates etme |
| `A` veya Sol Ok | Oyuncu gemisini sola hareket ettirme |
| `D` veya Sag Ok | Oyuncu gemisini saga hareket ettirme |
| `R` | Oyun bittikten sonra yeniden baslatma |

## Oyun Mekanikleri

### Oyuncu

Oyuncu gemisi ekranin alt tarafinda bulunur. Oyuncu saga ve sola hareket edebilir. `Space` tusuna basildiginda mermi atar. Oyuncu dusman mermisine carpinca can kaybeder.

### Dusmanlar

Dusmanlar satir ve sutun seklinde olusturulur. Saga ve sola hareket ederler. Ekran kenarlarina geldiklerinde yon degistirirler. Butun dusmanlar yok edilirse yeni dalga baslar. Yeni dalga yukaridan asagiya inerek gelir ve oyun ilerledikce dusman hizi artar. Dusmanlar pencerenin altina ulasirsa oyun biter.

### UFO

Oyuna ek olarak rastgele zamanlarda UFO cikmaktadir. UFO cok sik cikmayacak sekilde zamanlanmistir. Bazen soldan saga, bazen sagdan sola hareket eder. Oyuncu UFO'yu vurursa skor 300 puan artar.

### Engeller

Oyuncu ile dusmanlar arasinda engeller bulunur. Mermiler engellere carpinca engeller parca parca hasar alir. Bu sayede oyuncu dusman mermilerinden korunabilir.

### Skor Sistemi

- Ust siradaki dusmanlar: 150 puan
- Orta siradaki dusmanlar: 100 puan
- Alt siradaki dusmanlar: 50 puan
- UFO: 300 puan

## Sesler

Projeye arka plan muzigi ve ses efektleri ekledim. Oyuncu ates ettiginde, dusman ates ettiginde, dusman vuruldugunda, oyuncu hasar aldiginda, engel vuruldugunda ve yeni dalga geldiginde ses calar.

## Kod Yapisi

- `oyuncu`: Oyuncu gemisinin hareketi, can sistemi ve cizimi
- `mermi`: Oyuncu mermilerinin atilmasi ve hareketi
- `dusman`: Dusmanlarin olusturulmasi, hareketi ve ates etmesi
- `ufo`: Rastgele zamanlarda cikan bonus UFO sistemi
- `engel`: Koruma engellerinin olusturulmasi ve hasar almasi
- `carpismaDenetimi`: Mermi, dusman, oyuncu, UFO ve engel carpismalarinin kontrolu
- `main.cpp`: Oyun dongusu, ekran durumlari, skor ve seslerin yonetimi

## Oyun Durumlari

Oyunda uc temel durum vardir:

1. Baslangic ekrani
2. Oynanis ekrani
3. Sonuc ekrani

Baslangic ekraninda oyuncu `Space` tusuna basana kadar oyun baslamaz. Oynanis ekraninda tum oyun mekanikleri calisir. Canlar sifirlaninca veya dusmanlar pencerenin altina ulasinca sonuc ekrani acilir ve skor gosterilir.

## Sonuc

Bu proje sayesinde C++ ile sinif yapisi kurma, SFML ile grafik ve ses kullanma, oyun dongusu olusturma, carpisma kontrolu yapma ve proje dosyalarini duzenli tutma konularinda pratik yaptim. Proje klasik Space Invaders mantigini temel aliyor, buna ek olarak sesler, baslangic/sonuc ekranlari, yeniden baslatma sistemi ve UFO bonus hedefi gibi ozellikler iceriyor.
