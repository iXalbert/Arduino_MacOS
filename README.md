# Proiect Arduino & IoT (Mac M3 Max)

Acesta este un repository dedicat dezvoltării de proiecte embedded folosind kit-ul Arduino Uno R3.

## 🛠️ Hardware utilizat
* **Laptop:** MacBook Pro M3 Max
* **Placă de dezvoltare:** [Arduino Uno R3 — Kit Shijooer (165+ componente)](https://www.emag.ro/kit-de-programare-arduino-uno-r3-shijooer-kit-start-componente-electronice-kit-compatibil-arduino-ide-peste-165-componente-senzori-si-motor-pas-cu-pas-servo-motor-sg90-display-lcd-telecomanda-componen/pd/D3QM813BM/?ref=history-shopping_479259339_251821_1)
* **Componente:** Senzor Ultrasonic (HC-SR04), Servo SG90, Buzzer, LED RGB, Potențiometru, Senzor DHT11, Receptor IR + telecomandă, Display LCD I2C 16x2, Joystick, Afișaj 7 segmente

## 🚀 Proiecte
1. **Primul_task** — LED Blink de bază pe pinul 13 (LED-ul onboard), interval de 100ms.
2. **Distance_task** — Măsurarea distanței cu senzorul ultrasonic HC-SR04, afișare pe Serial Monitor.
3. **Distance_sound_task** — Senzor ultrasonic + buzzer. Buzzer-ul emite sunete în funcție de distanță (continuu < 10cm, intermitent 10–50cm, oprit > 100cm).
4. **Servo_motor_task** — Test servo motor: sweep complet 0°–180° și înapoi.
5. **Servomotor_task** — Test simplu servo motor: oscilare între 10° și 170°.
6. **Traffic_Lighter_task** — Semafor inteligent: senzor ultrasonic + LED RGB + buzzer + servo barieră. Schimbă culoarea și deschide bariera în funcție de distanță.
7. **parking_barrier** — Barieră de parcare: senzorul ultrasonic deschide servo-ul când detectează un obiect aproape.
8. **parking_barrier_led** — Barieră de parcare cu indicatoare LED (servo + LED roșu/verde).
9. **Potentiometru_Barrier** — Control manual al barierei: potențiometrul reglează unghiul servo-ului.
10. **Sound_by_emotion** — Barieră controlată prin Serial Monitor cu LED RGB și buzzer.
11. **Senzor_buzzer_RGB** — Distanța detectată controlează frecvența buzzer-ului și intensitatea LED-ului RGB.
12. **Pot_LED** — Potențiometrul controlează luminozitatea LED-ului prin PWM.
13. **Toggle_oc_Led** — LED cu toggle la apăsarea butonului, folosind debounce.
14. **Toggle_oc_LED_v2** — LED aprins cât timp butonul este apăsat.
15. **Temp_umiditate** — Citește temperatura și umiditatea cu DHT11 și aprinde un LED peste pragul setat.
16. **IR_Hexcode** — Afișează în Serial Monitor codurile HEX primite de la telecomanda IR.
17. **IR_task_buzz_led** — Telecomanda IR controlează LED-ul și buzzer-ul.
18. **LCD_IR** — Telecomandă IR + LCD I2C pentru afișarea comenzilor și control LED/buzzer.
19. **Piano_lcd_buzz** — Pian digital simplu cu telecomandă IR, buzzer și LCD.
20. **7_segment_display** — Timer/numărătoare pe display 7 segmente cu 4 cifre, controlat prin telecomandă.
21. **JoyStick_7seg** — Joystick-ul controlează schimbarea cifrelor pe un display 7 segmente.
22. **DODGE_MAN_v2** — Joc pe LCD controlat cu joystick: eviți obstacole, ai 3 vieți afișate pe 7 segmente, iar buzzer-ul și servo-ul reacționează la coliziuni.

## 💻 Setup Mac M3 Max
* **IDE:** Arduino IDE 2.x (Apple Silicon)
* **Port Serial:** `/dev/cu.usbserial-XXX` sau `/dev/cu.usbmodemXXX`
* **Limbaj:** C++ (Arduino)
