/*------------------------------------------------------------------------------------------------------
 * TileDriver.java
 * 		This is a driver program for the Tile class that students create
 *
 * NOTES TO STUDENTS:
 *
 * 	Save this program in the same location as your Tile class
 * 	Compile your Tile class.  Compile this driver program.
 * 	Run the driver program to test your class.
 *
 *  DO NOT CHANGE THIS CODE.  ALL ERRORS WILL BE DUE TO YOUR CODE IN Tile.java
 * ----------------------------------------------------------------------------------------------------*/

import java.util.Scanner;
import java.util.Calendar;

public class TileDriver
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner (System.in);

		//-----------------------------------------------------------------------------------------------
		// TESTING CONSTRUCTORS
		//
		// New objects are instantiated using the Tile class
		// Both constructors are used to test the two constructors
		//
		//   tileSample1 is a valid Tile object which used the default constructors
		//   tileSample2 is a valid Tile object which used the 2-parameter constructor
		//   tileSample3 has an invalid color.  This tests the constructor validation
		//   tileSample4 has an invalid value.  This tests the constructor validation
		//   tileSample5 has an invalid color for a Joker.  This tests the constructor validation
		//
		//-----------------------------------------------------------------------------------------------

		Tile tileSample1 = new Tile ();
		Tile tileSample2 = new Tile ("Red", 5);
		Tile tileSample3 = new Tile ("Purple", 8);
		Tile tileSample4 = new Tile ("Blue", 15);
		Tile tileSample5 = new Tile ("Yellow", 14);

		//-----------------------------------------------------------------------------------------------
		//  Results of instantiation is displayed
		//-----------------------------------------------------------------------------------------------

		System.out.println("\n\nWelcome to the Tile Driver\n");
		System.out.println("-----------------   Testing Mutators   -------------------\n");
		System.out.println("Tile 1: Default Constructor: \t" + tileSample1.toString());
		System.out.println("Tile 2: Valid Parameters:\t\t" + tileSample2);
		System.out.println("Tile 3: Invalid color: \t\t" + tileSample3);
		System.out.println("Tile 4: Invalid value: \t\t" + tileSample4);
		System.out.println("Tile 5: Invalid Joker color: \t" + tileSample5 + "\n\n");

		//-----------------------------------------------------------------------------------------------
		//  TESTING tradeTiles()
		//
		//  Tiles 1-2 are set to valid values using the tradeTiles() method
		//	Tiles 3-5 are attempted to be set to invalid values using tradeTiles();
		//  This tests the mutators:
		//
		//	tileSample3		Invalid joker
		//	tileSample4		Invalid color
		//	tileSample5		Invalid value
		//-----------------------------------------------------------------------------------------------


		tileSample1.tradeTiles("Blue",12);
		tileSample2.tradeTiles("Black",14);
		tileSample3.tradeTiles("Yellow",14);
		tileSample4.tradeTiles("Purple",1);
		tileSample5.tradeTiles("Blue", 20);

		System.out.println("------------- Testing tradeTiles method ------------------\n");
		System.out.println("Tile 1: valid:\t\t\t" + tileSample1.toString());
		System.out.println("Tile 2: valid:\t\t\t" + tileSample2);
		System.out.println("Tile 3: Invalid joker: \t\t" + tileSample3);
		System.out.println("Tile 4: Invalid color: \t\t" + tileSample4);
		System.out.println("Tile 5: Invalid value: \t\t" + tileSample5 + "\n\n");


		//-----------------------------------------------------------------------------------------------
		//  TESTING mutators
		//
		//  Tiles 3-5 are set to valid values using the tradeTiles() method
		//
		//
		//	tileSample1		Invalid color -  No change - still Blue 12
		//	tileSample2		Invalid value -  No change - still Black Joker
		//	tileSample3		Invalid joker -  No change - still Yellow 9
		//  tileSample4     Valid color change from Blue to Red
		//  tileSample5		Valid value change from 10 to 8
		//-----------------------------------------------------------------------------------------------

		tileSample3.tradeTiles("Yellow",9);
		tileSample4.tradeTiles("Blue",1);
		tileSample5.tradeTiles("Red", 10);


		tileSample1.setColor("Orange");
		tileSample2.setValue(20);
		tileSample3.setValue(14);
		tileSample4.setColor("Red");
		tileSample5.setValue(8);

		System.out.println("------------------   Testing mutators   ------------------\n");
		System.out.println("Tile 1: Invalid color still Blue 12:\t\t" + tileSample1.toString());
		System.out.println("Tile 2: Invalid value still Black Joker:\t" + tileSample2);
		System.out.println("Tile 3: Invalid joker still Yellow 9: \t\t" + tileSample3);
		System.out.println("Tile 4: Valid color change to Red: \t\t" + tileSample4);
		System.out.println("Tile 5: Valid value change to 8: \t\t" + tileSample5 + "\n\n");

		//-----------------------------------------------------------------------------------------------
		//  TESTING accessors
		//
		//	tileSample1		displaying color and value using the accessors
		//-----------------------------------------------------------------------------------------------

		System.out.println("-----------------  Testing accessors  --------------------\n");
		System.out.println("Tile 1 Color (Blue):\t" + tileSample1.getColor());
		System.out.println("Tile 1 Value (12):\t\t" + tileSample1.getValue() + "\n\n");

	}
}
