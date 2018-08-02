/*
 * radar.ino
 *  This program uses a sonic distance sensor to determine the distance from a
 * given object and adjusts the intensity of an LED based of the distance (e.g.
 * the closer an object gets the brighter the light gets). 
 */

int trig_pin = 2;
int echo_pin = 4;
int led_pin = 6;

long duration;
int distance;

void setup() {
    Serial.begin(9600);

    pinMode(led_pin, OUTPUT);
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}

void loop() {
    int brightness = 0;
    long dist_tot = 0;
    int count = 0;

    for(int i = 0; i < 10; i++) {
        digitalWrite(trig_pin, LOW);
        delayMicroseconds(2);

        digitalWrite(trig_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig_pin, LOW);

        duration = pulseIn(echo_pin, HIGH);

        distance = duration * (0.034 / 2);

        if(distance < 200) {
            dist_tot += distance;
            count++;
        }
        delay(10);
    }
    Serial.print("Distance Average: ");
    Serial.println(dist_tot / count);

    long avg_dist = (dist_tot / count);

    brightness = (200 - avg_dist) / 2;

    analogWrite(6, brightness);

    Serial.print("Brightness: ");
    Serial.println(brightness);
}