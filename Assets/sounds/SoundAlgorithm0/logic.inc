instr 999
	 

		if (gksrcOnTrig1 == 1) then
			event "i", 101, 1, 1000, gkloop1	
		endif
		
		
		if (gksrcOn1 == 0 && gktrigSrc1 == 1) then
			turnoff2 101, 1, 1	
		endif
				
				
		if (gksrcOnTrig2 == 1) then	
			event "i", 102, 1, 1000, gkloop2 		
		endif
		
		
		if (gksrcOn2 == 0 && gktrigSrc2 == 1) then
			turnoff2 102, 1, 1		
		endif
		
		
		if (gksrcOnTrig3 == 1) then	
			event "i", 103, 1, 1000, gkloop3 		
		endif
	

		
		if (gksrcOn3 == 0 && gktrigSrc3 == 1) then
			turnoff2 103, 1, 1		
		endif
		
			
		if (gksrcOnTrig4 == 1) then
			event "i", 104, 1, 1000, gkloop4 	
		endif
		
		
		if (gksrcOn4 == 0 && gktrigSrc4 == 1) then	
			turnoff2 104, 1, 1	
		endif
		
		
		
		if (gktrig != 0) then	
			turnoff2 10, 1, 1
			event     "i", 10, 0, 1000, gklowtime, gkhightime
		endif 
		
		
		if ((gktrig*gksrcOn1) != 0) then		
			turnoff2 1, 1, 1				
			event     "i", 1, 0, 1000, gklowtime, gkhightime, gkroomx, gkroomy, gkroomz, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3		
		endif
				
		if ((gktrig*gksrcOn2) != 0) then			
			turnoff2 2, 1, 1		
			event     "i", 2, 0, 1000, gklowtime, gkhightime, gkroomx, gkroomy, gkroomz, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3
			
		endif
		
		
		if ((gktrig*gksrcOn3) != 0) then			
			turnoff2 3, 1, 1	
			event     "i", 3, 0, 1000, gklowtime, gkhightime, gkroomx, gkroomy, gkroomz, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3		
		endif
		
		
		if ((gktrig*gksrcOn4) != 0) then			
			turnoff2 4, 1, 1		
			event     "i", 4, 0, 1000, gklowtime, gkhightime, gkroomx, gkroomy, gkroomz, gkwallhigh, gkwalllow, gkwallgain1, gkwallgain2, gkwallgain3, gkfloorhigh, gkfloorlow, gkfloorgain1, gkfloorgain2, gkfloorgain3, gkceilinghigh, gkceilinglow, gkceilinggain1, gkceilinggain2, gkceilinggain3		
		endif	
		
	ktrigend changed gkend
		
		if (ktrigend != 0) then
			turnoff2 1, 1, 1
			turnoff2 2, 1, 1
			turnoff2 3, 1, 1
			turnoff2 4, 1, 1
			turnoff2 10, 1, 1
			turnoff2 101, 1, 1
			turnoff2 102, 1, 1
			turnoff2 103, 1, 1					
			turnoff2 104, 1, 1	
		endif
		
endin
