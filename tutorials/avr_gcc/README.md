# Verwendung von AVR-GCC unter MPLAB X IDE

Innerhalb der MPLAB X IDE können verschiedene Compiler verwendet werden. Für die meisten ist der [XC8-Compiler](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers#tabs) für 8-Bit-Systeme von Microchip sicher die beste Wahl. Allerdings können wahlweise auch andere Compiler innerhalb der Entwicklungsumgebung genutzt werden. Dazu zählen:

- [AVR-GCC](https://gcc.gnu.org/wiki/avr-gcc)
- [IAR for AVR](https://www.iar.com/ewavr)

Im folgenden wird die Einbindung des AVR-GCC beschrieben.

## AVR-GCC für MacOS

Am einfachsten lässt sich die `avr-gcc`-Toolchain unter MacOS mittels [Homebrew](https://brew.sh) instllieren. Geben Sie dazu im Terminal folgendes ein:

```bash
> brew install avr-gcc
```

Nach erfolgreicher Installation ist die Toolchain nutzbar. Prüfen Sie dies durch Eingabe im Terminal:

```bash
> avr-gcc --version

avr-gcc (Homebrew AVR GCC 9.3.0_3) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
````

Nun muss die Toolchain noch in MPLAB X IDE eingebunden werden. Öffnen Sie dazu `MPLAB X IDE` und wählen unter `MPLAB X IDE` --> `Preferences` aus. Gehe Sie zum Reiter `Embedded` --> `Build Tools`.

Klicken Sie auf `Add...` um eine neue Toolchain hinzuzufügen:

![Neue Toolchain hinzufügen](img/mplab_avr-gcc_macos_01.png)

Wählen Sie danach den Pfad aus, in dem sich die Toolchain befindet. Wurde AVR-GCC mittels `brew` installiert, befinden sich die Programme im Ordner `/usr/local/bin`. Das Programm erkennt automatisch, dass sich der `AVR-GCC` im Ordner befindet und aktualisiert den Eintrag im Feld `Version` auf `AVR`. Klicken Sie anschließend auf `OK`.

![Pfadangabe für neue Toolchain](img/mplab_avr-gcc_macos_02.png)

MPLAB X IDE fügt automatisch alle entsprechenden Programme inkl. der Pfadangaben hinzu. Die Einträge für den AVR-GCC-Compiler sollten wie folgt aussehen:

![Übersicht der neu hinzugefügten Toolchain](img/mplab_avr-gcc_macos_03.png)

Von nun an kann `AVR-GCC` als Toolchain ausgewählt werden.


## AVR-GCC für Linux

Tbd

## AVR-GCC für Windows

Ist auf dem Rechner bereits die kostenlose [Arduino IDE](https://www.arduino.cc/en/software) installiert, befindet sich auch AVR-GCC auf dem Rechner. Diese Version kann in der MPLAB X IDE verwendet werden. Alternativ ist die AVR-GCC bei Microchip [downloadbar](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers-avr-and-arm).

Nun muss die Toolchain noch in MPLAB X IDE eingebunden werden. Öffnen Sie dazu `MPLAB X IDE` und wählen unter `Tools` --> `Options` aus. Gehe Sie zum Reiter `Embedded` --> `Build Tools`.

Klicken Sie auf `Add...` um eine neue Toolchain hinzuzufügen:

![Neue Toolchain hinzufügen](img/mplab_avr-gcc_win_01.png)

Wählen Sie danach den Pfad aus, in dem sich die Toolchain befindet. Wurde AVR-GCC über die Arduino IDE installiert, befinden sich die Programme im Ordner `C:\Program Files (x86)\Arduino\hardware\tools\avr\bin`. Das Programm erkennt automatisch, dass sich der `AVR-GCC` im Ordner befindet und aktualisiert den Eintrag im Feld `Version` auf `AVR`. Klicken Sie anschließend auf `OK`.

![Pfadangabe für neue Toolchain](img/mplab_avr-gcc_win_02.png)

MPLAB X IDE fügt automatisch alle entsprechenden Programme inkl. der Pfadangaben hinzu. Die Einträge für den AVR-GCC-Compiler sollten wie folgt aussehen:

![Übersicht der neu hinzugefügten Toolchain](img/mplab_avr-gcc_win_03.png)