/*----------------------------------------------------------------------------------------------------------------------
Author: Brennen Green
Instructor: Mrs.Tucker
Class: INF 120
Date: 11/1/2018
Class Name: Dalmuti_2D
Purpose: Class which creates an array that holds all the cards in the game m10_dalmuti
then deals all cards to a 2D array which represents each of 4 players hands
------------------------------------------------------------------------------------------------------------------------
INPUTS: User response to playing again
OTHER VALUES: All possible cards, all user hands (in 2D array)
OUTPUTS: All player hands
PROCESSING: Generate all 80 cards, swap all cards in the deck randomly(shuffle), validate all data, and deal all cards 
properly
------------------------------------------------------------------------------------------------------------------------
 */
import java.util.Scanner;

public class  Dalmuti_2D
{
  public static void main (String[] args)
  {
      Scanner scnr = new Scanner(System.in);
      /*****************************************************************************************************************
       * BEGIN DECK GENERATION
       * The following code uses a for loop and branches to generate all 80 cards of the deck properly formatted using
       * the defined cardToString() method which takes a integer rank value and a string rank name.
       * 
       * It then uses another defined method, shuffleCards() which takes an array of strings as an argument and randomly
       * sorts that array.
       * 
       ****************************************************************************************************************/
      String[] deckOfCards = new String[80];
      for (int i = 0; i <= deckOfCards.length; ++i)
      {
        if (i == 1)
        {
          deckOfCards[i] = (cardToString(1, "Dalmuti"));
        }
        else if (i <= 3)
        {
          deckOfCards[i] = (cardToString(2, "Archbishop"));
        }
        else if (i <= 6)
        {
          deckOfCards[i] = (cardToString(3, "Earl Marshal"));
        }
        else if (i <= 10)
        {
          deckOfCards[i] = (cardToString(4, "Baroness"));
        }
        else if (i <= 15)
        {
          deckOfCards[i] = (cardToString(5, "Abbess"));
        }
        else if (i <= 21)
        {
          deckOfCards[i] = (cardToString(6, "Knight"));
        }
        else if (i <= 27)
        {
          deckOfCards[i] = (cardToString(7, "Seamstress"));
        }
        else if (i <= 35)
        {
          deckOfCards[i] = (cardToString(8, "Mason"));
        }
        else if (i <= 44)
        {
          deckOfCards[i] = (cardToString(9, "Cook"));
        }
        else if (i <= 54)
        {
          deckOfCards[i] = (cardToString(10, "Shepherdess"));
        }
        else if (i <= 65)
        {
          deckOfCards[i] = (cardToString(11, "Stonecutter"));
        }
        else if (i <= 77)
        {
          deckOfCards[i] = (cardToString(12, "Peasant"));
        }
        else if (i < deckOfCards.length)
        {
          deckOfCards[i] = (cardToString(13, "Jester"));
        }
      }
      
      String userResponse;
      do
      {
        deckOfCards = shuffleCards(deckOfCards);

        String[][] cardsHeldByPlayers = new String[4][20];
        cardsHeldByPlayers = dealCards(cardsHeldByPlayers, deckOfCards);

        /*****************************************************************************************************************
         * BEGIN OUTPITTING DEALT CARDS
         * Using a for loop over the length of players it will display each play individually using displayCards()
         ****************************************************************************************************************/
        for (int currentPlayer = 0; currentPlayer < cardsHeldByPlayers.length; currentPlayer++)
        {
          System.out.print("Now displaying cards for player " + (currentPlayer + 1) + "\n-------------------------------\n");
          displayCards(cardsHeldByPlayers[currentPlayer]);
          System.out.println("-------------------------------");
        }

        /*****************************************************************************************************************
         * BEGIN USER INPUT
         * Gather and validate user input about repeating the game
         * 
         ****************************************************************************************************************/
        System.out.print("------------------------------\n Would you like to play again? (y for yes)\n");
        userResponse = scnr.nextLine();
      } while (userResponse.charAt(0) == 'y');
  }

  static void displayCards(String[] playerColumn)
  {
    /******************************************************************************************************************
     * Given a specific column that represents a player, displays that players cards
     ******************************************************************************************************************/
    for (int i = 0; i < playerColumn.length; i++ )
    {
      System.out.println(playerColumn[i]);
    }

  }

  static String[][] dealCards(String[][] arrayToDealTo, String[] deckToDealFrom)
  {
    int currentCard = 0;
      for (int row = 0; row < arrayToDealTo.length; row++)
      {
        for (int column = 0; column < arrayToDealTo[row].length; column++)
        {
          arrayToDealTo[row][column] = deckToDealFrom[currentCard++];
        }
      }
    return arrayToDealTo;
  }

  static String cardToString(int cardRank, String cardName)
  {
    /*****************************************************************************************************************
     * Format card given in argument as a string
     ****************************************************************************************************************/
      return String.format("%d: %s", cardRank, cardName);
  }

  static String[] shuffleCards(String[] deck)
  {
      /*****************************************************************************************************************
       * Credit to https://introcs.cs.princeton.edu/java/14array/ this sorting algorithm is derived from the example
       * given by the handout.
       * 
       ****************************************************************************************************************/
      int deck_length = deck.length;
      for (int i = 0; i < deck_length; ++i)
      {
        int randomValue = i + (int) (Math.random() * (deck_length-i));
        String swap = deck[randomValue];
        deck[randomValue] = deck[i];
        deck[i] = swap;
      }
      return deck;
  }
}
