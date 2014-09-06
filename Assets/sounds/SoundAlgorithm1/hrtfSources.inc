instr 1 

kamp, kaz, kel init 0

ksoundource OSClisten giosc1, "/sourceAttributes1", "fff", kaz, kel, kamp 

aleft, aright hrtfmove2 (gasrc1*kamp), kaz, kel, "hrtf-44100-left.dat","hrtf-44100-right.dat"
outs aleft, aright
  	
endin

instr 2 

kamp, kaz, kel init 0

ksoundource OSClisten giosc1, "/sourceAttributes2", "fff", kaz, kel, kamp 

aleft, aright hrtfmove2 (gasrc2*kamp), kaz, kel, "hrtf-44100-left.dat","hrtf-44100-right.dat"
outs aleft, aright
  	
endin

instr 3 

kamp, kaz, kel init 0

ksoundource OSClisten giosc1, "/sourceAttributes3", "fff", kaz, kel, kamp 

aleft, aright hrtfmove2 (gasrc3*kamp), kaz, kel, "hrtf-44100-left.dat","hrtf-44100-right.dat"
outs aleft, aright

endin

instr 4
	kamp, kaz, kel init 0

ksoundource OSClisten giosc1, "/sourceAttributes4", "fff", kaz, kel, kamp 

aleft, aright hrtfmove2 (gasrc4*kamp), kaz, kel, "hrtf-44100-left.dat","hrtf-44100-right.dat"
outs aleft, aright
endin
