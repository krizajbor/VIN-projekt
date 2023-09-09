int trigPin = 3;                        // Povežemo Trig v D3
int echoPin = 2;                        // Povežemo Echo v D2
long trajanje, dolzina;                 // Uvedemo spremenljivki, ki sta lahko decimalni števili

void setup() {  
    Serial.begin (9600);                // Začnemo s komunikacijo
    pinMode(trigPin, OUTPUT);           // Definiramo Trig kot izhodni podatek
    pinMode(echoPin, INPUT);            // Definiramo Echo kot vhodni podatek
    pinMode(4, OUTPUT);                 // Povežemo ledico na D4 in GND
    pinMode(5, OUTPUT);                 // Povežemo ledico na D5 in GND
    pinMode(6, OUTPUT);                 // Povežemo ledico na D6 in GND
}
void loop() {
    digitalWrite(trigPin, LOW);         // Izbrišemo signal
    delayMicroseconds(5);               // Počakamo 5 mikrosekund
    digitalWrite(trigPin, HIGH);        // Začnemo pošiljati signal s Trig, Echo ga bo sprejel
    delayMicroseconds(10);              // Ustvarimo val: Trig na HIGH za 10 mikrosekund
    digitalWrite(trigPin, LOW);         // Nehamo pošiljati signal
 
    trajanje = pulseIn(echoPin, HIGH);  // Shranimo trajanje signala (v mikrosekundah)
      dolzina = (trajanje/2)*0.034;     // Preračunamo čas v centimetre

    Serial.print(dolzina);              // Izpišemo dolžino
    Serial.print("cm");                 // Izpišemo enote
    Serial.println();                   // Gremo v novo vrstico

    if (dolzina > 15) {                 // Če je razdalja večja od 15 cm
      digitalWrite(4, LOW);             // Ugasnemo rdečo ledico
      digitalWrite(5, LOW);             // Ugasnemo rumeno ledico
      digitalWrite(6, HIGH);            // Prižgemo zeleno ledico
    }
    else if (dolzina < 8) {             // Če je razdalja manjša od 8 cm
      digitalWrite(4, HIGH);            // Prižgemo rdečo ledico
      digitalWrite(5, LOW);             // Ugasnemo rumeno ledico
      digitalWrite(6, LOW);             // Ugasnemo zeleno ledico
   }   
    else {                              // Če je razdalja med vključno 8 cm in vključno 15  cm
      digitalWrite(4, LOW);             // Ugasnemo rdečo ledico
      digitalWrite(5, HIGH);            // Prižgemo rumeno ledico
      digitalWrite(6, LOW);             // Ugasnemo zeleno ledico
    }
    delay(1000);                        // Počakamo 1 sekundo pred novim preverjanjem razdalje
}
