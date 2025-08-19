/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class Car extends Vehicle {

    public Car(int vehicleID, int rentalRATE, String Brand, String Model, boolean IsAvailable) {
        super(vehicleID, rentalRATE, Brand, Model, IsAvailable);
    }
    int numberOfDoors;

    public void displayDetails(int numberofDoors) {
        super.displayDetails();
        System.out.println("Number of Doors: " + numberOfDoors);
    }
    
    float luxuryTax;
    public double calculateRentalCost(int days, double discountPercentage, float luxuryTax) {
        return ( ( (super.getRentalRate() * days) * discountPercentage ) + luxuryTax);
    }
}
