class LED {
  public:
    LED(int anode, int cathode);
    void on();
    void off();
  private:
    int _anode;
    int _cathode;
};

LED::LED(int anode, int cathode) {
  _anode = anode;
  _cathode = cathode;
}

void LED::on() {
  pinMode(_cathode, OUTPUT);
  pinMode(_anode, OUTPUT);
  digitalWrite(_cathode, HIGH);
  digitalWrite(_anode, LOW);
}

void LED::off() {
  pinMode(_cathode, INPUT);
  pinMode(_anode, INPUT);
}

void initPins(int start, int count) {
  for (int pin=start; pin<(start + count); pin++) {
    pinMode(pin, INPUT);
  }
}

LED leds[] = {
  LED(3,2),
  LED(2,3),
  LED(4,3),
  LED(3,4),
  LED(6,5),
  LED(5,6)
};
int ledCount = 6;

void setup() {
  initPins(2, 7);
}

void loop() {
  for (int i = 0; i<ledCount; i++) {
    leds[i].on();
    delay(500);
    leds[i].off();
  }
}
