# Proiect Arduino & IoT (Mac M3 Max)

Acesta este un repository dedicat dezvoltării de proiecte embedded folosind kit-ul Arduino Uno R3.

## 🛠️ Hardware utilizat
* **Laptop:** MacBook Pro M3 Max
* **Placă de dezvoltare:** Arduino Uno R3
* **Componente:** Senzor Ultrasonic (HC-SR04), Servo SG90, Buzzer, LED RGB, Potențiometru

## 🚀 Proiecte
1. **Primul_task** — LED Blink de bază pe pinul 13 (LED-ul onboard), interval de 100ms.
2. **Distance_task** — Măsurarea distanței cu senzorul ultrasonic HC-SR04, afișare pe Serial Monitor.
3. **Distance_sound_task** — Senzor ultrasonic + buzzer. Buzzer-ul emite sunete în funcție de distanță (continuu < 10cm, intermitent 10–50cm, oprit > 100cm).
4. **Servo_motor_task** — Test servo motor: sweep complet 0°–180° și înapoi.
5. **Servomotor_task** — Test simplu servo motor: oscilare între 10° și 170°.
6. **Traffic_Lighter_task** — Semafor inteligent: senzor ultrasonic + LED RGB + buzzer + servo barieră. Schimbă culoarea și deschide bariera în funcție de distanță.
7. **parking_barrier** — Barieră de parcare: senzorul ultrasonic deschide servo-ul (90°) când detectează un obiect la < 15cm.
8. **parking_barrier_led** — Barieră de parcare cu indicatoare LED (servo + LED roșu/verde).
9. **Potentiometru_Barrier** — Control manual al barierei: potențiometrul reglează unghiul servo-ului (0°–180°).
10. **Sound_by_emotion** — Barieră controlată prin Serial Monitor cu LED RGB și buzzer. Comenzi: `O` = deschide, `C` = închide, `B` = blochează, `T` = oprește.

## 💻 Setup Mac M3 Max
* **IDE:** Arduino IDE 2.x (Apple Silicon)
* **Port Serial:** `/dev/cu.usbserial-XXX` sau `/dev/cu.usbmodemXXX`
* **Limbaj:** C++ (Arduino)
