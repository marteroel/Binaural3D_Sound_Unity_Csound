instr 1 

	kamp, kx, ky, kz init 0

	ksrc OSClisten giosc1, "/sourceAttributes1", "ffff", kx, ky, kz, kamp

	ksmoothx port kx, .025
	ksmoothy port ky, .025
	ksmoothz port kz, .025

gamain = gasrc1 + gamain

  		aearlyl,aearlyr, p4, p5, gimfp hrtfearly gasrc1*(kamp), ksmoothx, ksmoothy, ksmoothz, gklisxSmooth, gklisySmooth, gkliszSmooth, "hrtf-44100-left.dat", "hrtf-44100-right.dat", 0, 8, 44100, giorder, 1, gklisdirSmooth, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23

outs	aearlyl, aearlyr

gasrc1 = 0
  	
endin

instr 2 

	kamp, kx, ky, kz init 0

	ksrc OSClisten giosc1, "/sourceAttributes2", "ffff", kx, ky, kz, kamp

	ksmoothx port kx, .025
	ksmoothy port ky, .025
	ksmoothz port kz, .025
	
gamain = gasrc2 + gamain

  		aearlyl,aearlyr, p4, p5, gimfp hrtfearly gasrc2*(kamp), ksmoothx, ksmoothy, ksmoothz, gklisxSmooth, gklisySmooth, gkliszSmooth, "hrtf-44100-left.dat", "hrtf-44100-right.dat", 0, 8, 44100, giorder, 1, gklisdirSmooth, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23

  outs	aearlyl, aearlyr
  
gasrc2 = 0
  	
endin

instr 3 

	kamp, kx, ky, kz init 0

	ksrc OSClisten giosc1, "/sourceAttributes3", "ffff", kx, ky, kz, kamp

	ksmoothx port kx, .025
	ksmoothy port ky, .025
	ksmoothz port kz, .025
	
gamain = gasrc3 + gamain

   		aearlyl,aearlyr, p4, p5, gimfp hrtfearly gasrc3*(kamp), ksmoothx, ksmoothy, ksmoothz, gklisxSmooth, gklisySmooth, gkliszSmooth, "hrtf-44100-left.dat", "hrtf-44100-right.dat", 0, 8, 44100, giorder, 1, gklisdirSmooth, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23

  outs	aearlyl, aearlyr
  
  
gasrc3 = 0	


endin

instr 4
	
	kamp, kx, ky, kz init 0

	ksrc OSClisten giosc1, "/sourceAttributes4", "ffff", kx, ky, kz, kamp

	ksmoothx port kx, .025
	ksmoothy port ky, .025
	ksmoothz port kz, .025

gamain = gasrc4 + gamain

  		aearlyl,aearlyr, p4, p5, gimfp hrtfearly gasrc4*(kamp), ksmoothx, ksmoothy, ksmoothz, gklisxSmooth, gklisySmooth, gkliszSmooth, "hrtf-44100-left.dat", "hrtf-44100-right.dat", 0, 8, 44100, giorder, 1, gklisdirSmooth, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23

  outs	aearlyl, aearlyr
  
gasrc4 = 0
  
endin
