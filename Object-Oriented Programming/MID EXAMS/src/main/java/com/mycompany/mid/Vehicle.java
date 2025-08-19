/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class Vehicle {

    private int vehicleId, rentalRate;
    private String brand, model;
    private boolean isAvailable;

    public Vehicle(int vehicleID, int rentalRATE, String Brand, String Model, boolean IsAvailable) {
        this.vehicleId = vehicleID;
        this.rentalRate = rentalRATE;
        this.brand = Brand;
        this.model = Model;
        this.isAvailable = IsAvailable;
    }

    public void displayDetails() {
        System.out.println("Vehicle ID: " + vehicleId);
        if (rentalRate < 0) {
            System.out.println("Rental Rate can not be negative");
        } else {
            System.out.println("Rental Rate: " + rentalRate);
        }
        System.out.println("Brand: " + brand);
        System.out.println("Model: " + model);
        System.out.println("Is Available: " + isAvailable);
    }

    public double calculateRentalCost(int days) {
        if (days > 7) {
            return ((rentalRate * days) * 0.1);
        } else {
            return (rentalRate * days);
        }
    }

    public double calculateRentalCost(int days, double discountPercentage) {
        return ((rentalRate * days) * discountPercentage);
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public void setVehicleId(int vehicleId) {
        this.vehicleId = vehicleId;
    }

    public int getRentalRate() {
        return rentalRate;
    }

    public void setRentalRate(int rentalRate) {
        this.rentalRate = rentalRate;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public boolean isIsAvailable() {
        return isAvailable;
    }

    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }

}
