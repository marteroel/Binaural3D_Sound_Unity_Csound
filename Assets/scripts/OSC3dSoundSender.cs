/*
 * 
 * 3D sound template for use with Brian Carty's Csound opcodes via OSC
 * Developed by Marte Roel, 2013
 * marteroel@gmail.com
 * 
 * */

using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;

[AddComponentMenu("Scripts/OSC3dSoundSender")]

/// <summary>
/// Simple OSC test communication script
/// </summary>

public class OSC3dSoundSender : MonoBehaviour
{	
    private Osc oscHandler;
	
	public string remoteIp;
    public int sendToPort;
	
	public bool SoundOnOff;
	public int soundAlgorithm;	//0 = hrtfearly Csound, 1 = hrtfmove Csound
		
	private int soundEnable; 
	
	public Transform listener;
	
	public Transform soundObject1;
	public string soundName1;
	public float soundObject1Level;
	public bool sound1Loop;
	
	public Transform soundObject2;
	public string soundName2;
	public float soundObject2Level;
	public bool sound2Loop;
	
	public Transform soundObject3;
	public string soundName3;
	public float soundObject3Level;
	public bool sound3Loop;
	
	public Transform soundObject4;
	public string soundName4;
	public float soundObject4Level;
	public bool sound4Loop;
	
	public Vector3 roomSizeInMeters;
	
	public float reverbAmount;
	public float lowFreqReverbTime;
	public float highFreqReverbTime;
	
	public float wallHighAbsptnCoeff;
    public float wallLowAbsptnCoeff;
	public float wallGain250Hz;
	public float wallGain1000Hz;
	public float wallGain4000Hz;
	public float floorHighAbsptnCoeff;
	public float floorLowAbsptnCoeff;
	public float floorGain250Hz;
	public float floorGain1000Hz;
	public float floorGain4000Hz;
	public float ceilingHighAbsptnCoeff;
	public float ceilingLowAbsptnCoeff;
	public float ceilingGain250Hz;
	public float ceilingGain1000Hz;
	public float ceilingGain4000Hz;
	
    ~OSC3dSoundSender()
    {
        if (oscHandler != null)
        {            
            oscHandler.Cancel();
        }
		
        // speed up finalization
        oscHandler = null;
        System.GC.Collect();
    }
	
	
	/// <summary>
    /// Start is called just before any of the Update methods is called the first time.
    /// </summary>
    void Start()
    {
        UDPPacketIO udp = GetComponent<UDPPacketIO>();
        udp.init(remoteIp, sendToPort, 0);
         
	    oscHandler = GetComponent<Osc>();
        oscHandler.init(udp);
		
    }
	
	
	void Update()
	{
		string[] soundsOnOff  = new string [4];
		
		if(soundObject1 !=null)
		{
			SoundPositions(soundAlgorithm, 1, soundObject1, soundObject1Level);	
			soundsOnOff[0] = "1";
		}
		else 	
			soundsOnOff[0] = "0";	
		
		if(soundObject2 !=null)
		{
			SoundPositions(soundAlgorithm, 2, soundObject2, soundObject2Level) ;	
			soundsOnOff[1] = "1";
		}
		else 	
			soundsOnOff[1] = "0";
		
		if(soundObject3 !=null)
		{
			SoundPositions(soundAlgorithm, 3, soundObject3, soundObject3Level);	
			soundsOnOff[2] = "1";
		}
		else 	
			soundsOnOff[2] = "0";	
		
		if(soundObject4 !=null)
		{
			SoundPositions(soundAlgorithm, 4, soundObject4, soundObject4Level);	
			soundsOnOff[3] = "1";
		}
		else 	
			soundsOnOff[3] = "0";	
		
		if (soundAlgorithm == 0)	
			ListenerAndSpace();	
		
	    SourceLooping();
		
		OscMessage onOff = Osc.StringToOscMessage("/onOff " + soundsOnOff[0] + " " + 	soundsOnOff[1] + " " + soundsOnOff[2] + " " + soundsOnOff[3]);
		OscMessage srcName = Osc.StringToOscMessage("/sourceName " + soundName1 + " " + soundName2 + " " +  soundName3 + " " + soundName4);
		
		oscHandler.Send(onOff);
		oscHandler.Send(srcName);
	}
	
	
    /// <summary>
    /// Does the processing for sending spacial information to Csound.
    /// </summary>
 
    void SoundPositions(int algorithm, int soundSource, Transform soundObject, float level)
    {		
		OscMessage sourceAttributes = null;
		
		//Positions sent to Csound
		
	if (algorithm == 0) {	
			//to OSC
			sourceAttributes = Osc.StringToOscMessage("/sourceAttributes" + soundSource.ToString() + " " + 
				(soundObject.position.x + (roomSizeInMeters[0]/2)).ToString() + " " + 
				(soundObject.position.z + (roomSizeInMeters[2]/2)).ToString() + " " + 
				(soundObject.position.y + (roomSizeInMeters[1]/2)).ToString() + " " +
				(level).ToString());	
			
			
		}

	else if (algorithm == 1) { 
			
		sourceAttributes = Osc.StringToOscMessage("/sourceAttributes" + soundSource.ToString() 
				+ " " + (((Mathf.Atan2((soundObject.position.x-listener.position.x), (soundObject.position.z-listener.position.z)))*(180/Mathf.PI)) - listener.rotation.eulerAngles[1]).ToString()
			 	+ " " + (((Mathf.Atan2((soundObject.position.y-listener.position.y), (soundObject.position.z-listener.position.z)))*(180/Mathf.PI))+listener.rotation.eulerAngles[0]).ToString()
				+ " " + ((1/(((Mathf.Pow(((soundObject.position.x)-(listener.position.x)),2) + Mathf.Pow(((soundObject.position.y)-(listener.position.y)),2) + Mathf.Pow(((soundObject.position.z)-(listener.position.z)),2) +1))))*level).ToString());
		}
		
		
			oscHandler.Send(sourceAttributes);
    }
	
	
	void ListenerAndSpace()
	{	
		OscMessage lisPos = null, verb = null, roomParameters = null;
		
		lisPos = Osc.StringToOscMessage("/listenerPositions " + (listener.position.x + (roomSizeInMeters[0]/2)).ToString() + " " + 
			(listener.position.z + (roomSizeInMeters[2]/2)).ToString()  + " " + (listener.position.y + (roomSizeInMeters[1]/2)).ToString() + " " +
			(listener.rotation.eulerAngles[1].ToString()) );
		
		verb = Osc.StringToOscMessage("/reverbAmount " + (reverbAmount.ToString()));
		
		if (roomSizeInMeters[0] < 2)
				roomSizeInMeters[0] = 2;
		if (roomSizeInMeters[1] < 2)
				roomSizeInMeters[1] = 2;
		if (roomSizeInMeters[2] < 2)
				roomSizeInMeters[2] = 2;
		
		roomParameters = Osc.StringToOscMessage ("/roomParameters " + (roomSizeInMeters[0].ToString() + " " + roomSizeInMeters[2].ToString() + " " + 
			roomSizeInMeters[1].ToString() + " " + lowFreqReverbTime.ToString() + " " + highFreqReverbTime.ToString() + " " + wallHighAbsptnCoeff.ToString() + " " + 
			wallLowAbsptnCoeff.ToString() + " " + wallGain250Hz.ToString() + " " + wallGain1000Hz.ToString() + " " + wallGain4000Hz.ToString() + " " +
			floorHighAbsptnCoeff.ToString() + " " + floorLowAbsptnCoeff.ToString() + " " + floorGain250Hz.ToString() + " " +  floorGain1000Hz.ToString() + " " +  
			floorGain4000Hz.ToString() + " " + ceilingHighAbsptnCoeff.ToString() + " " + ceilingLowAbsptnCoeff.ToString() + " " +ceilingGain250Hz.ToString() + " " +  
			ceilingGain1000Hz.ToString() + " " + ceilingGain4000Hz.ToString()));

		oscHandler.Send (lisPos);
		
		oscHandler.Send(verb);
		oscHandler.Send(roomParameters);	
		
	}
	
		void SourceLooping()
	{
		int loop1, loop2, loop3, loop4;
		if (sound1Loop)
			loop1 = 1;
		else 
			loop1 = 0;	
		if (sound2Loop)
			loop2 = 1;
		else 
			loop2 = 0;
		if (sound3Loop)
			loop3 = 1;
		else 
			loop3 = 0;	
		if (sound4Loop)
			loop4 = 1;
		else 
			loop4 = 0;
		
		OscMessage srcLoop = Osc.StringToOscMessage ("/sourceLoop " + loop1.ToString() + " " + loop2.ToString() + " " + 
			loop3.ToString() + " " + loop4.ToString());
		oscHandler.Send(srcLoop);	
	}
	
	
	
    /// <summary>
    /// Awake is called when the script instance is being loaded.
    /// </summary>
    void Awake()
    {    
    }
	
	
    void OnDisable()
    {				
		OscMessage onOff = Osc.StringToOscMessage("/onOff " + 2 + " " + 2 + " " + 2 + " " + 2);
		oscHandler.Send(onOff);
		
		OscMessage ending = Osc.StringToOscMessage("/end 1");
		oscHandler.Send(ending);

        Debug.Log("closing OSC UDP socket in OnDisable");
        oscHandler.Cancel();
        oscHandler = null;
    }	
}