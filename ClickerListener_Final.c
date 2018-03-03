/* Project: rotatingDucks
 * Submission for: eHacks2018
 * Programmer: Jacob Grubb
 * File: ClickerListener_Final.c
 * Last Changed: 03/03/2018 03:47
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <signal.h>
 
void handler (int sig)
{
  printf ("\n exiting...(%d)\n", sig);
  exit (0);
}
 
void perror_exit (char *error)
{
  perror (error);
  handler (9);
}
 
int main (int argc, char *argv[])
{
  struct input_event ev[64];
  int fd, rd, value, size = sizeof (struct input_event);
  char name[256] = "Unknown";
  char *device = NULL;
  char deviceLocation[] = "/dev/input/event0";

  device = deviceLocation;
 
  //Open Device
  if ((fd = open (device, O_RDONLY)) == -1)
    printf ("%s is not currently connected.\n", device);
 
  //Print Device Name
  ioctl (fd, EVIOCGNAME (sizeof (name)), name);
  printf ("Reading From : %s (%s)\n", device, name);
 
  while (1){
      if ((rd = read (fd, ev, size * 64)) < size)
          perror_exit ("read()");      
 
      value = ev[0].value;
 
      if (value != ' ' && ev[1].value == 1 && ev[1].type == 1){ // Only read the key press event
       //printf ("Code[%d]\n", (ev[1].code));
       if(ev[1].code == 28){ //Android Button
           printf("Android Button\n");
           bottomButton();
       }
       if(ev[1].code == 115) { //IOS Button
            printf("iOS Button\n");
            topButton();
       }
      }
  }
 
  return 0;
}

void topButton()
{
    //Program the top button here, any code that goes here will be executed upon the use of the iOS button.
}

void bottomButton()
{
    //Program the bottom button here, any code that goes here will be executed upon the use of the android button.
}