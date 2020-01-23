%Connect_Arduino();

stepsPerRev = 32 * 16.032;
thisStepper = Stepper(a, stepsPerRev, 'D8', 'D9', 'D10', 'D11');

MoveClockWise(thisStepper,100,513);
MoveCounterClockWise(thisStepper,100,513);