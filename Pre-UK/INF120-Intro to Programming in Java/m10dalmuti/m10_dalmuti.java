/*----------------------------------------------------------------------------------------------------------------------
Author: Brennen Green
Instructor: Mrs.Tucker
Class: INF 120
Date: 11/1/2018
Class Name: m10_dalmuti
Purpose: Class which creates an array that holds all the cards in the game m10_dalmuti
then deals all cards to the appropriate amount of players
------------------------------------------------------------------------------------------------------------------------
INPUTS: Number of players in game
OTHER VALUES: All possible cards
OUTPUTS: All player hands
PROCESSING: Generate all 80 cards, swap all cards in the deck randomly, validate all data, and deal all cards
------------------------------------------------------------------------------------------------------------------------
 */
import java.util.Scanner;

public class  m10_dalmuti
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
      
      deckOfCards = shuffleCards(deckOfCards);
      /*****************************************************************************************************************
       * BEGIN USER INPUT
       * Gather and validate user input for the amount of players in the game.
       * 
       ****************************************************************************************************************/
      System.out.println("============WELCOME TO THE DALMUTI GAME============\n\n");
      int numPlayers;
      do
      {
        System.out.println("How many players are playing: (4-8 players required)");
        numPlayers = scnr.nextInt();
      } while (numPlayers < 4 || numPlayers > 8);
      /*****************************************************************************************************************
       * BEGIN OUTPITTING DEALT CARDS
       * 
       ****************************************************************************************************************/
      dealCards(numPlayers, deckOfCards);

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

  static void dealCards(int numOfPlayers, String[] deck)
  {
      /*****************************************************************************************************************
       * Output cards to stream using a for loop starting from the top of the deck provided (arr[0])
       * 
       ****************************************************************************************************************/
    int deck_length = deck.length;
    for (int i = 0; i < numOfPlayers; ++i)
    {
      System.out.print("Player" + (i + 1) + "\t    ");
    }
    System.out.println("\n================================================================================================");
    for (int index = 0; index < deck_length; ++index)
    {
      System.out.print(deck[index] + "\t    ");
      if ((index + 1) % numOfPlayers == 0)
      {
        System.out.println();
      }
    }
  }
}
