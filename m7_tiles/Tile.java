/*----------------------------------------------------------------------------------------------------------------------
Author: Brennen Green
Instructor: Mrs.Tucker
Class: INF 120
Date: 10/8/2018
Class Name: Tile
Purpose: TODO
------------------------------------------------------------------------------------------------------------------------
INPUTS: Color provided by driver program, value provided by driver program
OTHER VALUES:
OUTPUTS: Tile Color, Tile Value, String Format of class
PROCESSING: TODO
------------------------------------------------------------------------------------------------------------------------
 */
public class Tile
{
  private String color;
  private int value;

  public Tile()
  {
    self.color = "NO COLOR";
    self.value = 0;
  }

  public Tile(String color, int value)
  {
    self.color = color;
    self.value = value;
  }

  public String getColor()
  {
    return self.color;
  }

  public int getValue()
  {
    return self.value;
  }

  public void setColor(String color)
  {
    self.color = color;
  }

  public void setValue(int value)
  {
    self.value = value;
  }

  // TODO: tradeTile(String color, int value), toString()
}
