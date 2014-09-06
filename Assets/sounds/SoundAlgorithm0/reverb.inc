instr 10

	kverb init 0

	krev OSClisten giosc1, "/reverbAmount", "f", kverb
	
		aL, aR, idel hrtfreverb gamain, p4, p5, "hrtf-44100-left.dat", "hrtf-44100-right.dat", 44100, gimfp, giorder

	alateL delay aL * kverb, idel
	alateR delay aR * kverb, idel

outs alateL, alateR

gamain = 0

endin
