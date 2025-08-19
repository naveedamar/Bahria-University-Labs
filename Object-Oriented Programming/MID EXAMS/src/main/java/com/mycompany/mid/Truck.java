/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class Truck extends Vehicle {

    public Truck(int vehicleID, int rentalRATE, String Brand, String Model, boolean IsAvailable) {
        super(vehicleID, rentalRATE, Brand, Model, IsAvailable);
    }

    int loadCapacity, serviceFee = 1000, totalCost ;
    
    public void displayDetails(int loadCap) {
        super.displayDetails();
        if(loadCap > 5000){
            totalCost = super.getRentalRate() + serviceFee;
        }
        System.out.println("Max Load Capacity: " + loadCap);
    }
    
    public double calculateRentalCost(int days, double discountPercentage, int serviceFee) {
        return ( ( (super.getRentalRate() * days) * discountPercentage ) + serviceFee);
    }
}
