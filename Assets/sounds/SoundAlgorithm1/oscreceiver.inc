instr 1001

	ksources OSClisten giosc1, "/onOff", "iiii", gksrcOn1, gksrcOn2, gksrcOn3, gksrcOn4
	
	gktrigSrc1 changed gksrcOn1
	gktrigSrc2 changed gksrcOn2
	gktrigSrc3 changed gksrcOn3
	gktrigSrc4 changed gksrcOn4
	
	gksrcTrigAny changed gksrcOn1, gksrcOn2, gksrcOn3, gksrcOn4
	
	gksrcOnTrig1 = gktrigSrc1 * gksrcOn1
	gksrcOnTrig2 = gktrigSrc2 * gksrcOn2
	gksrcOnTrig3 = gktrigSrc3 * gksrcOn3
	gksrcOnTrig4 = gktrigSrc4 * gksrcOn4
	
	knames OSClisten giosc1, "/sourceName", "iiii", gkname1, gkname2, gkname3, gkname4
	
	kloops OSClisten giosc1, "/sourceLoop", "iiii", gkloop1, gkloop2, gkloop3, gkloop4

	
	kfinish OSClisten giosc1, "/end", "f", gkend
	
		gktrig changed gksrcTrigAny

endin
