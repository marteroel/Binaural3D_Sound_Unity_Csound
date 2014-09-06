Binaural3D_Sound_Unity_Csound
=============================

HRTF Binaural 3D sound engine for Unity, using Csound as a host via Open Sound Control.


README:

This is an example of how to use binaural 3D sound within Unity 3D, in combination with Csound. 
It works both on Windows and MacOS. It requires Unity3D and Csound 5.19 to be installed 
on your computer (note that it hasn’t been tested with Csound 6). 

This readme file includes a basic explanation on how to use it, for further information 
please send an email to marteroel@gmail.com. Using it requires none, 
or little programming experience.

a) Setup

1. Open the Unity3D project where this file is found.
2. Open one of the two Csound files.


b) Instructions

1. Csound

Choose one of the two sound algorithms provided for Csound, SoundAlgorithm0.csd includes 
room simulation (echoic); SoundAlgorithm1.csd positions sound without room simulation 
(anechoic). This example allows for up to four (4) different sounds to be positioned 
in 3D space.

To add a sound, simply make it a mono wave file and name it with an integer number, 
i.e. 1.wav, 2.wav, sound3.wav, or sound4.wav and drop it into the sounds folder in the 
Unity project. 

2. Unity

Drag the object that you want to position in 3D sound into one of the Sound Object fields 
found in the 3D Sound object. Up to four sounds may be positioned in 3D acoustic space 
in the current example. Set the initial level of each of the Sound Objects whether you
want it to loop, and its name (without the format, i.e: 1 rather than 1.wav). 
Choose an an algorithm depending on the Csound file used, if the algorithm is set to 0 
you may choose a room size with size not less than 2x2x2. 

Currently the Listener's position is paired with the camera's. This is good when doing a 
first person game, otherwise set the Transform of the head of the listener as the 
Listener by dragging and dropping.

3. Start

Run Csound and Unity


NOTE: This system has been tested using Csound 5.19 and may not work with later versions of Csound.