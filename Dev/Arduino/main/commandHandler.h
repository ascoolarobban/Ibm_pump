
//Recieve command from serial, check what it should do:
void commandHandler(int comdata) {

  switch (comdata) {

    case 'A': // A Starts pump
      pumpcontroller('A'); //Pumpcontroller in pumpOnOff.h
      break;

    case 'B'://B stops pump
      pumpcontroller('B');//Pumpcontroller in pumpOnOff.h

      break;

    case 3:
      break;

    case 4:

      break;
  }

}
