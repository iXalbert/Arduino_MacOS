###🏃‍♂️ DODGE MAN - Arduino Retro Console

Dodge Man este o mini-consolă de jocuri "Endless Runner" construită pe platforma Arduino Uno. Jocul testează reflexele jucătorului, care trebuie să ghideze un personaj printr-un câmp de obstacole generate dinamic pe un ecran LCD.

###🎮 Caracteristici (Features)

Grafică Custom: Personaj animat (omuleț) creat prin definirea pixelilor pe LCD.

Dificultate Progresivă: Viteza obstacolelor crește pe măsură ce scorul avansează.

Feedback Fizic: Servomotorul acționează ca o barieră mecanică (se ridică la start, cade la Game Over).

Sistem de Vieți: Afișaj în timp real pe un segment de 7 cifre (3 vieți per joc).

Interfață Sonoră: Buzzer pentru coliziuni și sunete de final de joc.

Salvare Scor: Scorul final rămâne afișat pe ecran până la resetarea manuală.

🛠️ Componente Necesare (BOM)

🧠 Creierul
Arduino Uno R3 — Cel care rulează codul și coordonează toate mișcările.

📺 Interfață Vizuală (Display)
LCD 16x2 (I2C) — Ecranul principal unde prinzi viață în format 8-bit.
7-Segment Display — Monitorul tău de vieți (3 pentru supraviețuire!).

🕹️ Control & Input
Joystick Analog — Volanul tău pentru eschive rapide sus/jos.
Buton Integrat (SW) — Declanșatorul pentru a începe o rundă nouă.

🦾 Feedback Fizic & Sonor
Servomotor SG90 — „Brațul” mecanic care indică starea jocului (Start/Stop).
Buzzer Pasiv — Cel care te „ceartă” sonor la fiecare coliziune.

🔌 Conectică (The Glue)
Rezistență 220Ω — Garda de corp a afișajului 7-segment.
Breadboard & Fire Jumper — Autostrăzile de cupru care leagă totul.

🔌 Schema de Conectare (Pinout)

📺 Afișaje & Actuatori

LCD I2C: SDA (A4), SCL (A5), VCC (5V), GND (GND)

7-Segment: Pinii D2, D4, D5, D6, D8, D12, D13 (Segmentele A-G)

Servomotor: Pin D11 (Semnal), Roșu (5V), Maro (GND)

Buzzer: Pin D9 (+)

🕹️ Control

Joystick VRx/VRy: Pin A0 (Mișcare)

Joystick SW: Pin D10 (Buton Click)

🕹️ Instrucțiuni de Joc

Start: Apasă pe butonul Joystick-ului când pe ecran apare mesajul "DODGE MAN".

Control: Mișcă maneta în sus sau în jos pentru a schimba rândul pe care se află omulețul.

Obiectiv: Evită caracterele # (obstacole).

Vieți: Ai 3 vieți. La fiecare coliziune, pierzi o viață și auzi un sunet de avertizare.

Game Over: Când rămâi fără vieți, brațul servomotorului va cădea, iar scorul tău va fi afișat constant pe ecran.

💻 Instalare Software

Descarcă și instalează Arduino IDE.

Instalează biblioteca LiquidCrystal_I2C din Library Manager.

Copiază codul sursă în IDE și apasă butonul Upload.

Notă: Proiect realizat ca exercițiu de învățare a interacțiunii dintre hardware și software folosind senzori și actuatori diverși.
