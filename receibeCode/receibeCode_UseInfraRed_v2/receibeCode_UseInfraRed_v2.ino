
#include <Arduino.h>
#include <IrReceiverPoll.h>

#ifdef ESP32
static constexpr pin_t RECEIVE_PIN = 4U;
#elif ESP8266
static constexpr pin_t RECEIVE_PIN = 2U;
#else
static constexpr pin_t RECEIVE_PIN = 2U;
#endif

static constexpr size_t BUFFERSIZE = 500UL;
static constexpr uint32_t BAUD = 115200UL;

IrReceiver *receiver;

void setup() {
    Serial.begin(BAUD);
    while (!Serial)
        ;
    receiver = new IrReceiverPoll(BUFFERSIZE, RECEIVE_PIN);
    Serial.print(F("Listening on pin "));
    Serial.println(receiver->getPin(), DEC);
}

void loop() {
    receiver->receive(); // combines enable, loop, disable

    if (!receiver->isEmpty()){
        receiver->dump(Serial);
        Serial.println();
    }
}
