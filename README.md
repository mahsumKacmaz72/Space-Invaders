# Space Invaders

Bu proje C++ ve SFML kullanarak yaptigim basit bir Space Invaders oyunudur. Oyunda oyuncu gemiyi saga sola hareket ettirerek dusmanlara ates eder, dusman mermilerinden korunmaya calisir ve engelleri siper olarak kullanir.

## Ozellikler

- Baslangic ekrani vardir.
- Oyuna baslamak icin `Space` tusuna basilir.
- Oyuncu gemisi `A / D` veya sag-sol ok tuslari ile kontrol edilir.
- Oyuncu `Space` ile ates eder.
- Dusmanlar dalga halinde gelir ve her yeni dalgada hiz biraz artar.
- Dusmanlar yeni dalga basladiginda yukaridan asagiya iner.
- Oyuncunun 3 cani vardir.
- Canlar bittiginde sonuc ekrani acilir ve skor gosterilir.
- Tekrar oynamak icin `R` tusuna basilir.
- Oyunda arka plan muzigi ve olaylara gore ses efektleri bulunur.

## Kontroller

| Tus | Gorev |
| --- | --- |
| `Space` | Oyunu baslatma / ates etme |
| `A` veya Sol Ok | Sola gitme |
| `D` veya Sag Ok | Saga gitme |
| `R` | Oyun bittikten sonra tekrar baslatma |

## Klasor Yapisi

```text
Space Invaders
├── assets
│   ├── font
│   ├── images
│   └── sounds
├── include
├── src
├── main.cpp
└── CMakeLists.txt
```

## Kullanilan Sesler

Ses dosyalari `assets/sounds` klasorundedir:

- `arka_plan.wav`
- `oyuncu_ates.wav`
- `dusman_ates.wav`
- `dusman_vuruldu.wav`
- `oyuncu_hasar.wav`
- `engel_vuruldu.wav`
- `yeni_dalga.wav`

## Derleme

Projeyi CMake ile derliyorum. SFML kurulumu `C:/SFML` konumunda olacak sekilde ayarlanmistir.

```powershell
cmake --build build-vs2026 --config Debug
```

Derleme bittikten sonra calistirilabilir dosya su konumda olusur:

```text
build-vs2026/Debug/SpaceInvaders.exe
```

## Notlar

Bu projede amacim klasik Space Invaders mantigini kendi kod yapimla kurmakti. Oyuncu, dusman, mermi, engel ve carpisma islemlerini ayri dosyalara bolerek kodu daha okunabilir hale getirdim. Sonradan baslangic ekrani, sonuc ekrani, yeniden baslatma sistemi ve ses efektleri ekledim.
