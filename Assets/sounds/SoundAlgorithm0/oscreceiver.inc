instr 1001

klisx, klisy, klisz, klisdir init 0

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
	
	kpositions OSClisten giosc1, "/listenerPositions", "ffff", klisx, klisy, klisz, klisdir
		
		gklisxSmooth port klisx, .025
		gklisySmooth port klisy, .025
		gkliszSmooth port klisz, .025
		gklisdirSmooth port klisdir, .025
	
	kroomparameters OSClisten giosc1, "/roomParameters", "ffffffffffffffffffff", gkroomx, gkroomy, gkroomz, gklowtime, gkhightime, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3
	
	kfinish OSClisten giosc1, "/end", "f", gkend
	
		gktrig changed gksrcTrigAny, gkroomx, gkroomy, gkroomz, gklowtime, gkhightime, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3
		
	gkrevTrig changed gklowtime, gkhightime

endin
