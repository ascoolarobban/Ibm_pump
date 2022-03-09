
//Recieve command from serial, check what it should do:
void commandHandler(int comdata) {

  switch (comdata) {

    case 'A': // A Starts pump
      pumpON(); //Pumpcontroller in pumpOnOff.h
      break;

    case 'B'://B stops pump
      pumpOFF();//Pumpcontroller in pumpOnOff.h

      break;
    case 'C': // Opens valve
      valveON(); //Pumpcontroller in pumpOnOff.h
      break;

    case 'D'://D  Closes Valve
      valveOFF();//Pumpcontroller in pumpOnOff.h
      break;
  }

}
