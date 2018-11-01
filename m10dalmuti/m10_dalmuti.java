/*----------------------------------------------------------------------------------------------------------------------
Author: Brennen Green
Instructor: Mrs.Tucker
Class: INF 120
Date: 11/1/2018
Class Name: m10_dalmuti
Purpose: Class which creates an array that holds all the cards in the game m10_dalmuti
then deals all cards to the appropriate amount of players
------------------------------------------------------------------------------------------------------------------------
INPUTS:
OTHER VALUES:
OUTPUTS:
PROCESSING:
------------------------------------------------------------------------------------------------------------------------
 */
public class  m10_dalmuti
{
  public static void main (String[] args)
  {
      List<String> handOfCards = new ArrayList<String>();
      for (int i = 0; i <= 80; ++i)
      {
          switch (i)
          {
              case 1:
                handOfCards.add(cardToString(i, "Dalmuti"));
                break;
              case 2:
                handOfCards.add(cardToString(i, "Archbishop"));
                break;
              case 3:
                handOfCards.add(cardToString(i, "Earl Marshal"));
                break;
              case 4:
                handOfCards.add(cardToString(i, "Baroness"));
                break;
              case 5:
                handOfCards.add(cardToString(i, "Abbess"));
                break;
              case 6:
                handOfCards.add(cardToString(i, "Knight"));
                break;
              case 7:
                handOfCards.add(cardToString(i, "Seamstress"));
                break;
              case 8:
                handOfCards.add(cardToString(i, "Mason"));
                break;
              case 9:
                handOfCards.add(cardToString(i, "Cook"));
                break;
              case 10:
                handOfCards.add(cardToString(i, "Shepherdess"));
                break;
              case 11:
                handOfCards.add(cardToString(i, "Stonecutter"));
                break;
              case 12:
                handOfCards.add(cardToString(i, "Peasant"));
                break;
              case 13:
                handOfCards.add(cardToString(i, "Jester"));
                break;
              default:
                System.out.println("Error: Improper Value");
          }
      }
  }

  public static String cardToString(int cardRank, String cardName)
  {
      return String.format("%d. %s", cardRank, cardName);
  }
}
