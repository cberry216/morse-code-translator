int code_led1 = 4;
int code_led2 = 11;
int code_led3 = 8;
int code_led4 = 13;

int ok_led = 6;
int no_led = 7;

int code_but1 = 10;
int code_but2 = 12;
int code_but3 = 3;
int code_but4 = 5;

int enter_but = 9;
int save_but = 2;

// Status Variables
int led1_status = 0;
int led2_status = 0;
int led3_status = 0;
int led4_status = 0;

int *led_statuses[4] = {&led1_status, &led2_status, &led3_status, &led4_status};

int ok_status = 0;
int no_status = 0;

// Code Variables
char set_code = 0;
const int code_len = 4;

int submit_code();
int save_code();
char get_code_as_char();
void turn_lights_off();

void setup() {
    Serial.begin(9600);

    pinMode(code_led1, OUTPUT);
    pinMode(code_led2, OUTPUT);
    pinMode(code_led3, OUTPUT);
    pinMode(code_led4, OUTPUT);

    pinMode(ok_led, OUTPUT);
    pinMode(no_led, OUTPUT);

    pinMode(code_but1, INPUT);
    pinMode(code_but2, INPUT);
    pinMode(code_but3, INPUT);
    pinMode(code_but4, INPUT);

    pinMode(enter_but, INPUT);
    pinMode(save_but, INPUT);

    digitalWrite(code_led1, led1_status);
    digitalWrite(code_led2, led2_status);
    digitalWrite(code_led3, led3_status);
    digitalWrite(code_led4, led4_status);

    digitalWrite(ok_led, ok_status);
    digitalWrite(no_led, no_status);
}

void loop() {

    int response1;
    int response2;
    int response3;
    int response4;

    int save;
    int enter;

    while((response1 = digitalRead(code_but1)) == LOW &&
        (response2 = digitalRead(code_but2)) == LOW &&
        (response3 = digitalRead(code_but3)) == LOW &&
        (response4 = digitalRead(code_but4)) == LOW &&
        (save = digitalRead(save_but)) == LOW &&
        (enter = digitalRead(enter_but)) == LOW) {
            //Serial.println("Nothing.");
    }

    if(response1 == HIGH) {
        while((response1 = digitalRead(code_but1)) == HIGH) {}
        led1_status = (led1_status) ? 0 : 1;
        Serial.print("Button 1 Pressed: ");
        Serial.print("Status = ");
        Serial.println(led1_status);
        digitalWrite(code_led1, led1_status);
    }
    
    if(response2 == HIGH) {
        while((response2 = digitalRead(code_but2)) == HIGH) {}
        led2_status = (led2_status) ? 0 : 1;
        Serial.print("Button 2 Pressed: ");
        Serial.print("Status = ");
        Serial.println(led2_status);
        digitalWrite(code_led2, led2_status);
    }

    if(response3 == HIGH) {
        while((response3 = digitalRead(code_but3)) == HIGH) {}
        led3_status = (led3_status) ? 0 : 1;
        Serial.print("Button 3 Pressed: ");
        Serial.print("Status = ");
        Serial.println(led3_status);
        digitalWrite(code_led3, led3_status);
    }

    if(response4 == HIGH) {
        while((response4 = digitalRead(code_but4)) == HIGH) {}
        led4_status = (led4_status) ? 0 : 1;
        Serial.print("Button 4 Pressed: ");
        Serial.print("Status = ");
        Serial.println(led4_status);
        digitalWrite(code_led4, led4_status);
    }

    if(enter == HIGH) {
        while((enter = digitalRead(enter_but)) == HIGH) {}

        Serial.println("Submitted Code Answer");

        digitalWrite(ok_led, LOW);
        digitalWrite(no_led, LOW);
        delay(100);

        digitalWrite((submit_code()) ? ok_led : no_led, HIGH);
        delay(1000);
        turn_lights_off();
    }

    if(save == HIGH) {
        while((save = digitalRead(save_but)) == HIGH) {}
        int new_code = save_code();
        Serial.print("New Code Set To: ");
        Serial.println(new_code);
    }

    delay(10);

}

int submit_code() {
    int guess_code = get_code_as_char();

    return (guess_code == set_code) ? 1 : 0;
}

int save_code() {
    int new_code = get_code_as_char();

    set_code = new_code;
    turn_lights_off();

    return set_code;
}

char get_code_as_char() {
    char value = 0;
    for(int i = 0; i < code_len; i++) {
        value += *(led_statuses[i]);
        value <<= 1;
    }
    return value;
}

void turn_lights_off() {
    digitalWrite(ok_led, LOW);
    digitalWrite(no_led, LOW);
    digitalWrite(code_led1, LOW);
    digitalWrite(code_led2, LOW);
    digitalWrite(code_led3, LOW);
    digitalWrite(code_led4, LOW);

    led1_status = 0;
    led2_status = 0;
    led3_status = 0;
    led4_status = 0;
    ok_status = 0;
    no_status = 0;
}