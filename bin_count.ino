/*
 * bin_count.ino
 *  This program uses LEDs to represent bits of a 4-bit integer. When a button
 * is pressed, the number is incremented (rounding back to 0 after 15) and the
 * LEDs are updated accordingly.  
 */

int first_led_pin = 8;
int second_led_pin = 6;
int third_led_pin = 4;
int fourth_led_pin = 2;
int button_pin = 10;

const int led_pins[4] = {8,6,4,2};

int count = 0;

void setup() {
    Serial.begin(9600);

    pinMode(first_led_pin, OUTPUT);
    pinMode(second_led_pin, OUTPUT);
    pinMode(third_led_pin, OUTPUT);
    pinMode(fourth_led_pin, OUTPUT);
    pinMode(button_pin, INPUT);
}

void loop() {
    int state;
    state = digitalRead(button_pin);
    Serial.println(state);
    while(state == LOW) {
        state = digitalRead(button_pin);
        Serial.println(state);
        delay(1);
    }      // Do nothing while button is not pressed
    while(state == HIGH) {
        state = digitalRead(button_pin);
        Serial.println(state);
        delay(1);
    }     // Wait till button is pressed and released
    Serial.println("Button pressed");
    count = ++count % 16;
    Serial.println(count);

    for(int i = 0; i < (sizeof(led_pins)/sizeof(led_pins[0])); i++) {
        digitalWrite(led_pins[i], get_pos_bit(count, i + 1));
    }
    delay(1);
}

/*
 * Function: get_pos_bit
 * -----------------------
 * gets the value of the bit of the given number at the given position.
 *      ex: 13 = 1101,
 *          get_pos_bit(13, 2) => 1 1 0 1
 *                                4 3 2 1
 *                                    ^
 *          returns 0
 * 
 *  num: number to extract bit from
 *  pos: position to extract bit from
 * 
 *  returns: the value of the bit of the number at the given position
 * */
int get_pos_bit(int num, int pos) {
    int mask = 1 << (pos - 1);
    int bit = (num & mask) >> (pos - 1);
    return bit;
}