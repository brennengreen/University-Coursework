/*----------------------------------------------------------------------------------------------------------------------
Program Name: m2_gas
Description: Used to calculate the total kWH of a household based on user given inputs
INPUTS: numRefrigerators, numDishWasher, numOvens, numMicrowaves, numCoffeeMachines, numComputers, numTV, numWasherDryer
OTHER VALUES: The program must keep a constant kWH of every application listed above, as well as the average cost of
kWH which is $0.09047
OUTPUT: Monthly cost for all the appliances to run
PROCESSING:


------------------------------------------------------------------------------------------------------------------------
 */
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final double COST_PER_KWH = 0.09047;
        final int REFRIGERATOR_KWH = 57;
        final int DISHWASHER_KWH = 13;
        final int OVEN_KWH = 24;
        final int MICROWAVE_KWH = 11;
        final int COFFEE_MACHINE_KWH = 10;
        final int COMPUTER_KWH = 21;
        final int TV_KWH = 23;
        final int WASHER_DRYER_KWH = 63;

        int refrigerators;
        int dishwashers;
        int ovens;
        int microwaves;
        int coffeeMachines;
        int computers;
        int tvs;
        int washerDryers;

        Scanner scnr = new Scanner(System.in);

        System.out.println("Please input the amount of each appliance you have in your household");
        System.out.print("Refrigerator: ");
        refrigerators = scnr.nextInt();
        System.out.print("Dishwasher: ");
        dishwashers = scnr.nextInt();
        System.out.print("Oven: ");
        ovens = scnr.nextInt();
        System.out.print("Microwave: ");
        microwaves = scnr.nextInt();
        System.out.print("Coffee Machine: ");
        coffeeMachines = scnr.nextInt();
        System.out.print("Computer: ");
        computers = scnr.nextInt();
        System.out.print("Television: ");
        tvs = scnr.nextInt();
        System.out.print("Washer/Dryer: ");
        washerDryers = scnr.nextInt();

        int totalKwh = (refrigerators * REFRIGERATOR_KWH) + (dishwashers * DISHWASHER_KWH) + (ovens * OVEN_KWH) +
                (microwaves * MICROWAVE_KWH) + (coffeeMachines * COFFEE_MACHINE_KWH) +
                (computers * COMPUTER_KWH) + (tvs * TV_KWH) + (washerDryers * WASHER_DRYER_KWH);
        double totalCost = totalKwh * COST_PER_KWH;

        System.out.println("Total Kilowatts Per Hour " + totalKwh + " Total cost per month: $" + totalCost);



    }
}
