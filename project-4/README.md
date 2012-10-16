Project-4 - Disk Scheduling
==============
John Archer  
Still a work in progress as the Elevator search is not working correctly.  This is being worked on and tested as well as possbally reducing the program length as corrections are introduced and can result in a possible sorting sub-routine being used.

First-come First-served:  
The first-come first-served algorithm was the easiest to implement and do as it just goes from one track to the next track in the list.  This is the fastest to implement but is the slowest is operation for the disk seek order as it produces excess head movement needed to prefrom the job.  
 
Sortest seek:  
The shortest seek operation was not very hard to do but it was not as easy as the first-come first served algorithm.  This algorithm required all of the tracks needs be read in first and then sorted to find the shortest amount of track distance from the current track being read to the next track in the sorted list.  This algorithm provide less wasted head movement and speed up the seek time of the disk but does take more processing power the the first-come first-served algorithm. 

Scan-Look or Elevator:
This algorithm is the one that still does not work correctly as the sorting algorithm is not working as corectly

