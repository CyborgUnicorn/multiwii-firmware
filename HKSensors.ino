#ifdef HK_MAX_SONAR

#define NUMSAMPLES 10

static uint16_t sonarAltitudeAverage = 0;

uint8_t samples[NUMSAMPLES];

void HK_Sonar_Init() {
  pinMode(A0,INPUT);
  memset(samples, 0, sizeof(uint8_t) * NUMSAMPLES);
}

void HK_Sonar_Update() {
  HK_sonarPushSample( analogRead(A0) );
  HK_calculateAverageSample();
}

void HK_sonarPushSample( uint8_t sample ) {
	for (int i = 0; i < NUMSAMPLES - 1; i++)
        samples[i] = samples[i + 1];

	samples[NUMSAMPLES - 1] = sample;
}

void HK_calculateAverageSample()  {
	uint16_t value = 0;
	for (int i = 0; i < NUMSAMPLES; ++i)
        value += samples[i];

    sonarAltitudeAverage = HK_toCentimeters(value / NUMSAMPLES);
}

uint16_t HK_toCentimeters( uint16_t reading ) {
  return (reading / 2.0) * 2.54;
}

#endif


#ifdef HK_HMC_COMPASS

#endif
