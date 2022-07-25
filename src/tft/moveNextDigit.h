void moveNextDigit() {
  // every step corresponds to 2 frames: 1 even + 1 uneven
  for (int step = 1; step <=45; step++) {
    for (int i = 0; i <=5; i++) {

      // lets start with uneven
      angleBack[i] = angleBack[i] + moveUnEvBack[i];
      if (angleBack[i] >= 360) {angleBack[i] = 0; }
      angleFront[i] = angleFront[i] + moveUnEvFront[i];
      if (angleFront[i] >= 360) {angleFront[i] = 0; }
      plotNeedle(angleBack[i], moveUnEvBack[i], angleFront[i], moveUnEvFront[i], i);

      // and next even
      angleBack[i] = angleBack[i] + moveEvenBack[i];
      if (angleBack[i] >= 360) {angleBack[i] = 0; }
      angleFront[i] = angleFront[i] + moveEvenFront[i];
      if (angleFront[i] >= 360) {angleFront[i] = 0; }
      plotNeedle(angleBack[i], moveEvenBack[i], angleFront[i], moveEvenFront[i], i);
    }
  }
}
