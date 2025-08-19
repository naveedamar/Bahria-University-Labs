/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.finals;

/**
 *
 * @author navee
 */
public class FINALS {

    public static void main(String[] args) {
        System.out.println("Welcome to the Restaurant!");

        Order myOrder = new Order();

        myOrder.addMeal(new AsianMeal("Sushi", 2));
        myOrder.addMeal(new ItalianMeal("Pizza", "Pepperoni"));
        myOrder.addMeal(new MexicanMeal("Burritos", "Chicken"));

        myOrder.showOrderSummary();
        myOrder.startPreparing();

        System.out.println("\nEnjoy your meal!");
    }
}
