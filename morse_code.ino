char letter[4];
int pos = 0;

char test_letter[4];

char convert_morse_to_char(char*, int);

void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
}

void loop() {
    // test_letter[0] = '.';
    // test_letter[1] = '-';
    // Serial.println(convert_morse_to_char(test_letter, 2));
    int switch_state = digitalRead(5);
    if(switch_state == HIGH) {
        unsigned int start_time = millis() % 100000;
        //Serial.println(start_time);
        while((switch_state = digitalRead(5)) == HIGH) {
            tone(3, 700, 20);
        }
        unsigned int end_time = millis() % 100000;
        //Serial.println(end_time);
        unsigned int total_time = end_time - start_time;

        if(total_time > 0 && total_time <= 200) {
            // Serial.print('.');
            letter[pos++] = '.';
        }
        if(total_time > 200 && total_time <= 450) {
            // Serial.print('-');
            letter[pos++] = '-';
        }
    }
    else {
        unsigned int start_time = millis();
        while((switch_state = digitalRead(5)) == LOW) {
            if(millis() - start_time >=1500){
                break;
            }
        }
        unsigned int end_time = millis();
        unsigned int total_time = end_time - start_time;
        if(total_time > 500 && pos > 0) {
            // Serial.print(' ');
            Serial.print(convert_morse_to_char(letter, pos));
            pos = 0;
            memset(letter, '\0', 4 * sizeof(char));
        }
    }
    delay(1);

}

char convert_morse_to_char(char* letter, int len) {
    if(len == 1) {
        if(letter[0] == '.') return 'E';
        if(letter[0] == '-') return 'T';
        else return ' ';
    }
    if(len == 2) {
        if(letter[0] == '.' && letter[1] == '-') return 'A';
        if(letter[0] == '.' && letter[1] == '.') return 'I';
        if(letter[0] == '-' && letter[1] == '-') return 'M';
        if(letter[0] == '-' && letter[1] == '.') return 'N';
        else return ' ';
    }
    if(len == 3) {
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '.') return 'D';
        if(letter[0] == '-' && letter[1] == '-' && letter[2] == '.') return 'G';
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '-') return 'K';
        if(letter[0] == '-' && letter[1] == '-' && letter[2] == '-') return 'O';
        if(letter[0] == '.' && letter[1] == '-' && letter[2] == '.') return 'R';
        if(letter[0] == '.' && letter[1] == '.' && letter[2] == '.') return 'S';
        if(letter[0] == '.' && letter[1] == '.' && letter[2] == '-') return 'U';
        if(letter[0] == '.' && letter[1] == '-' && letter[2] == '-') return 'W';
        else return ' ';
    }
    if(len == 4) {
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '.' && letter[3] == '.') return 'B';
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '-' && letter[3] == '.') return 'C';
        if(letter[0] == '.' && letter[1] == '.' && letter[2] == '-' && letter[3] == '.') return 'F';
        if(letter[0] == '.' && letter[1] == '.' && letter[2] == '.' && letter[3] == '.') return 'H';
        if(letter[0] == '.' && letter[1] == '-' && letter[2] == '-' && letter[3] == '-') return 'J';
        if(letter[0] == '.' && letter[1] == '-' && letter[2] == '.' && letter[3] == '.') return 'L';
        if(letter[0] == '.' && letter[1] == '-' && letter[2] == '-' && letter[3] == '.') return 'P';
        if(letter[0] == '-' && letter[1] == '-' && letter[2] == '.' && letter[3] == '-') return 'Q';
        if(letter[0] == '.' && letter[1] == '.' && letter[2] == '.' && letter[3] == '-') return 'V';
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '.' && letter[3] == '-') return 'X';
        if(letter[0] == '-' && letter[1] == '.' && letter[2] == '-' && letter[3] == '-') return 'Y';
        if(letter[0] == '-' && letter[1] == '-' && letter[2] == '.' && letter[3] == '.') return 'Z';
        printf("fuck");
    }
}