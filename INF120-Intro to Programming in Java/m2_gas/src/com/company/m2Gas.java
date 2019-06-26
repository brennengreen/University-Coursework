/*----------------------------------------------------------------------------------------------------------------------
Author: Brennen Green
Instructor: Mrs.Tucker
Class: INF 120
Date: 08/31/2018
Program Name: m2_gas
Purpose: Used to calculate the total kWH of a household based on user given inputs
------------------------------------------------------------------------------------------------------------------------
INPUTS: numRefrigerators, numDishWasher, numOvens, numMicrowaves, numCoffeeMachines, numComputers, numTV, numWasherDryer
OTHER VALUES: The program must keep a constant kWH of every application listed above, as well as the average cost of
kWH which is $0.09047
OUTPUT: Monthly cost for all the appliances to run
PROCESSING: Must multiply amount of each appliance by the average KWH of that appliance, add all of those products up
and multiply that sum by the average cost per KWH
------------------------------------------------------------------------------------------------------------------------
 */
package com.company;

import java.util.Scanner;

public class m2Gas {

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
        final int CELING_FAN_KWH = 75;
        final int LAMPS_LIGHT_KWH = 14;

        int refrigerators;
        int dishwashers;
        int ovens;
        int microwaves;
        int coffeeMachines;
        int computers;
        int tvs;
        int washerDryers;
        int ceilingFans;
        int lampsLights;

        Scanner scnr = new Scanner(System.in);

        /* Output chunk of the code, all the outputs here involve asking the
         * user for specific input, which the scanner gathers using nextInt()
         */

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
        System.out.print("Celing Fans: ");
        ceilingFans = scnr.nextInt();
        System.out.print("Lamps or light fixtures: ");
        lampsLights = scnr.nextInt();

        /* This big equation is just multiplying all amounts inputted by the
         * user by the average KWH/month by that appliance.
         */
        int totalKwh = (refrigerators * REFRIGERATOR_KWH) + (dishwashers * DISHWASHER_KWH) + (ovens * OVEN_KWH) +
                (microwaves * MICROWAVE_KWH) + (coffeeMachines * COFFEE_MACHINE_KWH) +
                (computers * COMPUTER_KWH) + (tvs * TV_KWH) + (washerDryers * WASHER_DRYER_KWH) +
                (ceilingFans * CELING_FAN_KWH) + (lampsLights * LAMPS_LIGHT_KWH);

        // Multiplies the totalKwH by average cost per KWH
        double totalCost = totalKwh * COST_PER_KWH;

        // Pretty prints the totalKwh and estimated cost to user
        System.out.println("Total Kilowatts Per Hour " + totalKwh + " Total cost per month: $" + totalCost);



    }
}
