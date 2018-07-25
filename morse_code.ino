void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);

}

void loop() {
    int switch_state = digitalRead(5);
    if(switch_state == HIGH) {
        unsigned int start_time = millis();
        //Serial.println(start_time);
        while((switch_state = digitalRead(5)) == HIGH) {
            tone(3, 700, 20);
        }
        unsigned int end_time = millis();
        //Serial.println(end_time);
        unsigned int total_time = end_time - start_time;

        if(total_time > 0 && total_time <= 200) {
            Serial.print('.');
        }
        if(total_time > 200 && total_time <= 450) {
            Serial.print('-');
        }
    }
    else {
        unsigned int start_time = millis();
        while((switch_state = digitalRead(5)) == LOW) {}
        unsigned int end_time = millis();
        unsigned int total_time = end_time - start_time;
        if(total_time > 500) {
            Serial.print(' ');
        }
    }
    delay(1);
}

char convert_time_to_char(int time) {
    
}