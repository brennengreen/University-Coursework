//-------------------------------------------------
//   State Class
//
//   STUDENTS:  UPDATE WITH YOUR PERSONAL INFORMATION
//-------------------------------------------------
import java.util.Calendar;

public class State
{
	private String stateName;
	private String stateCapital;
	private	String stateBird;
	private String stateFlower;
	private String stateNickName;
	private String dateEnteredUnion;
	private int yearSettled;


//--------------------------------------------------
//    Constructor for the State class
//--------------------------------------------------

	public State (String stateName, String stateCapital, String stateBird, String stateFlower)
	{
		this.stateName = stateName;
		this.stateCapital = stateCapital;
		this.stateBird = stateBird;
		this.stateFlower = stateFlower;
	}
	public State (String stateName, String stateCapital, String stateBird, String stateFlower, String nickname, String dateEnteredUnion, int yearSettled)
	{
		this.stateName = stateName;
		this.stateCapital = stateCapital;
		this.stateBird = stateBird;
		this.stateFlower = stateFlower;
		this.stateNickName = nickname;
		this.dateEnteredUnion = dateEnteredUnion;
		if (yearSettled > 1600 && yearSettled < Calendar.getInstance().get(Calendar.YEAR))
		{
			this.yearSettled = yearSettled;
		}
	}

//--------------------------------------------------
//    Accessors for the State class
//--------------------------------------------------

	public String getStateName()
	{	return stateName;	}

	public String getStateCapital()
	{	return stateCapital;	}

	public String getStateBird()
	{	return stateBird;	}

	public String getStateFlower()
	{	return stateFlower;	}

	public String getNickName()
	{ return stateNickName; }

	public String getDateEnteredUnion()
	{ return dateEnteredUnion; }

	public int getYearSettled()
	{ return yearSettled; }


//--------------------------------------------------
//    Mutators for the State class
//--------------------------------------------------

	public void setStateName(String stateName)
	{	this.stateName = stateName;	}

	public void setStateCapital(String stateCapital)
	{	this.stateCapital = stateCapital;	}

	public void setStateBird(String stateBird)
	{	this.stateBird = stateBird;	}

	public void setStateFlower(String stateFlower)
	{	this.stateFlower = stateFlower;	}

	public void setNickName(String nickname)
	{ return stateNickName; }

	public void setDateEnteredUnion(String dateEnteredUnion)
	{ return dateEnteredUnion; }

	public void setYearSettled(int yearSettled)
	{
		if (yearSettled > 1600 && yearSettled < Calendar.getInstance().get(Calendar.YEAR))
		{
			this.yearSettled = yearSettled;
		}
	}

//--------------------------------------------------
//    toString() method to override method from
//	  Object class
//--------------------------------------------------

	public String toString ()
	{ return stateName + "\t" + stateCapital;	}

}
