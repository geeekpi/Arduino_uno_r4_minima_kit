void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    pinMode(2 /*ESP RST*/, OUTPUT);

    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delay(50);

    while (Serial1.find("OK"))
    {
    }

    // 等模块就绪
    while (true)
    {
        delay(100);
        if (Serial1.available() > 0)
            if (Serial1.find("AT"))
                break;

        Serial1.println("AT");
    }

    Serial1.println("AT+CWMODE=1");
    delay(100);

    Serial1.println("AT+CWJAP=\"HUAWEI-B4NKSR\",\"stm32f429\"");

    while (true)
    {
        delay(100);
        if (Serial1.available() > 0)
            if (Serial1.find("GOT IP"))
                break;
    }

    // fix busy p... due to poor network ... conn to ap wait too long
    delay(2000);

    Serial1.println("AT+CIPSTART=\"TCP\",\"192.168.3.8\",44655");

    while (true)
    {
        delay(100);
        if (Serial1.available() > 0)
            if (Serial1.find("OK"))
                break;
    }

    // 100% ok
    delay(100);
    Serial1.println("AT+CIPMODE=1");
    delay(100);
    Serial1.println("AT+CIPSEND");
}

void loop()
{
    int sensorValue = 0;
    sensorValue = analogRead(A0);

    delay(1000);
    Serial.println("go");
    Serial1.print("ADC=");
    Serial1.print(sensorValue);
}
