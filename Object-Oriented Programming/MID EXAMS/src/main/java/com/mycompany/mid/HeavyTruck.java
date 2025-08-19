/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class HeavyTruck extends Truck {

    public HeavyTruck(int vehicleID, int rentalRATE, String Brand, String Model, boolean IsAvailable) {
        super(vehicleID, rentalRATE, Brand, Model, IsAvailable);
    }

    double maxTonnage;
    int permitFee = 500;

    public void displayDetails(double maxToonage) {
        super.displayDetails();
        if (maxToonage > 10000) {
            System.out.println("Special licensing restrictions applied!");
            System.out.println("Permit fee applied: " + permitFee);
        }
        System.out.println("Max Tonage Capacity: " + maxToonage);
    }

    public double calculateRentalCost(int days, double discountPercentage, int permitFee) {
        return (((super.getRentalRate() * days) * discountPercentage) + permitFee);
    }
}
