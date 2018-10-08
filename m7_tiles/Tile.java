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
        this("NO COLOR", 0);
    }

    public Tile(String color, int value)
    {
        tradeTiles(color, value);
    }

    public String getColor()
    {
        return this.color;
    }

    public int getValue()
    {
        return this.value;
    }

    public void setColor(String color)
    {
        this.color = color;
    }

    public void setValue(int value)
    {
        this.value = value;
    }

    public void tradeTiles(String color, int value)
    {
        if (color.toLowerCase() != "red" || color.toLowerCase() != "black" || color.toLowerCase() != "yellow" || color.toLowerCase() != "blue")
        {
            this.color = "NO COLOR";
            this.value = 0;
        }
        else if (value > 14 || value < 1)
        {
            this.color = "NO COLOR";
            this.value = 0;
        }
        else if (value == 14 && (color.toLowerCase() != "red" || color.toLowerCase() != "black"))
        {
            this.color = "NO COLOR";
            this.value = 0;
        }
        else
        {
            this.color = color;
            this.value = value;
        }
    }
}
